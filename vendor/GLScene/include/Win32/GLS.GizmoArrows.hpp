// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.GizmoArrows.pas' rev: 37.00 (Windows)

#ifndef GLS_GizmoArrowsHPP
#define GLS_GizmoArrowsHPP

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
#include <Winapi.OpenGLext.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorLists.hpp>
#include <Stage.Color.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Context.hpp>
#include <GLS.Objects.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <GLS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Gizmoarrows
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLGizmoArrow;
class DELPHICLASS TGLGizmoCorner;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGizmoArrowType : unsigned char { gtAxisX, gtAxisY, gtAxisZ };

enum DECLSPEC_DENUM TGizmoCornerType : unsigned char { gtPlaneXY, gtPlaneXZ, gtPlaneYZ };

class PASCALIMPLEMENTATION TGLGizmoArrow : public Gls::Objects::TGLQuadricObject
{
	typedef Gls::Objects::TGLQuadricObject inherited;
	
private:
	TGizmoArrowType FGizmoType;
	float FBottomRadius;
	float FHeight;
	float FArrowHeadHeight;
	bool FSelected;
	Stage::Color::TGSColor* FSelectedColor;
	void __fastcall SetGizmoType(const TGizmoArrowType Value);
	void __fastcall SetBottomRadius(const float Value);
	void __fastcall SetHeight(const float Value);
	void __fastcall SetArrowHeadHeight(const float Value);
	void __fastcall SetSelected(const bool Value);
	void __fastcall SetSelectedColor(Stage::Color::TGSColor* const Value);
	
public:
	__fastcall virtual TGLGizmoArrow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLGizmoArrow();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
__published:
	__property TGizmoArrowType GizmoType = {read=FGizmoType, write=SetGizmoType, nodefault};
	__property float BottomRadius = {read=FBottomRadius, write=SetBottomRadius};
	__property float Height = {read=FHeight, write=SetHeight};
	__property float ArrowHeadHeight = {read=FArrowHeadHeight, write=SetArrowHeadHeight};
	__property bool Selected = {read=FSelected, write=SetSelected, nodefault};
	__property Stage::Color::TGSColor* SelectedColor = {read=FSelectedColor, write=SetSelectedColor};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLGizmoArrow(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Objects::TGLQuadricObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLGizmoCorner : public Gls::Objects::TGLQuadricObject
{
	typedef Gls::Objects::TGLQuadricObject inherited;
	
private:
	TGizmoCornerType FGizmoType;
	float FHeight;
	float FDistance;
	bool FSelected;
	Stage::Color::TGSColor* FSelectedColor;
	void __fastcall SetGizmoType(const TGizmoCornerType Value);
	void __fastcall SetHeight(const float Value);
	void __fastcall SetDistance(const float Value);
	void __fastcall SetSelected(const bool Value);
	void __fastcall SetSelectedColor(Stage::Color::TGSColor* const Value);
	
public:
	__fastcall virtual TGLGizmoCorner(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLGizmoCorner();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
__published:
	__property TGizmoCornerType GizmoType = {read=FGizmoType, write=SetGizmoType, nodefault};
	__property float Height = {read=FHeight, write=SetHeight};
	__property float Distance = {read=FDistance, write=SetDistance};
	__property bool Selected = {read=FSelected, write=SetSelected, nodefault};
	__property Stage::Color::TGSColor* SelectedColor = {read=FSelectedColor, write=SetSelectedColor};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLGizmoCorner(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Objects::TGLQuadricObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Gizmoarrows */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_GIZMOARROWS)
using namespace Gls::Gizmoarrows;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_GizmoArrowsHPP
