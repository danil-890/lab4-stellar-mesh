// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Formats.X.pas' rev: 37.00 (Windows)

#ifndef Formats_XHPP
#define Formats_XHPP

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
#include <Stage.PersistentClasses.hpp>
#include <Stage.Utils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Formats
{
namespace X
{
//-- forward type declarations -----------------------------------------------
struct TDXFileHeader;
class DELPHICLASS TDXNode;
class DELPHICLASS TDXMaterial;
class DELPHICLASS TDXMaterialList;
class DELPHICLASS TDXFrame;
class DELPHICLASS TDXMesh;
class DELPHICLASS TDXFile;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TDXFileHeader
{
public:
	System::StaticArray<char, 4> Magic;
	System::StaticArray<char, 2> Major;
	System::StaticArray<char, 2> Minor;
	System::StaticArray<char, 4> FileType;
	System::StaticArray<char, 4> FloatType;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TDXNode : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
private:
	System::UnicodeString FName;
	System::UnicodeString FTypeName;
	TDXNode* FOwner;
	TDXNode* __fastcall GetItem(int index);
	
public:
	__fastcall TDXNode(TDXNode* AOwner);
	__fastcall virtual TDXNode();
	virtual void __fastcall Clear();
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property System::UnicodeString TypeName = {read=FTypeName, write=FTypeName};
	__property TDXNode* Owner = {read=FOwner};
	__property TDXNode* Items[int index] = {read=GetItem};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TDXNode() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDXMaterial : public Stage::Persistentclasses::TGSPersistentObject
{
	typedef Stage::Persistentclasses::TGSPersistentObject inherited;
	
private:
	Stage::Vectortypes::TVector4f FDiffuse;
	float FSpecPower;
	Stage::Vectortypes::TVector3f FSpecular;
	Stage::Vectortypes::TVector3f FEmissive;
	System::UnicodeString FTexture;
	
public:
	__fastcall TDXMaterial(TDXMaterialList* AOwner);
	__property Stage::Vectortypes::TVector4f Diffuse = {read=FDiffuse, write=FDiffuse};
	__property float SpecPower = {read=FSpecPower, write=FSpecPower};
	__property Stage::Vectortypes::TVector3f Specular = {read=FSpecular, write=FSpecular};
	__property Stage::Vectortypes::TVector3f Emissive = {read=FEmissive, write=FEmissive};
	__property System::UnicodeString Texture = {read=FTexture, write=FTexture};
public:
	/* TGSPersistentObject.Create */ inline __fastcall virtual TDXMaterial() : Stage::Persistentclasses::TGSPersistentObject() { }
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TDXMaterial(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObject(reader) { }
	/* TGSPersistentObject.Destroy */ inline __fastcall virtual ~TDXMaterial() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDXMaterialList : public TDXNode
{
	typedef TDXNode inherited;
	
private:
	TDXMaterial* __fastcall GetMaterial(int index);
	
public:
	__property TDXMaterial* Items[int index] = {read=GetMaterial};
public:
	/* TDXNode.CreateOwned */ inline __fastcall TDXMaterialList(TDXNode* AOwner) : TDXNode(AOwner) { }
	/* TDXNode.Create */ inline __fastcall virtual TDXMaterialList() : TDXNode() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TDXMaterialList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDXFrame : public TDXNode
{
	typedef TDXNode inherited;
	
private:
	Stage::Vectortypes::TGSMatrix FMatrix;
	
public:
	__fastcall virtual TDXFrame();
	Stage::Vectortypes::TGSMatrix __fastcall GlobalMatrix();
	__property Stage::Vectortypes::TGSMatrix Matrix = {read=FMatrix, write=FMatrix};
public:
	/* TDXNode.CreateOwned */ inline __fastcall TDXFrame(TDXNode* AOwner) : TDXNode(AOwner) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TDXFrame() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDXMesh : public TDXNode
{
	typedef TDXNode inherited;
	
private:
	Stage::Vectorlists::TGSAffineVectorList* FVertices;
	Stage::Vectorlists::TGSAffineVectorList* FNormals;
	Stage::Vectorlists::TGSAffineVectorList* FTexCoords;
	Stage::Vectorlists::TGSIntegerList* FVertexIndices;
	Stage::Vectorlists::TGSIntegerList* FNormalIndices;
	Stage::Vectorlists::TGSIntegerList* FMaterialIndices;
	Stage::Vectorlists::TGSIntegerList* FVertCountIndices;
	TDXMaterialList* FMaterialList;
	
public:
	__fastcall virtual TDXMesh();
	__fastcall virtual ~TDXMesh();
	__property Stage::Vectorlists::TGSAffineVectorList* Vertices = {read=FVertices};
	__property Stage::Vectorlists::TGSAffineVectorList* Normals = {read=FNormals};
	__property Stage::Vectorlists::TGSAffineVectorList* TexCoords = {read=FTexCoords};
	__property Stage::Vectorlists::TGSIntegerList* VertexIndices = {read=FVertexIndices};
	__property Stage::Vectorlists::TGSIntegerList* NormalIndices = {read=FNormalIndices};
	__property Stage::Vectorlists::TGSIntegerList* MaterialIndices = {read=FMaterialIndices};
	__property Stage::Vectorlists::TGSIntegerList* VertCountIndices = {read=FVertCountIndices};
	__property TDXMaterialList* MaterialList = {read=FMaterialList};
public:
	/* TDXNode.CreateOwned */ inline __fastcall TDXMesh(TDXNode* AOwner) : TDXNode(AOwner) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDXFile : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TDXNode* FRootNode;
	TDXFileHeader FHeader;
	
protected:
	void __fastcall ParseText(System::Classes::TStream* Stream);
	void __fastcall ParseBinary(System::Classes::TStream* Stream);
	
public:
	__fastcall TDXFile();
	__fastcall virtual ~TDXFile();
	void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	__property TDXFileHeader Header = {read=FHeader};
	__property TDXNode* RootNode = {read=FRootNode};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace X */
}	/* namespace Formats */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATS_X)
using namespace Formats::X;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATS)
using namespace Formats;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Formats_XHPP
