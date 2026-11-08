#include <vcl.h>
#pragma hdrstop
#include "MainForm.h"
#include "SQLite.h"
#include <System.SysUtils.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <memory>
#include <cstdio>
#pragma package(smart_init)
#pragma link "GLS.Scene"
#pragma link "GLS.Objects"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.SpaceText"
#pragma link "GLS.SimpleNavigation"
TMainForm* MainForm;
namespace {
const wchar_t* CLASSES=L"OBAFGKM";
const float COLORS[7][3]={{.15f,.8f,1},{.65f,.85f,1},{1,1,1},{1,1,.67f},{1,.85f,.2f},{1,.5f,.08f},{1,.2f,.12f}};
TLabel* label(TComponent* o,TWinControl* p,int y,const UnicodeString& text,int h=26){auto l=new TLabel(o);l->Parent=p;l->SetBounds(16,y,305,h);l->AutoSize=false;l->WordWrap=true;l->Caption=text;return l;}
TButton* button(TComponent* o,TWinControl* p,int y,const UnicodeString& text,TNotifyEvent event){auto b=new TButton(o);b->Parent=p;b->SetBounds(16,y,305,35);b->Caption=text;b->OnClick=event;return b;}
TGLLines* wire(TGLBaseSceneObject* p,float r,float g,float b){auto l=static_cast<TGLLines*>(p->AddNewChild(__classid(TGLLines)));l->NodesAspect=lnaInvisible;l->SplineMode=lsmSegments;l->LineColor->SetColor(r,g,b,1);return l;}
std::string utf8(const UnicodeString& s){return UTF8String(s).c_str();}
UnicodeString wide(const std::string& s){return UTF8ToString(UTF8String(s.c_str()));}
void text(TGLBaseSceneObject* p,const UnicodeString& s,float x,float y,float z){auto t=static_cast<TGLSpaceText*>(p->AddNewChild(__classid(TGLSpaceText)));t->Text=s;t->TextHeight=35;t->Font->Name=L"Arial";t->Position->SetPoint(x,y,z);t->Material->FrontProperties->Emission->SetColor(.9,.9,1,1);}
}
__fastcall TMainForm::TMainForm(TComponent* owner):TForm(owner,0){
 Caption=L"Лабораторная №4 · HYG / TetGen / GLScene";Position=poScreenCenter;ClientWidth=1320;ClientHeight=820;Font->Name=L"Segoe UI";Font->Size=11;
 auto p=new TPanel(this);p->Parent=this;p->Align=alRight;p->Width=338;p->BevelOuter=bvNone;
 label(this,p,16,L"Звёзды окрестности Солнца",35)->Font->Style=TFontStyles()<<fsBold;
 label(this,p,52,L"Куб: [−500; +500] св. лет\nHYG v2 · радиус отбора 500 св. лет",55);
 startButton_=button(this,p,116,L"Start — загрузить 14 баз",begin);
 label(this,p,164,L"Модель");mode_=new TComboBox(this);mode_->Parent=p;mode_->SetBounds(16,194,305,30);mode_->Style=csDropDownList;
 mode_->Items->Add(L"Звёзды — точки");mode_->Items->Add(L"Тетраэдрализация Делоне");mode_->Items->Add(L"Вороного — обрезка кубом");mode_->ItemIndex=0;mode_->Enabled=false;mode_->OnChange=changed;
 label(this,p,237,L"Спектральные классы");
 for(int i=0;i<7;++i){auto c=new TCheckBox(this);c->Parent=p;c->SetBounds(20+(i%4)*76,272+(i/4)*31,72,27);c->Caption=UnicodeString(CLASSES[i]);c->Checked=i==2;c->Enabled=false;c->OnClick=changed;checks_[i]=c;}
 info_=label(this,p,344,L"Нажмите Start для загрузки данных.",158);
 dataButton_=button(this,p,518,L"Data — таблицы SQLite",data);dataButton_->Enabled=false;
 sectionButton_=button(this,p,563,L"Шесть сечений на гранях",sections);sectionButton_->Enabled=false;
 button(this,p,608,L"Сохранить снимок",save);
 label(this,p,670,L"Мышь — вращение\nКолесо — масштаб\nСолнце — начало координат\nЦвет рёбер соответствует классу",110);
 viewer_=new TGLSceneViewer(this);viewer_->Parent=this;viewer_->Align=alClient;viewer_->Buffer->BackgroundColor=static_cast<TColor>(0x00241B13);viewer_->Buffer->Lighting=false;
 scene_=new TGLScene(this);scene_->ObjectsSorting=osNone;root_=static_cast<TGLDummyCube*>(scene_->Objects->AddNewChild(__classid(TGLDummyCube)));
 auto cube=wire(root_,.38,.46,.58);cube->LineWidth=1.5;
 for(int ax=0;ax<3;++ax)for(int s=-1;s<=1;s+=2)for(int t=-1;t<=1;t+=2){float a[3]={0,0,0},b[3]={0,0,0};a[ax]=-500;b[ax]=500;a[(ax+1)%3]=b[(ax+1)%3]=s*500;a[(ax+2)%3]=b[(ax+2)%3]=t*500;cube->AddNode(a[0],a[1],a[2]);cube->AddNode(b[0],b[1],b[2]);}
 text(root_,L"X +500",520,-500,-500);text(root_,L"Y +500",-500,520,-500);text(root_,L"Z +500",-500,-500,520);
 for(int i=0;i<7;++i){points_[i]=static_cast<TGLPoints*>(root_->AddNewChild(__classid(TGLPoints)));points_[i]->Size=3;lines_[i]=wire(root_,COLORS[i][0],COLORS[i][1],COLORS[i][2]);}
 camera_=static_cast<TGLCamera*>(scene_->Objects->AddNewChild(__classid(TGLCamera)));camera_->TargetObject=root_;camera_->Position->SetPoint(1250,920,1320);camera_->FocalLength=75;camera_->DepthOfView=15000;viewer_->Camera=camera_;
 nav_=new TGLSimpleNavigation(this);nav_->Form=this;nav_->GLSceneViewer=viewer_;nav_->FormCaption=Caption;nav_->ZoomSpeed=1.12;
}
void TMainForm::start(){
 folder_=IncludeTrailingPathDelimiter(ExpandFileName(ExtractFilePath(Application->ExeName)+L"..\\"));
 if(!FileExists(folder_+L"data\\O_Delaunay.sqlite"))throw Exception(L"Папка data должна находиться рядом с bin.");
 RecreateWnd();Show();Application->ProcessMessages();
 if(ParamStr(1)==L"--capture"){
   Show();Application->ProcessMessages();load();capture(L"points-A");
   for(int i=0;i<7;++i)checks_[i]->Checked=i==0;mode_->ItemIndex=1;update();capture(L"delaunay-O");
   mode_->ItemIndex=2;update();capture(L"voronoi-O");sections(nullptr);captureForm(sectionForm_,L"sections-O");sectionForm_->Hide();
   for(int i=0;i<7;++i)checks_[i]->Checked=i==1;mode_->ItemIndex=1;update();capture(L"delaunay-B");mode_->ItemIndex=2;update();capture(L"voronoi-B");
   data(nullptr);dbChoice_->ItemIndex=0;selectDB(nullptr);tableChoice_->ItemIndex=2;selectTable(nullptr);captureForm(dataForm_,L"data-O");dataForm_->Hide();
   for(auto c:checks_)c->OnClick=nullptr;
   for(int i=0;i<7;++i){
     for(int j=0;j<7;++j)checks_[j]->Checked=j==i;
     for(int m=0;m<3;++m){mode_->ItemIndex=m;update();capture(L"check-"+UnicodeString(CLASSES[i])+L"-"+IntToStr(m));}
   }
   for(int j=0;j<7;++j)checks_[j]->Checked=j==3||j==6;mode_->ItemIndex=0;update();capture(L"points-FM");
   for(auto c:checks_)c->OnClick=changed;
   for(int i=0;i<7;++i)checks_[i]->Checked=i==0;mode_->ItemIndex=2;update();
 }
}
void TMainForm::load(){
 for(int i=0;i<7;++i)for(auto kind:{L"Delaunay",L"Voronoi"})if(!FileExists(folder_+L"data\\"+UnicodeString(CLASSES[i])+L"_"+kind+L".sqlite"))throw Exception(L"Отсутствует одна из 14 баз SQLite");
 for(int i=0;i<7;++i){
  SQLite dt(utf8(folder_+L"data\\"+UnicodeString(CLASSES[i])+L"_Delaunay.sqlite"));
  dt.query("SELECT x,y,z FROM node ORDER BY id");while(dt.next())models_[i].points.push_back({float(dt.number(dt.stmt,0)),float(dt.number(dt.stmt,1)),float(dt.number(dt.stmt,2))});
  dt.query("SELECT a.x,a.y,a.z,b.x,b.y,b.z FROM edge e JOIN node a ON a.id=e.n1 JOIN node b ON b.id=e.n2 ORDER BY e.id");
  while(dt.next()){std::array<float,6>a;for(int j=0;j<6;++j)a[j]=dt.number(dt.stmt,j);models_[i].dt.push_back(a);}
  SQLite vd(utf8(folder_+L"data\\"+UnicodeString(CLASSES[i])+L"_Voronoi.sqlite"));vd.query("SELECT x1,y1,z1,x2,y2,z2 FROM clipped_edges ORDER BY id");
  while(vd.next()){std::array<float,6>a;for(int j=0;j<6;++j)a[j]=vd.number(vd.stmt,j);models_[i].vd.push_back(a);}
 }
 loaded_=true;startButton_->Enabled=false;mode_->Enabled=true;dataButton_->Enabled=true;sectionButton_->Enabled=true;for(auto c:checks_)c->Enabled=true;update();
}
void TMainForm::update(){
 if(!loaded_)return;scene_->BeginUpdate();int stars=0,edges=0;
 for(int i=0;i<7;++i){auto pts=points_[i];auto ln=lines_[i];pts->Positions->Clear();pts->Colors->Clear();ln->Nodes->Clear();bool active=checks_[i]->Checked;pts->Visible=active;ln->Visible=active&&mode_->ItemIndex!=0;if(!active)continue;
  for(auto a:models_[i].points){pts->Positions->Add(a[0],a[1],a[2]);pts->Colors->Add(COLORS[i][0],COLORS[i][1],COLORS[i][2],1.f);++stars;}
  if(mode_->ItemIndex){auto& ee=mode_->ItemIndex==1?models_[i].dt:models_[i].vd;for(auto a:ee){ln->AddNode(a[0],a[1],a[2]);ln->AddNode(a[3],a[4],a[5]);++edges;}}
 }
 info_->Caption=L"Звёзд на сцене: "+IntToStr(stars)+L"\nРёбер на сцене: "+IntToStr(edges)+L"\n\nX, Y, Z — световые годы\nВсе вершины в пределах куба\nВороного: границы ячеек замкнуты\nна шести гранях куба";
 scene_->EndUpdate();viewer_->Invalidate();
}
void __fastcall TMainForm::begin(TObject*){if(!loaded_)load();}
void __fastcall TMainForm::changed(TObject*){update();}
void TMainForm::captureForm(TForm* f,const UnicodeString& name){f->BringToFront();f->Repaint();Application->ProcessMessages();std::unique_ptr<TBitmap> b(new TBitmap);b->SetSize(f->ClientWidth,f->ClientHeight);HDC dc=GetDC(f->Handle);BitBlt(b->Canvas->Handle,0,0,b->Width,b->Height,dc,0,0,SRCCOPY);ReleaseDC(f->Handle,dc);std::unique_ptr<TPngImage> png(new TPngImage);png->Assign(b.get());png->SaveToFile(folder_+L"images\\"+name+L".png");}
void TMainForm::capture(const UnicodeString& name){viewer_->Buffer->Render();captureForm(this,name);}
void __fastcall TMainForm::save(TObject*){capture(L"scene-"+FormatDateTime(L"yyyymmdd-hhnnss",Now()));}
void __fastcall TMainForm::data(TObject*){
 if(!dataForm_){dataForm_=new TForm(this,0);dataForm_->Caption=L"Data · 14 баз SQLite · исходные и ограниченные сетки";dataForm_->Position=poScreenCenter;dataForm_->ClientWidth=1150;dataForm_->ClientHeight=620;dataForm_->Font->Name=L"Segoe UI";dataForm_->Font->Size=11;
  auto top=new TPanel(dataForm_);top->Parent=dataForm_;top->Align=alTop;top->Height=82;
  dbChoice_=new TComboBox(dataForm_);dbChoice_->Parent=top;dbChoice_->SetBounds(12,12,260,30);dbChoice_->Style=csDropDownList;
  for(int i=0;i<7;++i)for(auto k:{L"Delaunay",L"Voronoi"})dbChoice_->Items->Add(UnicodeString(CLASSES[i])+L"_"+k);dbChoice_->ItemIndex=0;dbChoice_->OnChange=selectDB;
  tableChoice_=new TComboBox(dataForm_);tableChoice_->Parent=top;tableChoice_->SetBounds(286,12,230,30);tableChoice_->Style=csDropDownList;tableChoice_->OnChange=selectTable;
  auto prev=button(dataForm_,top,10,L"Назад",prevPage);prev->SetBounds(530,12,100,30);auto next=button(dataForm_,top,10,L"Далее",nextPage);next->SetBounds(640,12,100,30);
  rows_=label(dataForm_,top,49,L"",26);rows_->Width=1100;
  grid_=new TStringGrid(dataForm_);grid_->Parent=dataForm_;grid_->Align=alClient;grid_->FixedCols=0;grid_->DefaultColWidth=160;grid_->DefaultRowHeight=27;grid_->Options=grid_->Options<<goColSizing<<goRowSelect;
  selectDB(nullptr);
 }dataForm_->Show();dataForm_->BringToFront();
}
void __fastcall TMainForm::selectDB(TObject*){offset_=0;SQLite db(utf8(folder_+L"data\\"+dbChoice_->Text+L".sqlite"));db.query("SELECT name FROM sqlite_master WHERE type='table' ORDER BY name");tableChoice_->Items->Clear();while(db.next())tableChoice_->Items->Add(wide(db.value(0)));tableChoice_->ItemIndex=0;selectTable(nullptr);}
void __fastcall TMainForm::selectTable(TObject* sender){if(sender!=nullptr||offset_<0)offset_=0;SQLite db(utf8(folder_+L"data\\"+dbChoice_->Text+L".sqlite"));std::string table=utf8(tableChoice_->Text);db.query("SELECT COUNT(*) FROM \""+table+"\"");db.next();int total=db.number(db.stmt,0);if(offset_>=total)offset_=0;
 db.query("SELECT * FROM \""+table+"\" LIMIT 500 OFFSET "+std::to_string(offset_));int cols=db.columns(db.stmt);grid_->ColCount=cols;grid_->RowCount=502;for(int j=0;j<cols;++j)grid_->Cells[j][0]=wide(db.name(db.stmt,j));int i=1;while(db.next()){for(int j=0;j<cols;++j)grid_->Cells[j][i]=wide(db.value(j));++i;}grid_->RowCount=i>1?i:2;rows_->Caption=L"Записей в таблице: "+IntToStr(total)+L" · показаны строки "+IntToStr(offset_+1)+L"–"+IntToStr(offset_+i-1)+L" · координаты сеток в св. годах";
}
void __fastcall TMainForm::nextPage(TObject*){offset_+=500;selectTable(nullptr);}
void __fastcall TMainForm::prevPage(TObject*){offset_-=500;selectTable(nullptr);}
void __fastcall TMainForm::sections(TObject*){
 if(!sectionForm_){sectionForm_=new TForm(this,0);sectionForm_->Caption=L"Шесть сечений мозаики Вороного по граням куба";sectionForm_->Position=poScreenCenter;sectionForm_->ClientWidth=1150;sectionForm_->ClientHeight=780;
 auto p=new TPanel(sectionForm_);p->Parent=sectionForm_;p->Align=alTop;p->Height=40;sectionChoice_=new TComboBox(sectionForm_);sectionChoice_->Parent=p;sectionChoice_->SetBounds(16,7,230,28);sectionChoice_->Style=csDropDownList;for(int i=0;i<7;++i)sectionChoice_->Items->Add(L"Класс "+UnicodeString(CLASSES[i]));sectionChoice_->ItemIndex=0;sectionChoice_->OnChange=selectSection;
 sectionImage_=new TImage(sectionForm_);sectionImage_->Parent=sectionForm_;sectionImage_->Align=alClient;sectionImage_->Proportional=true;sectionImage_->Stretch=true;sectionImage_->Center=true;
 }selectSection(nullptr);sectionForm_->Show();sectionForm_->BringToFront();
}
void __fastcall TMainForm::selectSection(TObject*){sectionImage_->Picture->LoadFromFile(folder_+L"results\\"+UnicodeString(CLASSES[sectionChoice_->ItemIndex])+L"\\sections.png");}
