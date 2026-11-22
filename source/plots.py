from pathlib import Path
import json
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon
from matplotlib.collections import PatchCollection

ROOT=Path(__file__).resolve().parents[1]
plt.rcParams.update({'font.family':'DejaVu Sans','font.size':11,'svg.fonttype':'none'})
for cls in 'OBAFGKM':
    caps=json.loads((ROOT/f'results/{cls}/caps.json').read_text())
    fig,axes=plt.subplots(2,3,figsize=(12,8.2),layout='constrained')
    for face,ax in enumerate(axes.flat):
        axis=face//2;sign=-1 if face%2==0 else 1;uv=[j for j in range(3) if j!=axis]
        selected=[c for c in caps if c['face']==face]
        patches=[Polygon(np.array(c['vertices'])[:,uv]) for c in selected]
        colors=[plt.get_cmap('tab20')((c['star']*13%20)/19) for c in selected]
        ax.add_collection(PatchCollection(patches,facecolors=colors,edgecolors='#26384b',linewidths=.55))
        ax.set(xlim=(-500,500),ylim=(-500,500),aspect='equal',xticks=[-500,0,500],yticks=[-500,0,500],
               xlabel='XYZ'[uv[0]]+', св. лет',ylabel='XYZ'[uv[1]]+', св. лет',
               title=f"{'XYZ'[axis]} = {sign*500:+d} · {len(selected)} ячеек")
        if cls=='O':
            for c in selected:
                v=np.array(c['vertices'])[:,uv];cent=v.mean(axis=0)
                ax.text(*cent,str(c['star']),ha='center',va='center',fontsize=7,
                        bbox=dict(facecolor='white',alpha=.75,edgecolor='none',pad=.5))
    fig.suptitle(f'Класс {cls} · пересечение 3D ячеек Вороного с шестью гранями куба',fontsize=15)
    fig.savefig(ROOT/f'results/{cls}/sections.png',dpi=160)
    fig.savefig(ROOT/f'results/{cls}/sections.svg')
    if cls in 'OB':fig.savefig(ROOT/f'images/sections-{cls}-plot.pdf')
    plt.close(fig)
    # Preserve a polygonal export of the six cap mosaics.
    vv=[v for c in caps for v in c['vertices']]
    with (ROOT/f'results/{cls}/caps.vtk').open('w') as f:
        f.write('# vtk DataFile Version 3.0\nCube face mosaics, light years\nASCII\nDATASET POLYDATA\n')
        f.write(f'POINTS {len(vv)} double\n');np.savetxt(f,vv,fmt='%.15g')
        f.write(f'POLYGONS {len(caps)} {len(vv)+len(caps)}\n');offset=0
        for c in caps:
            n=len(c['vertices']);f.write(str(n)+' '+' '.join(map(str,range(offset,offset+n)))+'\n');offset+=n
        f.write(f'CELL_DATA {len(caps)}\nSCALARS StarID int 1\nLOOKUP_TABLE default\n')
        for c in caps:f.write(str(c['star'])+'\n')
print('Rendered six cube-face sections for all seven classes.')
