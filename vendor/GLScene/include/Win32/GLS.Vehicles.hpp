// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Vehicles.pas' rev: 37.00 (Windows)

#ifndef GLS_VehiclesHPP
#define GLS_VehiclesHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <System.Contnrs.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Coordinates.hpp>
#include <Stage.BaseClasses.hpp>
#include <Stage.XCollection.hpp>
#include <Stage.Manager.hpp>
#include <Stage.Keyboard.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Behaviours.hpp>
#include <GLS.Collision.hpp>
#include <GLS.Cadencer.hpp>
#include <GLS.VectorFileObjects.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Vehicles
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLBaseSteerBehaviour;
class DELPHICLASS TGLWanderSteer;
class DELPHICLASS TGLSeekSteer;
class DELPHICLASS TGLFleeSteer;
class DELPHICLASS TGLPursueSteer;
class DELPHICLASS TGLWorldCollisionSteer;
class DELPHICLASS TGLBVehicle;
class DELPHICLASS TGLVehicleManager;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLSteerBehaviours : unsigned char { sbhSeek, sbhFlee, sbhPursuit, sbhEvasion, sbhOffsetPursuit, sbhArrival, sbhObstacleAvoidance, sbhWander };

typedef System::Set<TGLSteerBehaviours, TGLSteerBehaviours::sbhSeek, TGLSteerBehaviours::sbhWander> TGLSteeringBehaviours;

typedef System::TMetaClass* TGLSteerBehaviourClass;

class PASCALIMPLEMENTATION TGLBaseSteerBehaviour : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TGLBVehicle* FVehicle;
	float FSteerRatio;
	
protected:
	virtual void __fastcall SetVehicle(TGLBVehicle* const AValue);
	
public:
	__fastcall virtual TGLBaseSteerBehaviour(System::Classes::TComponent* AOwner);
	virtual void __fastcall ApplySteerForce() = 0 ;
	__property TGLBVehicle* Vehicle = {read=FVehicle, write=SetVehicle};
	__property float Ratio = {read=FSteerRatio, write=FSteerRatio};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TGLBaseSteerBehaviour() { }
	
};


class PASCALIMPLEMENTATION TGLWanderSteer : public TGLBaseSteerBehaviour
{
	typedef TGLBaseSteerBehaviour inherited;
	
private:
	Stage::Vectortypes::TGSVector FWanderModifier;
	double FRate;
	double FStrength;
	
protected:
	virtual void __fastcall SetVehicle(TGLBVehicle* const AValue);
	
public:
	__fastcall virtual TGLWanderSteer(System::Classes::TComponent* AOwner);
	virtual void __fastcall ApplySteerForce();
	__property double Rate = {read=FRate, write=FRate};
	__property double Strength = {read=FStrength, write=FStrength};
	__property Stage::Vectortypes::TGSVector WanderModifier = {read=FWanderModifier, write=FWanderModifier};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TGLWanderSteer() { }
	
};


class PASCALIMPLEMENTATION TGLSeekSteer : public TGLBaseSteerBehaviour
{
	typedef TGLBaseSteerBehaviour inherited;
	
private:
	Gls::Scene::TGLBaseSceneObject* FTarget;
	float FTurnRate;
	void __fastcall SetTarget(Gls::Scene::TGLBaseSceneObject* const Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLSeekSteer(System::Classes::TComponent* AOwner);
	virtual void __fastcall ApplySteerForce();
	__property Gls::Scene::TGLBaseSceneObject* Target = {read=FTarget, write=SetTarget};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TGLSeekSteer() { }
	
};


class PASCALIMPLEMENTATION TGLFleeSteer : public TGLBaseSteerBehaviour
{
	typedef TGLBaseSteerBehaviour inherited;
	
private:
	Gls::Scene::TGLBaseSceneObject* FTarget;
	void __fastcall SetTarget(Gls::Scene::TGLBaseSceneObject* const Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLFleeSteer(System::Classes::TComponent* AOwner);
	virtual void __fastcall ApplySteerForce();
	__property Gls::Scene::TGLBaseSceneObject* Target = {read=FTarget, write=SetTarget};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TGLFleeSteer() { }
	
};


class PASCALIMPLEMENTATION TGLPursueSteer : public TGLBaseSteerBehaviour
{
	typedef TGLBaseSteerBehaviour inherited;
	
private:
	Gls::Scene::TGLBaseSceneObject* FTarget;
	void __fastcall SetTarget(Gls::Scene::TGLBaseSceneObject* const Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLPursueSteer(System::Classes::TComponent* AOwner);
	virtual void __fastcall ApplySteerForce();
	__property Gls::Scene::TGLBaseSceneObject* Target = {read=FTarget, write=SetTarget};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TGLPursueSteer() { }
	
};


class PASCALIMPLEMENTATION TGLWorldCollisionSteer : public TGLBaseSteerBehaviour
{
	typedef TGLBaseSteerBehaviour inherited;
	
private:
	Gls::Vectorfileobjects::TGLFreeForm* FMap;
	bool FCollided;
	Stage::Vectortypes::TGSVector oldPosition;
	Stage::Vectortypes::TGSVector velocity;
	float FTurnRate;
	void __fastcall SetMap(Gls::Vectorfileobjects::TGLFreeForm* const Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	bool __fastcall SphereSweepAndSlide(Gls::Vectorfileobjects::TGLFreeForm* freeform, const Stage::Vectortypes::TGSVector &SphereStart, Stage::Vectortypes::TGSVector &velocity, Stage::Vectortypes::TGSVector &newPosition, float sphereRadius);
	virtual void __fastcall SetVehicle(TGLBVehicle* const AValue);
	
public:
	__fastcall virtual TGLWorldCollisionSteer(System::Classes::TComponent* AOwner);
	virtual void __fastcall ApplySteerForce();
	__property Gls::Vectorfileobjects::TGLFreeForm* Map = {read=FMap, write=SetMap};
	__property bool Collided = {read=FCollided, nodefault};
	__property float TurnRate = {read=FTurnRate, write=FTurnRate};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TGLWorldCollisionSteer() { }
	
};


class PASCALIMPLEMENTATION TGLBVehicle : public Gls::Scene::TGLBehaviour
{
	typedef Gls::Scene::TGLBehaviour inherited;
	
private:
	double FSteerUpdateInterval;
	int FMass;
	double FSpeed;
	double FMaxForce;
	double FMaxSpeed;
	Stage::Coordinates::TGSCoordinates* FUp;
	Stage::Coordinates::TGSCoordinates* FVelocity;
	Stage::Coordinates::TGSCoordinates* FAccumulator;
	Stage::Baseclasses::TGSProgressTimes FProgressTime;
	double FAccumulatedTime;
	TGLVehicleManager* FManager;
	int FGroupIndex;
	System::UnicodeString FManagerName;
	System::Contnrs::TObjectList* FSteerBehaviours;
	TGLSteeringBehaviours FGLSteeringBehaviours;
	TGLSeekSteer* FSeekSteer;
	TGLWanderSteer* FWanderSteer;
	TGLPursueSteer* FPursueSteer;
	TGLFleeSteer* FFleeSteer;
	TGLWorldCollisionSteer* FWorldCollisionSteer;
	Gls::Scene::TGLBaseSceneObject* FCollisionObject;
	
protected:
	void __fastcall SetGLSteeringBehaviours(const TGLSteeringBehaviours Value);
	void __fastcall SetManager(TGLVehicleManager* const Value);
	void __fastcall SetGroupIndex(const int Value);
	Stage::Coordinates::TGSCoordinates* __fastcall GetVelocity();
	void __fastcall SetVelocity(Stage::Coordinates::TGSCoordinates* const Value);
	double __fastcall GetSpeed();
	void __fastcall SetSpeed(const double Value);
	virtual void __fastcall WriteToFiler(System::Classes::TWriter* writer);
	virtual void __fastcall ReadFromFiler(System::Classes::TReader* reader);
	DYNAMIC void __fastcall Loaded();
	
public:
	__fastcall virtual TGLBVehicle(Stage::Xcollection::TXCollection* AOwner);
	__fastcall virtual ~TGLBVehicle();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall FriendlyName();
	__classmethod virtual System::UnicodeString __fastcall FriendlyDescription();
	virtual void __fastcall DoProgress(const Stage::Baseclasses::TGSProgressTimes &progressTime);
	void __fastcall DoSteering();
	__property Stage::Baseclasses::TGSProgressTimes progressTime = {read=FProgressTime, write=FProgressTime};
	__property double AccumulatedTime = {read=FAccumulatedTime, write=FAccumulatedTime};
	__property Gls::Scene::TGLBaseSceneObject* CollisionObject = {read=FCollisionObject, write=FCollisionObject};
	__property Stage::Coordinates::TGSCoordinates* Accumulator = {read=FAccumulator};
	__property TGLFleeSteer* Flee = {read=FFleeSteer, write=FFleeSteer};
	__property TGLSeekSteer* Seek = {read=FSeekSteer, write=FSeekSteer};
	__property TGLPursueSteer* Pursue = {read=FPursueSteer, write=FPursueSteer};
	__property TGLWanderSteer* Wander = {read=FWanderSteer, write=FWanderSteer};
	__property TGLWorldCollisionSteer* WorldCollision = {read=FWorldCollisionSteer, write=FWorldCollisionSteer};
	
__published:
	__property TGLVehicleManager* Manager = {read=FManager, write=SetManager};
	__property int GroupIndex = {read=FGroupIndex, write=SetGroupIndex, nodefault};
	__property int Mass = {read=FMass, write=FMass, nodefault};
	__property double MaxForce = {read=FMaxForce, write=FMaxForce};
	__property double MaxSpeed = {read=FMaxSpeed, write=FMaxSpeed};
	__property double Speed = {read=GetSpeed, write=SetSpeed};
	__property TGLSteeringBehaviours SteeringBehaviours = {read=FGLSteeringBehaviours, write=SetGLSteeringBehaviours, nodefault};
	__property double SteerUpdateInterval = {read=FSteerUpdateInterval, write=FSteerUpdateInterval};
	__property System::Contnrs::TObjectList* SteerBehaviours = {read=FSteerBehaviours, write=FSteerBehaviours};
	__property Stage::Coordinates::TGSCoordinates* Up = {read=FUp, write=FUp};
};


class PASCALIMPLEMENTATION TGLVehicleManager : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	double FSteerInterval;
	System::Classes::TList* FClients;
	Gls::Cadencer::TGLCadencer* FCadencer;
	Gls::Vectorfileobjects::TGLFreeForm* FWorldCollisionMap;
	void __fastcall SetCadencer(Gls::Cadencer::TGLCadencer* const Value);
	Gls::Cadencer::TGLCadencer* __fastcall GetCadencer();
	void __fastcall SetSteerInterval(const double Value);
	void __fastcall SetWorldCollisionMap(Gls::Vectorfileobjects::TGLFreeForm* const Value);
	
protected:
	void __fastcall RegisterClient(TGLBVehicle* aClient);
	void __fastcall DeRegisterClient(TGLBVehicle* aClient);
	void __fastcall DeRegisterAllClients();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLVehicleManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLVehicleManager();
	void __fastcall DoSteering();
	__property System::Classes::TList* Clients = {read=FClients};
	
__published:
	__property Gls::Cadencer::TGLCadencer* Cadencer = {read=GetCadencer, write=SetCadencer};
	__property double SteerInterval = {read=FSteerInterval, write=SetSteerInterval};
	__property Gls::Vectorfileobjects::TGLFreeForm* WorldCollisionMap = {read=FWorldCollisionMap, write=SetWorldCollisionMap};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TGLBVehicle* __fastcall GetOrCreateVehicle(Gls::Scene::TGLBehaviours* Behaviours)/* overload */;
extern DELPHI_PACKAGE TGLBVehicle* __fastcall GetOrCreateVehicle(Gls::Scene::TGLBaseSceneObject* obj)/* overload */;
}	/* namespace Vehicles */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_VEHICLES)
using namespace Gls::Vehicles;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_VehiclesHPP
