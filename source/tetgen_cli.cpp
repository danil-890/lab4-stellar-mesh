#define TETLIBRARY
#include "tetgen.h"
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <string>
std::ofstream file(const std::string& p, const char* ext) {
  std::ofstream f(p + ext); f << std::setprecision(17); return f;
}
int main(int argc, char **argv) {
  if (argc != 2) { std::fprintf(stderr,"Usage: tetgen_cli input.node\n"); return 2; }
  std::ifstream f(argv[1]); int dim,attrs,markers,id;
  tetgenio input, out; input.firstnumber=0;
  if (!(f >> input.numberofpoints >> dim >> attrs >> markers) || dim!=3 || attrs || markers) return 3;
  input.pointlist=new REAL[input.numberofpoints*3];
  for(int i=0;i<input.numberofpoints;++i) {
    if(!(f>>id>>input.pointlist[i*3]>>input.pointlist[i*3+1]>>input.pointlist[i*3+2]) || id!=i) return 4;
  }
  char switches[]="zvfenQ";
  try { tetrahedralize(switches, &input, &out); }
  catch (int code) { return code ? code : 1; }
  {
  std::string p(argv[1]); p=p.substr(0,p.size()-5)+".1";
  auto n=file(p,".node"); n<<out.numberofpoints<<" 3 0 0\n";
  for(int i=0;i<out.numberofpoints;++i)n<<i<<' '<<out.pointlist[3*i]<<' '<<out.pointlist[3*i+1]<<' '<<out.pointlist[3*i+2]<<'\n';
  auto e=file(p,".edge");e<<out.numberofedges<<" 0\n";
  for(int i=0;i<out.numberofedges;++i)e<<i<<' '<<out.edgelist[2*i]<<' '<<out.edgelist[2*i+1]<<'\n';
  auto t=file(p,".ele"); t<<out.numberoftetrahedra<<" 4 0\n";
  auto ng=file(p,".neigh");ng<<out.numberoftetrahedra<<" 4\n";
  for(int i=0;i<out.numberoftetrahedra;++i){t<<i;ng<<i;for(int j=0;j<4;++j){t<<' '<<out.tetrahedronlist[4*i+j];ng<<' '<<out.neighborlist[4*i+j];} t<<'\n';ng<<'\n';}
  auto fc=file(p,".face");fc<<out.numberoftrifaces<<" 0\n";
  for(int i=0;i<out.numberoftrifaces;++i)fc<<i<<' '<<out.trifacelist[3*i]<<' '<<out.trifacelist[3*i+1]<<' '<<out.trifacelist[3*i+2]<<'\n';
  auto vn=file(p,".v.node");vn<<out.numberofvpoints<<" 3 0 0\n";
  for(int i=0;i<out.numberofvpoints;++i)vn<<i<<' '<<out.vpointlist[3*i]<<' '<<out.vpointlist[3*i+1]<<' '<<out.vpointlist[3*i+2]<<'\n';
  auto ve=file(p,".v.edge");ve<<out.numberofvedges<<'\n';
  // This legacy DLL returns inward normals for hull rays. Export the outward
  // convention q(t)=vpoint[v1]+t*direction, t>=0, used by .v.edge readers.
  for(int i=0;i<out.numberofvedges;++i){auto a=out.vedgelist[i];ve<<i<<' '<<a.v1<<' '<<a.v2;for(int j=0;j<3;++j)ve<<' '<<(a.v2==-1 ? -a.vnormal[j] : a.vnormal[j]);ve<<'\n';}
  auto vf=file(p,".v.face");vf<<out.numberofvfacets<<'\n';
  for(int i=0;i<out.numberofvfacets;++i){auto a=out.vfacetlist[i];vf<<i<<' '<<a.c1<<' '<<a.c2;for(int j=0;j<=a.elist[0];++j)vf<<' '<<a.elist[j];vf<<'\n';}
  auto vc=file(p,".v.cell");vc<<out.numberofvcells<<'\n';
  for(int i=0;i<out.numberofvcells;++i){vc<<i;for(int j=0;j<=out.vcelllist[i][0];++j)vc<<' '<<out.vcelllist[i][j];vc<<'\n';}
  std::printf("TetGen DLL: %d points, %d tetrahedra, %d DT edges, %d VD vertices, %d VD edges\n",out.numberofpoints,out.numberoftetrahedra,out.numberofedges,out.numberofvpoints,out.numberofvedges);
  }
  // The legacy DLL and the modern compiler have separate C++ heaps.
  // Flush/close our streams, then let the OS reclaim the DLL's allocations.
  // Do not execute inline tetgenio destructors across that ABI boundary.
  std::fflush(NULL);
  std::_Exit(0);
}
