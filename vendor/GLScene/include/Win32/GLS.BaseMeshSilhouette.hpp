// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.BaseMeshSilhouette.pas' rev: 37.00 (Windows)

#ifndef GLS_BaseMeshSilhouetteHPP
#define GLS_BaseMeshSilhouetteHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorLists.hpp>
#include <Stage.Silhouette.hpp>
#include <GLS.VectorFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Basemeshsilhouette
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLFaceGroupConnectivity;
class DELPHICLASS TGLBaseMeshConnectivity;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLFaceGroupConnectivity : public Stage::Silhouette::TGSConnectivity
{
	typedef Stage::Silhouette::TGSConnectivity inherited;
	
private:
	Gls::Vectorfileobjects::TGLMeshObject* FMeshObject;
	bool FOwnsVertices;
	void __fastcall SetMeshObject(Gls::Vectorfileobjects::TGLMeshObject* const Value);
	
public:
	virtual void __fastcall Clear();
	void __fastcall RebuildEdgeList();
	__property Gls::Vectorfileobjects::TGLMeshObject* MeshObject = {read=FMeshObject, write=SetMeshObject};
	__fastcall virtual TGLFaceGroupConnectivity(bool APrecomputeFaceNormal);
	__fastcall TGLFaceGroupConnectivity(Gls::Vectorfileobjects::TGLMeshObject* aMeshObject, bool APrecomputeFaceNormal);
	__fastcall virtual ~TGLFaceGroupConnectivity();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLBaseMeshConnectivity : public Stage::Silhouette::TGSBaseConnectivity
{
	typedef Stage::Silhouette::TGSBaseConnectivity inherited;
	
private:
	Gls::Vectorfileobjects::TGLBaseMesh* FBaseMesh;
	System::Classes::TList* FFaceGroupConnectivityList;
	TGLFaceGroupConnectivity* __fastcall GetFaceGroupConnectivity(int i);
	int __fastcall GetConnectivityCount();
	void __fastcall SetBaseMesh(Gls::Vectorfileobjects::TGLBaseMesh* const Value);
	
protected:
	virtual int __fastcall GetEdgeCount();
	virtual int __fastcall GetFaceCount();
	
public:
	__property int ConnectivityCount = {read=GetConnectivityCount, nodefault};
	__property TGLFaceGroupConnectivity* FaceGroupConnectivity[int i] = {read=GetFaceGroupConnectivity};
	__property Gls::Vectorfileobjects::TGLBaseMesh* BaseMesh = {read=FBaseMesh, write=SetBaseMesh};
	void __fastcall Clear(bool SaveFaceGroupConnectivity);
	void __fastcall RebuildEdgeList();
	virtual void __fastcall CreateSilhouette(const Stage::Silhouette::TGSSilhouetteParameters &silhouetteParameters, Stage::Silhouette::TGSSilhouette* &aSilhouette, bool AddToSilhouette);
	__fastcall virtual TGLBaseMeshConnectivity(bool APrecomputeFaceNormal);
	__fastcall TGLBaseMeshConnectivity(Gls::Vectorfileobjects::TGLBaseMesh* aBaseMesh);
	__fastcall virtual ~TGLBaseMeshConnectivity();
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Basemeshsilhouette */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_BASEMESHSILHOUETTE)
using namespace Gls::Basemeshsilhouette;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_BaseMeshSilhouetteHPP
