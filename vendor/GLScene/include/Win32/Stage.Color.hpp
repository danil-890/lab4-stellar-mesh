// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stage.Color.pas' rev: 37.00 (Windows)

#ifndef Stage_ColorHPP
#define Stage_ColorHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.UITypes.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.Utils.hpp>
#include <Stage.PersistentClasses.hpp>
#include <Stage.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stage
{
namespace Color
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGSColor;
struct TGSColorEntry;
class DELPHICLASS TGSColorManager;
//-- type declarations -------------------------------------------------------
typedef Stage::Vectortypes::TVector4f *PGSColorVector;

typedef Stage::Vectortypes::TVector4f TGSColorVector;

typedef Stage::Vectortypes::TVector3b *PRGBColor;

typedef Stage::Vectortypes::TVector3b TRGBColor;

class PASCALIMPLEMENTATION TGSColor : public Stage::Baseclasses::TGSUpdateAbleObject
{
	typedef Stage::Baseclasses::TGSUpdateAbleObject inherited;
	
private:
	TGSColorVector FColor;
	PGSColorVector FPDefaultColor;
	void __fastcall SetColorVector(const TGSColorVector &aColor)/* overload */;
	void __fastcall SetColorComponent(int index, float value);
	float __fastcall GetColorComponent(const int index);
	void __fastcall SetAsWinColor(const System::Uitypes::TColor val);
	System::Uitypes::TColor __fastcall GetAsWinColor();
	void __fastcall SetDirectColorVector(const TGSColorVector &aColor);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	Stage::Vectortypes::TGSVector __fastcall GetHSVA();
	void __fastcall SetHSVA(const Stage::Vectortypes::TGSVector &hsva);
	
public:
	__fastcall virtual TGSColor(System::Classes::TPersistent* AOwner);
	__fastcall TGSColor(System::Classes::TPersistent* AOwner, const TGSColorVector &Color, System::Classes::TNotifyEvent changeEvent);
	__fastcall virtual ~TGSColor();
	virtual void __fastcall NotifyChange(System::TObject* Sender);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Initialize(const TGSColorVector &color);
	System::PSingle __fastcall AsAddress();
	void __fastcall RandomColor();
	void __fastcall SetColor(float Red, float Green, float Blue, float Alpha = 1.000000E+00f)/* overload */;
	__property TGSColorVector Color = {read=FColor, write=SetColorVector};
	__property TGSColorVector DirectColor = {read=FColor, write=SetDirectColorVector};
	__property System::Uitypes::TColor AsWinColor = {read=GetAsWinColor, write=SetAsWinColor, nodefault};
	__property Stage::Vectortypes::TGSVector hsva = {read=GetHSVA, write=SetHSVA};
	__property TGSColorVector DefaultColor = {read=FColor};
	
__published:
	__property float Red = {read=GetColorComponent, write=SetColorComponent, stored=false, index=0};
	__property float Green = {read=GetColorComponent, write=SetColorComponent, stored=false, index=1};
	__property float Blue = {read=GetColorComponent, write=SetColorComponent, stored=false, index=2};
	__property float Alpha = {read=GetColorComponent, write=SetColorComponent, stored=false, index=3};
};


typedef TGSColorEntry *PGSColorEntry;

struct DECLSPEC_DRECORD TGSColorEntry
{
public:
	System::UnicodeString Name;
	TGSColorVector Color;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGSColorManager : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	__fastcall virtual ~TGSColorManager();
	void __fastcall AddColor(const System::UnicodeString aName, const TGSColorVector &aColor);
	void __fastcall EnumColors(System::Classes::TGetStrProc Proc)/* overload */;
	void __fastcall EnumColors(System::Classes::TStrings* AValues)/* overload */;
	TGSColorVector __fastcall FindColor(const System::UnicodeString aName);
	TGSColorVector __fastcall GetColor(const System::UnicodeString aName);
	System::UnicodeString __fastcall GetColorName(const TGSColorVector &aColor);
	void __fastcall RegisterDefaultColors();
	void __fastcall RemoveColor(const System::UnicodeString aName);
public:
	/* TObject.Create */ inline __fastcall TGSColorManager() : System::Classes::TList() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Uitypes::TColor clForeground = System::Uitypes::TColor(-1);
static _DELPHI_CONST System::Uitypes::TColor clButton = System::Uitypes::TColor(-2);
static _DELPHI_CONST System::Uitypes::TColor clLight = System::Uitypes::TColor(-3);
static _DELPHI_CONST System::Uitypes::TColor clMidlight = System::Uitypes::TColor(-4);
static _DELPHI_CONST System::Uitypes::TColor clDark = System::Uitypes::TColor(-5);
static _DELPHI_CONST System::Uitypes::TColor clMid = System::Uitypes::TColor(-6);
static _DELPHI_CONST System::Uitypes::TColor clText = System::Uitypes::TColor(-7);
static _DELPHI_CONST System::Uitypes::TColor clBrightText = System::Uitypes::TColor(-8);
static _DELPHI_CONST System::Uitypes::TColor clButtonText = System::Uitypes::TColor(-9);
static _DELPHI_CONST System::Uitypes::TColor clBase = System::Uitypes::TColor(-10);
static _DELPHI_CONST System::Uitypes::TColor clBackground = System::Uitypes::TColor(-11);
static _DELPHI_CONST System::Uitypes::TColor clShadow = System::Uitypes::TColor(-12);
static _DELPHI_CONST System::Uitypes::TColor clHighlight = System::Uitypes::TColor(-13);
static _DELPHI_CONST System::Uitypes::TColor clHighlightedText = System::Uitypes::TColor(-14);
static _DELPHI_CONST System::Int8 cloNormal = System::Int8(0x20);
static _DELPHI_CONST System::Int8 cloDisabled = System::Int8(0x40);
static _DELPHI_CONST System::Int8 cloActive = System::Int8(0x60);
static _DELPHI_CONST System::Uitypes::TColor clNormalForeground = System::Uitypes::TColor(-33);
static _DELPHI_CONST System::Uitypes::TColor clNormalButton = System::Uitypes::TColor(-34);
static _DELPHI_CONST System::Uitypes::TColor clNormalLight = System::Uitypes::TColor(-35);
static _DELPHI_CONST System::Uitypes::TColor clNormalMidlight = System::Uitypes::TColor(-36);
static _DELPHI_CONST System::Uitypes::TColor clNormalDark = System::Uitypes::TColor(-37);
static _DELPHI_CONST System::Uitypes::TColor clNormalMid = System::Uitypes::TColor(-38);
static _DELPHI_CONST System::Uitypes::TColor clNormalText = System::Uitypes::TColor(-39);
static _DELPHI_CONST System::Uitypes::TColor clNormalBrightText = System::Uitypes::TColor(-40);
static _DELPHI_CONST System::Uitypes::TColor clNormalButtonText = System::Uitypes::TColor(-41);
static _DELPHI_CONST System::Uitypes::TColor clNormalBase = System::Uitypes::TColor(-42);
static _DELPHI_CONST System::Uitypes::TColor clNormalBackground = System::Uitypes::TColor(-43);
static _DELPHI_CONST System::Uitypes::TColor clNormalShadow = System::Uitypes::TColor(-44);
static _DELPHI_CONST System::Uitypes::TColor clNormalHighlight = System::Uitypes::TColor(-45);
static _DELPHI_CONST System::Uitypes::TColor clNormalHighlightedText = System::Uitypes::TColor(-46);
static _DELPHI_CONST System::Uitypes::TColor clDisabledForeground = System::Uitypes::TColor(-65);
static _DELPHI_CONST System::Uitypes::TColor clDisabledButton = System::Uitypes::TColor(-66);
static _DELPHI_CONST System::Uitypes::TColor clDisabledLight = System::Uitypes::TColor(-67);
static _DELPHI_CONST System::Uitypes::TColor clDisabledMidlight = System::Uitypes::TColor(-68);
static _DELPHI_CONST System::Uitypes::TColor clDisabledDark = System::Uitypes::TColor(-69);
static _DELPHI_CONST System::Uitypes::TColor clDisabledMid = System::Uitypes::TColor(-70);
static _DELPHI_CONST System::Uitypes::TColor clDisabledText = System::Uitypes::TColor(-71);
static _DELPHI_CONST System::Uitypes::TColor clDisabledBrightText = System::Uitypes::TColor(-72);
static _DELPHI_CONST System::Uitypes::TColor clDisabledButtonText = System::Uitypes::TColor(-73);
static _DELPHI_CONST System::Uitypes::TColor clDisabledBase = System::Uitypes::TColor(-74);
static _DELPHI_CONST System::Uitypes::TColor clDisabledBackground = System::Uitypes::TColor(-75);
static _DELPHI_CONST System::Uitypes::TColor clDisabledShadow = System::Uitypes::TColor(-76);
static _DELPHI_CONST System::Uitypes::TColor clDisabledHighlight = System::Uitypes::TColor(-77);
static _DELPHI_CONST System::Uitypes::TColor clDisabledHighlightedText = System::Uitypes::TColor(-78);
static _DELPHI_CONST System::Uitypes::TColor clActiveForeground = System::Uitypes::TColor(-97);
static _DELPHI_CONST System::Uitypes::TColor clActiveButton = System::Uitypes::TColor(-98);
static _DELPHI_CONST System::Uitypes::TColor clActiveLight = System::Uitypes::TColor(-99);
static _DELPHI_CONST System::Uitypes::TColor clActiveMidlight = System::Uitypes::TColor(-100);
static _DELPHI_CONST System::Uitypes::TColor clActiveDark = System::Uitypes::TColor(-101);
static _DELPHI_CONST System::Uitypes::TColor clActiveMid = System::Uitypes::TColor(-102);
static _DELPHI_CONST System::Uitypes::TColor clActiveText = System::Uitypes::TColor(-103);
static _DELPHI_CONST System::Uitypes::TColor clActiveBrightText = System::Uitypes::TColor(-104);
static _DELPHI_CONST System::Uitypes::TColor clActiveButtonText = System::Uitypes::TColor(-105);
static _DELPHI_CONST System::Uitypes::TColor clActiveBase = System::Uitypes::TColor(-106);
static _DELPHI_CONST System::Uitypes::TColor clActiveBackground = System::Uitypes::TColor(-107);
static _DELPHI_CONST System::Uitypes::TColor clActiveShadow = System::Uitypes::TColor(-108);
static _DELPHI_CONST System::Uitypes::TColor clActiveHighlight = System::Uitypes::TColor(-109);
static _DELPHI_CONST System::Uitypes::TColor clActiveHighlightedText = System::Uitypes::TColor(-110);
static _DELPHI_CONST System::Uitypes::TColor clFirstSpecialColor = System::Uitypes::TColor(-110);
static _DELPHI_CONST System::Uitypes::TColor clMask = System::Uitypes::TColor(0);
static _DELPHI_CONST System::Uitypes::TColor clDontMask = System::Uitypes::TColor(16777215);
extern DELPHI_PACKAGE TGSColorVector clrScrollBar;
extern DELPHI_PACKAGE TGSColorVector clrBackground;
extern DELPHI_PACKAGE TGSColorVector clrActiveCaption;
extern DELPHI_PACKAGE TGSColorVector clrInactiveCaption;
extern DELPHI_PACKAGE TGSColorVector clrMenu;
extern DELPHI_PACKAGE TGSColorVector clrWindow;
extern DELPHI_PACKAGE TGSColorVector clrWindowFrame;
extern DELPHI_PACKAGE TGSColorVector clrMenuText;
extern DELPHI_PACKAGE TGSColorVector clrWindowText;
extern DELPHI_PACKAGE TGSColorVector clrCaptionText;
extern DELPHI_PACKAGE TGSColorVector clrActiveBorder;
extern DELPHI_PACKAGE TGSColorVector clrInactiveBorder;
extern DELPHI_PACKAGE TGSColorVector clrAppWorkSpace;
extern DELPHI_PACKAGE TGSColorVector clrHighlight;
extern DELPHI_PACKAGE TGSColorVector clrHighlightText;
extern DELPHI_PACKAGE TGSColorVector clrBtnFace;
extern DELPHI_PACKAGE TGSColorVector clrBtnShadow;
extern DELPHI_PACKAGE TGSColorVector clrGrayText;
extern DELPHI_PACKAGE TGSColorVector clrBtnText;
extern DELPHI_PACKAGE TGSColorVector clrInactiveCaptionText;
extern DELPHI_PACKAGE TGSColorVector clrBtnHighlight;
extern DELPHI_PACKAGE TGSColorVector clr3DDkShadow;
extern DELPHI_PACKAGE TGSColorVector clr3DLight;
extern DELPHI_PACKAGE TGSColorVector clrInfoText;
extern DELPHI_PACKAGE TGSColorVector clrInfoBk;
extern DELPHI_PACKAGE TGSColorVector clrTransparent;
extern DELPHI_PACKAGE TGSColorVector clrBlack;
extern DELPHI_PACKAGE TGSColorVector clrGray05;
extern DELPHI_PACKAGE TGSColorVector clrGray10;
extern DELPHI_PACKAGE TGSColorVector clrGray15;
extern DELPHI_PACKAGE TGSColorVector clrGray20;
extern DELPHI_PACKAGE TGSColorVector clrGray25;
extern DELPHI_PACKAGE TGSColorVector clrGray30;
extern DELPHI_PACKAGE TGSColorVector clrGray35;
extern DELPHI_PACKAGE TGSColorVector clrGray40;
extern DELPHI_PACKAGE TGSColorVector clrGray45;
extern DELPHI_PACKAGE TGSColorVector clrGray50;
extern DELPHI_PACKAGE TGSColorVector clrGray55;
extern DELPHI_PACKAGE TGSColorVector clrGray60;
extern DELPHI_PACKAGE TGSColorVector clrGray65;
extern DELPHI_PACKAGE TGSColorVector clrGray70;
extern DELPHI_PACKAGE TGSColorVector clrGray75;
extern DELPHI_PACKAGE TGSColorVector clrGray80;
extern DELPHI_PACKAGE TGSColorVector clrGray85;
extern DELPHI_PACKAGE TGSColorVector clrGray90;
extern DELPHI_PACKAGE TGSColorVector clrGray95;
extern DELPHI_PACKAGE TGSColorVector clrWhite;
extern DELPHI_PACKAGE TGSColorVector clrDimGray;
extern DELPHI_PACKAGE TGSColorVector clrGray;
extern DELPHI_PACKAGE TGSColorVector clrLightGray;
extern DELPHI_PACKAGE TGSColorVector clrAqua;
extern DELPHI_PACKAGE TGSColorVector clrAquamarine;
extern DELPHI_PACKAGE TGSColorVector clrBakersChoc;
extern DELPHI_PACKAGE TGSColorVector clrBlue;
extern DELPHI_PACKAGE TGSColorVector clrBlueViolet;
extern DELPHI_PACKAGE TGSColorVector clrBrown;
extern DELPHI_PACKAGE TGSColorVector clrCadetBlue;
extern DELPHI_PACKAGE TGSColorVector clrCoral;
extern DELPHI_PACKAGE TGSColorVector clrCornflowerBlue;
extern DELPHI_PACKAGE TGSColorVector clrDarkGreen;
extern DELPHI_PACKAGE TGSColorVector clrDarkOliveGreen;
extern DELPHI_PACKAGE TGSColorVector clrDarkOrchid;
extern DELPHI_PACKAGE TGSColorVector clrDarkSlateBlue;
extern DELPHI_PACKAGE TGSColorVector clrDarkSlateGray;
extern DELPHI_PACKAGE TGSColorVector clrDarkSlateGrey;
extern DELPHI_PACKAGE TGSColorVector clrDarkTurquoise;
extern DELPHI_PACKAGE TGSColorVector clrFirebrick;
extern DELPHI_PACKAGE TGSColorVector clrForestGreen;
extern DELPHI_PACKAGE TGSColorVector clrFuchsia;
extern DELPHI_PACKAGE TGSColorVector clrGold;
extern DELPHI_PACKAGE TGSColorVector clrGoldenrod;
extern DELPHI_PACKAGE TGSColorVector clrGreenYellow;
extern DELPHI_PACKAGE TGSColorVector clrIndian;
extern DELPHI_PACKAGE TGSColorVector clrKhaki;
extern DELPHI_PACKAGE TGSColorVector clrLightBlue;
extern DELPHI_PACKAGE TGSColorVector clrLightSteelBlue;
extern DELPHI_PACKAGE TGSColorVector clrLime;
extern DELPHI_PACKAGE TGSColorVector clrLimeGreen;
extern DELPHI_PACKAGE TGSColorVector clrMaroon;
extern DELPHI_PACKAGE TGSColorVector clrMediumAquamarine;
extern DELPHI_PACKAGE TGSColorVector clrMediumBlue;
extern DELPHI_PACKAGE TGSColorVector clrMediumForestGreen;
extern DELPHI_PACKAGE TGSColorVector clrMediumGoldenrod;
extern DELPHI_PACKAGE TGSColorVector clrMediumOrchid;
extern DELPHI_PACKAGE TGSColorVector clrMediumSeaGreen;
extern DELPHI_PACKAGE TGSColorVector clrMediumSlateBlue;
extern DELPHI_PACKAGE TGSColorVector clrMediumSpringGreen;
extern DELPHI_PACKAGE TGSColorVector clrMediumTurquoise;
extern DELPHI_PACKAGE TGSColorVector clrMediumViolet;
extern DELPHI_PACKAGE TGSColorVector clrMediumPurple;
extern DELPHI_PACKAGE TGSColorVector clrMidnightBlue;
extern DELPHI_PACKAGE TGSColorVector clrNavy;
extern DELPHI_PACKAGE TGSColorVector clrNavyBlue;
extern DELPHI_PACKAGE TGSColorVector clrOrange;
extern DELPHI_PACKAGE TGSColorVector clrOrangeRed;
extern DELPHI_PACKAGE TGSColorVector clrOrchid;
extern DELPHI_PACKAGE TGSColorVector clrPaleGreen;
extern DELPHI_PACKAGE TGSColorVector clrPink;
extern DELPHI_PACKAGE TGSColorVector clrPlum;
extern DELPHI_PACKAGE TGSColorVector clrSalmon;
extern DELPHI_PACKAGE TGSColorVector clrSeaGreen;
extern DELPHI_PACKAGE TGSColorVector clrSienna;
extern DELPHI_PACKAGE TGSColorVector clrSkyBlue;
extern DELPHI_PACKAGE TGSColorVector clrSlateBlue;
extern DELPHI_PACKAGE TGSColorVector clrSpringGreen;
extern DELPHI_PACKAGE TGSColorVector clrSteelBlue;
extern DELPHI_PACKAGE TGSColorVector clrTan;
extern DELPHI_PACKAGE TGSColorVector clrThistle;
extern DELPHI_PACKAGE TGSColorVector clrTurquoise;
extern DELPHI_PACKAGE TGSColorVector clrViolet;
extern DELPHI_PACKAGE TGSColorVector clrVioletRed;
extern DELPHI_PACKAGE TGSColorVector clrYellowGreen;
extern DELPHI_PACKAGE TGSColorVector clrSummerSky;
extern DELPHI_PACKAGE TGSColorVector clrRichBlue;
extern DELPHI_PACKAGE TGSColorVector clrBrass;
extern DELPHI_PACKAGE TGSColorVector clrCopper;
extern DELPHI_PACKAGE TGSColorVector clrBronze;
extern DELPHI_PACKAGE TGSColorVector clrBronze2;
extern DELPHI_PACKAGE TGSColorVector clrSilver;
extern DELPHI_PACKAGE TGSColorVector clrBrightGold;
extern DELPHI_PACKAGE TGSColorVector clrOldGold;
extern DELPHI_PACKAGE TGSColorVector clrFeldspar;
extern DELPHI_PACKAGE TGSColorVector clrQuartz;
extern DELPHI_PACKAGE TGSColorVector clrNeonPink;
extern DELPHI_PACKAGE TGSColorVector clrDarkPurple;
extern DELPHI_PACKAGE TGSColorVector clrNeonBlue;
extern DELPHI_PACKAGE TGSColorVector clrCoolCopper;
extern DELPHI_PACKAGE TGSColorVector clrMandarinOrange;
extern DELPHI_PACKAGE TGSColorVector clrLightWood;
extern DELPHI_PACKAGE TGSColorVector clrMediumWood;
extern DELPHI_PACKAGE TGSColorVector clrDarkWood;
extern DELPHI_PACKAGE TGSColorVector clrSpicyPink;
extern DELPHI_PACKAGE TGSColorVector clrSemiSweetChoc;
extern DELPHI_PACKAGE TGSColorVector clrFlesh;
extern DELPHI_PACKAGE TGSColorVector clrNewTan;
extern DELPHI_PACKAGE TGSColorVector clrNewMidnightBlue;
extern DELPHI_PACKAGE TGSColorVector clrVeryDarkBrown;
extern DELPHI_PACKAGE TGSColorVector clrDarkBrown;
extern DELPHI_PACKAGE TGSColorVector clrDarkTan;
extern DELPHI_PACKAGE TGSColorVector clrGreenCopper;
extern DELPHI_PACKAGE TGSColorVector clrDkGreenCopper;
extern DELPHI_PACKAGE TGSColorVector clrDustyRose;
extern DELPHI_PACKAGE TGSColorVector clrHuntersGreen;
extern DELPHI_PACKAGE TGSColorVector clrScarlet;
extern DELPHI_PACKAGE TGSColorVector clrLightPurple;
extern DELPHI_PACKAGE TGSColorVector clrVeryLightPurple;
extern DELPHI_PACKAGE TGSColorVector clrGreen;
extern DELPHI_PACKAGE TGSColorVector clrOlive;
extern DELPHI_PACKAGE TGSColorVector clrPurple;
extern DELPHI_PACKAGE TGSColorVector clrTeal;
extern DELPHI_PACKAGE TGSColorVector clrRed;
extern DELPHI_PACKAGE TGSColorVector clrYellow;
extern DELPHI_PACKAGE TGSColorVector clrWheat;
#define cDefaultNormalMapScale  (1.250000E-01)
extern DELPHI_PACKAGE bool vUseDefaultColorSets;
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall RGB2Color(const System::Byte r, const System::Byte g, const System::Byte b);
extern DELPHI_PACKAGE TGSColorManager* __fastcall ColorManager(void);
extern DELPHI_PACKAGE TGSColorVector __fastcall ConvertWinColor(System::Uitypes::TColor aColor, float Alpha = 1.000000E+00f);
extern DELPHI_PACKAGE void __fastcall InitGLSceneColors(void);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall ConvertColorVector(const TGSColorVector &aColor)/* overload */;
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall ConvertColorVector(const TGSColorVector &aColor, float intensity)/* overload */;
extern DELPHI_PACKAGE TGSColorVector __fastcall ConvertRGBColor(const System::Byte *aColor, const System::NativeInt aColor_High);
extern DELPHI_PACKAGE void __fastcall RegisterColor(const System::UnicodeString aName, const TGSColorVector &aColor);
extern DELPHI_PACKAGE void __fastcall UnRegisterColor(const System::UnicodeString aName);
}	/* namespace Color */
}	/* namespace Stage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE_COLOR)
using namespace Stage::Color;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STAGE)
using namespace Stage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Stage_ColorHPP
