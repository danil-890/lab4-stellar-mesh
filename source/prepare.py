"""HYG v2 -> SQLite / TetGen DLL -> cube-clipped Voronoi geometry.
Run from any directory: python source/prepare.py
All distances in generated meshes are light years.
"""
from pathlib import Path
import csv, gzip, json, sqlite3, subprocess, hashlib, time
import numpy as np
from scipy.spatial import HalfspaceIntersection, ConvexHull

ROOT = Path(__file__).resolve().parents[1]
CLASSES = 'OBAFGKM'
SCALE = 3.262
LIMIT = 500.

def read_table(path):
    lines = [s.split('#')[0].split() for s in path.read_text().splitlines()]
    lines = [s for s in lines if s]
    assert int(lines[0][0]) == len(lines)-1, path
    return lines[1:]

def slab(origin, direction, ray=False):
    lo, hi = 0., float('inf') if ray else 1.
    for a,b in zip(origin,direction):
        if abs(b)<1e-15:
            if abs(a)>LIMIT: return None
        else:
            t1,t2=sorted(((-LIMIT-a)/b,(LIMIT-a)/b))
            lo,hi=max(lo,t1),min(hi,t2)
            if lo>hi: return None
    if hi-lo<1e-12: return None
    return np.clip(np.array([origin+lo*direction,origin+hi*direction]),-LIMIT,LIMIT)

def add_sql(db, name, columns, rows):
    db.execute('CREATE TABLE "'+name+'" ('+','.join(columns)+')')
    db.executemany('INSERT INTO "'+name+'" VALUES ('+','.join('?' for _ in columns)+')',rows)

def process(cls, rows):
    start=time.perf_counter()
    target=ROOT/'results'/cls; target.mkdir(exist_ok=True)
    raw=np.array([[float(r[k])*SCALE for k in ['X','Y','Z']] for r in rows])
    # Keep the original catalogue record and explicit mapping when stars coincide.
    p, first, inverse=np.unique(raw,axis=0,return_index=True,return_inverse=True)
    order=np.argsort(first); remap=np.empty(len(order),int);remap[order]=np.arange(len(order))
    p=p[order]; first=first[order]; inverse=remap[inverse]
    with (target/f'{cls}500ly.csv').open('w',newline='') as f:
        w=csv.writer(f,delimiter=' ');w.writerow(['StarID','X','Y','Z','NodeID'])
        w.writerows((r['StarID'],*xyz,int(idx)) for r,xyz,idx in zip(rows,raw,inverse))
    prefix=target/f'{cls}500ly'
    np.savetxt(prefix.with_suffix('.node'),np.column_stack((np.arange(len(p)),p)),
               fmt=['%d','%.15g','%.15g','%.15g'],header=f'{len(p)} 3 0 0',comments='')
    cmd=[str(ROOT/'bin/tetgen_cli.exe'),str(prefix.with_suffix('.node'))]
    run=subprocess.run(cmd,capture_output=True,text=True)
    (target/'tetgen.log').write_text(run.stdout+run.stderr)
    if run.returncode: raise RuntimeError((cls,run.returncode,run.stdout,run.stderr))
    base=str(prefix)+'.1'
    suffixes=['node','edge','face','ele','neigh','v.node','v.edge','v.face','v.cell']
    tables={ext:read_table(Path(base+'.'+ext)) for ext in suffixes}
    edges=np.array(tables['edge'],int)[:,1:3]
    neigh=[set() for _ in p]
    for a,b in edges:neigh[a].add(b);neigh[b].add(a)
    vn=np.array(tables['v.node'],float)[:,1:4]
    clipped=[]; rays=0; kept_rays=0
    for row in tables['v.edge']:
        _,a,b,*normal=row;a=int(a);b=int(b)
        ray=b==-1;rays+=ray
        segment=slab(vn[a],np.array(normal,float) if ray else vn[b]-vn[a],ray)
        if segment is not None:clipped.append(segment);kept_rays+=ray
    caps=[];volumes=[];areas=np.zeros(6);max_violation=0.
    # Work in local coordinates y=x-p_i, ensuring a strict interior seed at y=0.
    for i,site in enumerate(p):
        ids=sorted(neigh[i]);delta=p[ids]-site
        norms=np.linalg.norm(delta,axis=1)
        H=np.column_stack((delta/norms[:,None],-norms/2))
        cube=[]
        for ax in range(3):
            for sign in [-1,1]:
                n=np.zeros(3);n[ax]=sign;cube.append([*n,sign*site[ax]-LIMIT])
        H=np.vstack((H,cube))
        local=HalfspaceIntersection(H,np.zeros(3)).intersections
        vertices=local+site
        max_violation=max(max_violation,float(np.max(local@H[:,:3].T+H[:,3])))
        volumes.append(ConvexHull(local).volume)
        for face,(ax,sign) in enumerate((a,s) for a in range(3) for s in [-1,1]):
            v=vertices[np.abs(vertices[:,ax]-sign*LIMIT)<1e-6]
            if len(v)<3:continue
            uv=[j for j in range(3) if j!=ax]
            hull=ConvexHull(v[:,uv]);v=v[hull.vertices];v[:,ax]=sign*LIMIT
            areas[face]+=hull.volume
            caps.append(dict(face=face,node=i,star=int(rows[first[i]]['StarID']),vertices=v.tolist(),area=hull.volume))
    # A clipped VD needs the newly created polygon edges on the cube boundary.
    boundary={}
    for cap in caps:
        poly=np.array(cap['vertices'])
        for a,b in zip(poly,np.roll(poly,-1,axis=0)):
            key=tuple(sorted((tuple(np.round(a,6)),tuple(np.round(b,6)))))
            boundary[key]=np.array([a,b])
    clipped=np.array(clipped+list(boundary.values()))
    np.save(target/'points.npy',p);np.save(target/'delaunay.npy',p[edges]);np.save(target/'voronoi.npy',clipped)
    (target/'caps.json').write_text(json.dumps(caps,separators=(',',':')))
    np.savetxt(target/'points.txt',p,fmt='%.9g')
    np.savetxt(target/'delaunay.txt',p[edges].reshape(-1,6),fmt='%.9g')
    np.savetxt(target/'voronoi.txt',clipped.reshape(-1,6),fmt='%.9g')
    # vtk Delaunay mesh, directly loadable in ParaView.
    tets=np.array(tables['ele'],int)[:,1:5]
    with (target/'delaunay.vtk').open('w') as f:
        f.write('# vtk DataFile Version 3.0\nHYG light years\nASCII\nDATASET UNSTRUCTURED_GRID\n')
        f.write(f'POINTS {len(p)} double\n');np.savetxt(f,p,fmt='%.15g')
        f.write(f'CELLS {len(tets)} {len(tets)*5}\n');np.savetxt(f,np.column_stack((np.full(len(tets),4),tets)),fmt='%d')
        f.write(f'CELL_TYPES {len(tets)}\n');np.savetxt(f,np.full(len(tets),10),fmt='%d')
    schemas={'node':['id INTEGER PRIMARY KEY','x REAL','y REAL','z REAL'],
             'edge':['id INTEGER PRIMARY KEY','n1 INTEGER','n2 INTEGER'],
             'face':['id INTEGER PRIMARY KEY','n1 INTEGER','n2 INTEGER','n3 INTEGER'],
             'ele':['id INTEGER PRIMARY KEY','n1 INTEGER','n2 INTEGER','n3 INTEGER','n4 INTEGER'],
             'neigh':['id INTEGER PRIMARY KEY','t1 INTEGER','t2 INTEGER','t3 INTEGER','t4 INTEGER']}
    for family,exts in [('Delaunay',suffixes[:5]),('Voronoi',suffixes[5:])]:
        dbpath=ROOT/'data'/f'{cls}_{family}.sqlite'
        if dbpath.exists():dbpath.unlink()
        with sqlite3.connect(dbpath) as db:
            for ext in exts:
                name=ext.replace('v.','');rr=tables[ext]
                if ext.startswith('v.') and name in ['face','cell']:
                    columns=['id INTEGER PRIMARY KEY','members TEXT']
                    values=[(int(r[0]),' '.join(r[1:])) for r in rr]
                else:
                    columns=schemas[name] if ext in schemas else schemas['node'] if name=='node' else ['id INTEGER PRIMARY KEY','n1 INTEGER','n2 INTEGER','dx REAL','dy REAL','dz REAL']
                    values=[tuple(float(v) if '.' in v or 'e' in v.lower() else int(v) for v in r) for r in rr]
                add_sql(db,name,columns,values)
                with (target/((('VD_' if family=='Voronoi' else 'DT_')+cls+'_'+name+'.csv'))).open('w',newline='') as f:
                    w=csv.writer(f);w.writerow([c.split()[0] for c in columns]);w.writerows(values)
            if family=='Delaunay':
                add_sql(db,'catalogue',['StarID INTEGER','NodeID INTEGER'],[(int(r['StarID']),int(idx)) for r,idx in zip(rows,inverse)])
            else:
                add_sql(db,'clipped_edges',['id INTEGER PRIMARY KEY','x1 REAL','y1 REAL','z1 REAL','x2 REAL','y2 REAL','z2 REAL'],[(j,*seg.ravel()) for j,seg in enumerate(clipped)])
                add_sql(db,'caps',['id INTEGER PRIMARY KEY','face INTEGER','node INTEGER','StarID INTEGER','area REAL','vertices TEXT'],[(j,c['face'],c['node'],c['star'],c['area'],json.dumps(c['vertices'])) for j,c in enumerate(caps)])
                add_sql(db,'cell_volume',['node INTEGER PRIMARY KEY','volume REAL'],list(enumerate(volumes)))
            assert db.execute('PRAGMA integrity_check').fetchone()[0]=='ok'
    summary=dict(records=len(rows),points=len(p),duplicates=len(rows)-len(p),tetrahedra=len(tets),dt_edges=len(edges),
                 vd_vertices=len(vn),vd_edges=len(tables['v.edge']),rays=rays,clipped_rays=kept_rays,
                 clipped_edges=len(clipped),boundary_edges=len(boundary),caps=len(caps),
                 cap_counts=[sum(c['face']==j for c in caps) for j in range(6)],face_areas=areas.tolist(),
                 volume=sum(volumes),max_halfspace_violation=max_violation,seconds=time.perf_counter()-start)
    assert np.max(np.abs(clipped))<=500+1e-8
    assert abs(summary['volume']-1e9)<10
    assert np.max(np.abs(areas-1e6))<.01
    (target/'summary.json').write_text(json.dumps(summary,indent=2));print(cls,summary,flush=True)
    return summary

def main():
    rows=list(csv.DictReader(gzip.open(ROOT/'data/hygxyz.csv.gz','rt')))
    selected=[r for r in rows if 0<=float(r['Distance'] or 'inf')*SCALE<=500]
    for filename,rr in [('hyg.sqlite',rows),('500ly.sqlite',selected)]:
        path=ROOT/'data'/filename
        if path.exists():path.unlink()
        with sqlite3.connect(path) as db:
            add_sql(db,'hyg',['StarID INTEGER PRIMARY KEY','Distance REAL','Light_Years REAL','Spectrum TEXT','X REAL','Y REAL','Z REAL'],
                    [(int(r['StarID']),float(r['Distance']),float(r['Distance'])*SCALE,r['Spectrum'],*[float(r[k]) for k in ['X','Y','Z']]) for r in rr])
    stats={}
    for cls in CLASSES:
        rr=[r for r in selected if r['Spectrum'][:1].upper()==cls]
        stats[cls]=process(cls,rr)
    (ROOT/'results/summary.json').write_text(json.dumps(dict(source_count=len(rows),selected_count=len(selected),classes=stats),indent=2))
    (ROOT/'data/provenance.json').write_text(json.dumps(dict(author='David Nash / Astronexus',version='HYG v2 hygxyz',license='CC BY-SA 2.5',url='https://github.com/astronexus/HYG-Database/blob/main/hyg/v2/hygxyz.csv.gz',sha256=hashlib.sha256((ROOT/'data/hygxyz.csv.gz').read_bytes()).hexdigest(),scale=SCALE),indent=2))

if __name__=='__main__':main()
