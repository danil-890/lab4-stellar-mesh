#pragma once
#include <System.Classes.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "GLS.Scene.hpp"
#include "GLS.Objects.hpp"
#include "GLS.SceneViewer.hpp"
#include "GLS.SpaceText.hpp"
#ifdef SetForm
#undef SetForm
#endif
#include "GLS.SimpleNavigation.hpp"
#include <vector>
#include <array>
struct Model {std::vector<std::array<float,3>> points;std::vector<std::array<float,6>> dt,vd;};
class TMainForm:public TForm {
public:
 __fastcall TMainForm(TComponent* owner);void start();
private:
 UnicodeString folder_;bool loaded_=false;Model models_[7];
 TGLScene* scene_;TGLSceneViewer* viewer_;TGLCamera* camera_;TGLDummyCube* root_;
 TGLPoints* points_[7];TGLLines* lines_[7];TGLSimpleNavigation* nav_;
 TComboBox* mode_;TCheckBox* checks_[7];TLabel* info_;TButton* startButton_;TButton* dataButton_;TButton* sectionButton_;
 TComboBox* dbChoice_;TComboBox* tableChoice_;TStringGrid* grid_;TLabel* rows_;int offset_=0;TForm* dataForm_=nullptr;
 TComboBox* sectionChoice_;TImage* sectionImage_;TForm* sectionForm_=nullptr;
 void load();void update();void capture(const UnicodeString&);void captureForm(TForm*,const UnicodeString&);
 void __fastcall begin(TObject*);void __fastcall changed(TObject*);void __fastcall data(TObject*);void __fastcall sections(TObject*);
 void __fastcall selectDB(TObject*);void __fastcall selectTable(TObject*);void __fastcall nextPage(TObject*);void __fastcall prevPage(TObject*);
 void __fastcall selectSection(TObject*);void __fastcall save(TObject*);
};
extern PACKAGE TMainForm* MainForm;
