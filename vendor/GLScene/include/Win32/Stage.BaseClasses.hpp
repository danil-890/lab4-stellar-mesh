// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.BaseClasses.pas' rev: 37.00 (Windows)

#ifndef Stage_BaseClassesHPP
#define Stage_BaseClassesHPP

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
#include <Stage.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Baseclasses
{
//-- forward type declarations -----------------------------------------------
struct TGSProgressTimes;
__interface DELPHIINTERFACE IGSNotifyAble;
typedef System::DelphiInterface<IGSNotifyAble> _di_IGSNotifyAble;
__interface DELPHIINTERFACE IGSProgessAble;
typedef System::DelphiInterface<IGSProgessAble> _di_IGSProgessAble;
class DELPHICLASS TGSUpdateAbleObject;
class DELPHICLASS TGSCadenceAbleComponent;
class DELPHICLASS TGSUpdateAbleComponent;
class DELPHICLASS TGSNotifyCollection;
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct DECLSPEC_DRECORD TGSProgressTimes
{
public:
	double DeltaTime;
	double NewTime;
	float SqrDeltaTime;
	float InvSqrDeltaTime;
};
#pragma pack(pop)


typedef void __fastcall (__closure *TGSProgressEvent)(System::TObject* Sender, const double DeltaTime, const double NewTime);

__interface  INTERFACE_UUID("{00079A6C-D46E-4126-86EE-F9E2951B4593}") IGSNotifyAble  : public System::IInterface 
{
	virtual void __fastcall NotifyChange(System::TObject* Sender) = 0 ;
};

__interface  INTERFACE_UUID("{95E44548-B0FE-4607-98D0-CA51169AF8B5}") IGSProgessAble  : public System::IInterface 
{
	virtual void __fastcall DoProgress(const TGSProgressTimes &progressTime) = 0 ;
};

class PASCALIMPLEMENTATION TGSUpdateAbleObject : public Stage::Persistentclasses::TGSInterfacedPersistent
{
	typedef Stage::Persistentclasses::TGSInterfacedPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	int FUpdating;
	System::Classes::TNotifyEvent FOnNotifyChange;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner() _FINAL_ATTRIBUTE;
	
public:
	__fastcall virtual TGSUpdateAbleObject(System::Classes::TPersistent* AOwner);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall Notification(System::TObject* Sender, System::Classes::TOperation Operation);
	__property int Updating = {read=FUpdating, nodefault};
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	__property System::Classes::TPersistent* Owner = {read=FOwner};
	__property System::Classes::TNotifyEvent OnNotifyChange = {read=FOnNotifyChange, write=FOnNotifyChange};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGSUpdateAbleObject() { }
	
private:
	void *__IGSNotifyAble;	// IGSNotifyAble 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00079A6C-D46E-4126-86EE-F9E2951B4593}
	operator _di_IGSNotifyAble()
	{
		_di_IGSNotifyAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IGSNotifyAble*(void) { return (IGSNotifyAble*)&__IGSNotifyAble; }
	#endif
	
};


class PASCALIMPLEMENTATION TGSCadenceAbleComponent : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
public:
	virtual void __fastcall DoProgress(const TGSProgressTimes &progressTime);
public:
	/* TComponent.Create */ inline __fastcall virtual TGSCadenceAbleComponent(System::Classes::TComponent* AOwner) : System::Classes::TComponent(AOwner) { }
	/* TComponent.Destroy */ inline __fastcall virtual ~TGSCadenceAbleComponent() { }
	
private:
	void *__IGSProgessAble;	// IGSProgessAble 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {95E44548-B0FE-4607-98D0-CA51169AF8B5}
	operator _di_IGSProgessAble()
	{
		_di_IGSProgessAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IGSProgessAble*(void) { return (IGSProgessAble*)&__IGSProgessAble; }
	#endif
	
};


class PASCALIMPLEMENTATION TGSUpdateAbleComponent : public TGSCadenceAbleComponent
{
	typedef TGSCadenceAbleComponent inherited;
	
public:
	virtual void __fastcall NotifyChange(System::TObject* Sender);
public:
	/* TComponent.Create */ inline __fastcall virtual TGSUpdateAbleComponent(System::Classes::TComponent* AOwner) : TGSCadenceAbleComponent(AOwner) { }
	/* TComponent.Destroy */ inline __fastcall virtual ~TGSUpdateAbleComponent() { }
	
private:
	void *__IGSNotifyAble;	// IGSNotifyAble 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00079A6C-D46E-4126-86EE-F9E2951B4593}
	operator _di_IGSNotifyAble()
	{
		_di_IGSNotifyAble intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IGSNotifyAble*(void) { return (IGSNotifyAble*)&__IGSNotifyAble; }
	#endif
	
};


class PASCALIMPLEMENTATION TGSNotifyCollection : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
private:
	System::Classes::TNotifyEvent FOnNotifyChange;
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* item);
	
public:
	__fastcall TGSNotifyCollection(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass AItemClass);
	__property System::Classes::TNotifyEvent OnNotifyChange = {read=FOnNotifyChange, write=FOnNotifyChange};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TGSNotifyCollection() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Baseclasses */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_BASECLASSES)
using namespace Stage::Baseclasses;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_BaseClassesHPP
