// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Texture3D.pas' rev: 37.00 (Windows)

#ifndef GLS_Texture3DHPP
#define GLS_Texture3DHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Messages.hpp>
#include <Winapi.OpenGL.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.BaseClasses.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Objects.hpp>
#include <GLS.SceneViewer.hpp>
#include <GLS.Texture.hpp>
#include <GLS.Context.hpp>
#include <GLS.Cadencer.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Texture3d
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLTexture3D;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TGLTexture3D : public Stage::Baseclasses::TGSUpdateAbleObject
{
	typedef Stage::Baseclasses::TGSUpdateAbleObject inherited;
	
protected:
	System::LongWord FDataType;
	int FSizeX;
	int FSizeY;
	int FSizeZ;
	int FTexelByteSize;
	System::UnicodeString M_Data;
	int __fastcall Data_Type_To_Texel_Byte_Size(int F_Data_Type);
	void __fastcall Set_Data_Type(System::LongWord AValue);
	void __fastcall SetSizeX(int AValue);
	void __fastcall SetSizeY(int AValue);
	void __fastcall SetSizeZ(int AValue);
	void __fastcall Set_Data(const System::UnicodeString AValue);
	
public:
	__fastcall TGLTexture3D();
	__fastcall virtual ~TGLTexture3D();
	void __fastcall SaveToFile(const System::UnicodeString FileName);
	void __fastcall LoadFromFile(const System::UnicodeString FileName);
	__property System::LongWord DataType = {read=FDataType, write=Set_Data_Type, nodefault};
	__property int SizeX = {read=FSizeX, write=SetSizeX, nodefault};
	__property int SizeY = {read=FSizeY, write=SetSizeY, nodefault};
	__property int SizeZ = {read=FSizeZ, write=SetSizeZ, nodefault};
	__property int Texel_Byte_Size = {read=FTexelByteSize, nodefault};
	__property System::UnicodeString Data = {read=M_Data, write=Set_Data};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Texture3d */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_TEXTURE3D)
using namespace Gls::Texture3d;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_Texture3DHPP
