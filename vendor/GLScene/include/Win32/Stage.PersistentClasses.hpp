// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.PersistentClasses.pas' rev: 37.00 (Windows)

#ifndef Stage_PersistentClassesHPP
#define Stage_PersistentClassesHPP

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
#include <Stage.Strings.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Persistentclasses
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGSVirtualReader;
class DELPHICLASS TGSVirtualWriter;
__interface DELPHIINTERFACE IGSPersistentObject;
typedef System::DelphiInterface<IGSPersistentObject> _di_IGSPersistentObject;
class DELPHICLASS TGSPersistentObject;
class DELPHICLASS TGSPersistentObjectList;
class DELPHICLASS TGSBinaryReader;
class DELPHICLASS TGSBinaryWriter;
class DELPHICLASS TGSTextReader;
class DELPHICLASS TGSTextWriter;
class DELPHICLASS TGSOwnedPersistent;
class DELPHICLASS TGSInterfacedPersistent;
class DELPHICLASS TGSInterfacedCollectionItem;
class DELPHICLASS EInvalidFileSignature;
class DELPHICLASS EFilerException;
//-- type declarations -------------------------------------------------------
typedef System::TObject* *PObject;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSVirtualReader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TStream* FStream;
	
public:
	__fastcall virtual TGSVirtualReader(System::Classes::TStream* Stream);
	__property System::Classes::TStream* Stream = {read=FStream};
	void __fastcall ReadTypeError();
	virtual void __fastcall Read(void *Buf, System::LongInt Count) = 0 ;
	virtual System::Classes::TValueType __fastcall NextValue() = 0 ;
	virtual int __fastcall ReadInteger() = 0 ;
	virtual bool __fastcall ReadBoolean() = 0 ;
	virtual System::UnicodeString __fastcall ReadString() = 0 ;
	virtual System::Extended __fastcall ReadFloat() = 0 ;
	virtual void __fastcall ReadListBegin() = 0 ;
	virtual void __fastcall ReadListEnd() = 0 ;
	virtual bool __fastcall EndOfList() = 0 ;
	void __fastcall ReadTStrings(System::Classes::TStrings* aStrings);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGSVirtualReader() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSVirtualWriter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TStream* FStream;
	
public:
	__fastcall virtual TGSVirtualWriter(System::Classes::TStream* Stream);
	__property System::Classes::TStream* Stream = {read=FStream};
	virtual void __fastcall Write(const void *Buf, System::LongInt Count) = 0 ;
	virtual void __fastcall WriteInteger(int anInteger) = 0 ;
	virtual void __fastcall WriteBoolean(bool aBoolean) = 0 ;
	virtual void __fastcall WriteString(const System::UnicodeString aString) = 0 ;
	virtual void __fastcall WriteFloat(const System::Extended aFloat) = 0 ;
	virtual void __fastcall WriteListBegin() = 0 ;
	virtual void __fastcall WriteListEnd() = 0 ;
	void __fastcall WriteTStrings(System::Classes::TStrings* const aStrings, bool storeObjects = true);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGSVirtualWriter() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TGSVirtualReaderClass;

typedef System::TMetaClass* TGSVirtualWriterClass;

__interface  INTERFACE_UUID("{A9A0198A-F11B-4325-A92C-2F24DB41652B}") IGSPersistentObject  : public System::IInterface 
{
	virtual void __fastcall WriteToFiler(TGSVirtualWriter* writer) = 0 ;
	virtual void __fastcall ReadFromFiler(TGSVirtualReader* reader) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSPersistentObject : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
protected:
	void __fastcall RaiseFilerException(const int archiveVersion);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
	
public:
	__fastcall virtual TGSPersistentObject();
	__fastcall TGSPersistentObject(TGSVirtualReader* reader);
	__fastcall virtual ~TGSPersistentObject();
	virtual void __fastcall Assign(System::Classes::TPersistent* source);
	DYNAMIC TGSPersistentObject* __fastcall CreateClone();
	__classmethod virtual System::UnicodeString __fastcall FileSignature();
	__classmethod virtual TGSVirtualWriterClass __fastcall FileVirtualWriter();
	__classmethod virtual TGSVirtualReaderClass __fastcall FileVirtualReader();
	DYNAMIC void __fastcall WriteToFiler(TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(TGSVirtualReader* reader);
	DYNAMIC void __fastcall SaveToStream(System::Classes::TStream* stream, TGSVirtualWriterClass writerClass = 0x0);
	DYNAMIC void __fastcall LoadFromStream(System::Classes::TStream* stream, TGSVirtualReaderClass readerClass = 0x0);
	DYNAMIC void __fastcall SaveToFile(const System::UnicodeString fileName, TGSVirtualWriterClass writerClass = 0x0);
	DYNAMIC void __fastcall LoadFromFile(const System::UnicodeString fileName, TGSVirtualReaderClass readerClass = 0x0);
	DYNAMIC System::UnicodeString __fastcall SaveToString(TGSVirtualWriterClass writerClass = 0x0);
	DYNAMIC void __fastcall LoadFromString(const System::UnicodeString data, TGSVirtualReaderClass readerClass = 0x0);
private:
	void *__IGSPersistentObject;	// IGSPersistentObject 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A9A0198A-F11B-4325-A92C-2F24DB41652B}
	operator _di_IGSPersistentObject()
	{
		_di_IGSPersistentObject intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IGSPersistentObject*(void) { return (IGSPersistentObject*)&__IGSPersistentObject; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TGSPersistentObjectClass;

typedef System::StaticArray<System::TObject*, 268435456> TGSPointerObjectList;

typedef TGSPointerObjectList *PGSPointerObjectList;

typedef int __fastcall (*TGSObjectListSortCompare)(System::TObject* item1, System::TObject* item2);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSPersistentObjectList : public TGSPersistentObject
{
	typedef TGSPersistentObject inherited;
	
public:
	System::TObject* operator[](int Index) { return this->Items[Index]; }
	
private:
	PGSPointerObjectList FList;
	int FCount;
	int FCapacity;
	int FGrowthDelta;
	
protected:
	virtual void __fastcall Error();
	System::TObject* __fastcall Get(int Index);
	void __fastcall Put(int Index, System::TObject* Item);
	void __fastcall SetCapacity(int newCapacity);
	void __fastcall SetCount(int NewCount);
	System::TObject* __fastcall GetFirst();
	void __fastcall SetFirst(System::TObject* item);
	System::TObject* __fastcall GetLast();
	void __fastcall SetLast(System::TObject* item);
	virtual void __fastcall AfterObjectCreatedByReader(System::TObject* Sender);
	void __fastcall DoClean();
	
public:
	__fastcall virtual TGSPersistentObjectList();
	__fastcall virtual ~TGSPersistentObjectList();
	DYNAMIC void __fastcall WriteToFiler(TGSVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(TGSVirtualReader* reader);
	void __fastcall ReadFromFilerWithEvent(TGSVirtualReader* reader, System::Classes::TNotifyEvent afterSenderObjectCreated);
	int __fastcall Add(System::TObject* const item);
	void __fastcall AddNils(unsigned nbVals);
	void __fastcall Delete(int index);
	void __fastcall DeleteItems(int index, unsigned nbVals);
	void __fastcall Exchange(int Index1, int Index2);
	void __fastcall Insert(int Index, System::TObject* Item);
	void __fastcall InsertNils(int index, unsigned nbVals);
	void __fastcall Move(int CurIndex, int NewIndex);
	int __fastcall Remove(System::TObject* Item);
	void __fastcall DeleteAndFree(int index);
	void __fastcall DeleteAndFreeItems(int index, unsigned nbVals);
	int __fastcall RemoveAndFree(System::TObject* item);
	__property int GrowthDelta = {read=FGrowthDelta, write=FGrowthDelta, nodefault};
	TGSPersistentObjectList* __fastcall Expand();
	__property System::TObject* Items[int Index] = {read=Get, write=Put/*, default*/};
	__property int Count = {read=FCount, write=SetCount, nodefault};
	__property PGSPointerObjectList List = {read=FList};
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	void __fastcall RequiredCapacity(int aCapacity);
	void __fastcall Pack();
	virtual void __fastcall Clear();
	virtual void __fastcall Clean();
	void __fastcall CleanFree();
	int __fastcall IndexOf(System::TObject* Item);
	__property System::TObject* First = {read=GetFirst, write=SetFirst};
	__property System::TObject* Last = {read=GetLast, write=SetLast};
	void __fastcall Push(System::TObject* item);
	System::TObject* __fastcall Pop();
	void __fastcall PopAndFree();
	int __fastcall AddObjects(TGSPersistentObjectList* const objectList);
	void __fastcall RemoveObjects(TGSPersistentObjectList* const objectList);
	void __fastcall Sort(TGSObjectListSortCompare compareFunc);
public:
	/* TGSPersistentObject.CreateFromFiler */ inline __fastcall TGSPersistentObjectList(TGSVirtualReader* reader) : TGSPersistentObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSBinaryReader : public TGSVirtualReader
{
	typedef TGSVirtualReader inherited;
	
protected:
	System::Classes::TValueType __fastcall ReadValue();
	System::WideString __fastcall ReadWideString(System::Classes::TValueType vType);
	
public:
	virtual void __fastcall Read(void *Buf, System::LongInt Count);
	virtual System::Classes::TValueType __fastcall NextValue();
	virtual int __fastcall ReadInteger();
	virtual bool __fastcall ReadBoolean();
	virtual System::UnicodeString __fastcall ReadString();
	virtual System::Extended __fastcall ReadFloat();
	virtual void __fastcall ReadListBegin();
	virtual void __fastcall ReadListEnd();
	virtual bool __fastcall EndOfList();
public:
	/* TGSVirtualReader.Create */ inline __fastcall virtual TGSBinaryReader(System::Classes::TStream* Stream) : TGSVirtualReader(Stream) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGSBinaryReader() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSBinaryWriter : public TGSVirtualWriter
{
	typedef TGSVirtualWriter inherited;
	
protected:
	virtual void __fastcall WriteAnsiString(const System::AnsiString aString);
	virtual void __fastcall WriteWideString(const System::WideString aString);
	
public:
	virtual void __fastcall Write(const void *Buf, System::LongInt Count);
	virtual void __fastcall WriteInteger(int anInteger);
	virtual void __fastcall WriteBoolean(bool aBoolean);
	virtual void __fastcall WriteString(const System::UnicodeString aString);
	virtual void __fastcall WriteFloat(const System::Extended aFloat);
	virtual void __fastcall WriteListBegin();
	virtual void __fastcall WriteListEnd();
public:
	/* TGSVirtualWriter.Create */ inline __fastcall virtual TGSBinaryWriter(System::Classes::TStream* Stream) : TGSVirtualWriter(Stream) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGSBinaryWriter() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSTextReader : public TGSVirtualReader
{
	typedef TGSVirtualReader inherited;
	
private:
	System::UnicodeString FValueType;
	System::UnicodeString FData;
	
protected:
	void __fastcall ReadLine(const System::UnicodeString requestedType = System::UnicodeString());
	
public:
	virtual void __fastcall Read(void *Buf, System::LongInt Count);
	virtual System::Classes::TValueType __fastcall NextValue();
	virtual int __fastcall ReadInteger();
	virtual bool __fastcall ReadBoolean();
	virtual System::UnicodeString __fastcall ReadString();
	virtual System::Extended __fastcall ReadFloat();
	virtual void __fastcall ReadListBegin();
	virtual void __fastcall ReadListEnd();
	virtual bool __fastcall EndOfList();
public:
	/* TGSVirtualReader.Create */ inline __fastcall virtual TGSTextReader(System::Classes::TStream* Stream) : TGSVirtualReader(Stream) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TGSTextReader() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSTextWriter : public TGSVirtualWriter
{
	typedef TGSVirtualWriter inherited;
	
private:
	int FIndentLevel;
	
protected:
	void __fastcall WriteLine(const System::UnicodeString valueType, const System::UnicodeString data);
	
public:
	__fastcall virtual TGSTextWriter(System::Classes::TStream* aStream);
	__fastcall virtual ~TGSTextWriter();
	virtual void __fastcall Write(const void *Buf, System::LongInt Count);
	virtual void __fastcall WriteInteger(int anInteger);
	virtual void __fastcall WriteBoolean(bool aBoolean);
	virtual void __fastcall WriteString(const System::UnicodeString aString);
	virtual void __fastcall WriteFloat(const System::Extended aFloat);
	virtual void __fastcall WriteListBegin();
	virtual void __fastcall WriteListEnd();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSOwnedPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	
public:
	__fastcall virtual TGSOwnedPersistent(System::Classes::TPersistent* AOwner);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGSOwnedPersistent() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSInterfacedPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGSInterfacedPersistent() { }
	
public:
	/* TObject.Create */ inline __fastcall TGSInterfacedPersistent() : System::Classes::TPersistent() { }
	
private:
	void *__IInterface;	// System::IInterface 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSInterfacedCollectionItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef();
	int __stdcall _Release();
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TGSInterfacedCollectionItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TGSInterfacedCollectionItem() { }
	
private:
	void *__IInterface;	// System::IInterface 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EInvalidFileSignature : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EInvalidFileSignature(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EInvalidFileSignature(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidFileSignature(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidFileSignature(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidFileSignature(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidFileSignature(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EInvalidFileSignature(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidFileSignature(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidFileSignature(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidFileSignature(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidFileSignature(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidFileSignature(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EInvalidFileSignature() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EFilerException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EFilerException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EFilerException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EFilerException(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EFilerException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EFilerException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EFilerException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EFilerException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EFilerException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EFilerException(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EFilerException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EFilerException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EFilerException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EFilerException() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall RaiseFilerException(System::TClass aClass, int archiveVersion);
extern DELPHI_PACKAGE System::WideString __fastcall UTF8ToWideString(const System::AnsiString s);
}	/* namespace Persistentclasses */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_PERSISTENTCLASSES)
using namespace Stage::Persistentclasses;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_PersistentClassesHPP
