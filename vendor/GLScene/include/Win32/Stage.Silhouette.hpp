// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.Silhouette.pas' rev: 37.00 (Windows)

#ifndef Stage_SilhouetteHPP
#define Stage_SilhouetteHPP

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
#include <System.SysUtils.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorLists.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Silhouette
{
//-- forward type declarations -----------------------------------------------
struct TGSSilhouetteParameters;
class DELPHICLASS TGSSilhouette;
class DELPHICLASS TGSBaseConnectivity;
class DELPHICLASS TGSConnectivity;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGSSilhouetteStyle : unsigned char { ssOmni, ssParallel };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGSSilhouetteParameters
{
public:
	Stage::Vectorgeometry::TAffineVector SeenFrom;
	Stage::Vectorgeometry::TAffineVector LightDirection;
	TGSSilhouetteStyle Style;
	bool CappingRequired;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSSilhouette : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Stage::Vectorlists::TGSVectorList* FVertices;
	Stage::Vectorlists::TGSIntegerList* FIndices;
	Stage::Vectorlists::TGSIntegerList* FCapIndices;
	TGSSilhouetteParameters FParameters;
	
protected:
	void __fastcall SetIndices(Stage::Vectorlists::TGSIntegerList* const value);
	void __fastcall SetCapIndices(Stage::Vectorlists::TGSIntegerList* const value);
	void __fastcall SetVertices(Stage::Vectorlists::TGSVectorList* const value);
	
public:
	__fastcall virtual TGSSilhouette();
	__fastcall virtual ~TGSSilhouette();
	__property TGSSilhouetteParameters Parameters = {read=FParameters, write=FParameters};
	__property Stage::Vectorlists::TGSVectorList* Vertices = {read=FVertices, write=SetVertices};
	__property Stage::Vectorlists::TGSIntegerList* Indices = {read=FIndices, write=SetIndices};
	__property Stage::Vectorlists::TGSIntegerList* CapIndices = {read=FCapIndices, write=SetCapIndices};
	virtual void __fastcall Flush();
	void __fastcall Clear();
	void __fastcall ExtrudeVerticesToInfinity(const Stage::Vectorgeometry::TAffineVector &origin);
	void __fastcall AddEdgeToSilhouette(const Stage::Vectorgeometry::TAffineVector &v0, const Stage::Vectorgeometry::TAffineVector &v1, bool tightButSlow);
	void __fastcall AddIndexedEdgeToSilhouette(const int Vi0, const int Vi1);
	void __fastcall AddCapToSilhouette(const Stage::Vectorgeometry::TAffineVector &v0, const Stage::Vectorgeometry::TAffineVector &v1, const Stage::Vectorgeometry::TAffineVector &v2, bool tightButSlow);
	void __fastcall AddIndexedCapToSilhouette(const int Vi0, const int Vi1, const int vi2);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSBaseConnectivity : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	bool FPrecomputeFaceNormal;
	virtual int __fastcall GetEdgeCount();
	virtual int __fastcall GetFaceCount();
	
public:
	__property int EdgeCount = {read=GetEdgeCount, nodefault};
	__property int FaceCount = {read=GetFaceCount, nodefault};
	__property bool PrecomputeFaceNormal = {read=FPrecomputeFaceNormal, nodefault};
	virtual void __fastcall CreateSilhouette(const TGSSilhouetteParameters &ASilhouetteParameters, TGSSilhouette* &ASilhouette, bool AddToSilhouette);
	__fastcall virtual TGSBaseConnectivity(bool APrecomputeFaceNormal);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGSBaseConnectivity() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSConnectivity : public TGSBaseConnectivity
{
	typedef TGSBaseConnectivity inherited;
	
protected:
	Stage::Vectorlists::TGSIntegerList* FEdgeVertices;
	Stage::Vectorlists::TGSIntegerList* FEdgeFaces;
	Stage::Vectorlists::TGSByteList* FFaceVisible;
	Stage::Vectorlists::TGSIntegerList* FFaceVertexIndex;
	Stage::Vectorlists::TGSAffineVectorList* FFaceNormal;
	Stage::Vectorlists::TGSIntegerList* FVertexMemory;
	Stage::Vectorlists::TGSAffineVectorList* FVertices;
	virtual int __fastcall GetEdgeCount();
	virtual int __fastcall GetFaceCount();
	int __fastcall ReuseOrFindVertexID(const Stage::Vectorgeometry::TAffineVector &SeenFrom, TGSSilhouette* ASilhouette, int index);
	
public:
	virtual void __fastcall Clear();
	virtual void __fastcall CreateSilhouette(const TGSSilhouetteParameters &silhouetteParameters, TGSSilhouette* &ASilhouette, bool AddToSilhouette);
	int __fastcall AddIndexedEdge(int vertexIndex0, int vertexIndex1, int FaceID);
	int __fastcall AddIndexedFace(int Vi0, int Vi1, int vi2);
	int __fastcall AddFace(const Stage::Vectorgeometry::TAffineVector &vertex0, const Stage::Vectorgeometry::TAffineVector &vertex1, const Stage::Vectorgeometry::TAffineVector &vertex2);
	int __fastcall AddQuad(const Stage::Vectorgeometry::TAffineVector &vertex0, const Stage::Vectorgeometry::TAffineVector &vertex1, const Stage::Vectorgeometry::TAffineVector &vertex2, const Stage::Vectorgeometry::TAffineVector &vertex3);
	__property int EdgeCount = {read=GetEdgeCount, nodefault};
	__property int FaceCount = {read=GetFaceCount, nodefault};
	__fastcall virtual TGSConnectivity(bool APrecomputeFaceNormal);
	__fastcall virtual ~TGSConnectivity();
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Silhouette */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_SILHOUETTE)
using namespace Stage::Silhouette;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_SilhouetteHPP
