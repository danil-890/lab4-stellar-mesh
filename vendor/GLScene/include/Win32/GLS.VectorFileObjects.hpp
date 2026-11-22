// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.VectorFileObjects.pas' rev: 37.00 (Windows)

#ifndef GLS_VectorFileObjectsHPP
#define GLS_VectorFileObjectsHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <System.Math.hpp>
#include <Vcl.Consts.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypesExt.hpp>
#include <Stage.PersistentClasses.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.Strings.hpp>
#include <Stage.Utils.hpp>
#include <Stage.VectorLists.hpp>
#include <Stage.Coordinates.hpp>
#include <Stage.BaseClasses.hpp>
#include <Stage.Silhouette.hpp>
#include <Stage.Color.hpp>
#include <Stage.GeometryBB.hpp>
#include <Stage.MeshUtils.hpp>
#include <GLS.ApplicationFileIO.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Texture.hpp>
#include <GLS.Material.hpp>
#include <GLS.Mesh.hpp>
#include <GLS.Octree.hpp>
#include <GLS.Context.hpp>
#include <GLS.Selection.hpp>
#include <GLS.XOpenGL.hpp>
#include <GLS.State.hpp>
#include <GLS.RenderContextInfo.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Vectorfileobjects
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLBaseMeshObject;
class DELPHICLASS TGLSkeletonFrame;
class DELPHICLASS TGLSkeletonFrameList;
class DELPHICLASS TGLSkeletonBoneList;
class DELPHICLASS TGLSkeletonRootBoneList;
class DELPHICLASS TGLSkeletonBone;
class DELPHICLASS TGLSkeletonCollider;
class DELPHICLASS TGLSkeletonColliderList;
struct TGLBlendedLerpInfo;
class DELPHICLASS TGLSkeleton;
class DELPHICLASS TGLMeshObject;
class DELPHICLASS TGLMeshObjectList;
class DELPHICLASS TGLMeshMorphTarget;
class DELPHICLASS TGLMeshMorphTargetList;
class DELPHICLASS TGLMorphableMeshObject;
struct TGLVertexBoneWeight;
class DELPHICLASS TGLSkeletonMeshObject;
class DELPHICLASS TGLFaceGroup;
class DELPHICLASS TFGVertexIndexList;
class DELPHICLASS TFGVertexNormalTexIndexList;
class DELPHICLASS TFGIndexTexCoordList;
class DELPHICLASS TGLFaceGroups;
class DELPHICLASS TGLVectorFile;
class DELPHICLASS TGLSMVectorFile;
class DELPHICLASS TGLBaseMesh;
class DELPHICLASS TGLFreeForm;
class DELPHICLASS TGLActorAnimation;
class DELPHICLASS TGLActorAnimations;
class DELPHICLASS TGLBaseAnimationControler;
class DELPHICLASS TGLAnimationControler;
class DELPHICLASS TGLActor;
class DELPHICLASS TGLVectorFileFormat;
class DELPHICLASS TGLVectorFileFormatsList;
class DELPHICLASS EInvalidVectorFile;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLMeshAutoCentering : unsigned char { macCenterX, macCenterY, macCenterZ, macUseBarycenter, macRestorePosition };

typedef System::Set<TGLMeshAutoCentering, TGLMeshAutoCentering::macCenterX, TGLMeshAutoCentering::macRestorePosition> TGLMeshAutoCenterings;

enum DECLSPEC_DENUM TGLMeshObjectMode : unsigned char { momTriangles, momTriangleStrip, momFaceGroups };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLBaseMeshObject : public Stage::Persistentclasses::TGSPersistentObject
{
	typedef Stage::Persistentclasses::TGSPersistentObject inherited;
	
private:
	System::UnicodeString FName;
	Stage::Vectorlists::TGSAffineVectorList* FVertices;
	Stage::Vectorlists::TGSAffineVectorList* FNormals;
	bool FVisible;
	
protected:
	void __fastcall SetVertices(Stage::Vectorlists::TGSAffineVectorList* const val);
	void __fastcall SetNormals(Stage::Vectorlists::TGSAffineVectorList* const val);
	virtual void __fastcall ContributeToBarycenter(Stage::Vectorgeometry::TAffineVector &currentSum, int &nb);
	
public:
	__fastcall virtual TGLBaseMeshObject();
	__fastcall virtual ~TGLBaseMeshObject();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall Clear();
	virtual void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta);
	void __fastcall BuildNormals(Stage::Vectorlists::TGSIntegerList* vertexIndices, TGLMeshObjectMode mode, Stage::Vectorlists::TGSIntegerList* NormalIndices = (Stage::Vectorlists::TGSIntegerList*)(0x0));
	void __fastcall GenericOrderedBuildNormals(TGLMeshObjectMode mode);
	virtual Stage::Vectorlists::TGSAffineVectorList* __fastcall ExtractTriangles(Stage::Vectorlists::TGSAffineVectorList* texCoords = (Stage::Vectorlists::TGSAffineVectorList*)(0x0), Stage::Vectorlists::TGSAffineVectorList* Normals = (Stage::Vectorlists::TGSAffineVectorList*)(0x0));
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
	__property Stage::Vectorlists::TGSAffineVectorList* Vertices = {read=FVertices, write=SetVertices};
	__property Stage::Vectorlists::TGSAffineVectorList* Normals = {read=FNormals, write=SetNormals};
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLBaseMeshObject(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObject(reader) { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TGLSkeletonFrameTransform : unsigned char { sftRotation, sftQuaternion };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSkeletonFrame : public Stage::Persistentclasses::TGSPersistentObject
{
	typedef Stage::Persistentclasses::TGSPersistentObject inherited;
	
private:
	TGLSkeletonFrameList* FOwner;
	System::UnicodeString FName;
	Stage::Vectorlists::TGSAffineVectorList* FPosition;
	Stage::Vectorlists::TGSAffineVectorList* FRotation;
	Stage::Vectorlists::TGSQuaternionList* FQuaternion;
	Stage::Vectorgeometry::PMatrixArray FLocalMatrixList;
	TGLSkeletonFrameTransform FTransformMode;
	
protected:
	void __fastcall SetPosition(Stage::Vectorlists::TGSAffineVectorList* const val);
	void __fastcall SetRotation(Stage::Vectorlists::TGSAffineVectorList* const val);
	void __fastcall SetQuaternion(Stage::Vectorlists::TGSQuaternionList* const val);
	
public:
	__fastcall TGLSkeletonFrame(TGLSkeletonFrameList* aOwner);
	__fastcall virtual TGLSkeletonFrame();
	__fastcall virtual ~TGLSkeletonFrame();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	__property TGLSkeletonFrameList* Owner = {read=FOwner};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property Stage::Vectorlists::TGSAffineVectorList* Position = {read=FPosition, write=SetPosition};
	__property Stage::Vectorlists::TGSAffineVectorList* Rotation = {read=FRotation, write=SetRotation};
	__property Stage::Vectorlists::TGSQuaternionList* Quaternion = {read=FQuaternion, write=SetQuaternion};
	__property TGLSkeletonFrameTransform TransformMode = {read=FTransformMode, write=FTransformMode, nodefault};
	Stage::Vectorgeometry::PMatrixArray __fastcall LocalMatrixList();
	void __fastcall FlushLocalMatrixList();
	void __fastcall ConvertQuaternionsToRotations(bool KeepQuaternions = true);
	void __fastcall ConvertRotationsToQuaternions(bool KeepRotations = true);
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSkeletonFrame(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSkeletonFrameList : public Stage::Persistentclasses::TGSPersistentObjectList
{
	typedef Stage::Persistentclasses::TGSPersistentObjectList inherited;
	
public:
	TGLSkeletonFrame* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	TGLSkeletonFrame* __fastcall GetSkeletonFrame(int Index);
	
public:
	__fastcall TGLSkeletonFrameList(System::Classes::TPersistent* aOwner);
	__fastcall virtual ~TGLSkeletonFrameList();
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	void __fastcall ConvertQuaternionsToRotations(bool KeepQuaternions = true, bool SetTransformMode = true);
	void __fastcall ConvertRotationsToQuaternions(bool KeepRotations = true, bool SetTransformMode = true);
	__property System::Classes::TPersistent* Owner = {read=FOwner};
	virtual void __fastcall Clear();
	__property TGLSkeletonFrame* Items[int Index] = {read=GetSkeletonFrame/*, default*/};
public:
	/* TGSPersistentObjectList.Create */ inline __fastcall virtual TGLSkeletonFrameList() : Stage::Persistentclasses::TGSPersistentObjectList() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSkeletonFrameList(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSkeletonBoneList : public Stage::Persistentclasses::TGSPersistentObjectList
{
	typedef Stage::Persistentclasses::TGSPersistentObjectList inherited;
	
public:
	TGLSkeletonBone* operator[](int Index) { return this->Items[Index]; }
	
private:
	TGLSkeleton* FSkeleton;
	
protected:
	Stage::Vectortypes::TGSMatrix FGlobalMatrix;
	TGLSkeletonBone* __fastcall GetSkeletonBone(int Index);
	virtual void __fastcall AfterObjectCreatedByReader(System::TObject* Sender);
	
public:
	__fastcall TGLSkeletonBoneList(TGLSkeleton* aOwner);
	__fastcall virtual TGLSkeletonBoneList();
	__fastcall virtual ~TGLSkeletonBoneList();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	__property TGLSkeleton* Skeleton = {read=FSkeleton};
	__property TGLSkeletonBone* Items[int Index] = {read=GetSkeletonBone/*, default*/};
	virtual TGLSkeletonBone* __fastcall BoneByID(int anID);
	virtual TGLSkeletonBone* __fastcall BoneByName(const System::UnicodeString aName);
	int __fastcall BoneCount();
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci) = 0 ;
	virtual void __fastcall PrepareGlobalMatrices();
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSkeletonBoneList(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSkeletonRootBoneList : public TGLSkeletonBoneList
{
	typedef TGLSkeletonBoneList inherited;
	
public:
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	__property Stage::Vectortypes::TGSMatrix GlobalMatrix = {read=FGlobalMatrix, write=FGlobalMatrix};
public:
	/* TGLSkeletonBoneList.CreateOwned */ inline __fastcall TGLSkeletonRootBoneList(TGLSkeleton* aOwner) : TGLSkeletonBoneList(aOwner) { }
	/* TGLSkeletonBoneList.Create */ inline __fastcall virtual TGLSkeletonRootBoneList() : TGLSkeletonBoneList() { }
	/* TGLSkeletonBoneList.Destroy */ inline __fastcall virtual ~TGLSkeletonRootBoneList() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSkeletonRootBoneList(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLSkeletonBoneList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSkeletonBone : public TGLSkeletonBoneList
{
	typedef TGLSkeletonBoneList inherited;
	
public:
	TGLSkeletonBone* operator[](int Index) { return this->Items[Index]; }
	
private:
	TGLSkeletonBoneList* FOwner;
	int FBoneID;
	System::UnicodeString FName;
	unsigned FColor;
	
protected:
	HIDESBASE TGLSkeletonBone* __fastcall GetSkeletonBone(int Index);
	void __fastcall SetColor(const unsigned val);
	
public:
	__fastcall TGLSkeletonBone(TGLSkeletonBoneList* aOwner);
	__fastcall virtual TGLSkeletonBone();
	__fastcall virtual ~TGLSkeletonBone();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	__property TGLSkeletonBoneList* Owner = {read=FOwner};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property int BoneID = {read=FBoneID, write=FBoneID, nodefault};
	__property unsigned Color = {read=FColor, write=SetColor, nodefault};
	__property TGLSkeletonBone* Items[int Index] = {read=GetSkeletonBone/*, default*/};
	virtual TGLSkeletonBone* __fastcall BoneByID(int anID);
	virtual TGLSkeletonBone* __fastcall BoneByName(const System::UnicodeString aName);
	void __fastcall SetGlobalMatrix(const Stage::Vectortypes::TGSMatrix &Matrix);
	void __fastcall SetGlobalMatrixForRagDoll(const Stage::Vectortypes::TGSMatrix &RagDollMatrix);
	virtual void __fastcall PrepareGlobalMatrices();
	__property Stage::Vectortypes::TGSMatrix GlobalMatrix = {read=FGlobalMatrix};
	virtual void __fastcall Clean();
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSkeletonBone(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLSkeletonBoneList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSkeletonCollider : public Stage::Persistentclasses::TGSPersistentObject
{
	typedef Stage::Persistentclasses::TGSPersistentObject inherited;
	
private:
	TGLSkeletonColliderList* FOwner;
	TGLSkeletonBone* FBone;
	int FBoneID;
	Stage::Vectortypes::TGSMatrix FLocalMatrix;
	Stage::Vectortypes::TGSMatrix FGlobalMatrix;
	bool FAutoUpdate;
	
protected:
	void __fastcall SetBone(TGLSkeletonBone* const val);
	void __fastcall SetLocalMatrix(const Stage::Vectortypes::TGSMatrix &val);
	
public:
	__fastcall virtual TGLSkeletonCollider();
	__fastcall TGLSkeletonCollider(TGLSkeletonColliderList* AOwner);
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall AlignCollider();
	__property TGLSkeletonColliderList* Owner = {read=FOwner};
	__property TGLSkeletonBone* Bone = {read=FBone, write=SetBone};
	__property Stage::Vectortypes::TGSMatrix LocalMatrix = {read=FLocalMatrix, write=SetLocalMatrix};
	__property Stage::Vectortypes::TGSMatrix GlobalMatrix = {read=FGlobalMatrix};
	__property bool AutoUpdate = {read=FAutoUpdate, write=FAutoUpdate, nodefault};
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSkeletonCollider(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObject(reader) { }
	/* TGSPersistentObject.Destroy */ inline __fastcall virtual ~TGLSkeletonCollider() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSkeletonColliderList : public Stage::Persistentclasses::TGSPersistentObjectList
{
	typedef Stage::Persistentclasses::TGSPersistentObjectList inherited;
	
public:
	TGLSkeletonCollider* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	TGLSkeletonCollider* __fastcall GetSkeletonCollider(int Index);
	
public:
	__fastcall TGLSkeletonColliderList(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TGLSkeletonColliderList();
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall Clear();
	void __fastcall AlignColliders();
	__property System::Classes::TPersistent* Owner = {read=FOwner};
	__property TGLSkeletonCollider* Items[int Index] = {read=GetSkeletonCollider/*, default*/};
public:
	/* TGSPersistentObjectList.Create */ inline __fastcall virtual TGLSkeletonColliderList() : Stage::Persistentclasses::TGSPersistentObjectList() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSkeletonColliderList(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TGLBlendedLerpInfo
{
public:
	int FrameIndex1;
	int frameIndex2;
	float LerpFactor;
	float Weight;
	Stage::Vectorlists::TGSAffineVectorList* ExternalPositions;
	Stage::Vectorlists::TGSAffineVectorList* ExternalRotations;
	Stage::Vectorlists::TGSQuaternionList* ExternalQuaternions;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSkeleton : public Stage::Persistentclasses::TGSPersistentObject
{
	typedef Stage::Persistentclasses::TGSPersistentObject inherited;
	
private:
	TGLBaseMesh* FOwner;
	TGLSkeletonRootBoneList* FRootBones;
	TGLSkeletonFrameList* FFrames;
	TGLSkeletonFrame* FCurrentFrame;
	System::Classes::TList* FBonesByIDCache;
	TGLSkeletonColliderList* FColliders;
	bool FRagDollEnabled;
	bool FMorphInvisibleParts;
	
protected:
	void __fastcall SetRootBones(TGLSkeletonRootBoneList* const val);
	void __fastcall SetFrames(TGLSkeletonFrameList* const val);
	TGLSkeletonFrame* __fastcall GetCurrentFrame();
	void __fastcall SetCurrentFrame(TGLSkeletonFrame* val);
	void __fastcall SetColliders(TGLSkeletonColliderList* const val);
	
public:
	__fastcall TGLSkeleton(TGLBaseMesh* aOwner);
	__fastcall virtual TGLSkeleton();
	__fastcall virtual ~TGLSkeleton();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	__property TGLBaseMesh* Owner = {read=FOwner};
	__property TGLSkeletonRootBoneList* RootBones = {read=FRootBones, write=SetRootBones};
	__property TGLSkeletonFrameList* Frames = {read=FFrames, write=SetFrames};
	__property TGLSkeletonFrame* CurrentFrame = {read=GetCurrentFrame, write=SetCurrentFrame};
	__property TGLSkeletonColliderList* Colliders = {read=FColliders, write=SetColliders};
	void __fastcall FlushBoneByIDCache();
	TGLSkeletonBone* __fastcall BoneByID(int anID);
	TGLSkeletonBone* __fastcall BoneByName(const System::UnicodeString aName);
	int __fastcall BoneCount();
	void __fastcall MorphTo(int frameIndex)/* overload */;
	void __fastcall MorphTo(TGLSkeletonFrame* frame)/* overload */;
	void __fastcall Lerp(int frameIndex1, int frameIndex2, float lerpFactor);
	void __fastcall BlendedLerps(const TGLBlendedLerpInfo *lerpInfos, const System::NativeInt lerpInfos_High);
	void __fastcall MakeSkeletalTranslationStatic(int startFrame, int endFrame);
	void __fastcall MakeSkeletalRotationDelta(int startFrame, int endFrame);
	void __fastcall MorphMesh(bool normalize);
	void __fastcall Synchronize(TGLSkeleton* reference);
	void __fastcall Clear();
	void __fastcall StartRagdoll();
	void __fastcall StopRagdoll();
	__property bool MorphInvisibleParts = {read=FMorphInvisibleParts, write=FMorphInvisibleParts, nodefault};
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSkeleton(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObject(reader) { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TGLMeshObjectRenderingOption : unsigned char { moroGroupByMaterial };

typedef System::Set<TGLMeshObjectRenderingOption, TGLMeshObjectRenderingOption::moroGroupByMaterial, TGLMeshObjectRenderingOption::moroGroupByMaterial> TGLMeshObjectRenderingOptions;

enum DECLSPEC_DENUM TGLVBOBuffer : unsigned char { vbVertices, vbNormals, vbColors, vbTexCoords, vbLightMapTexCoords, vbTexCoordsEx };

typedef System::Set<TGLVBOBuffer, TGLVBOBuffer::vbVertices, TGLVBOBuffer::vbTexCoordsEx> TGLVBOBuffers;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLMeshObject : public TGLBaseMeshObject
{
	typedef TGLBaseMeshObject inherited;
	
	
private:
	typedef System::DynamicArray<Gls::Context::TGLVBOHandle*> _TGLMeshObject__1;
	
	
private:
	TGLMeshObjectList* FOwner;
	unsigned FExtentCacheRevision;
	Stage::Vectorlists::TGSAffineVectorList* FTexCoords;
	Stage::Vectorlists::TGSAffineVectorList* FLightMapTexCoords;
	Stage::Vectorlists::TGSVectorList* FColors;
	TGLFaceGroups* FFaceGroups;
	TGLMeshObjectMode FMode;
	TGLMeshObjectRenderingOptions FRenderingOptions;
	bool FArraysDeclared;
	bool FLightMapArrayEnabled;
	int FLastLightMapIndex;
	System::Classes::TList* FTexCoordsEx;
	int FBinormalsTexCoordIndex;
	int FTangentsTexCoordIndex;
	unsigned FLastXOpenGLTexMapping;
	bool FUseVBO;
	Gls::Context::TGLVBOHandle* FVerticesVBO;
	Gls::Context::TGLVBOHandle* FNormalsVBO;
	Gls::Context::TGLVBOHandle* FColorsVBO;
	_TGLMeshObject__1 FTexCoordsVBO;
	Gls::Context::TGLVBOHandle* FLightmapTexCoordsVBO;
	TGLVBOBuffers FValidBuffers;
	Stage::Geometrybb::TAABB FExtentCache;
	void __fastcall SetUseVBO(const bool Value);
	void __fastcall SetValidBuffers(TGLVBOBuffers Value);
	
protected:
	void __fastcall SetTexCoords(Stage::Vectorlists::TGSAffineVectorList* const val);
	void __fastcall SetLightmapTexCoords(Stage::Vectorlists::TGSAffineVectorList* const val);
	void __fastcall SetColors(Stage::Vectorlists::TGSVectorList* const val);
	void __fastcall BufferArrays();
	void __fastcall DeclareArraysToOpenGL(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci, bool EvenIfAlreadyDeclared = false);
	void __fastcall DisableOpenGLArrays(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	void __fastcall EnableLightMapArray(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	void __fastcall DisableLightMapArray(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	void __fastcall SetTexCoordsEx(int Index, Stage::Vectorlists::TGSVectorList* const val);
	Stage::Vectorlists::TGSVectorList* __fastcall GetTexCoordsEx(int Index);
	void __fastcall SetBinormals(Stage::Vectorlists::TGSVectorList* const val);
	Stage::Vectorlists::TGSVectorList* __fastcall GetBinormals();
	void __fastcall SetBinormalsTexCoordIndex(const int val);
	void __fastcall SetTangents(Stage::Vectorlists::TGSVectorList* const val);
	Stage::Vectorlists::TGSVectorList* __fastcall GetTangents();
	void __fastcall SetTangentsTexCoordIndex(const int val);
	__property TGLVBOBuffers ValidBuffers = {read=FValidBuffers, write=SetValidBuffers, nodefault};
	
public:
	__fastcall TGLMeshObject(TGLMeshObjectList* AOwner);
	__fastcall virtual TGLMeshObject();
	__fastcall virtual ~TGLMeshObject();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall Clear();
	virtual Stage::Vectorlists::TGSAffineVectorList* __fastcall ExtractTriangles(Stage::Vectorlists::TGSAffineVectorList* texCoords = (Stage::Vectorlists::TGSAffineVectorList*)(0x0), Stage::Vectorlists::TGSAffineVectorList* Normals = (Stage::Vectorlists::TGSAffineVectorList*)(0x0));
	virtual int __fastcall TriangleCount();
	void __fastcall PrepareMaterialLibraryCache(Gls::Material::TGLMaterialLibrary* matLib);
	void __fastcall DropMaterialLibraryCache();
	virtual void __fastcall PrepareBuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	virtual void __fastcall GetExtents(/* out */ Stage::Vectorgeometry::TAffineVector &min, /* out */ Stage::Vectorgeometry::TAffineVector &max)/* overload */;
	virtual void __fastcall GetExtents(/* out */ Stage::Geometrybb::TAABB &aabb)/* overload */;
	Stage::Vectortypes::TGSVector __fastcall GetBarycenter();
	virtual void __fastcall Prepare();
	virtual bool __fastcall PointInObject(const Stage::Vectorgeometry::TAffineVector &aPoint);
	void __fastcall GetTriangleData(int tri, Stage::Vectorlists::TGSAffineVectorList* list, Stage::Vectorgeometry::TAffineVector &v0, Stage::Vectorgeometry::TAffineVector &v1, Stage::Vectorgeometry::TAffineVector &v2)/* overload */;
	void __fastcall GetTriangleData(int tri, Stage::Vectorlists::TGSVectorList* list, Stage::Vectortypes::TGSVector &v0, Stage::Vectortypes::TGSVector &v1, Stage::Vectortypes::TGSVector &v2)/* overload */;
	void __fastcall SetTriangleData(int tri, Stage::Vectorlists::TGSAffineVectorList* list, const Stage::Vectorgeometry::TAffineVector &v0, const Stage::Vectorgeometry::TAffineVector &v1, const Stage::Vectorgeometry::TAffineVector &v2)/* overload */;
	void __fastcall SetTriangleData(int tri, Stage::Vectorlists::TGSVectorList* list, const Stage::Vectortypes::TGSVector &v0, const Stage::Vectortypes::TGSVector &v1, const Stage::Vectortypes::TGSVector &v2)/* overload */;
	void __fastcall BuildTangentSpace(bool buildBinormals = true, bool buildTangents = true);
	__property TGLMeshObjectList* Owner = {read=FOwner};
	__property TGLMeshObjectMode Mode = {read=FMode, write=FMode, nodefault};
	__property Stage::Vectorlists::TGSAffineVectorList* TexCoords = {read=FTexCoords, write=SetTexCoords};
	__property Stage::Vectorlists::TGSAffineVectorList* LightMapTexCoords = {read=FLightMapTexCoords, write=SetLightmapTexCoords};
	__property Stage::Vectorlists::TGSVectorList* Colors = {read=FColors, write=SetColors};
	__property TGLFaceGroups* FaceGroups = {read=FFaceGroups};
	__property TGLMeshObjectRenderingOptions RenderingOptions = {read=FRenderingOptions, write=FRenderingOptions, nodefault};
	__property bool UseVBO = {read=FUseVBO, write=SetUseVBO, nodefault};
	__property Stage::Vectorlists::TGSVectorList* TexCoordsEx[int index] = {read=GetTexCoordsEx, write=SetTexCoordsEx};
	__property Stage::Vectorlists::TGSVectorList* Binormals = {read=GetBinormals, write=SetBinormals};
	__property Stage::Vectorlists::TGSVectorList* Tangents = {read=GetTangents, write=SetTangents};
	__property int BinormalsTexCoordIndex = {read=FBinormalsTexCoordIndex, write=SetBinormalsTexCoordIndex, nodefault};
	__property int TangentsTexCoordIndex = {read=FTangentsTexCoordIndex, write=SetTangentsTexCoordIndex, nodefault};
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLMeshObject(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLBaseMeshObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLMeshObjectList : public Stage::Persistentclasses::TGSPersistentObjectList
{
	typedef Stage::Persistentclasses::TGSPersistentObjectList inherited;
	
public:
	TGLMeshObject* operator[](int Index) { return this->Items[Index]; }
	
private:
	TGLBaseMesh* FOwner;
	bool __fastcall GetUseVBO();
	void __fastcall SetUseVBO(const bool Value);
	
protected:
	TGLMeshObject* __fastcall GetMeshObject(int Index);
	
public:
	__fastcall TGLMeshObjectList(TGLBaseMesh* aOwner);
	__fastcall virtual ~TGLMeshObjectList();
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	void __fastcall PrepareMaterialLibraryCache(Gls::Material::TGLMaterialLibrary* matLib);
	void __fastcall DropMaterialLibraryCache();
	virtual void __fastcall PrepareBuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	void __fastcall MorphTo(int morphTargetIndex);
	void __fastcall Lerp(int morphTargetIndex1, int morphTargetIndex2, float lerpFactor);
	int __fastcall MorphTargetCount();
	void __fastcall GetExtents(/* out */ Stage::Vectorgeometry::TAffineVector &min, /* out */ Stage::Vectorgeometry::TAffineVector &max);
	void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta);
	Stage::Vectorlists::TGSAffineVectorList* __fastcall ExtractTriangles(Stage::Vectorlists::TGSAffineVectorList* texCoords = (Stage::Vectorlists::TGSAffineVectorList*)(0x0), Stage::Vectorlists::TGSAffineVectorList* normals = (Stage::Vectorlists::TGSAffineVectorList*)(0x0));
	int __fastcall TriangleCount();
	float __fastcall Area();
	float __fastcall Volume();
	void __fastcall BuildTangentSpace(bool buildBinormals = true, bool buildTangents = true);
	__property bool UseVBO = {read=GetUseVBO, write=SetUseVBO, nodefault};
	virtual void __fastcall Prepare();
	TGLMeshObject* __fastcall FindMeshByName(const System::UnicodeString MeshName);
	__property TGLBaseMesh* Owner = {read=FOwner};
	virtual void __fastcall Clear();
	__property TGLMeshObject* Items[int Index] = {read=GetMeshObject/*, default*/};
public:
	/* TGSPersistentObjectList.Create */ inline __fastcall virtual TGLMeshObjectList() : Stage::Persistentclasses::TGSPersistentObjectList() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLMeshObjectList(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TGLMeshObjectListClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLMeshMorphTarget : public TGLBaseMeshObject
{
	typedef TGLBaseMeshObject inherited;
	
private:
	TGLMeshMorphTargetList* FOwner;
	
public:
	__fastcall TGLMeshMorphTarget(TGLMeshMorphTargetList* aOwner);
	__fastcall virtual ~TGLMeshMorphTarget();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	__property TGLMeshMorphTargetList* Owner = {read=FOwner};
public:
	/* TGLBaseMeshObject.Create */ inline __fastcall virtual TGLMeshMorphTarget() : TGLBaseMeshObject() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLMeshMorphTarget(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLBaseMeshObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLMeshMorphTargetList : public Stage::Persistentclasses::TGSPersistentObjectList
{
	typedef Stage::Persistentclasses::TGSPersistentObjectList inherited;
	
public:
	TGLMeshMorphTarget* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	TGLMeshMorphTarget* __fastcall GeTGLMeshMorphTarget(int Index);
	
public:
	__fastcall TGLMeshMorphTargetList(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TGLMeshMorphTargetList();
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta);
	__property System::Classes::TPersistent* Owner = {read=FOwner};
	virtual void __fastcall Clear();
	__property TGLMeshMorphTarget* Items[int Index] = {read=GeTGLMeshMorphTarget/*, default*/};
public:
	/* TGSPersistentObjectList.Create */ inline __fastcall virtual TGLMeshMorphTargetList() : Stage::Persistentclasses::TGSPersistentObjectList() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLMeshMorphTargetList(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLMorphableMeshObject : public TGLMeshObject
{
	typedef TGLMeshObject inherited;
	
private:
	TGLMeshMorphTargetList* FMorphTargets;
	
public:
	__fastcall virtual TGLMorphableMeshObject();
	__fastcall virtual ~TGLMorphableMeshObject();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall Clear();
	virtual void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta);
	virtual void __fastcall MorphTo(int morphTargetIndex);
	virtual void __fastcall Lerp(int morphTargetIndex1, int morphTargetIndex2, float lerpFactor);
	__property TGLMeshMorphTargetList* MorphTargets = {read=FMorphTargets};
public:
	/* TGLMeshObject.CreateOwned */ inline __fastcall TGLMorphableMeshObject(TGLMeshObjectList* AOwner) : TGLMeshObject(AOwner) { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLMorphableMeshObject(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLMeshObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGLVertexBoneWeight
{
public:
	int BoneID;
	float weight;
};
#pragma pack(pop)


typedef System::StaticArray<TGLVertexBoneWeight, 134217728> TGLVertexBoneWeightArray;

typedef TGLVertexBoneWeightArray *PGLVertexBoneWeightArray;

typedef System::StaticArray<PGLVertexBoneWeightArray, 268435456> TGLVerticesBoneWeights;

typedef TGLVerticesBoneWeights *PGLVerticesBoneWeights;

typedef System::DynamicArray<TGLVertexBoneWeight> TGLVertexBoneWeightDynArray;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSkeletonMeshObject : public TGLMorphableMeshObject
{
	typedef TGLMorphableMeshObject inherited;
	
private:
	PGLVerticesBoneWeights FVerticesBonesWeights;
	int FVerticeBoneWeightCount;
	int FVerticeBoneWeightCapacity;
	int FBonesPerVertex;
	int FLastVerticeBoneWeightCount;
	int FLastBonesPerVertex;
	System::Classes::TList* FBoneMatrixInvertedMeshes;
	System::Classes::TList* FBackupInvertedMeshes;
	void __fastcall BackupBoneMatrixInvertedMeshes();
	void __fastcall RestoreBoneMatrixInvertedMeshes();
	
protected:
	void __fastcall SetVerticeBoneWeightCount(const int val);
	void __fastcall SetVerticeBoneWeightCapacity(const int val);
	void __fastcall SetBonesPerVertex(const int val);
	void __fastcall ResizeVerticesBonesWeights();
	
public:
	__fastcall virtual TGLSkeletonMeshObject();
	__fastcall virtual ~TGLSkeletonMeshObject();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall Clear();
	__property PGLVerticesBoneWeights VerticesBonesWeights = {read=FVerticesBonesWeights};
	__property int VerticeBoneWeightCount = {read=FVerticeBoneWeightCount, write=SetVerticeBoneWeightCount, nodefault};
	__property int VerticeBoneWeightCapacity = {read=FVerticeBoneWeightCapacity, write=SetVerticeBoneWeightCapacity, nodefault};
	__property int BonesPerVertex = {read=FBonesPerVertex, write=SetBonesPerVertex, nodefault};
	int __fastcall FindOrAdd(int BoneID, const Stage::Vectorgeometry::TAffineVector &vertex, const Stage::Vectorgeometry::TAffineVector &normal)/* overload */;
	int __fastcall FindOrAdd(const TGLVertexBoneWeightDynArray boneIDs, const Stage::Vectorgeometry::TAffineVector &vertex, const Stage::Vectorgeometry::TAffineVector &normal)/* overload */;
	void __fastcall AddWeightedBone(int aBoneID, float aWeight);
	void __fastcall AddWeightedBones(const TGLVertexBoneWeightDynArray boneIDs);
	void __fastcall PrepareBoneMatrixInvertedMeshes();
	void __fastcall ApplyCurrentSkeletonFrame(bool normalize);
public:
	/* TGLMeshObject.CreateOwned */ inline __fastcall TGLSkeletonMeshObject(TGLMeshObjectList* AOwner) : TGLMorphableMeshObject(AOwner) { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLSkeletonMeshObject(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLMorphableMeshObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLFaceGroup : public Stage::Persistentclasses::TGSPersistentObject
{
	typedef Stage::Persistentclasses::TGSPersistentObject inherited;
	
private:
	TGLFaceGroups* FOwner;
	System::UnicodeString FMaterialName;
	Gls::Material::TGLLibMaterial* FMaterialCache;
	int FLightMapIndex;
	int FRenderGroupID;
	
protected:
	void __fastcall AttachLightmap(Gls::Texture::TGLTexture* lightMap, Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	void __fastcall AttachOrDetachLightmap(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	
public:
	__fastcall virtual TGLFaceGroup(TGLFaceGroups* aOwner);
	__fastcall virtual ~TGLFaceGroup();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	void __fastcall PrepareMaterialLibraryCache(Gls::Material::TGLMaterialLibrary* matLib);
	void __fastcall DropMaterialLibraryCache();
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci) = 0 ;
	virtual void __fastcall AddToTriangles(Stage::Vectorlists::TGSAffineVectorList* aList, Stage::Vectorlists::TGSAffineVectorList* aTexCoords = (Stage::Vectorlists::TGSAffineVectorList*)(0x0), Stage::Vectorlists::TGSAffineVectorList* aNormals = (Stage::Vectorlists::TGSAffineVectorList*)(0x0));
	virtual int __fastcall TriangleCount() = 0 ;
	virtual void __fastcall Reverse();
	virtual void __fastcall Prepare();
	__property TGLFaceGroups* Owner = {read=FOwner, write=FOwner};
	__property System::UnicodeString MaterialName = {read=FMaterialName, write=FMaterialName};
	__property Gls::Material::TGLLibMaterial* MaterialCache = {read=FMaterialCache};
	__property int LightMapIndex = {read=FLightMapIndex, write=FLightMapIndex, nodefault};
public:
	/* TGSPersistentObject.Create */ inline __fastcall virtual TGLFaceGroup() : Stage::Persistentclasses::TGSPersistentObject() { }
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLFaceGroup(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObject(reader) { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TGLFaceGroupMeshMode : unsigned char { fgmmTriangles, fgmmTriangleStrip, fgmmFlatTriangles, fgmmTriangleFan, fgmmQuads };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFGVertexIndexList : public TGLFaceGroup
{
	typedef TGLFaceGroup inherited;
	
private:
	Stage::Vectorlists::TGSIntegerList* FVertexIndices;
	Gls::Context::TGLVBOElementArrayHandle* FIndexVBO;
	TGLFaceGroupMeshMode FMode;
	void __fastcall SetupVBO();
	void __fastcall InvalidateVBO();
	
protected:
	void __fastcall SetVertexIndices(Stage::Vectorlists::TGSIntegerList* const val);
	void __fastcall AddToList(Stage::Vectorlists::TGSAffineVectorList* Source, Stage::Vectorlists::TGSAffineVectorList* destination, Stage::Vectorlists::TGSIntegerList* indices);
	
public:
	__fastcall virtual TFGVertexIndexList();
	__fastcall virtual ~TFGVertexIndexList();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	virtual void __fastcall AddToTriangles(Stage::Vectorlists::TGSAffineVectorList* aList, Stage::Vectorlists::TGSAffineVectorList* aTexCoords = (Stage::Vectorlists::TGSAffineVectorList*)(0x0), Stage::Vectorlists::TGSAffineVectorList* aNormals = (Stage::Vectorlists::TGSAffineVectorList*)(0x0));
	virtual int __fastcall TriangleCount();
	virtual void __fastcall Reverse();
	void __fastcall Add(int idx);
	void __fastcall GetExtents(Stage::Vectorgeometry::TAffineVector &min, Stage::Vectorgeometry::TAffineVector &max);
	void __fastcall ConvertToList();
	Stage::Vectorgeometry::TAffineVector __fastcall GetNormal();
	__property TGLFaceGroupMeshMode Mode = {read=FMode, write=FMode, nodefault};
	__property Stage::Vectorlists::TGSIntegerList* VertexIndices = {read=FVertexIndices, write=SetVertexIndices};
public:
	/* TGLFaceGroup.CreateOwned */ inline __fastcall virtual TFGVertexIndexList(TGLFaceGroups* aOwner) : TGLFaceGroup(aOwner) { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TFGVertexIndexList(Stage::Persistentclasses::TGSVirtualReader* reader) : TGLFaceGroup(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFGVertexNormalTexIndexList : public TFGVertexIndexList
{
	typedef TFGVertexIndexList inherited;
	
private:
	Stage::Vectorlists::TGSIntegerList* FNormalIndices;
	Stage::Vectorlists::TGSIntegerList* FTexCoordIndices;
	
protected:
	void __fastcall SetNormalIndices(Stage::Vectorlists::TGSIntegerList* const val);
	void __fastcall SetTexCoordIndices(Stage::Vectorlists::TGSIntegerList* const val);
	
public:
	__fastcall virtual TFGVertexNormalTexIndexList();
	__fastcall virtual ~TFGVertexNormalTexIndexList();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	virtual void __fastcall AddToTriangles(Stage::Vectorlists::TGSAffineVectorList* aList, Stage::Vectorlists::TGSAffineVectorList* aTexCoords = (Stage::Vectorlists::TGSAffineVectorList*)(0x0), Stage::Vectorlists::TGSAffineVectorList* aNormals = (Stage::Vectorlists::TGSAffineVectorList*)(0x0));
	HIDESBASE void __fastcall Add(int vertexIdx, int normalIdx, int texCoordIdx);
	__property Stage::Vectorlists::TGSIntegerList* NormalIndices = {read=FNormalIndices, write=SetNormalIndices};
	__property Stage::Vectorlists::TGSIntegerList* TexCoordIndices = {read=FTexCoordIndices, write=SetTexCoordIndices};
public:
	/* TGLFaceGroup.CreateOwned */ inline __fastcall virtual TFGVertexNormalTexIndexList(TGLFaceGroups* aOwner) : TFGVertexIndexList(aOwner) { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TFGVertexNormalTexIndexList(Stage::Persistentclasses::TGSVirtualReader* reader) : TFGVertexIndexList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFGIndexTexCoordList : public TFGVertexIndexList
{
	typedef TFGVertexIndexList inherited;
	
private:
	Stage::Vectorlists::TGSAffineVectorList* FTexCoords;
	
protected:
	void __fastcall SetTexCoords(Stage::Vectorlists::TGSAffineVectorList* const val);
	
public:
	__fastcall virtual TFGIndexTexCoordList();
	__fastcall virtual ~TFGIndexTexCoordList();
	DYNAMIC void __fastcall WriteToFiler(Stage::Persistentclasses::TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	virtual void __fastcall AddToTriangles(Stage::Vectorlists::TGSAffineVectorList* aList, Stage::Vectorlists::TGSAffineVectorList* aTexCoords = (Stage::Vectorlists::TGSAffineVectorList*)(0x0), Stage::Vectorlists::TGSAffineVectorList* aNormals = (Stage::Vectorlists::TGSAffineVectorList*)(0x0));
	HIDESBASE void __fastcall Add(int idx, const Stage::Vectorgeometry::TAffineVector &texCoord)/* overload */;
	HIDESBASE void __fastcall Add(int idx, const float s, const float t)/* overload */;
	__property Stage::Vectorlists::TGSAffineVectorList* TexCoords = {read=FTexCoords, write=SetTexCoords};
public:
	/* TGLFaceGroup.CreateOwned */ inline __fastcall virtual TFGIndexTexCoordList(TGLFaceGroups* aOwner) : TFGVertexIndexList(aOwner) { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TFGIndexTexCoordList(Stage::Persistentclasses::TGSVirtualReader* reader) : TFGVertexIndexList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLFaceGroups : public Stage::Persistentclasses::TGSPersistentObjectList
{
	typedef Stage::Persistentclasses::TGSPersistentObjectList inherited;
	
public:
	TGLFaceGroup* operator[](int Index) { return this->Items[Index]; }
	
private:
	TGLMeshObject* FOwner;
	
protected:
	TGLFaceGroup* __fastcall GetFaceGroup(int Index);
	
public:
	__fastcall TGLFaceGroups(TGLMeshObject* aOwner);
	__fastcall virtual ~TGLFaceGroups();
	DYNAMIC void __fastcall ReadFromFiler(Stage::Persistentclasses::TGSVirtualReader* reader);
	void __fastcall PrepareMaterialLibraryCache(Gls::Material::TGLMaterialLibrary* matLib);
	void __fastcall DropMaterialLibraryCache();
	__property TGLMeshObject* Owner = {read=FOwner};
	virtual void __fastcall Clear();
	__property TGLFaceGroup* Items[int Index] = {read=GetFaceGroup/*, default*/};
	void __fastcall AddToTriangles(Stage::Vectorlists::TGSAffineVectorList* aList, Stage::Vectorlists::TGSAffineVectorList* aTexCoords = (Stage::Vectorlists::TGSAffineVectorList*)(0x0), Stage::Vectorlists::TGSAffineVectorList* aNormals = (Stage::Vectorlists::TGSAffineVectorList*)(0x0));
	Gls::Material::TGLMaterialLibrary* __fastcall MaterialLibrary();
	void __fastcall SortByMaterial();
public:
	/* TGSPersistentObjectList.Create */ inline __fastcall virtual TGLFaceGroups() : Stage::Persistentclasses::TGSPersistentObjectList() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLFaceGroups(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TGLMeshNormalsOrientation : unsigned char { mnoDefault, mnoInvert };

class PASCALIMPLEMENTATION TGLVectorFile : public Gls::Applicationfileio::TGSDataFile
{
	typedef Gls::Applicationfileio::TGSDataFile inherited;
	
private:
	TGLMeshNormalsOrientation FNormalsOrientation;
	
protected:
	virtual void __fastcall SetNormalsOrientation(const TGLMeshNormalsOrientation val);
	
public:
	__fastcall virtual TGLVectorFile(System::Classes::TPersistent* AOwner);
	HIDESBASE TGLBaseMesh* __fastcall Owner();
	__property TGLMeshNormalsOrientation NormalsOrientation = {read=FNormalsOrientation, write=SetNormalsOrientation, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGLVectorFile() { }
	
};


typedef System::TMetaClass* TGLVectorFileClass;

class PASCALIMPLEMENTATION TGLSMVectorFile : public TGLVectorFile
{
	typedef TGLVectorFile inherited;
	
public:
	__classmethod virtual Gls::Applicationfileio::TGSDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* aStream);
public:
	/* TGLVectorFile.Create */ inline __fastcall virtual TGLSMVectorFile(System::Classes::TPersistent* AOwner) : TGLVectorFile(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGLSMVectorFile() { }
	
};


class PASCALIMPLEMENTATION TGLBaseMesh : public Gls::Scene::TGLSceneObject
{
	typedef Gls::Scene::TGLSceneObject inherited;
	
private:
	TGLMeshNormalsOrientation FNormalsOrientation;
	Gls::Material::TGLMaterialLibrary* FMaterialLibrary;
	Gls::Material::TGLMaterialLibrary* FLightmapLibrary;
	Stage::Vectortypes::TGSVector FAxisAlignedDimensionsCache;
	bool FBaryCenterOffsetChanged;
	Stage::Vectortypes::TGSVector FBaryCenterOffset;
	bool FUseMeshMaterials;
	bool FOverlaySkeleton;
	bool FIgnoreMissingTextures;
	TGLMeshAutoCenterings FAutoCentering;
	Stage::Coordinates::TGSCoordinates* FAutoScaling;
	bool FMaterialLibraryCachesPrepared;
	System::TObject* FConnectivity;
	System::UnicodeString FLastLoadedFilename;
	
protected:
	TGLMeshObjectList* FMeshObjects;
	TGLSkeleton* FSkeleton;
	void __fastcall SetUseMeshMaterials(const bool val);
	void __fastcall SetMaterialLibrary(Gls::Material::TGLMaterialLibrary* const val);
	void __fastcall SetLightmapLibrary(Gls::Material::TGLMaterialLibrary* const val);
	void __fastcall SetNormalsOrientation(const TGLMeshNormalsOrientation val);
	void __fastcall SetOverlaySkeleton(const bool val);
	void __fastcall SetAutoScaling(Stage::Coordinates::TGSCoordinates* const Value);
	virtual void __fastcall DestroyHandle();
	virtual void __fastcall PrepareVectorFile(TGLVectorFile* aFile);
	virtual void __fastcall PrepareMesh();
	void __fastcall PrepareMaterialLibraryCache();
	void __fastcall DropMaterialLibraryCache();
	virtual void __fastcall PrepareBuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	
public:
	__fastcall virtual TGLBaseMesh(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLBaseMesh();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual Stage::Vectortypes::TGSVector __fastcall AxisAlignedDimensionsUnscaled();
	Stage::Vectortypes::TGSVector __fastcall BarycenterOffset();
	Stage::Vectortypes::TGSVector __fastcall BarycenterPosition();
	virtual Stage::Vectortypes::TGSVector __fastcall BarycenterAbsolutePosition();
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall DoRender(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall StructureChanged();
	void __fastcall StructureChangedNoPrepare();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TGSVector &rayStart, const Stage::Vectortypes::TGSVector &rayVector, Stage::Vectortypes::PGSVector intersectPoint = (Stage::Vectortypes::PGSVector)(0x0), Stage::Vectortypes::PGSVector intersectNormal = (Stage::Vectortypes::PGSVector)(0x0));
	virtual Stage::Silhouette::TGSSilhouette* __fastcall GenerateSilhouette(const Stage::Silhouette::TGSSilhouetteParameters &silhouetteParameters);
	void __fastcall BuildSilhouetteConnectivityData();
	__property TGLMeshObjectList* MeshObjects = {read=FMeshObjects};
	__property TGLSkeleton* Skeleton = {read=FSkeleton};
	void __fastcall GetExtents(/* out */ Stage::Vectorgeometry::TAffineVector &min, /* out */ Stage::Vectorgeometry::TAffineVector &max);
	Stage::Vectorgeometry::TAffineVector __fastcall GetBarycenter();
	virtual void __fastcall PerformAutoCentering();
	virtual void __fastcall PerformAutoScaling();
	virtual void __fastcall LoadFromFile(const System::UnicodeString filename);
	virtual void __fastcall LoadFromStream(const System::UnicodeString filename, System::Classes::TStream* aStream);
	virtual void __fastcall SaveToFile(const System::UnicodeString filename);
	virtual void __fastcall SaveToStream(const System::UnicodeString filename, System::Classes::TStream* aStream);
	virtual void __fastcall AddDataFromFile(const System::UnicodeString filename);
	virtual void __fastcall AddDataFromStream(const System::UnicodeString filename, System::Classes::TStream* aStream);
	System::UnicodeString __fastcall LastLoadedFilename();
	__property TGLMeshAutoCenterings AutoCentering = {read=FAutoCentering, write=FAutoCentering, default=0};
	__property Stage::Coordinates::TGSCoordinates* AutoScaling = {read=FAutoScaling, write=FAutoScaling};
	__property Gls::Material::TGLMaterialLibrary* MaterialLibrary = {read=FMaterialLibrary, write=SetMaterialLibrary};
	__property bool UseMeshMaterials = {read=FUseMeshMaterials, write=SetUseMeshMaterials, default=1};
	__property Gls::Material::TGLMaterialLibrary* LightmapLibrary = {read=FLightmapLibrary, write=SetLightmapLibrary};
	__property bool IgnoreMissingTextures = {read=FIgnoreMissingTextures, write=FIgnoreMissingTextures, default=0};
	__property TGLMeshNormalsOrientation NormalsOrientation = {read=FNormalsOrientation, write=SetNormalsOrientation, default=0};
	__property bool OverlaySkeleton = {read=FOverlaySkeleton, write=SetOverlaySkeleton, default=0};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLBaseMesh(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLFreeForm : public TGLBaseMesh
{
	typedef TGLBaseMesh inherited;
	
private:
	Gls::Octree::TGLOctree* FOctree;
	
public:
	__fastcall virtual TGLFreeForm(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TGLFreeForm();
	bool __fastcall OctreeRayCastIntersect(const Stage::Vectortypes::TGSVector &rayStart, const Stage::Vectortypes::TGSVector &rayVector, Stage::Vectortypes::PGSVector intersectPoint = (Stage::Vectortypes::PGSVector)(0x0), Stage::Vectortypes::PGSVector intersectNormal = (Stage::Vectortypes::PGSVector)(0x0));
	bool __fastcall OctreeSphereSweepIntersect(const Stage::Vectortypes::TGSVector &rayStart, const Stage::Vectortypes::TGSVector &rayVector, const float velocity, const float radius, Stage::Vectortypes::PGSVector intersectPoint = (Stage::Vectortypes::PGSVector)(0x0), Stage::Vectortypes::PGSVector intersectNormal = (Stage::Vectortypes::PGSVector)(0x0));
	bool __fastcall OctreeTriangleIntersect(const Stage::Vectorgeometry::TAffineVector &v1, const Stage::Vectorgeometry::TAffineVector &v2, const Stage::Vectorgeometry::TAffineVector &v3);
	bool __fastcall OctreePointInMesh(const Stage::Vectortypes::TGSVector &Point);
	bool __fastcall OctreeAABBIntersect(const Stage::Geometrybb::TAABB &AABB, const Stage::Vectortypes::TGSMatrix &objMatrix, const Stage::Vectortypes::TGSMatrix &invObjMatrix, Stage::Vectorlists::TGSAffineVectorList* triangles = (Stage::Vectorlists::TGSAffineVectorList*)(0x0));
	__property Gls::Octree::TGLOctree* Octree = {read=FOctree};
	void __fastcall BuildOctree(int TreeDepth = 0x3);
	
__published:
	__property AutoCentering = {default=0};
	__property AutoScaling;
	__property MaterialLibrary;
	__property LightmapLibrary;
	__property UseMeshMaterials = {default=1};
	__property NormalsOrientation = {default=0};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLFreeForm(Gls::Scene::TGLBaseSceneObject* aParentOwner) : TGLBaseMesh(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TGLActorOption : unsigned char { aoSkeletonNormalizeNormals };

typedef System::Set<TGLActorOption, TGLActorOption::aoSkeletonNormalizeNormals, TGLActorOption::aoSkeletonNormalizeNormals> TGLActorOptions;

enum DECLSPEC_DENUM TGLActorAnimationReference : unsigned char { aarMorph, aarSkeleton, aarNone };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLActorAnimation : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FName;
	int FStartFrame;
	int FEndFrame;
	TGLActorAnimationReference FReference;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	int __fastcall FrameCount();
	void __fastcall SetStartFrame(const int val);
	void __fastcall SetEndFrame(const int val);
	void __fastcall SetReference(TGLActorAnimationReference val);
	void __fastcall SetAsString(const System::UnicodeString val);
	System::UnicodeString __fastcall GetAsString();
	
public:
	__fastcall virtual TGLActorAnimation(System::Classes::TCollection* Collection);
	__fastcall virtual ~TGLActorAnimation();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::UnicodeString AsString = {read=GetAsString, write=SetAsString};
	TGLActor* __fastcall OwnerActor();
	void __fastcall MakeSkeletalTranslationStatic();
	void __fastcall MakeSkeletalRotationDelta();
	
__published:
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property int StartFrame = {read=FStartFrame, write=SetStartFrame, nodefault};
	__property int EndFrame = {read=FEndFrame, write=SetEndFrame, nodefault};
	__property TGLActorAnimationReference Reference = {read=FReference, write=SetReference, default=0};
};

#pragma pack(pop)

typedef System::UnicodeString TGLActorAnimationName;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLActorAnimations : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TGLActorAnimation* operator[](int index) { return this->Items[index]; }
	
private:
	TGLActor* FOwner;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	void __fastcall SetItems(int Index, TGLActorAnimation* const val);
	TGLActorAnimation* __fastcall GetItems(int Index);
	
public:
	__fastcall TGLActorAnimations(TGLActor* AOwner);
	HIDESBASE TGLActorAnimation* __fastcall Add();
	HIDESBASE TGLActorAnimation* __fastcall FindItemID(int ID);
	TGLActorAnimation* __fastcall FindName(const System::UnicodeString aName);
	TGLActorAnimation* __fastcall FindFrame(int aFrame, TGLActorAnimationReference aReference);
	void __fastcall SetToStrings(System::Classes::TStrings* aStrings);
	void __fastcall SaveToStream(System::Classes::TStream* aStream);
	void __fastcall LoadFromStream(System::Classes::TStream* aStream);
	void __fastcall SaveToFile(const System::UnicodeString fileName);
	void __fastcall LoadFromFile(const System::UnicodeString fileName);
	__property TGLActorAnimation* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	TGLActorAnimation* __fastcall Last();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TGLActorAnimations() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLBaseAnimationControler : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FEnabled;
	TGLActor* FActor;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetEnabled(const bool val);
	void __fastcall SetActor(TGLActor* const val);
	virtual void __fastcall DoChange();
	virtual bool __fastcall Apply(TGLBlendedLerpInfo &lerpInfo);
	
public:
	__fastcall virtual TGLBaseAnimationControler(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLBaseAnimationControler();
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property TGLActor* Actor = {read=FActor, write=SetActor};
};


class PASCALIMPLEMENTATION TGLAnimationControler : public TGLBaseAnimationControler
{
	typedef TGLBaseAnimationControler inherited;
	
private:
	TGLActorAnimationName FAnimationName;
	float FRatio;
	
protected:
	void __fastcall SetAnimationName(const TGLActorAnimationName val);
	void __fastcall SetRatio(const float val);
	virtual void __fastcall DoChange();
	virtual bool __fastcall Apply(TGLBlendedLerpInfo &lerpInfo);
	
__published:
	__property System::UnicodeString AnimationName = {read=FAnimationName, write=SetAnimationName};
	__property float Ratio = {read=FRatio, write=SetRatio};
public:
	/* TGLBaseAnimationControler.Create */ inline __fastcall virtual TGLAnimationControler(System::Classes::TComponent* AOwner) : TGLBaseAnimationControler(AOwner) { }
	/* TGLBaseAnimationControler.Destroy */ inline __fastcall virtual ~TGLAnimationControler() { }
	
};


enum DECLSPEC_DENUM TGLActorFrameInterpolation : unsigned char { afpNone, afpLinear };

enum DECLSPEC_DENUM TGLActorAnimationMode : unsigned char { aamNone, aamPlayOnce, aamLoop, aamBounceForward, aamBounceBackward, aamLoopBackward, aamExternal };

class PASCALIMPLEMENTATION TGLActor : public TGLBaseMesh
{
	typedef TGLBaseMesh inherited;
	
private:
	int FStartFrame;
	int FEndFrame;
	TGLActorAnimationReference FReference;
	int FCurrentFrame;
	float FCurrentFrameDelta;
	TGLActorFrameInterpolation FFrameInterpolation;
	int FInterval;
	TGLActorAnimationMode FAnimationMode;
	System::Classes::TNotifyEvent FOnFrameChanged;
	System::Classes::TNotifyEvent FOnEndFrameReached;
	System::Classes::TNotifyEvent FOnStartFrameReached;
	TGLActorAnimations* FAnimations;
	TGLActorAnimation* FTargetSmoothAnimation;
	System::Classes::TList* FControlers;
	TGLActorOptions FOptions;
	
protected:
	void __fastcall SetCurrentFrame(int val);
	void __fastcall SetStartFrame(int val);
	void __fastcall SetEndFrame(int val);
	HIDESBASE void __fastcall SetReference(TGLActorAnimationReference val);
	void __fastcall SetAnimations(TGLActorAnimations* const val);
	bool __fastcall StoreAnimations();
	void __fastcall SetOptions(const TGLActorOptions val);
	virtual void __fastcall PrepareMesh();
	virtual void __fastcall PrepareBuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &mrci);
	virtual void __fastcall DoAnimate();
	void __fastcall RegisterControler(TGLBaseAnimationControler* aControler);
	void __fastcall UnRegisterControler(TGLBaseAnimationControler* aControler);
	
public:
	__fastcall virtual TGLActor(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TGLActor();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall DoProgress(const Stage::Baseclasses::TGSProgressTimes &progressTime);
	virtual void __fastcall LoadFromStream(const System::UnicodeString filename, System::Classes::TStream* aStream);
	void __fastcall SwitchToAnimation(TGLActorAnimation* anAnimation, bool smooth = false)/* overload */;
	void __fastcall SwitchToAnimation(const System::UnicodeString AnimationName, bool smooth = false)/* overload */;
	void __fastcall SwitchToAnimation(int animationIndex, bool smooth = false)/* overload */;
	System::UnicodeString __fastcall CurrentAnimation();
	void __fastcall Synchronize(TGLActor* referenceActor);
	void __fastcall SetCurrentFrameDirect(const int Value);
	int __fastcall NextFrameIndex();
	void __fastcall NextFrame(int nbSteps = 0x1);
	void __fastcall PrevFrame(int nbSteps = 0x1);
	int __fastcall FrameCount();
	bool __fastcall isSwitchingAnimation();
	
__published:
	__property int StartFrame = {read=FStartFrame, write=SetStartFrame, default=0};
	__property int EndFrame = {read=FEndFrame, write=SetEndFrame, default=0};
	__property TGLActorAnimationReference Reference = {read=FReference, write=FReference, default=0};
	__property int CurrentFrame = {read=FCurrentFrame, write=SetCurrentFrame, default=0};
	__property float CurrentFrameDelta = {read=FCurrentFrameDelta, write=FCurrentFrameDelta};
	__property TGLActorFrameInterpolation FrameInterpolation = {read=FFrameInterpolation, write=FFrameInterpolation, default=1};
	__property TGLActorAnimationMode AnimationMode = {read=FAnimationMode, write=FAnimationMode, default=0};
	__property int Interval = {read=FInterval, write=FInterval, nodefault};
	__property TGLActorOptions Options = {read=FOptions, write=SetOptions, default=1};
	__property System::Classes::TNotifyEvent OnFrameChanged = {read=FOnFrameChanged, write=FOnFrameChanged};
	__property System::Classes::TNotifyEvent OnEndFrameReached = {read=FOnEndFrameReached, write=FOnEndFrameReached};
	__property System::Classes::TNotifyEvent OnStartFrameReached = {read=FOnStartFrameReached, write=FOnStartFrameReached};
	__property TGLActorAnimations* Animations = {read=FAnimations, write=SetAnimations, stored=StoreAnimations};
	__property AutoCentering = {default=0};
	__property MaterialLibrary;
	__property LightmapLibrary;
	__property UseMeshMaterials = {default=1};
	__property NormalsOrientation = {default=0};
	__property OverlaySkeleton = {default=0};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLActor(Gls::Scene::TGLBaseSceneObject* aParentOwner) : TGLBaseMesh(aParentOwner) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVectorFileFormat : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TGLVectorFileClass VectorFileClass;
	System::UnicodeString Extension;
	System::UnicodeString Description;
	int DescResID;
public:
	/* TObject.Create */ inline __fastcall TGLVectorFileFormat() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TGLVectorFileFormat() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVectorFileFormatsList : public Stage::Persistentclasses::TGSPersistentObjectList
{
	typedef Stage::Persistentclasses::TGSPersistentObjectList inherited;
	
public:
	__fastcall virtual ~TGLVectorFileFormatsList();
	HIDESBASE void __fastcall Add(const System::UnicodeString Ext, const System::UnicodeString Desc, int DescID, TGLVectorFileClass AClass);
	TGLVectorFileClass __fastcall FindExt(System::UnicodeString Ext);
	TGLVectorFileClass __fastcall FindFromFileName(const System::UnicodeString filename);
	HIDESBASE void __fastcall Remove(TGLVectorFileClass AClass);
	void __fastcall BuildFilterStrings(TGLVectorFileClass vectorFileClass, /* out */ System::UnicodeString &descriptions, /* out */ System::UnicodeString &filters, bool formatsThatCanBeOpened = true, bool formatsThatCanBeSaved = false);
	System::UnicodeString __fastcall FindExtByIndex(int index, bool formatsThatCanBeOpened = true, bool formatsThatCanBeSaved = false);
public:
	/* TGSPersistentObjectList.Create */ inline __fastcall virtual TGLVectorFileFormatsList() : Stage::Persistentclasses::TGSPersistentObjectList() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGLVectorFileFormatsList(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EInvalidVectorFile : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EInvalidVectorFile(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EInvalidVectorFile(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidVectorFile(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidVectorFile(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidVectorFile(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidVectorFile(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EInvalidVectorFile(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidVectorFile(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidVectorFile(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidVectorFile(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidVectorFile(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidVectorFile(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EInvalidVectorFile() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define cDefaultActorOptions (System::Set<TGLActorOption, TGLActorOption::aoSkeletonNormalizeNormals, TGLActorOption::aoSkeletonNormalizeNormals>() << TGLActorOption::aoSkeletonNormalizeNormals )
extern DELPHI_PACKAGE bool vGLVectorFileObjectsAllocateMaterials;
extern DELPHI_PACKAGE bool vGLVectorFileObjectsEnableVBOByDefault;
extern DELPHI_PACKAGE TGLVectorFileFormatsList* __fastcall GetVectorFileFormats(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall VectorFileFormatsFilter(void);
extern DELPHI_PACKAGE System::UnicodeString __fastcall VectorFileFormatsSaveFilter(void);
extern DELPHI_PACKAGE void __fastcall RegisterVectorFileFormat(const System::UnicodeString aExtension, const System::UnicodeString aDescription, TGLVectorFileClass AClass);
extern DELPHI_PACKAGE void __fastcall UnregisterVectorFileClass(TGLVectorFileClass AClass);
extern DELPHI_PACKAGE System::UnicodeString __fastcall VectorFileFormatExtensionByIndex(int Index);
}	/* namespace Vectorfileobjects */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_VECTORFILEOBJECTS)
using namespace Gls::Vectorfileobjects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_VectorFileObjectsHPP
