// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.ArchiveManager.pas' rev: 37.00 (Windows)

#ifndef GLS_ArchiveManagerHPP
#define GLS_ArchiveManagerHPP

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
#include <GLS.ApplicationFileIO.hpp>
#include <Stage.PersistentClasses.hpp>
#include <Stage.Strings.hpp>
#include <Stage.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Archivemanager
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGSBaseArchive;
class DELPHICLASS TGSArchiveFileFormat;
class DELPHICLASS TGSArchiveFileFormatsList;
class DELPHICLASS TGSLibArchive;
class DELPHICLASS TGSLibArchives;
class DELPHICLASS TGLArchiveManager;
class DELPHICLASS EInvalidArchiveFile;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TCompressionLevel : unsigned char { clNone, clFastest, clDefault, clMax, clLevel1, clLevel2, clLevel3, clLevel4, clLevel5, clLevel6, clLevel7, clLevel8, clLevel9 };

class PASCALIMPLEMENTATION TGSBaseArchive : public Gls::Applicationfileio::TGSDataFile
{
	typedef Gls::Applicationfileio::TGSDataFile inherited;
	
protected:
	System::UnicodeString FFileName;
	System::Classes::TStrings* FContentList;
	TCompressionLevel FCompressionLevel;
	virtual void __fastcall SetCompressionLevel(TCompressionLevel aValue);
	
public:
	__fastcall virtual TGSBaseArchive(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TGSBaseArchive();
	__property System::Classes::TStrings* ContentList = {read=FContentList};
	__property TCompressionLevel CompressionLevel = {read=FCompressionLevel, write=SetCompressionLevel, default=0};
	virtual void __fastcall Clear() = 0 ;
	virtual bool __fastcall ContentExists(System::UnicodeString ContentName) = 0 ;
	virtual System::Classes::TStream* __fastcall GetContent(System::Classes::TStream* Stream, int index) = 0 /* overload */;
	virtual System::Classes::TStream* __fastcall GetContent(System::UnicodeString ContentName) = 0 /* overload */;
	virtual System::Classes::TStream* __fastcall GetContent(int index) = 0 /* overload */;
	virtual int __fastcall GetContentSize(int index) = 0 /* overload */;
	virtual int __fastcall GetContentSize(System::UnicodeString ContentName) = 0 /* overload */;
	virtual void __fastcall AddFromStream(System::UnicodeString ContentName, System::UnicodeString Path, System::Classes::TStream* FS) = 0 ;
	virtual void __fastcall AddFromFile(System::UnicodeString FileName, System::UnicodeString Path) = 0 ;
	virtual void __fastcall RemoveContent(int index) = 0 /* overload */;
	virtual void __fastcall RemoveContent(System::UnicodeString ContentName) = 0 /* overload */;
	virtual void __fastcall Extract(int index, System::UnicodeString NewName) = 0 /* overload */;
	virtual void __fastcall Extract(System::UnicodeString ContentName, System::UnicodeString NewName) = 0 /* overload */;
};


typedef System::TMetaClass* TGSBaseArchiveClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSArchiveFileFormat : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TGSBaseArchiveClass BaseArchiveClass;
	System::UnicodeString Extension;
	System::UnicodeString Description;
	int DescResID;
public:
	/* TObject.Create */ inline __fastcall TGSArchiveFileFormat() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TGSArchiveFileFormat() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSArchiveFileFormatsList : public Stage::Persistentclasses::TGSPersistentObjectList
{
	typedef Stage::Persistentclasses::TGSPersistentObjectList inherited;
	
public:
	__fastcall virtual ~TGSArchiveFileFormatsList();
	HIDESBASE void __fastcall Add(const System::UnicodeString Ext, const System::UnicodeString Desc, int DescID, TGSBaseArchiveClass AClass);
	TGSBaseArchiveClass __fastcall FindExt(System::UnicodeString Ext);
	TGSBaseArchiveClass __fastcall FindFromFileName(const System::UnicodeString FileName);
	HIDESBASE void __fastcall Remove(TGSBaseArchiveClass AClass);
public:
	/* TGSPersistentObjectList.Create */ inline __fastcall virtual TGSArchiveFileFormatsList() : Stage::Persistentclasses::TGSPersistentObjectList() { }
	
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGSArchiveFileFormatsList(Stage::Persistentclasses::TGSVirtualReader* reader) : Stage::Persistentclasses::TGSPersistentObjectList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSLibArchive : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TGSBaseArchive* vArchive;
	TGSBaseArchiveClass ArcClass;
	System::UnicodeString FFileName;
	System::UnicodeString FName;
	void __fastcall SetCompressionLevel(TCompressionLevel aValue);
	TCompressionLevel __fastcall GetCompressionLevel();
	System::Classes::TStrings* __fastcall GetContentList();
	void __fastcall SetName(const System::UnicodeString val);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TGSLibArchive(System::Classes::TCollection* ACollection);
	__fastcall virtual ~TGSLibArchive();
	__property TCompressionLevel CompressionLevel = {read=GetCompressionLevel, write=SetCompressionLevel, default=2};
	void __fastcall CreateArchive(System::UnicodeString FileName, bool OverwriteExistingFile = false);
	__property System::Classes::TStrings* ContentList = {read=GetContentList};
	void __fastcall LoadFromFile(System::UnicodeString aFileName)/* overload */;
	void __fastcall LoadFromFile(System::UnicodeString aFileName, System::UnicodeString aAchiverType)/* overload */;
	void __fastcall Clear();
	bool __fastcall ContentExists(System::UnicodeString aContentName);
	__property System::UnicodeString FileName = {read=FFileName};
	System::Classes::TStream* __fastcall GetContent(int aindex)/* overload */;
	System::Classes::TStream* __fastcall GetContent(System::UnicodeString aContentName)/* overload */;
	int __fastcall GetContentSize(int aindex)/* overload */;
	int __fastcall GetContentSize(System::UnicodeString aContentName)/* overload */;
	void __fastcall AddFromStream(System::UnicodeString aContentName, System::UnicodeString aPath, System::Classes::TStream* aF)/* overload */;
	void __fastcall AddFromStream(System::UnicodeString aContentName, System::Classes::TStream* aF)/* overload */;
	void __fastcall AddFromFile(System::UnicodeString aFileName, System::UnicodeString aPath)/* overload */;
	void __fastcall AddFromFile(System::UnicodeString aFileName)/* overload */;
	void __fastcall RemoveContent(int aindex)/* overload */;
	void __fastcall RemoveContent(System::UnicodeString aContentName)/* overload */;
	void __fastcall Extract(int aindex, System::UnicodeString aNewName)/* overload */;
	void __fastcall Extract(System::UnicodeString aContentName, System::UnicodeString aNewName)/* overload */;
	
__published:
	__property System::UnicodeString Name = {read=FName, write=SetName};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSLibArchives : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TGSLibArchive* operator[](int index) { return this->Items[index]; }
	
protected:
	void __fastcall SetItems(int index, TGSLibArchive* const val);
	TGSLibArchive* __fastcall GetItems(int index);
	
public:
	__fastcall TGSLibArchives(System::Classes::TComponent* AOwner);
	HIDESBASE System::Classes::TPersistent* __fastcall Owner();
	int __fastcall IndexOf(TGSLibArchive* const Item);
	HIDESBASE TGSLibArchive* __fastcall Add();
	HIDESBASE TGSLibArchive* __fastcall FindItemID(int ID);
	__property TGSLibArchive* Items[int index] = {read=GetItems, write=SetItems/*, default*/};
	TGSLibArchive* __fastcall GetArchiveByFileName(const System::UnicodeString AName);
	System::UnicodeString __fastcall GetFileNameOfArchive(TGSLibArchive* aValue);
	System::UnicodeString __fastcall MakeUniqueName(const System::UnicodeString nameRoot);
	TGSLibArchive* __fastcall GetLibArchiveByName(const System::UnicodeString AName);
	System::UnicodeString __fastcall GetNameOfLibArchive(TGSLibArchive* const Archive);
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TGSLibArchives() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLArchiveManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TGSLibArchives* FArchives;
	void __fastcall SetArchives(TGSLibArchives* aValue);
	
public:
	__fastcall virtual TGLArchiveManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLArchiveManager();
	TGSLibArchive* __fastcall GetArchiveByFileName(const System::UnicodeString AName);
	System::UnicodeString __fastcall GetFileNameOfArchive(TGSLibArchive* const aArchive);
	System::Classes::TStream* __fastcall GetContent(System::UnicodeString aContentName);
	bool __fastcall ContentExists(System::UnicodeString aContentName);
	TGSLibArchive* __fastcall OpenArchive(System::UnicodeString aFileName)/* overload */;
	TGSLibArchive* __fastcall OpenArchive(System::UnicodeString aFileName, System::UnicodeString aAchiverType)/* overload */;
	void __fastcall CloseArchive(TGSLibArchive* aArchive);
	
__published:
	__property TGSLibArchives* Archives = {read=FArchives, write=SetArchives};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION EInvalidArchiveFile : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EInvalidArchiveFile(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EInvalidArchiveFile(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidArchiveFile(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidArchiveFile(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidArchiveFile(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidArchiveFile(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EInvalidArchiveFile(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidArchiveFile(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidArchiveFile(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidArchiveFile(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidArchiveFile(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidArchiveFile(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EInvalidArchiveFile() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TGSArchiveFileFormatsList* __fastcall GetArchiveFileFormats(void);
extern DELPHI_PACKAGE void __fastcall RegisterArchiveFormat(const System::UnicodeString AExtension, const System::UnicodeString ADescription, TGSBaseArchiveClass AClass);
extern DELPHI_PACKAGE void __fastcall UnregisterArchiveFormat(TGSBaseArchiveClass AClass);
extern DELPHI_PACKAGE TGLArchiveManager* __fastcall GetArchiveManager(void);
extern DELPHI_PACKAGE System::Classes::TStream* __fastcall ArcCreateFileStream(const System::UnicodeString FileName, System::Word mode);
extern DELPHI_PACKAGE bool __fastcall ArcFileStreamExists(const System::UnicodeString FileName);
}	/* namespace Archivemanager */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_ARCHIVEMANAGER)
using namespace Gls::Archivemanager;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ArchiveManagerHPP
