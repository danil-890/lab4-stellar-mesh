// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.SpacePartition.pas' rev: 37.00 (Windows)

#ifndef GLS_SpacePartitionHPP
#define GLS_SpacePartitionHPP

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
#include <System.Math.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.PersistentClasses.hpp>
#include <Stage.Coordinates.hpp>
#include <Stage.GeometryBB.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Context.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <GLS.SceneViewer.hpp>
#include <GLS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Spacepartition
{
//-- forward type declarations -----------------------------------------------
struct TGLConeSP;
struct TGLExtendedFrustum;
class DELPHICLASS TGLSpacePartitionLeaf;
class DELPHICLASS TGLSpacePartitionLeafList;
class DELPHICLASS TGLSpacePartitionLeafS;
class DELPHICLASS TGLBaseSpacePartition;
class DELPHICLASS TGLLeavedSpacePartition;
class DELPHICLASS TGLSectorNode;
class DELPHICLASS TGLSectoredSpacePartition;
class DELPHICLASS TSPOctreeNode;
class DELPHICLASS TGLOctreeSpacePartition;
class DELPHICLASS TSPQuadtreeNode;
class DELPHICLASS TGLQuadtreeSpacePartition;
class DELPHICLASS TGLSceneObj;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TGLConeSP
{
public:
	Stage::Vectorgeometry::TAffineVector Base;
	Stage::Vectorgeometry::TAffineVector Axis;
	float Angle;
	float Length;
};


struct DECLSPEC_DRECORD TGLExtendedFrustum
{
public:
	Stage::Vectorgeometry::TFrustum Frustum;
	Stage::Geometrybb::TBSphere BSphere;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSpacePartitionLeaf : public Stage::Persistentclasses::TGSPersistentObject
{
	typedef Stage::Persistentclasses::TGSPersistentObject inherited;
	
private:
	TGLBaseSpacePartition* FSpacePartition;
	void __fastcall SetSpacePartition(TGLBaseSpacePartition* const Value);
	
public:
	void *FPartitionTag;
	Stage::Geometrybb::TAABB FCachedAABB;
	Stage::Geometrybb::TBSphere FCachedBSphere;
	virtual void __fastcall Changed();
	virtual void __fastcall UpdateCachedAABBAndBSphere();
	__property TGLBaseSpacePartition* SpacePartition = {read=FSpacePartition, write=SetSpacePartition};
	__property void * PartitionTag = {read=FPartitionTag};
	__fastcall TGLSpacePartitionLeaf(TGLBaseSpacePartition* SpacePartition);
	__fastcall virtual ~TGLSpacePartitionLeaf();
public:
	/* TGSPersistentObject.Create */ inline __fastcall virtual TGLSpacePartitionLeaf() : Stage::Persistentclasses::TGSPersistentObject() { }
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSpacePartitionLeaf(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSpacePartitionLeafList : public Stage::Persistentclasses::TGSPersistentObjectList
{
	typedef Stage::Persistentclasses::TGSPersistentObjectList inherited;
	
public:
	TGLSpacePartitionLeaf* operator[](int I) { return this->Items[I]; }
	
private:
	TGLSpacePartitionLeaf* __fastcall GetItems(int I);
	void __fastcall SetItems(int I, TGLSpacePartitionLeaf* const Value);
	
public:
	__property TGLSpacePartitionLeaf* Items[int I] = {read=GetItems, write=SetItems/*, default*/};
	__fastcall virtual TGLSpacePartitionLeafList();
public:
	/* TGSPersistentObjectList.Destroy */ inline __fastcall virtual ~TGLSpacePartitionLeafList() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSpacePartitionLeafList(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSpacePartitionLeafS : public TGLSpacePartitionLeaf
{
	typedef TGLSpacePartitionLeaf inherited;
	
public:
	Gls::Scene::TGLBaseSceneObject* GLBaseSceneObject;
	Stage::Vectorgeometry::TAffineVector Direction;
	virtual void __fastcall UpdateCachedAABBAndBSphere();
	__fastcall TGLSpacePartitionLeafS(TGLBaseSpacePartition* SpacePartition, Gls::Scene::TGLBaseSceneObject* aGLBaseSceneObject);
public:
	/* TGLSpacePartitionLeaf.CreateOwned */ inline __fastcall TGLSpacePartitionLeafS(TGLBaseSpacePartition* SpacePartition) : TGLSpacePartitionLeaf(SpacePartition) { }
	/* TGLSpacePartitionLeaf.Destroy */ inline __fastcall virtual ~TGLSpacePartitionLeafS() { }
	
public:
	/* TGSPersistentObject.Create */ inline __fastcall virtual TGLSpacePartitionLeafS() : TGLSpacePartitionLeaf() { }
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSpacePartitionLeafS(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLSpacePartitionLeaf(reader) { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TGLCullingMode : unsigned char { CmFineCulling, CmGrossCulling };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLBaseSpacePartition : public Stage::Persistentclasses::TGSPersistentObject
{
	typedef Stage::Persistentclasses::TGSPersistentObject inherited;
	
private:
	TGLCullingMode FCullingMode;
	virtual int __fastcall QueryCone(const TGLConeSP &ACone);
	
protected:
	TGLSpacePartitionLeafList* FQueryResult;
	int FQueryInterObjectTests;
	virtual void __fastcall FlushQueryResult();
	
public:
	__property TGLSpacePartitionLeafList* QueryResult = {read=FQueryResult};
	virtual void __fastcall Clear();
	virtual void __fastcall AddLeaf(TGLSpacePartitionLeaf* ALeaf);
	virtual void __fastcall RemoveLeaf(TGLSpacePartitionLeaf* ALeaf);
	virtual void __fastcall LeafChanged(TGLSpacePartitionLeaf* ALeaf);
	virtual int __fastcall QueryAABB(const Stage::Geometrybb::TAABB &AAABB);
	virtual int __fastcall QueryBSphere(const Stage::Geometrybb::TBSphere &ABSphere);
	virtual int __fastcall QueryLeaf(TGLSpacePartitionLeaf* const ALeaf);
	virtual int __fastcall QueryPlane(const Stage::Vectorgeometry::TAffineVector &Location, const Stage::Vectorgeometry::TAffineVector &Normal);
	virtual int __fastcall QueryFrustum(const Stage::Vectorgeometry::TFrustum &Frustum);
	virtual int __fastcall QueryFrustumEx(const TGLExtendedFrustum &ExtendedFrustum);
	__property int QueryInterObjectTests = {read=FQueryInterObjectTests, nodefault};
	virtual void __fastcall ProcessUpdated();
	__property TGLCullingMode CullingMode = {read=FCullingMode, write=FCullingMode, nodefault};
	__fastcall virtual TGLBaseSpacePartition();
	__fastcall virtual ~TGLBaseSpacePartition();
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLBaseSpacePartition(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLLeavedSpacePartition : public TGLBaseSpacePartition
{
	typedef TGLBaseSpacePartition inherited;
	
private:
	TGLSpacePartitionLeafList* FLeaves;
	virtual int __fastcall QueryCone(const TGLConeSP &ACone);
	
public:
	virtual void __fastcall Clear();
	virtual void __fastcall AddLeaf(TGLSpacePartitionLeaf* ALeaf);
	virtual void __fastcall RemoveLeaf(TGLSpacePartitionLeaf* ALeaf);
	virtual int __fastcall QueryAABB(const Stage::Geometrybb::TAABB &AAABB);
	virtual int __fastcall QueryBSphere(const Stage::Geometrybb::TBSphere &ABSphere);
	virtual int __fastcall QueryPlane(const Stage::Vectorgeometry::TAffineVector &FLocation, const Stage::Vectorgeometry::TAffineVector &FNormal);
	__fastcall virtual TGLLeavedSpacePartition();
	__fastcall virtual ~TGLLeavedSpacePartition();
	
__published:
	__property TGLSpacePartitionLeafList* Leaves = {read=FLeaves};
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLLeavedSpacePartition(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLBaseSpacePartition(reader) { }
	
};

#pragma pack(pop)

typedef System::StaticArray<TGLSectorNode*, 8> TGLSectorNodeArray;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSectorNode : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TGLSpacePartitionLeafList* FLeaves;
	Stage::Geometrybb::TAABB FAABB;
	TGLSectoredSpacePartition* FSectoredSpacePartition;
	int FRecursiveLeafCount;
	TGLSectorNode* FParent;
	int FNodeDepth;
	int FChildCount;
	TGLSectorNodeArray FChildren;
	Stage::Geometrybb::TBSphere FBSphere;
	bool __fastcall GetNoChildren();
	void __fastcall SetAABB(const Stage::Geometrybb::TAABB &Value);
	Stage::Vectorgeometry::TAffineVector __fastcall GetCenter();
	
protected:
	int __fastcall CalcRecursiveLeafCount();
	TGLSectorNode* __fastcall PlaceLeafInChild(TGLSpacePartitionLeaf* ALeaf);
	System::UnicodeString __fastcall VerifyRecursiveLeafCount();
	virtual void __fastcall ChildrenChanged();
	
public:
	void __fastcall Clear();
	__property Stage::Geometrybb::TAABB AABB = {read=FAABB, write=SetAABB};
	__property Stage::Geometrybb::TBSphere BSphere = {read=FBSphere};
	__property Stage::Vectorgeometry::TAffineVector Center = {read=GetCenter};
	__property bool NoChildren = {read=GetNoChildren, nodefault};
	__property TGLSectorNodeArray Children = {read=FChildren};
	__property int ChildCount = {read=FChildCount, nodefault};
	virtual TGLSectorNode* __fastcall GetChildForAABB(const Stage::Geometrybb::TAABB &AABB);
	__property TGLSpacePartitionLeafList* Leaves = {read=FLeaves};
	__property TGLSectoredSpacePartition* SectoredSpacePartition = {read=FSectoredSpacePartition};
	__property TGLSectorNode* Parent = {read=FParent};
	__property int RecursiveLeafCount = {read=FRecursiveLeafCount, nodefault};
	__property int NodeDepth = {read=FNodeDepth, nodefault};
	virtual bool __fastcall AABBFitsInNode(const Stage::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall AABBIntersectsNode(const Stage::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall BSphereFitsInNode(const Stage::Geometrybb::TBSphere &BSphere);
	virtual bool __fastcall BSphereIntersectsNode(const Stage::Geometrybb::TBSphere &BSphere);
	virtual Stage::Geometrybb::TSpaceContains __fastcall AABBContainsSector(const Stage::Geometrybb::TAABB &AABB);
	virtual Stage::Geometrybb::TSpaceContains __fastcall BSphereContainsSector(const Stage::Geometrybb::TBSphere &BSphere);
	virtual Stage::Geometrybb::TSpaceContains __fastcall ContainsBSphere(const Stage::Geometrybb::TBSphere &ABSphere);
	virtual Stage::Geometrybb::TSpaceContains __fastcall ContainsAABB(const Stage::Geometrybb::TAABB &AAABB);
	TGLSectorNode* __fastcall AddLeaf(TGLSpacePartitionLeaf* ALeaf);
	bool __fastcall RemoveLeaf(TGLSpacePartitionLeaf* ALeaf, bool OwnerByThis);
	void __fastcall QueryAABB(const Stage::Geometrybb::TAABB &AAABB, TGLSpacePartitionLeafList* const QueryResult);
	void __fastcall QueryBSphere(const Stage::Geometrybb::TBSphere &ABSphere, TGLSpacePartitionLeafList* const QueryResult);
	void __fastcall QueryPlane(const Stage::Vectorgeometry::TAffineVector &Location, const Stage::Vectorgeometry::TAffineVector &Normal, TGLSpacePartitionLeafList* const QueryResult);
	void __fastcall QueryFrustum(const Stage::Vectorgeometry::TFrustum &Frustum, TGLSpacePartitionLeafList* const QueryResult);
	void __fastcall QueryFrustumEx(const TGLExtendedFrustum &ExtendedFrustum, TGLSpacePartitionLeafList* const QueryResult);
	void __fastcall AddAllLeavesRecursive(TGLSpacePartitionLeafList* const QueryResult);
	void __fastcall ExpandNode();
	virtual void __fastcall CreateChildren();
	void __fastcall CollapseNode();
	int __fastcall GetNodeCount();
	__fastcall TGLSectorNode(TGLSectoredSpacePartition* ASectoredSpacePartition, TGLSectorNode* AParent);
	__fastcall virtual ~TGLSectorNode();
};

#pragma pack(pop)

enum DECLSPEC_DENUM TGLGrowMethod : unsigned char { gmNever, gmBestFit, gmIncreaseToFitAll };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSectoredSpacePartition : public TGLLeavedSpacePartition
{
	typedef TGLLeavedSpacePartition inherited;
	
private:
	TGLSectorNode* FRootNode;
	int FLeafThreshold;
	int FMaxTreeDepth;
	float FGrowGravy;
	TGLGrowMethod FGrowMethod;
	void __fastcall SetLeafThreshold(const int Value);
	void __fastcall SetMaxTreeDepth(const int Value);
	
protected:
	int FQueryNodeTests;
	virtual void __fastcall FlushQueryResult();
	
public:
	virtual void __fastcall AddLeaf(TGLSpacePartitionLeaf* ALeaf);
	virtual void __fastcall RemoveLeaf(TGLSpacePartitionLeaf* ALeaf);
	virtual void __fastcall LeafChanged(TGLSpacePartitionLeaf* ALeaf);
	virtual int __fastcall QueryAABB(const Stage::Geometrybb::TAABB &AAABB);
	virtual int __fastcall QueryBSphere(const Stage::Geometrybb::TBSphere &ABSphere);
	virtual int __fastcall QueryLeaf(TGLSpacePartitionLeaf* const ALeaf);
	virtual int __fastcall QueryPlane(const Stage::Vectorgeometry::TAffineVector &Location, const Stage::Vectorgeometry::TAffineVector &Normal);
	virtual int __fastcall QueryFrustum(const Stage::Vectorgeometry::TFrustum &Frustum);
	virtual int __fastcall QueryFrustumEx(const TGLExtendedFrustum &ExtendedFrustum);
	__property int QueryNodeTests = {read=FQueryNodeTests, nodefault};
	int __fastcall GetNodeCount();
	void __fastcall UpdateStructureSize(float Gravy);
	void __fastcall RebuildTree(const Stage::Geometrybb::TAABB &NewAABB);
	Stage::Geometrybb::TAABB __fastcall GetAABB();
	virtual TGLSectorNode* __fastcall CreateNewNode(TGLSectorNode* AParent);
	virtual void __fastcall Clear();
	__fastcall virtual TGLSectoredSpacePartition();
	__fastcall virtual ~TGLSectoredSpacePartition();
	
__published:
	__property TGLSectorNode* RootNode = {read=FRootNode};
	__property int MaxTreeDepth = {read=FMaxTreeDepth, write=SetMaxTreeDepth, nodefault};
	__property int LeafThreshold = {read=FLeafThreshold, write=SetLeafThreshold, nodefault};
	__property TGLGrowMethod GrowMethod = {read=FGrowMethod, write=FGrowMethod, nodefault};
	__property float GrowGravy = {read=FGrowGravy, write=FGrowGravy};
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSectoredSpacePartition(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLLeavedSpacePartition(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSPOctreeNode : public TGLSectorNode
{
	typedef TGLSectorNode inherited;
	
public:
	virtual void __fastcall CreateChildren();
	virtual bool __fastcall AABBFitsInNode(const Stage::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall AABBIntersectsNode(const Stage::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall BSphereFitsInNode(const Stage::Geometrybb::TBSphere &BSphere);
	virtual bool __fastcall BSphereIntersectsNode(const Stage::Geometrybb::TBSphere &BSphere);
public:
	/* TGLSectorNode.Create */ inline __fastcall TSPOctreeNode(TGLSectoredSpacePartition* ASectoredSpacePartition, TGLSectorNode* AParent) : TGLSectorNode(ASectoredSpacePartition, AParent) { }
	/* TGLSectorNode.Destroy */ inline __fastcall virtual ~TSPOctreeNode() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLOctreeSpacePartition : public TGLSectoredSpacePartition
{
	typedef TGLSectoredSpacePartition inherited;
	
public:
	void __fastcall SetSize(const Stage::Vectorgeometry::TAffineVector &Min, const Stage::Vectorgeometry::TAffineVector &Max);
	virtual TGLSectorNode* __fastcall CreateNewNode(TGLSectorNode* AParent);
public:
	/* TGLSectoredSpacePartition.Create */ inline __fastcall virtual TGLOctreeSpacePartition() : TGLSectoredSpacePartition() { }
	/* TGLSectoredSpacePartition.Destroy */ inline __fastcall virtual ~TGLOctreeSpacePartition() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLOctreeSpacePartition(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLSectoredSpacePartition(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSPQuadtreeNode : public TSPOctreeNode
{
	typedef TSPOctreeNode inherited;
	
protected:
	virtual void __fastcall ChildrenChanged();
	
public:
	virtual void __fastcall CreateChildren();
	virtual bool __fastcall AABBFitsInNode(const Stage::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall AABBIntersectsNode(const Stage::Geometrybb::TAABB &AAABB);
	virtual bool __fastcall BSphereFitsInNode(const Stage::Geometrybb::TBSphere &BSphere);
	virtual bool __fastcall BSphereIntersectsNode(const Stage::Geometrybb::TBSphere &BSphere);
	virtual TGLSectorNode* __fastcall GetChildForAABB(const Stage::Geometrybb::TAABB &AABB);
public:
	/* TGLSectorNode.Create */ inline __fastcall TSPQuadtreeNode(TGLSectoredSpacePartition* ASectoredSpacePartition, TGLSectorNode* AParent) : TSPOctreeNode(ASectoredSpacePartition, AParent) { }
	/* TGLSectorNode.Destroy */ inline __fastcall virtual ~TSPQuadtreeNode() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLQuadtreeSpacePartition : public TGLSectoredSpacePartition
{
	typedef TGLSectoredSpacePartition inherited;
	
public:
	void __fastcall SetSize(const Stage::Vectorgeometry::TAffineVector &Min, const Stage::Vectorgeometry::TAffineVector &Max);
	virtual TGLSectorNode* __fastcall CreateNewNode(TGLSectorNode* AParent);
public:
	/* TGLSectoredSpacePartition.Create */ inline __fastcall virtual TGLQuadtreeSpacePartition() : TGLSectoredSpacePartition() { }
	/* TGLSectoredSpacePartition.Destroy */ inline __fastcall virtual ~TGLQuadtreeSpacePartition() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLQuadtreeSpacePartition(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLSectoredSpacePartition(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSceneObj : public TGLSpacePartitionLeaf
{
	typedef TGLSpacePartitionLeaf inherited;
	
public:
	Gls::Scene::TGLBaseSceneObject* Obj;
	virtual void __fastcall UpdateCachedAABBAndBSphere();
	__fastcall TGLSceneObj(TGLSectoredSpacePartition* Owner, Gls::Scene::TGLBaseSceneObject* aObj);
	__fastcall virtual ~TGLSceneObj();
public:
	/* TGLSpacePartitionLeaf.CreateOwned */ inline __fastcall TGLSceneObj(TGLBaseSpacePartition* SpacePartition) : TGLSpacePartitionLeaf(SpacePartition) { }
	
public:
	/* TGSPersistentObject.Create */ inline __fastcall virtual TGLSceneObj() : TGLSpacePartitionLeaf() { }
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSceneObj(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLSpacePartitionLeaf(reader) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 COctree_LEAF_TRHESHOLD = System::Int8(0x1e);
static _DELPHI_CONST System::Int8 COctree_MAX_TREE_DEPTH = System::Int8(0x8);
#define COctree_GROW_GRAVY  (1.000000E-01)
extern DELPHI_PACKAGE Stage::Geometrybb::TSpaceContains __fastcall ConeContainsBSphere(const TGLConeSP &Cone, const Stage::Geometrybb::TBSphere &BSphere);
extern DELPHI_PACKAGE bool __fastcall ExtendedFrustumIntersectsBSphere(const TGLExtendedFrustum &AExtendedFrustum, const Stage::Geometrybb::TBSphere &ABSphere);
extern DELPHI_PACKAGE TGLExtendedFrustum __fastcall ExtendedFrustumMake(const Stage::Vectorgeometry::TFrustum &AFrustum, const float ANearDist, const float AFarDist, const float AFieldOfViewRadians, const Stage::Vectorgeometry::TAffineVector &ACameraPosition, const Stage::Vectorgeometry::TAffineVector &ALookVector);
extern DELPHI_PACKAGE void __fastcall RenderAABB(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, const Stage::Geometrybb::TAABB &AABB)/* overload */;
extern DELPHI_PACKAGE void __fastcall RenderAABB(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, const Stage::Geometrybb::TAABB &AABB, float w, float r, float g, float b)/* overload */;
extern DELPHI_PACKAGE void __fastcall RenderSpatialPartitioning(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, TGLSectoredSpacePartition* const Space);
extern DELPHI_PACKAGE TGLExtendedFrustum __fastcall ExtendedFrustumMakeFromSceneViewer(const Stage::Vectorgeometry::TFrustum &AFrustum, Gls::Sceneviewer::TGLSceneViewer* const AGLSceneViewer)/* overload */;
extern DELPHI_PACKAGE TGLExtendedFrustum __fastcall ExtendedFrustumMakeFromSceneViewer(const Stage::Vectorgeometry::TFrustum &AFrustum, const int vWidth, const int vHeight, Gls::Scene::TGLCamera* AGLCamera)/* overload */;
}	/* namespace Spacepartition */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_SPACEPARTITION)
using namespace Gls::Spacepartition;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_SpacePartitionHPP
