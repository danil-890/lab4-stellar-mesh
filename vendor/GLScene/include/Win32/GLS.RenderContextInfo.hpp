// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.RenderContextInfo.pas' rev: 37.00 (Windows)

#ifndef GLS_RenderContextInfoHPP
#define GLS_RenderContextInfoHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Stage.PersistentClasses.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.Color.hpp>
#include <GLS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Rendercontextinfo
{
//-- forward type declarations -----------------------------------------------
struct TGLSize;
struct TGLRenderContextClippingInfo;
struct TGLRenderContextInfo;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLDrawState : unsigned char { dsRendering, dsPicking, dsPrinting };

struct DECLSPEC_DRECORD TGLSize
{
public:
	System::LongInt cx;
	System::LongInt cy;
};


enum DECLSPEC_DENUM TGLObjectsSorting : unsigned char { osInherited, osNone, osRenderFarthestFirst, osRenderBlendedLast, osRenderNearestFirst };

enum DECLSPEC_DENUM TGLVisibilityCulling : unsigned char { vcInherited, vcNone, vcObjectBased, vcHierarchical };

struct DECLSPEC_DRECORD TGLRenderContextClippingInfo
{
public:
	Stage::Vectortypes::TGSVector Origin;
	Stage::Vectortypes::TGSVector ClippingDirection;
	float ViewPortRadius;
	float NearClippingDistance;
	float FarClippingDistance;
	Stage::Vectorgeometry::TFrustum Frustum;
};


struct DECLSPEC_DRECORD TGLRenderContextInfo
{
public:
	System::TObject* Scene;
	System::TObject* Buffer;
	Stage::Vectortypes::TGSVector CameraPosition;
	Stage::Vectortypes::TGSVector CameraDirection;
	Stage::Vectortypes::TGSVector CameraUp;
	TGLSize ViewPortSize;
	int RenderDPI;
	System::TObject* MaterialLibrary;
	System::TObject* LightMapLibrary;
	int FogDisabledCounter;
	TGLDrawState DrawState;
	TGLObjectsSorting ObjectsSorting;
	TGLVisibilityCulling VisibilityCulling;
	Gls::State::TGLStateCache* GLStates;
	Stage::Pipelinetransform::TgTransformation* PipelineTransformation;
	TGLRenderContextClippingInfo Rcci;
	Stage::Color::TGSColorVector SceneAmbientColor;
	bool BufferFaceCull;
	bool BufferLighting;
	bool BufferFog;
	bool BufferDepthTest;
	bool ProxySubObject;
	bool IgnoreMaterials;
	bool IgnoreBlendingRequests;
	bool IgnoreDepthRequests;
	bool Amalgamating;
	Stage::Persistentclasses::TGSPersistentObjectList* Lights;
	Stage::Persistentclasses::TGSPersistentObjectList* AfterRenderEffects;
	Gls::State::TGLMaterialLevel CurrentMaterialLevel;
	Gls::State::TGLMeshPrimitives PrimitiveMask;
	int OrderCounter;
};


typedef TGLRenderContextInfo *PGLRenderContextInfo;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Rendercontextinfo */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_RENDERCONTEXTINFO)
using namespace Gls::Rendercontextinfo;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_RenderContextInfoHPP
