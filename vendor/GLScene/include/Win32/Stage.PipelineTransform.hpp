// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.PipelineTransform.pas' rev: 37.00 (Windows)

#ifndef Stage_PipelineTransformHPP
#define Stage_PipelineTransformHPP

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
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Pipelinetransform
{
//-- forward type declarations -----------------------------------------------
struct TGSTransformationRec;
class DELPHICLASS TgTransformation;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGSPipelineTransformationState : unsigned char { trsModelViewChanged, trsInvModelViewChanged, trsInvModelChanged, trsNormalModelChanged, trsViewProjChanged, trsFrustum };

typedef System::Set<TGSPipelineTransformationState, TGSPipelineTransformationState::trsModelViewChanged, TGSPipelineTransformationState::trsFrustum> TGSPipelineTransformationStates;

typedef TGSTransformationRec *PGSTransformationRec;

struct DECLSPEC_DRECORD TGSTransformationRec
{
public:
	TGSPipelineTransformationStates FStates;
	Stage::Vectortypes::TGSMatrix FModelMatrix;
	Stage::Vectortypes::TGSMatrix FViewMatrix;
	Stage::Vectortypes::TGSMatrix FProjectionMatrix;
	Stage::Vectortypes::TGSMatrix FInvModelMatrix;
	Stage::Vectorgeometry::TAffineMatrix FNormalModelMatrix;
	Stage::Vectortypes::TGSMatrix FModelViewMatrix;
	Stage::Vectortypes::TGSMatrix FInvModelViewMatrix;
	Stage::Vectortypes::TGSMatrix FViewProjectionMatrix;
	Stage::Vectorgeometry::TFrustum FFrustum;
};


typedef void __fastcall (__closure *TGSOnMatricesPush)(void);

class PASCALIMPLEMENTATION TgTransformation : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TGSTransformationRec> _TgTransformation__1;
	
	
private:
	int FStackPos;
	_TgTransformation__1 FStack;
	bool FLoadMatricesEnabled;
	TGSOnMatricesPush FOnPush;
	Stage::Vectortypes::PGSMatrix __fastcall GetModelMatrix();
	Stage::Vectortypes::PGSMatrix __fastcall GetViewMatrix();
	Stage::Vectortypes::PGSMatrix __fastcall GetProjectionMatrix();
	Stage::Vectortypes::PGSMatrix __fastcall GetModelViewMatrix();
	Stage::Vectortypes::PGSMatrix __fastcall GetInvModelViewMatrix();
	Stage::Vectortypes::PGSMatrix __fastcall GetInvModelMatrix();
	Stage::Vectorgeometry::PAffineMatrix __fastcall GetNormalModelMatrix();
	Stage::Vectortypes::PGSMatrix __fastcall GetViewProjectionMatrix();
	Stage::Vectorgeometry::TFrustum __fastcall GetFrustum();
	
protected:
	void __fastcall LoadModelViewMatrix();
	void __fastcall LoadProjectionMatrix();
	void __fastcall DoMatricesLoaded();
	__property TGSOnMatricesPush OnPush = {read=FOnPush, write=FOnPush};
	
public:
	__fastcall TgTransformation();
	void __fastcall SetModelMatrix(const Stage::Vectortypes::TGSMatrix &AMatrix);
	void __fastcall SetViewMatrix(const Stage::Vectortypes::TGSMatrix &AMatrix);
	void __fastcall SetProjectionMatrix(const Stage::Vectortypes::TGSMatrix &AMatrix);
	void __fastcall IdentityAll();
	void __fastcall Push(PGSTransformationRec AValue)/* overload */;
	void __fastcall Push()/* overload */;
	void __fastcall Pop();
	void __fastcall ReplaceFromStack();
	TGSTransformationRec __fastcall StackTop();
	__property Stage::Vectortypes::PGSMatrix ModelMatrix = {read=GetModelMatrix};
	__property Stage::Vectortypes::PGSMatrix ViewMatrix = {read=GetViewMatrix};
	__property Stage::Vectortypes::PGSMatrix ProjectionMatrix = {read=GetProjectionMatrix};
	__property Stage::Vectortypes::PGSMatrix InvModelMatrix = {read=GetInvModelMatrix};
	__property Stage::Vectortypes::PGSMatrix ModelViewMatrix = {read=GetModelViewMatrix};
	__property Stage::Vectorgeometry::PAffineMatrix NormalModelMatrix = {read=GetNormalModelMatrix};
	__property Stage::Vectortypes::PGSMatrix InvModelViewMatrix = {read=GetInvModelViewMatrix};
	__property Stage::Vectortypes::PGSMatrix ViewProjectionMatrix = {read=GetViewProjectionMatrix};
	__property Stage::Vectorgeometry::TFrustum Frustum = {read=GetFrustum};
	__property bool LoadMatricesEnabled = {read=FLoadMatricesEnabled, write=FLoadMatricesEnabled, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TgTransformation() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Byte MAX_MATRIX_STACK_DEPTH = System::Byte(0x80);
#define cAllStatesChanged (System::Set<TGSPipelineTransformationState, TGSPipelineTransformationState::trsModelViewChanged, TGSPipelineTransformationState::trsFrustum>() << TGSPipelineTransformationState::trsModelViewChanged << TGSPipelineTransformationState::trsInvModelViewChanged << TGSPipelineTransformationState::trsInvModelChanged << TGSPipelineTransformationState::trsNormalModelChanged << TGSPipelineTransformationState::trsViewProjChanged << TGSPipelineTransformationState::trsFrustum )
}	/* namespace Pipelinetransform */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_PIPELINETRANSFORM)
using namespace Stage::Pipelinetransform;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_PipelineTransformHPP
