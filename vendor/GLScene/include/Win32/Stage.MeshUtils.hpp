// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.MeshUtils.pas' rev: 37.00 (Windows)

#ifndef Stage_MeshUtilsHPP
#define Stage_MeshUtilsHPP

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
#include <System.Math.hpp>
#include <Stage.PersistentClasses.hpp>
#include <Stage.VectorLists.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Meshutils
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
typedef void __fastcall (*TSubdivideEdgeEvent)(const int idxA, const int idxB, const int newIdx);

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool vImprovedFixingOpenTriangleEdge;
extern DELPHI_PACKAGE System::LongWord vEdgeInfoReserveSize;
extern DELPHI_PACKAGE void __fastcall ConvertStripToList(Stage::Vectorlists::TGSAffineVectorList* const strip, Stage::Vectorlists::TGSAffineVectorList* list)/* overload */;
extern DELPHI_PACKAGE void __fastcall ConvertStripToList(Stage::Vectorlists::TGSIntegerList* const strip, Stage::Vectorlists::TGSIntegerList* list)/* overload */;
extern DELPHI_PACKAGE void __fastcall ConvertStripToList(Stage::Vectorlists::TGSAffineVectorList* const strip, Stage::Vectorlists::TGSIntegerList* const indices, Stage::Vectorlists::TGSAffineVectorList* list)/* overload */;
extern DELPHI_PACKAGE void __fastcall ConvertIndexedListToList(Stage::Vectorlists::TGSAffineVectorList* const data, Stage::Vectorlists::TGSIntegerList* const indices, Stage::Vectorlists::TGSAffineVectorList* list);
extern DELPHI_PACKAGE Stage::Vectorlists::TGSIntegerList* __fastcall BuildVectorCountOptimizedIndices(Stage::Vectorlists::TGSAffineVectorList* const vertices, Stage::Vectorlists::TGSAffineVectorList* const normals = (Stage::Vectorlists::TGSAffineVectorList*)(0x0), Stage::Vectorlists::TGSAffineVectorList* const texCoords = (Stage::Vectorlists::TGSAffineVectorList*)(0x0));
extern DELPHI_PACKAGE void __fastcall RemapReferences(Stage::Vectorlists::TGSAffineVectorList* reference, Stage::Vectorlists::TGSIntegerList* const indices)/* overload */;
extern DELPHI_PACKAGE void __fastcall RemapReferences(Stage::Vectorlists::TGSIntegerList* reference, Stage::Vectorlists::TGSIntegerList* const indices)/* overload */;
extern DELPHI_PACKAGE void __fastcall RemapAndCleanupReferences(Stage::Vectorlists::TGSAffineVectorList* reference, Stage::Vectorlists::TGSIntegerList* indices);
extern DELPHI_PACKAGE Stage::Vectorlists::TGSIntegerList* __fastcall RemapIndicesToIndicesMap(Stage::Vectorlists::TGSIntegerList* remapIndices);
extern DELPHI_PACKAGE void __fastcall RemapTrianglesIndices(Stage::Vectorlists::TGSIntegerList* indices, Stage::Vectorlists::TGSIntegerList* indicesMap);
extern DELPHI_PACKAGE void __fastcall remapIndices(Stage::Vectorlists::TGSIntegerList* indices, Stage::Vectorlists::TGSIntegerList* indicesMap);
extern DELPHI_PACKAGE void __fastcall UnifyTrianglesWinding(Stage::Vectorlists::TGSIntegerList* indices);
extern DELPHI_PACKAGE void __fastcall InvertTrianglesWinding(Stage::Vectorlists::TGSIntegerList* indices);
extern DELPHI_PACKAGE Stage::Vectorlists::TGSAffineVectorList* __fastcall BuildNormals(Stage::Vectorlists::TGSAffineVectorList* reference, Stage::Vectorlists::TGSIntegerList* indices);
extern DELPHI_PACKAGE Stage::Vectorlists::TGSIntegerList* __fastcall BuildNonOrientedEdgesList(Stage::Vectorlists::TGSIntegerList* triangleIndices, Stage::Vectorlists::TGSIntegerList* triangleEdges = (Stage::Vectorlists::TGSIntegerList*)(0x0), Stage::Vectorlists::TGSIntegerList* edgesTriangles = (Stage::Vectorlists::TGSIntegerList*)(0x0));
extern DELPHI_PACKAGE void __fastcall IncreaseCoherency(Stage::Vectorlists::TGSIntegerList* indices, int cacheSize);
extern DELPHI_PACKAGE void __fastcall WeldVertices(Stage::Vectorlists::TGSAffineVectorList* vertices, Stage::Vectorlists::TGSIntegerList* indicesMap, float weldRadius);
extern DELPHI_PACKAGE Stage::Persistentclasses::TGSPersistentObjectList* __fastcall StripifyMesh(Stage::Vectorlists::TGSIntegerList* indices, int maxVertexIndex, bool agglomerateLoneTriangles = false);
extern DELPHI_PACKAGE void __fastcall SubdivideTriangles(float smoothFactor, Stage::Vectorlists::TGSAffineVectorList* vertices, Stage::Vectorlists::TGSIntegerList* triangleIndices, Stage::Vectorlists::TGSAffineVectorList* normals = (Stage::Vectorlists::TGSAffineVectorList*)(0x0), TSubdivideEdgeEvent onSubdivideEdge = 0x0);
extern DELPHI_PACKAGE Stage::Vectorlists::TGSLongWordList* __fastcall MakeTriangleAdjacencyList(const Stage::Vectorgeometry::PLongWordArray AindicesList, System::LongWord Count, const Stage::Vectorgeometry::PAffineVectorArray AVerticesList);
extern DELPHI_PACKAGE Stage::Vectorlists::TGSLongWordList* __fastcall ConvertStripToList(const Stage::Vectorgeometry::PLongWordArray AindicesList, System::LongWord Count, System::LongWord RestartIndex)/* overload */;
extern DELPHI_PACKAGE Stage::Vectorlists::TGSLongWordList* __fastcall ConvertFansToList(const Stage::Vectorgeometry::PLongWordArray AindicesList, System::LongWord Count, System::LongWord RestartIndex);
}	/* namespace Meshutils */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_MESHUTILS)
using namespace Stage::Meshutils;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_MeshUtilsHPP
