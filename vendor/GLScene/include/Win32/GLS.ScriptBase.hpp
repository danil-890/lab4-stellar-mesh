// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.ScriptBase.pas' rev: 37.00 (Windows)

#ifndef GLS_ScriptBaseHPP
#define GLS_ScriptBaseHPP

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
#include <Stage.XCollection.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Scriptbase
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGSScriptBase;
class DELPHICLASS TGSScripts;
class DELPHICLASS TGLScriptLibrary;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGSScriptState : unsigned char { ssUncompiled, ssCompileErrors, ssCompiled, ssRunningErrors, ssRunning };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSScriptBase : public Stage::Xcollection::TXCollectionItem
{
	typedef Stage::Xcollection::TXCollectionItem inherited;
	
private:
	System::Classes::TStringList* FText;
	System::UnicodeString FDescription;
	System::Classes::TStringList* FErrors;
	
protected:
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	virtual TGSScriptState __fastcall GetState() = 0 ;
	void __fastcall SetText(System::Classes::TStringList* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGSScriptBase(Stage::Xcollection::TXCollection* aOwner);
	__fastcall virtual ~TGSScriptBase();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Compile() = 0 ;
	virtual void __fastcall Start() = 0 ;
	virtual void __fastcall Stop() = 0 ;
	virtual void __fastcall Execute() = 0 ;
	virtual void __fastcall Invalidate() = 0 ;
	virtual System::Variant __fastcall Call(System::UnicodeString aName, System::Variant *aParams, const System::NativeInt aParams_High) = 0 ;
	__property System::Classes::TStringList* Errors = {read=FErrors};
	__property TGSScriptState State = {read=GetState, nodefault};
	
__published:
	__property System::Classes::TStringList* Text = {read=FText, write=SetText};
	__property System::UnicodeString Description = {read=FDescription, write=FDescription};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSScripts : public Stage::Xcollection::TXCollection
{
	typedef Stage::Xcollection::TXCollection inherited;
	
public:
	TGSScriptBase* operator[](int index) { return this->Items[index]; }
	
protected:
	HIDESBASE TGSScriptBase* __fastcall GetItems(int index);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual Stage::Xcollection::TXCollectionItemClass __fastcall ItemsClass();
	virtual bool __fastcall CanAdd(Stage::Xcollection::TXCollectionItemClass aClass);
	__property TGSScriptBase* Items[int index] = {read=GetItems/*, default*/};
public:
	/* TXCollection.Create */ inline __fastcall virtual TGSScripts(System::Classes::TPersistent* aOwner) : Stage::Xcollection::TXCollection(aOwner) { }
	/* TXCollection.Destroy */ inline __fastcall virtual ~TGSScripts() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLScriptLibrary : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TGSScripts* FScripts;
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall WriteScriptsData(System::Classes::TStream* Stream);
	void __fastcall ReadScriptsData(System::Classes::TStream* Stream);
	virtual void __fastcall Loaded();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLScriptLibrary(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TGLScriptLibrary();
	
__published:
	__property TGSScripts* Scripts = {read=FScripts};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Scriptbase */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_SCRIPTBASE)
using namespace Gls::Scriptbase;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ScriptBaseHPP
