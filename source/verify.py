"""Independent geometric checks of saved mesh outputs, without editing them."""
from pathlib import Path
import json, sqlite3
import numpy as np
from scipy.spatial import cKDTree,ConvexHull,HalfspaceIntersection
ROOT=Path(__file__).resolve().parents[1]
checks={}
for cls in 'OBAFGKM':
    folder=ROOT/'results'/cls
    p=np.load(folder/'points.npy');tree=cKDTree(p)
    t=np.loadtxt(folder/f'{cls}500ly.1.ele',skiprows=1,dtype=int)[:,1:5]
    v=p[t];a=v[:,1:]-v[:,0,None,:];b=(a*a).sum(axis=2)/2
    centers=v[:,0]+np.linalg.solve(a,b[...,None])[...,0]
    radius=np.linalg.norm(centers-v[:,0],axis=1);nearest=tree.query(centers)[0]
    violation=np.max((radius-nearest)/np.maximum(radius,1))
    assert violation<1e-7,(cls,violation)
    tetvolume=np.abs(np.linalg.det(a)).sum()/6
    hullvolume=ConvexHull(p).volume
    assert abs(tetvolume-hullvolume)<max(1,hullvolume)*1e-9
    cap_error=0.;cap_area=np.zeros(6)
    caps=json.loads((folder/'caps.json').read_text())
    for cap in caps:
        q=np.array(cap['vertices']);site=p[cap['node']]
        samples=np.vstack((q,q.mean(axis=0)))
        err=np.max(np.linalg.norm(samples-site,axis=1)-tree.query(samples)[0]);cap_error=max(cap_error,err)
        assert err<1e-6,(cls,err)
        ax=cap['face']//2;sgn=-1 if cap['face']%2==0 else 1
        assert np.max(abs(q[:,ax]-sgn*500))<1e-7
        uv=[j for j in range(3) if j!=ax]
        cap_area[cap['face']]+=ConvexHull(q[:,uv]).volume
    assert np.max(abs(cap_area-1e6))<.01
    segments=np.load(folder/'voronoi.npy');assert np.max(abs(segments))<=500+1e-8
    # Genuine 3D Voronoi edges have at least three equally nearest sites.
    raw_nodes=np.loadtxt(folder/f'{cls}500ly.1.v.node',skiprows=1)[:,1:4]
    raw_edges=np.loadtxt(folder/f'{cls}500ly.1.v.edge',skiprows=1)
    interior_samples=[];rays_checked=0
    for row in raw_edges:
        a,b=map(int,row[1:3]);origin=raw_nodes[a]
        if b==-1:
            direction=row[3:6]
            q=origin+100*direction/np.linalg.norm(direction)
            distances=tree.query(q,k=3)[0]
            assert distances[2]-distances[0]<max(1,distances[0])*1e-8,(cls,'ray orientation',row[0])
            rays_checked+=1
        else:direction=raw_nodes[b]-origin
        lo,hi=0.,float('inf') if b==-1 else 1.
        for x,d in zip(origin,direction):
            if abs(d)<1e-15:
                if abs(x)>500:hi=-1.;break
            else:
                aa,bb=sorted(((-500-x)/d,(500-x)/d));lo=max(lo,aa);hi=min(hi,bb)
        if hi>lo:interior_samples.append(origin+(lo+hi)/2*direction)
    distances=tree.query(np.array(interior_samples),k=3)[0]
    edge_error=float(np.max((distances[:,2]-distances[:,0])/np.maximum(1,distances[:,0])))
    assert edge_error<1e-8,(cls,'Voronoi edge',edge_error)
    for typ in ['Delaunay','Voronoi']:
        with sqlite3.connect(ROOT/'data'/f'{cls}_{typ}.sqlite') as db:assert db.execute('PRAGMA integrity_check').fetchone()[0]=='ok'
    # Rebuild O using ALL competing sites instead of TetGen adjacency.
    if cls=='O':
        volumes=[]
        for i,s in enumerate(p):
            d=np.delete(p,i,axis=0)-s;norm=np.linalg.norm(d,axis=1)
            h=np.column_stack((d/norm[:,None],-norm/2))
            cube=[]
            for ax in range(3):
                for sign in [-1,1]:
                    n=np.zeros(3);n[ax]=sign;cube.append([*n,sign*s[ax]-500])
            vertices=HalfspaceIntersection(np.vstack((h,cube)),np.zeros(3)).intersections
            volumes.append(ConvexHull(vertices).volume)
        assert abs(sum(volumes)-1e9)<.01
    checks[cls]=dict(tetrahedra_checked=len(t),empty_sphere_relative_error=float(violation),
        tetra_volume=float(tetvolume),hull_volume=float(hullvolume),cap_nearest_site_error=float(cap_error),
        face_areas=cap_area.tolist(),max_abs_mesh_coordinate=float(np.max(abs(segments))),
        rays_checked=rays_checked,clipped_voronoi_edges_checked=len(interior_samples),voronoi_edge_relative_error=edge_error)
print(json.dumps(checks,indent=2))
(ROOT/'results/verification.json').write_text(json.dumps(checks,indent=2))
