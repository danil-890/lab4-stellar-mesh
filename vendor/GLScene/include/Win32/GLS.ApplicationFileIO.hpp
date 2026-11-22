// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.ApplicationFileIO.pas' rev: 37.00 (Windows)

#ifndef GLS_ApplicationFileIOHPP
#define GLS_ApplicationFileIOHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Stage.BaseClasses.hpp>
#include <Stage.Strings.hpp>
#include <Stage.Logger.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Applicationfileio
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLApplicationFileIO;
class DELPHICLASS TGSDataFile;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGSApplicationResource : unsigned char { aresNone, aresSplash, aresTexture, aresMaterial, aresSampler, aresFont, aresMesh };

typedef System::Classes::TStream* __fastcall (*TGSAFIOCreateFileStream)(const System::UnicodeString fileName, System::Word mode);

typedef bool __fastcall (*TGSAFIOFileStreamExists)(const System::UnicodeString fileName);

typedef void __fastcall (__closure *TGSAFIOFileStreamEvent)(const System::UnicodeString fileName, System::Word mode, System::Classes::TStream* &Stream);

typedef bool __fastcall (__closure *TGSAFIOFileStreamExistsEvent)(const System::UnicodeString fileName);

class PASCALIMPLEMENTATION TGLApplicationFileIO : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TGSAFIOFileStreamEvent FOnFileStream;
	TGSAFIOFileStreamExistsEvent FOnFileStreamExists;
	
public:
	__fastcall virtual TGLApplicationFileIO(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLApplicationFileIO();
	
__published:
	__property TGSAFIOFileStreamEvent OnFileStream = {read=FOnFileStream, write=FOnFileStream};
	__property TGSAFIOFileStreamExistsEvent OnFileStreamExists = {read=FOnFileStreamExists, write=FOnFileStreamExists};
};


enum DECLSPEC_DENUM TGSDataFileCapability : unsigned char { dfcRead, dfcWrite };

typedef System::Set<TGSDataFileCapability, TGSDataFileCapability::dfcRead, TGSDataFileCapability::dfcWrite> TGSDataFileCapabilities;

class PASCALIMPLEMENTATION TGSDataFile : public Stage::Baseclasses::TGSUpdateAbleObject
{
	typedef Stage::Baseclasses::TGSUpdateAbleObject inherited;
	
private:
	System::UnicodeString FResourceName;
	void __fastcall SetResourceName(const System::UnicodeString AName);
	
public:
	__classmethod virtual TGSDataFileCapabilities __fastcall Capabilities();
	virtual TGSDataFile* __fastcall CreateCopy(System::Classes::TPersistent* AOwner);
	virtual void __fastcall LoadFromFile(const System::UnicodeString fileName);
	virtual void __fastcall SaveToFile(const System::UnicodeString fileName);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall Initialize();
	__property System::UnicodeString ResourceName = {read=FResourceName, write=SetResourceName};
public:
	/* TGSUpdateAbleObject.Create */ inline __fastcall virtual TGSDataFile(System::Classes::TPersistent* AOwner) : Stage::Baseclasses::TGSUpdateAbleObject(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGSDataFile() { }
	
};


typedef System::TMetaClass* TGSDataFileClass;

typedef System::Classes::TResourceStream TGSResourceStream;

//-- var, const, procedure ---------------------------------------------------
#define GLS_RC_DDS_Type (System::WideChar *)(0xa)
#define GLS_RC_JPG_Type (System::WideChar *)(0xa)
#define GLS_RC_XML_Type (System::WideChar *)(0xa)
#define GLS_RC_String_Type (System::WideChar *)(0xa)
extern DELPHI_PACKAGE TGSAFIOCreateFileStream vAFIOCreateFileStream;
extern DELPHI_PACKAGE TGSAFIOFileStreamExists vAFIOFileStreamExists;
extern DELPHI_PACKAGE bool __fastcall ApplicationFileIODefined(void);
extern DELPHI_PACKAGE bool __fastcall FileStreamExists(const System::UnicodeString fileName);
extern DELPHI_PACKAGE TGSResourceStream* __fastcall CreateResourceStream(const System::UnicodeString ResName, System::WideChar * ResType);
extern DELPHI_PACKAGE TGSApplicationResource __fastcall StrToGLSResType(const System::UnicodeString AStrRes);
}	/* namespace Applicationfileio */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_APPLICATIONFILEIO)
using namespace Gls::Applicationfileio;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ApplicationFileIOHPP
