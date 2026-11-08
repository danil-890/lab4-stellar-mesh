// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Terrainer.pas' rev: 37.00 (Windows)

#ifndef GLS_TerrainerHPP
#define GLS_TerrainerHPP

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
#include <System.Math.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Terrainer
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLTerrainData;
class DELPHICLASS TGLTerrainerBrush;
class DELPHICLASS TGLTerrainerCircularBrush;
class DELPHICLASS TGLTerrainerHeightModifier;
class DELPHICLASS TGLTerrainerModifier;
class DELPHICLASS TGLTerrainer;
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<float, 3> TGLTerrainerVertex;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLTerrainData : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<float> _TGLTerrainData__1;
	
	typedef System::DynamicArray<System::DynamicArray<float> > _TGLTerrainData__2;
	
	typedef System::DynamicArray<Stage::Vectortypes::TVector3f> _TGLTerrainData__3;
	
	typedef System::DynamicArray<System::DynamicArray<Stage::Vectortypes::TVector3f> > _TGLTerrainData__4;
	
	
private:
	_TGLTerrainData__2 FHeights;
	_TGLTerrainData__4 FNormals;
	int FXDim;
	int FYDim;
	void __fastcall SetHeights(int x, int y, const float Value);
	float __fastcall GetHeights(int x, int y);
	Stage::Vectorgeometry::TAffineVector __fastcall GetNormals(int x, int y);
	
public:
	__fastcall TGLTerrainData(int XDim, int YDim);
	void __fastcall CalculateNormals();
	__property int XDim = {read=FXDim, nodefault};
	__property int YDim = {read=FYDim, nodefault};
	__property float Heights[int x][int y] = {read=GetHeights, write=SetHeights};
	__property Stage::Vectorgeometry::TAffineVector Normals[int x][int y] = {read=GetNormals};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGLTerrainData() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLTerrainerBrush : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual float __fastcall GetWeight(int x, int y) = 0 ;
	virtual int __fastcall GetHalfWidth() = 0 ;
	virtual int __fastcall GetHalfHeight() = 0 ;
	
public:
	__property int HalfWidth = {read=GetHalfWidth, nodefault};
	__property int HalfHeight = {read=GetHalfHeight, nodefault};
	__property float Weight[int x][int y] = {read=GetWeight};
public:
	/* TObject.Create */ inline __fastcall TGLTerrainerBrush() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TGLTerrainerBrush() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLTerrainerCircularBrush : public TGLTerrainerBrush
{
	typedef TGLTerrainerBrush inherited;
	
private:
	int FRadius;
	
protected:
	virtual float __fastcall GetWeight(int x, int y);
	virtual int __fastcall GetHalfWidth();
	virtual int __fastcall GetHalfHeight();
	
public:
	__fastcall TGLTerrainerCircularBrush(int Radius);
	__property int Radius = {read=FRadius, write=FRadius, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGLTerrainerCircularBrush() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLTerrainerHeightModifier : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TGLTerrainData* FData;
	
protected:
	__property TGLTerrainData* Data = {read=FData};
	
public:
	__fastcall TGLTerrainerHeightModifier(TGLTerrainData* Data);
	virtual void __fastcall Modify(int OriginX, int OriginY, TGLTerrainerBrush* Brush, float Strength) = 0 ;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGLTerrainerHeightModifier() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLTerrainerModifier : public TGLTerrainerHeightModifier
{
	typedef TGLTerrainerHeightModifier inherited;
	
public:
	virtual void __fastcall Modify(int OriginX, int OriginY, TGLTerrainerBrush* Brush, float Strength);
public:
	/* TGLTerrainerHeightModifier.Create */ inline __fastcall TGLTerrainerModifier(TGLTerrainData* Data) : TGLTerrainerHeightModifier(Data) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGLTerrainerModifier() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLTerrainer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TGLTerrainData* FData;
	
protected:
	float VScale;
	float TScale;
	float GridSize;
	unsigned DisplayList;
	bool GotDisplayList;
	void __fastcall DrawManually();
	void __fastcall LoadFromBitmap(Vcl::Graphics::TBitmap* Bitmap);
	
public:
	__fastcall TGLTerrainer(const System::UnicodeString FileName, float GridScale, float VerticalScale, float TextureScale);
	__fastcall virtual ~TGLTerrainer();
	Stage::Vectorgeometry::TAffineVector __fastcall GridPointPosition(int x, int y);
	void __fastcall Render();
	__property TGLTerrainData* Data = {read=FData};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Terrainer */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_TERRAINER)
using namespace Gls::Terrainer;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_TerrainerHPP
