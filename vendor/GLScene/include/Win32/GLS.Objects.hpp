// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.Objects.pas' rev: 37.00 (Windows)

#ifndef GLS_ObjectsHPP
#define GLS_ObjectsHPP

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
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.Spline.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.PersistentClasses.hpp>
#include <Stage.OpenGLAdapter.hpp>
#include <Stage.BaseClasses.hpp>
#include <Stage.Coordinates.hpp>
#include <Stage.VectorLists.hpp>
#include <Stage.Silhouette.hpp>
#include <Stage.Color.hpp>
#include <GLS.Scene.hpp>
#include <GLS.Context.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <GLS.Nodes.hpp>
#include <GLS.State.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Objects
{
//-- forward type declarations -----------------------------------------------
struct TGLVertexRec;
class DELPHICLASS TGLDummyCube;
class DELPHICLASS TGLPlane;
class DELPHICLASS TGLSprite;
class DELPHICLASS TGLPointParameters;
class DELPHICLASS TGLPoints;
class DELPHICLASS TGLLinesNode;
class DELPHICLASS TGLLinesNodes;
class DELPHICLASS TGLLineBase;
class DELPHICLASS TGLNodedLines;
class DELPHICLASS TGLLines;
class DELPHICLASS TGLCube;
class DELPHICLASS TGLQuadricObject;
class DELPHICLASS TGLSphere;
class DELPHICLASS TGLPolygonBase;
class DELPHICLASS TGLSuperellipsoid;
//-- type declarations -------------------------------------------------------
typedef bool __fastcall (__closure *TGLVisibilityDeterminationEvent)(System::TObject* Sender, Gls::Rendercontextinfo::TGLRenderContextInfo &rci);

typedef TGLVertexRec *PGLVertexRec;

struct DECLSPEC_DRECORD TGLVertexRec
{
public:
	Stage::Vectortypes::TVector3f Position;
	Stage::Vectortypes::TVector3f Normal;
	Stage::Vectortypes::TVector3f Binormal;
	Stage::Vectortypes::TVector3f Tangent;
	Stage::Vectortypes::TVector2f TexCoord;
};


class PASCALIMPLEMENTATION TGLDummyCube : public Gls::Scene::TGLCameraInvariantObject
{
	typedef Gls::Scene::TGLCameraInvariantObject inherited;
	
private:
	Stage::Opengltokens::TGLfloat FCubeSize;
	Stage::Color::TGSColor* FEdgeColor;
	bool FVisibleAtRunTime;
	bool FAmalgamate;
	Gls::Context::TGLListHandle* FGroupList;
	TGLVisibilityDeterminationEvent FOnVisibilityDetermination;
	
protected:
	void __fastcall SetCubeSize(const Stage::Opengltokens::TGLfloat val);
	void __fastcall SetEdgeColor(Stage::Color::TGSColor* const val);
	void __fastcall SetVisibleAtRunTime(const bool val);
	void __fastcall SetAmalgamate(const bool val);
	
public:
	__fastcall virtual TGLDummyCube(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLDummyCube();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Stage::Vectortypes::TGSVector __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TGSVector &rayStart, const Stage::Vectortypes::TGSVector &rayVector, Stage::Vectortypes::PGSVector intersectPoint = (Stage::Vectortypes::PGSVector)(0x0), Stage::Vectortypes::PGSVector intersectNormal = (Stage::Vectortypes::PGSVector)(0x0));
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall DoRender(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, bool renderSelf, bool renderChildren);
	virtual void __fastcall StructureChanged();
	virtual Stage::Vectortypes::TGSVector __fastcall BarycenterAbsolutePosition();
	
__published:
	__property Stage::Opengltokens::TGLfloat CubeSize = {read=FCubeSize, write=SetCubeSize};
	__property Stage::Color::TGSColor* EdgeColor = {read=FEdgeColor, write=SetEdgeColor};
	__property bool VisibleAtRunTime = {read=FVisibleAtRunTime, write=SetVisibleAtRunTime, default=0};
	__property bool Amalgamate = {read=FAmalgamate, write=SetAmalgamate, default=0};
	__property CamInvarianceMode = {default=0};
	__property TGLVisibilityDeterminationEvent OnVisibilityDetermination = {read=FOnVisibilityDetermination, write=FOnVisibilityDetermination};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLDummyCube(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLCameraInvariantObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TGLPlaneStyle : unsigned char { psSingleQuad, psTileTexture };

typedef System::Set<TGLPlaneStyle, TGLPlaneStyle::psSingleQuad, TGLPlaneStyle::psTileTexture> TGLPlaneStyles;

class PASCALIMPLEMENTATION TGLPlane : public Gls::Scene::TGLSceneObject
{
	typedef Gls::Scene::TGLSceneObject inherited;
	
	
private:
	typedef System::DynamicArray<TGLVertexRec> _TGLPlane__1;
	
	typedef System::DynamicArray<System::DynamicArray<TGLVertexRec> > _TGLPlane__2;
	
	
private:
	Stage::Opengltokens::TGLfloat FXOffset;
	Stage::Opengltokens::TGLfloat FYOffset;
	Stage::Opengltokens::TGLfloat FXScope;
	Stage::Opengltokens::TGLfloat FYScope;
	Stage::Opengltokens::TGLfloat FWidth;
	Stage::Opengltokens::TGLfloat FHeight;
	unsigned FXTiles;
	unsigned FYTiles;
	TGLPlaneStyles FStyle;
	_TGLPlane__2 FMesh;
	
protected:
	void __fastcall SetHeight(const float aValue);
	void __fastcall SetWidth(const float aValue);
	void __fastcall SetXOffset(const Stage::Opengltokens::TGLfloat Value);
	void __fastcall SetXScope(const Stage::Opengltokens::TGLfloat Value);
	bool __fastcall StoreXScope();
	void __fastcall SetXTiles(const unsigned Value);
	void __fastcall SetYOffset(const Stage::Opengltokens::TGLfloat Value);
	void __fastcall SetYScope(const Stage::Opengltokens::TGLfloat Value);
	bool __fastcall StoreYScope();
	void __fastcall SetYTiles(const unsigned Value);
	void __fastcall SetStyle(const TGLPlaneStyles val);
	
public:
	__fastcall virtual TGLPlane(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual Stage::Silhouette::TGSSilhouette* __fastcall GenerateSilhouette(const Stage::Silhouette::TGSSilhouetteParameters &silhouetteParameters);
	virtual Stage::Vectortypes::TGSVector __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TGSVector &rayStart, const Stage::Vectortypes::TGSVector &rayVector, Stage::Vectortypes::PGSVector intersectPoint = (Stage::Vectortypes::PGSVector)(0x0), Stage::Vectortypes::PGSVector intersectNormal = (Stage::Vectortypes::PGSVector)(0x0));
	System::Types::TRect __fastcall ScreenRect(Gls::Scene::TGLSceneBuffer* aBuffer);
	float __fastcall PointDistance(const Stage::Vectortypes::TGSVector &aPoint);
	
__published:
	__property Stage::Opengltokens::TGLfloat Height = {read=FHeight, write=SetHeight};
	__property Stage::Opengltokens::TGLfloat Width = {read=FWidth, write=SetWidth};
	__property Stage::Opengltokens::TGLfloat XOffset = {read=FXOffset, write=SetXOffset};
	__property Stage::Opengltokens::TGLfloat XScope = {read=FXScope, write=SetXScope, stored=StoreXScope};
	__property unsigned XTiles = {read=FXTiles, write=SetXTiles, default=1};
	__property Stage::Opengltokens::TGLfloat YOffset = {read=FYOffset, write=SetYOffset};
	__property Stage::Opengltokens::TGLfloat YScope = {read=FYScope, write=SetYScope, stored=StoreYScope};
	__property unsigned YTiles = {read=FYTiles, write=SetYTiles, default=1};
	__property TGLPlaneStyles Style = {read=FStyle, write=SetStyle, default=3};
public:
	/* TGLCustomSceneObject.Destroy */ inline __fastcall virtual ~TGLPlane() { }
	
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLPlane(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLSprite : public Gls::Scene::TGLSceneObject
{
	typedef Gls::Scene::TGLSceneObject inherited;
	
private:
	Stage::Opengltokens::TGLfloat FWidth;
	Stage::Opengltokens::TGLfloat FHeight;
	Stage::Opengltokens::TGLfloat FRotation;
	float FAlphaChannel;
	bool FMirrorU;
	bool FMirrorV;
	
protected:
	void __fastcall SetWidth(const Stage::Opengltokens::TGLfloat val);
	void __fastcall SetHeight(const Stage::Opengltokens::TGLfloat val);
	HIDESBASE void __fastcall SetRotation(const Stage::Opengltokens::TGLfloat val);
	void __fastcall SetAlphaChannel(const float val);
	bool __fastcall StoreAlphaChannel();
	void __fastcall SetMirrorU(const bool val);
	void __fastcall SetMirrorV(const bool val);
	
public:
	__fastcall virtual TGLSprite(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual Stage::Vectortypes::TGSVector __fastcall AxisAlignedDimensionsUnscaled();
	void __fastcall SetSize(const Stage::Opengltokens::TGLfloat Width, const Stage::Opengltokens::TGLfloat Height);
	void __fastcall SetSquareSize(const Stage::Opengltokens::TGLfloat Size);
	
__published:
	__property Stage::Opengltokens::TGLfloat Width = {read=FWidth, write=SetWidth};
	__property Stage::Opengltokens::TGLfloat Height = {read=FHeight, write=SetHeight};
	__property Stage::Opengltokens::TGLfloat Rotation = {read=FRotation, write=SetRotation};
	__property float AlphaChannel = {read=FAlphaChannel, write=SetAlphaChannel, stored=StoreAlphaChannel};
	__property bool MirrorU = {read=FMirrorU, write=SetMirrorU, default=0};
	__property bool MirrorV = {read=FMirrorV, write=SetMirrorV, default=0};
public:
	/* TGLCustomSceneObject.Destroy */ inline __fastcall virtual ~TGLSprite() { }
	
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLSprite(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TGLPointStyle : unsigned char { psSquare, psRound, psSmooth, psSmoothAdditive, psSquareAdditive };

class PASCALIMPLEMENTATION TGLPointParameters : public Stage::Baseclasses::TGSUpdateAbleObject
{
	typedef Stage::Baseclasses::TGSUpdateAbleObject inherited;
	
private:
	bool FEnabled;
	float FMinSize;
	float FMaxSize;
	float FFadeTresholdSize;
	Stage::Coordinates::TGSCoordinates* FDistanceAttenuation;
	
protected:
	void __fastcall SetEnabled(const bool val);
	void __fastcall SetMinSize(const float val);
	void __fastcall SetMaxSize(const float val);
	void __fastcall SetFadeTresholdSize(const float val);
	void __fastcall SetDistanceAttenuation(Stage::Coordinates::TGSCoordinates* const val);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TGLPointParameters(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TGLPointParameters();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Apply();
	void __fastcall UnApply();
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=0};
	__property float MinSize = {read=FMinSize, write=SetMinSize, stored=false};
	__property float MaxSize = {read=FMaxSize, write=SetMaxSize, stored=false};
	__property float FadeTresholdSize = {read=FFadeTresholdSize, write=SetFadeTresholdSize, stored=false};
	__property Stage::Coordinates::TGSCoordinates* DistanceAttenuation = {read=FDistanceAttenuation, write=SetDistanceAttenuation};
};


class PASCALIMPLEMENTATION TGLPoints : public Gls::Scene::TGLImmaterialSceneObject
{
	typedef Gls::Scene::TGLImmaterialSceneObject inherited;
	
private:
	Stage::Vectorlists::TGSAffineVectorList* FPositions;
	Stage::Vectorlists::TGSVectorList* FColors;
	float FSize;
	TGLPointStyle FStyle;
	TGLPointParameters* FPointParameters;
	bool FStatic;
	bool FNoZWrite;
	
protected:
	bool __fastcall StoreSize();
	void __fastcall SetNoZWrite(const bool val);
	void __fastcall SetStatic(const bool val);
	void __fastcall SetSize(const float val);
	void __fastcall SetPositions(Stage::Vectorlists::TGSAffineVectorList* const val);
	void __fastcall SetColors(Stage::Vectorlists::TGSVectorList* const val);
	void __fastcall SetStyle(const TGLPointStyle val);
	void __fastcall SetPointParameters(TGLPointParameters* const val);
	
public:
	__fastcall virtual TGLPoints(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLPoints();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__property Stage::Vectorlists::TGSAffineVectorList* Positions = {read=FPositions, write=SetPositions};
	__property Stage::Vectorlists::TGSVectorList* Colors = {read=FColors, write=SetColors};
	
__published:
	__property bool NoZWrite = {read=FNoZWrite, write=SetNoZWrite, nodefault};
	__property bool Static = {read=FStatic, write=SetStatic, nodefault};
	__property float Size = {read=FSize, write=SetSize, stored=StoreSize};
	__property TGLPointStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property TGLPointParameters* PointParameters = {read=FPointParameters, write=SetPointParameters};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLPoints(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLImmaterialSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TGLLineNodesAspect : unsigned char { lnaInvisible, lnaAxes, lnaCube };

enum DECLSPEC_DENUM TGLLineSplineMode : unsigned char { lsmLines, lsmCubicSpline, lsmBezierSpline, lsmNURBSCurve, lsmSegments, lsmLoop };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLLinesNode : public Gls::Nodes::TGLNode
{
	typedef Gls::Nodes::TGLNode inherited;
	
private:
	Stage::Color::TGSColor* FColor;
	
protected:
	void __fastcall SetColor(Stage::Color::TGSColor* const val);
	void __fastcall OnColorChange(System::TObject* Sender);
	bool __fastcall StoreColor();
	
public:
	__fastcall virtual TGLLinesNode(System::Classes::TCollection* Collection);
	__fastcall virtual ~TGLLinesNode();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Stage::Color::TGSColor* Color = {read=FColor, write=SetColor, stored=StoreColor};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLLinesNodes : public Gls::Nodes::TGLNodes
{
	typedef Gls::Nodes::TGLNodes inherited;
	
public:
	__fastcall TGLLinesNodes(System::Classes::TComponent* AOwner)/* overload */;
	virtual void __fastcall NotifyChange();
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TGLLinesNodes() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TGLLineBase : public Gls::Scene::TGLImmaterialSceneObject
{
	typedef Gls::Scene::TGLImmaterialSceneObject inherited;
	
private:
	Stage::Color::TGSColor* FLineColor;
	Stage::Opengltokens::TGLushort FLinePattern;
	float FLineWidth;
	bool FAntiAliased;
	
protected:
	void __fastcall SetLineColor(Stage::Color::TGSColor* const Value);
	void __fastcall SetLinePattern(const Stage::Opengltokens::TGLushort Value);
	void __fastcall SetLineWidth(const float val);
	bool __fastcall StoreLineWidth();
	void __fastcall SetAntiAliased(const bool val);
	void __fastcall SetupLineStyle(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
public:
	__fastcall virtual TGLLineBase(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLLineBase();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	
__published:
	__property bool AntiAliased = {read=FAntiAliased, write=SetAntiAliased, default=0};
	__property Stage::Color::TGSColor* LineColor = {read=FLineColor, write=SetLineColor};
	__property Stage::Opengltokens::TGLushort LinePattern = {read=FLinePattern, write=SetLinePattern, default=65535};
	__property float LineWidth = {read=FLineWidth, write=SetLineWidth, stored=StoreLineWidth};
	__property Visible = {default=1};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLLineBase(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLImmaterialSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLNodedLines : public TGLLineBase
{
	typedef TGLLineBase inherited;
	
private:
	TGLLinesNodes* FNodes;
	TGLLineNodesAspect FNodesAspect;
	Stage::Color::TGSColor* FNodeColor;
	float FNodeSize;
	Stage::Color::TGSColorVector FOldNodeColor;
	
protected:
	void __fastcall SetNodesAspect(const TGLLineNodesAspect Value);
	void __fastcall SetNodeColor(Stage::Color::TGSColor* const Value);
	void __fastcall OnNodeColorChanged(System::TObject* Sender);
	void __fastcall SetNodes(TGLLinesNodes* const aNodes);
	void __fastcall SetNodeSize(const float val);
	bool __fastcall StoreNodeSize();
	void __fastcall DrawNode(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, float X, float Y, float Z, Stage::Color::TGSColor* Color);
	
public:
	__fastcall virtual TGLNodedLines(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLNodedLines();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Stage::Vectortypes::TGSVector __fastcall AxisAlignedDimensionsUnscaled();
	void __fastcall AddNode(Stage::Coordinates::TGSCoordinates* const coords)/* overload */;
	void __fastcall AddNode(const Stage::Opengltokens::TGLfloat X, const Stage::Opengltokens::TGLfloat Y, const Stage::Opengltokens::TGLfloat Z)/* overload */;
	void __fastcall AddNode(const Stage::Vectortypes::TGSVector &Value)/* overload */;
	void __fastcall AddNode(const Stage::Vectorgeometry::TAffineVector &Value)/* overload */;
	
__published:
	__property Stage::Color::TGSColor* NodeColor = {read=FNodeColor, write=SetNodeColor};
	__property TGLLinesNodes* Nodes = {read=FNodes, write=SetNodes};
	__property TGLLineNodesAspect NodesAspect = {read=FNodesAspect, write=SetNodesAspect, default=1};
	__property float NodeSize = {read=FNodeSize, write=SetNodeSize, stored=StoreNodeSize};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLNodedLines(Gls::Scene::TGLBaseSceneObject* aParentOwner) : TGLLineBase(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TGLLinesOption : unsigned char { loUseNodeColorForLines, loColorLogicXor };

typedef System::Set<TGLLinesOption, TGLLinesOption::loUseNodeColorForLines, TGLLinesOption::loColorLogicXor> TGLLinesOptions;

class PASCALIMPLEMENTATION TGLLines : public TGLNodedLines
{
	typedef TGLNodedLines inherited;
	
private:
	int FDivision;
	TGLLineSplineMode FSplineMode;
	TGLLinesOptions FOptions;
	int FNURBSOrder;
	float FNURBSTolerance;
	Stage::Vectorlists::TGSSingleList* FNURBSKnots;
	
protected:
	void __fastcall SetSplineMode(const TGLLineSplineMode val);
	void __fastcall SetDivision(const int Value);
	void __fastcall SetOptions(const TGLLinesOptions val);
	void __fastcall SetNURBSOrder(const int val);
	void __fastcall SetNURBSTolerance(const float val);
	
public:
	__fastcall virtual TGLLines(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLLines();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__property Stage::Vectorlists::TGSSingleList* NURBSKnots = {read=FNURBSKnots};
	__property int NURBSOrder = {read=FNURBSOrder, write=SetNURBSOrder, nodefault};
	__property float NURBSTolerance = {read=FNURBSTolerance, write=SetNURBSTolerance};
	
__published:
	__property int Division = {read=FDivision, write=SetDivision, default=10};
	__property TGLLineSplineMode SplineMode = {read=FSplineMode, write=SetSplineMode, default=0};
	__property TGLLinesOptions Options = {read=FOptions, write=SetOptions, nodefault};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLLines(Gls::Scene::TGLBaseSceneObject* aParentOwner) : TGLNodedLines(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TGLCubePart : unsigned char { cpTop, cpBottom, cpFront, cpBack, cpLeft, cpRight };

typedef System::Set<TGLCubePart, TGLCubePart::cpTop, TGLCubePart::cpRight> TGLCubeParts;

class PASCALIMPLEMENTATION TGLCube : public Gls::Scene::TGLSceneObject
{
	typedef Gls::Scene::TGLSceneObject inherited;
	
private:
	Stage::Vectorgeometry::TAffineVector FCubeSize;
	TGLCubeParts FParts;
	Gls::Scene::TGLNormalDirection FNormalDirection;
	Stage::Opengltokens::TGLfloat __fastcall GetCubeWHD(const int Index);
	void __fastcall SetCubeWHD(int Index, Stage::Opengltokens::TGLfloat aValue);
	void __fastcall SetParts(TGLCubeParts aValue);
	void __fastcall SetNormalDirection(Gls::Scene::TGLNormalDirection aValue);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TGLCube(System::Classes::TComponent* AOwner);
	virtual Stage::Silhouette::TGSSilhouette* __fastcall GenerateSilhouette(const Stage::Silhouette::TGSSilhouetteParameters &silhouetteParameters);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Stage::Vectortypes::TGSVector __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TGSVector &rayStart, const Stage::Vectortypes::TGSVector &rayVector, Stage::Vectortypes::PGSVector intersectPoint = (Stage::Vectortypes::PGSVector)(0x0), Stage::Vectortypes::PGSVector intersectNormal = (Stage::Vectortypes::PGSVector)(0x0));
	
__published:
	__property Stage::Opengltokens::TGLfloat CubeWidth = {read=GetCubeWHD, write=SetCubeWHD, stored=false, index=0};
	__property Stage::Opengltokens::TGLfloat CubeHeight = {read=GetCubeWHD, write=SetCubeWHD, stored=false, index=1};
	__property Stage::Opengltokens::TGLfloat CubeDepth = {read=GetCubeWHD, write=SetCubeWHD, stored=false, index=2};
	__property Gls::Scene::TGLNormalDirection NormalDirection = {read=FNormalDirection, write=SetNormalDirection, default=1};
	__property TGLCubeParts Parts = {read=FParts, write=SetParts, default=63};
public:
	/* TGLCustomSceneObject.Destroy */ inline __fastcall virtual ~TGLCube() { }
	
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLCube(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLSceneObject(aParentOwner) { }
	
};


enum DECLSPEC_DENUM TGLNormalSmoothing : unsigned char { nsFlat, nsSmooth, nsNone };

class PASCALIMPLEMENTATION TGLQuadricObject : public Gls::Scene::TGLSceneObject
{
	typedef Gls::Scene::TGLSceneObject inherited;
	
private:
	TGLNormalSmoothing FNormals;
	Gls::Scene::TGLNormalDirection FNormalDirection;
	
protected:
	void __fastcall SetNormals(TGLNormalSmoothing aValue);
	void __fastcall SetNormalDirection(Gls::Scene::TGLNormalDirection aValue);
	void __fastcall SetupQuadricParams(Stage::Opengltokens::PGLUQuadricObj quadric);
	void __fastcall SetNormalQuadricOrientation(Stage::Opengltokens::PGLUQuadricObj quadric);
	void __fastcall SetInvertedQuadricOrientation(Stage::Opengltokens::PGLUQuadricObj quadric);
	
public:
	__fastcall virtual TGLQuadricObject(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TGLNormalSmoothing Normals = {read=FNormals, write=SetNormals, default=1};
	__property Gls::Scene::TGLNormalDirection NormalDirection = {read=FNormalDirection, write=SetNormalDirection, default=1};
public:
	/* TGLCustomSceneObject.Destroy */ inline __fastcall virtual ~TGLQuadricObject() { }
	
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLQuadricObject(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLSceneObject(aParentOwner) { }
	
};


typedef System::Int8 TGLAngleLimit180;

typedef System::Word TGLAngleLimit360;

enum DECLSPEC_DENUM TGLCapType : unsigned char { ctNone, ctCenter, ctFlat };

class PASCALIMPLEMENTATION TGLSphere : public TGLQuadricObject
{
	typedef TGLQuadricObject inherited;
	
private:
	Stage::Opengltokens::TGLfloat FRadius;
	Stage::Opengltokens::TGLint FSlices;
	Stage::Opengltokens::TGLint FStacks;
	TGLAngleLimit180 FTop;
	TGLAngleLimit180 FBottom;
	TGLAngleLimit360 FStart;
	TGLAngleLimit360 FStop;
	TGLCapType FTopCap;
	TGLCapType FBottomCap;
	void __fastcall SetBottom(TGLAngleLimit180 aValue);
	void __fastcall SetBottomCap(TGLCapType aValue);
	void __fastcall SetRadius(const Stage::Opengltokens::TGLfloat aValue);
	void __fastcall SetSlices(Stage::Opengltokens::TGLint aValue);
	void __fastcall SetStart(TGLAngleLimit360 aValue);
	void __fastcall SetStop(TGLAngleLimit360 aValue);
	void __fastcall SetStacks(Stage::Opengltokens::TGLint aValue);
	void __fastcall SetTop(TGLAngleLimit180 aValue);
	void __fastcall SetTopCap(TGLCapType aValue);
	
public:
	__fastcall virtual TGLSphere(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual Stage::Vectortypes::TGSVector __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TGSVector &rayStart, const Stage::Vectortypes::TGSVector &rayVector, Stage::Vectortypes::PGSVector intersectPoint = (Stage::Vectortypes::PGSVector)(0x0), Stage::Vectortypes::PGSVector intersectNormal = (Stage::Vectortypes::PGSVector)(0x0));
	virtual Stage::Silhouette::TGSSilhouette* __fastcall GenerateSilhouette(const Stage::Silhouette::TGSSilhouetteParameters &silhouetteParameters);
	
__published:
	__property TGLAngleLimit180 Bottom = {read=FBottom, write=SetBottom, default=-90};
	__property TGLCapType BottomCap = {read=FBottomCap, write=SetBottomCap, default=0};
	__property Stage::Opengltokens::TGLfloat Radius = {read=FRadius, write=SetRadius};
	__property Stage::Opengltokens::TGLint Slices = {read=FSlices, write=SetSlices, default=32};
	__property Stage::Opengltokens::TGLint Stacks = {read=FStacks, write=SetStacks, default=32};
	__property TGLAngleLimit360 Start = {read=FStart, write=SetStart, default=0};
	__property TGLAngleLimit360 Stop = {read=FStop, write=SetStop, default=360};
	__property TGLAngleLimit180 Top = {read=FTop, write=SetTop, default=90};
	__property TGLCapType TopCap = {read=FTopCap, write=SetTopCap, default=0};
public:
	/* TGLCustomSceneObject.Destroy */ inline __fastcall virtual ~TGLSphere() { }
	
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLSphere(Gls::Scene::TGLBaseSceneObject* aParentOwner) : TGLQuadricObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLPolygonBase : public Gls::Scene::TGLSceneObject
{
	typedef Gls::Scene::TGLSceneObject inherited;
	
private:
	int FDivision;
	TGLLineSplineMode FSplineMode;
	
protected:
	Gls::Nodes::TGLNodes* FNodes;
	DYNAMIC void __fastcall CreateNodes();
	void __fastcall SetSplineMode(const TGLLineSplineMode val);
	void __fastcall SetDivision(const int Value);
	void __fastcall SetNodes(Gls::Nodes::TGLNodes* const aNodes);
	
public:
	__fastcall virtual TGLPolygonBase(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLPolygonBase();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	void __fastcall AddNode(Stage::Coordinates::TGSCoordinates* const coords)/* overload */;
	void __fastcall AddNode(const Stage::Opengltokens::TGLfloat X, const Stage::Opengltokens::TGLfloat Y, const Stage::Opengltokens::TGLfloat Z)/* overload */;
	void __fastcall AddNode(const Stage::Vectortypes::TGSVector &Value)/* overload */;
	void __fastcall AddNode(const Stage::Vectorgeometry::TAffineVector &Value)/* overload */;
	
__published:
	__property Gls::Nodes::TGLNodes* Nodes = {read=FNodes, write=SetNodes};
	__property int Division = {read=FDivision, write=SetDivision, default=10};
	__property TGLLineSplineMode SplineMode = {read=FSplineMode, write=SetSplineMode, default=0};
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLPolygonBase(Gls::Scene::TGLBaseSceneObject* aParentOwner) : Gls::Scene::TGLSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TGLSuperellipsoid : public TGLQuadricObject
{
	typedef TGLQuadricObject inherited;
	
private:
	Stage::Opengltokens::TGLfloat FRadius;
	Stage::Opengltokens::TGLfloat FVCurve;
	Stage::Opengltokens::TGLfloat FHCurve;
	Stage::Opengltokens::TGLint FSlices;
	Stage::Opengltokens::TGLint FStacks;
	TGLAngleLimit180 FTop;
	TGLAngleLimit180 FBottom;
	TGLAngleLimit360 FStart;
	TGLAngleLimit360 FStop;
	TGLCapType FTopCap;
	TGLCapType FBottomCap;
	void __fastcall SetBottom(TGLAngleLimit180 aValue);
	void __fastcall SetBottomCap(TGLCapType aValue);
	void __fastcall SetRadius(const Stage::Opengltokens::TGLfloat aValue);
	void __fastcall SetVCurve(const Stage::Opengltokens::TGLfloat aValue);
	void __fastcall SetHCurve(const Stage::Opengltokens::TGLfloat aValue);
	void __fastcall SetSlices(Stage::Opengltokens::TGLint aValue);
	void __fastcall SetStart(TGLAngleLimit360 aValue);
	void __fastcall SetStop(TGLAngleLimit360 aValue);
	void __fastcall SetStacks(Stage::Opengltokens::TGLint aValue);
	void __fastcall SetTop(TGLAngleLimit180 aValue);
	void __fastcall SetTopCap(TGLCapType aValue);
	
public:
	__fastcall virtual TGLSuperellipsoid(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual Stage::Vectortypes::TGSVector __fastcall AxisAlignedDimensionsUnscaled();
	virtual bool __fastcall RayCastIntersect(const Stage::Vectortypes::TGSVector &rayStart, const Stage::Vectortypes::TGSVector &rayVector, Stage::Vectortypes::PGSVector intersectPoint = (Stage::Vectortypes::PGSVector)(0x0), Stage::Vectortypes::PGSVector intersectNormal = (Stage::Vectortypes::PGSVector)(0x0));
	virtual Stage::Silhouette::TGSSilhouette* __fastcall GenerateSilhouette(const Stage::Silhouette::TGSSilhouetteParameters &silhouetteParameters);
	
__published:
	__property TGLAngleLimit180 Bottom = {read=FBottom, write=SetBottom, default=-90};
	__property TGLCapType BottomCap = {read=FBottomCap, write=SetBottomCap, default=0};
	__property Stage::Opengltokens::TGLfloat Radius = {read=FRadius, write=SetRadius};
	__property Stage::Opengltokens::TGLfloat VCurve = {read=FVCurve, write=SetVCurve};
	__property Stage::Opengltokens::TGLfloat HCurve = {read=FHCurve, write=SetHCurve};
	__property Stage::Opengltokens::TGLint Slices = {read=FSlices, write=SetSlices, default=32};
	__property Stage::Opengltokens::TGLint Stacks = {read=FStacks, write=SetStacks, default=32};
	__property TGLAngleLimit360 Start = {read=FStart, write=SetStart, default=0};
	__property TGLAngleLimit360 Stop = {read=FStop, write=SetStop, default=360};
	__property TGLAngleLimit180 Top = {read=FTop, write=SetTop, default=90};
	__property TGLCapType TopCap = {read=FTopCap, write=SetTopCap, default=0};
public:
	/* TGLCustomSceneObject.Destroy */ inline __fastcall virtual ~TGLSuperellipsoid() { }
	
public:
	/* TGLBaseSceneObject.CreateAsChild */ inline __fastcall TGLSuperellipsoid(Gls::Scene::TGLBaseSceneObject* aParentOwner) : TGLQuadricObject(aParentOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE float cDefaultPointSize;
extern DELPHI_PACKAGE char *TangentAttributeName;
extern DELPHI_PACKAGE char *BinormalAttributeName;
extern DELPHI_PACKAGE void __fastcall CubeWireframeBuildList(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, Stage::Opengltokens::TGLfloat Size, bool Stipple, const Stage::Color::TGSColorVector &Color);
}	/* namespace Objects */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_OBJECTS)
using namespace Gls::Objects;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_ObjectsHPP
