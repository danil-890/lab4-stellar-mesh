// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.ThorFX.pas' rev: 37.00 (Windows)

#ifndef GLS_ThorFXHPP
#define GLS_ThorFXHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.OpenGL.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <System.Math.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.XCollection.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorLists.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Color.hpp>
#include <Stage.BaseClasses.hpp>
#include <Stage.Coordinates.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.Manager.hpp>
#include <Stage.TextureFormat.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Cadencer.hpp>
#include <GLS.Context.hpp>
#include <GLS.State.hpp>
#include <GLS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Thorfx
{
//-- forward type declarations -----------------------------------------------
struct TThorpoint;
class DELPHICLASS TGLThorFXManager;
class DELPHICLASS TGLBThorFX;
//-- type declarations -------------------------------------------------------
typedef TThorpoint *PThorpoint;

struct DECLSPEC_DRECORD TThorpoint
{
public:
	Stage::Vectortypes::TGSVector Position;
	float Size;
};


typedef System::StaticArray<TThorpoint, 33554432> TThorpointArray;

typedef TThorpointArray *PThorpointArray;

typedef void __fastcall (__closure *TCalcPointEvent)(System::TObject* Sender, int PointNo, float &x, float &y, float &z);

class PASCALIMPLEMENTATION TGLThorFXManager : public Stage::Baseclasses::TGSCadenceAbleComponent
{
	typedef Stage::Baseclasses::TGSCadenceAbleComponent inherited;
	
private:
	System::Classes::TList* FClients;
	PThorpointArray FThorpoints;
	Stage::Coordinates::TGSCoordinates* FTarget;
	Gls::Cadencer::TGLCadencer* FCadencer;
	int FMaxpoints;
	float FGlowSize;
	float FVibrate;
	float FWildness;
	int NP;
	Stage::Color::TGSColor* FInnerColor;
	Stage::Color::TGSColor* FOuterColor;
	Stage::Color::TGSColor* FCoreColor;
	bool FDisabled;
	bool FCore;
	bool FGlow;
	TCalcPointEvent FOnCalcPoint;
	
protected:
	void __fastcall RegisterClient(TGLBThorFX* aClient);
	void __fastcall DeRegisterClient(TGLBThorFX* aClient);
	void __fastcall DeRegisterAllClients();
	void __fastcall SetTarget(Stage::Coordinates::TGSCoordinates* const val);
	void __fastcall SetCadencer(Gls::Cadencer::TGLCadencer* const val);
	void __fastcall SetMaxpoints(const int val);
	bool __fastcall StoreGlowSize();
	bool __fastcall StoreVibrate();
	void __fastcall SetInnerColor(Stage::Color::TGSColor* const val);
	void __fastcall SetOuterColor(Stage::Color::TGSColor* const val);
	void __fastcall SetCoreColor(Stage::Color::TGSColor* const val);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall ThorInit();
	void __fastcall CalcThor();
	void __fastcall CalcFrac(int left, int right, float lh, float rh, int xyz);
	
public:
	__fastcall virtual TGLThorFXManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLThorFXManager();
	virtual void __fastcall DoProgress(const Stage::Baseclasses::TGSProgressTimes &progressTime);
	
__published:
	__property Stage::Coordinates::TGSCoordinates* Target = {read=FTarget, write=SetTarget};
	__property Gls::Cadencer::TGLCadencer* Cadencer = {read=FCadencer, write=SetCadencer};
	__property int Maxpoints = {read=FMaxpoints, write=SetMaxpoints, default=256};
	__property float GlowSize = {read=FGlowSize, write=FGlowSize, stored=StoreGlowSize};
	__property float Vibrate = {read=FVibrate, write=FVibrate, stored=StoreVibrate};
	__property Stage::Color::TGSColor* InnerColor = {read=FInnerColor, write=SetInnerColor};
	__property Stage::Color::TGSColor* OuterColor = {read=FOuterColor, write=SetOuterColor};
	__property Stage::Color::TGSColor* CoreColor = {read=FCoreColor, write=SetCoreColor};
	__property bool Disabled = {read=FDisabled, write=FDisabled, nodefault};
	__property bool Core = {read=FCore, write=FCore, nodefault};
	__property bool Glow = {read=FGlow, write=FGlow, nodefault};
	__property float Wildness = {read=FWildness, write=FWildness};
	__property TCalcPointEvent OnCalcPoint = {read=FOnCalcPoint, write=FOnCalcPoint};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLBThorFX : public Gls::Scene::TGLObjectPostEffect
{
	typedef Gls::Scene::TGLObjectPostEffect inherited;
	
private:
	TGLThorFXManager* FManager;
	System::UnicodeString FManagerName;
	Stage::Coordinates::TGSCoordinates* FTarget;
	
protected:
	void __fastcall SetManager(TGLThorFXManager* const val);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	void __fastcall SetTarget(Stage::Coordinates::TGSCoordinates* const val);
	
public:
	__fastcall virtual TGLBThorFX(Stage::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLBThorFX();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	virtual void __fastcall Render(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
__published:
	__property TGLThorFXManager* Manager = {read=FManager, write=SetManager};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TGLBThorFX* __fastcall GetOrCreateThorFX(Gls::Scene::TGLBaseSceneObject* obj, const System::UnicodeString name = System::UnicodeString());
}	/* namespace Thorfx */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_THORFX)
using namespace Gls::Thorfx;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ThorFXHPP
