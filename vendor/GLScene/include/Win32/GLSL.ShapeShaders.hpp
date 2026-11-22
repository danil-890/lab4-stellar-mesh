// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLSL.ShapeShaders.pas' rev: 37.00 (Windows)

#ifndef GLSL_ShapeShadersHPP
#define GLSL_ShapeShadersHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <GLS.Scene.hpp>
#include <Stage.BaseClasses.hpp>
#include <GLS.State.hpp>
#include <GLS.Context.hpp>
#include <GLS.Graphics.hpp>
#include <GLS.RenderContextInfo.hpp>
#include <Stage.Coordinates.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.Color.hpp>
#include <GLS.Texture.hpp>
#include <GLS.Material.hpp>
#include <GLSL.Shader.hpp>
#include <GLSL.CustomShader.hpp>

//-- user supplied -----------------------------------------------------------

namespace Glsl
{
namespace Shapeshaders
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLCelShader;
class DELPHICLASS TGLCustomGLSLSimpleErosionShader;
class DELPHICLASS TGLSLSimpleErosionShader;
class DELPHICLASS TGLCustomGLSLGlassShader;
class DELPHICLASS TGLSLGlassShader;
class DELPHICLASS TGLCustomGLSLSimpleGoochShader;
class DELPHICLASS TGLSLSimpleGoochShader;
class DELPHICLASS TGLCustomGLSLFurShader;
class DELPHICLASS TGLSLFurShader;
class DELPHICLASS TGLCustomGLSLIvoryShader;
class DELPHICLASS TGLSLIvoryShader;
class DELPHICLASS TGLCustomGLSLSimpleLatticeShader;
class DELPHICLASS TGLCustomGLSLLatticeShader;
class DELPHICLASS TGLSLSimpleLatticeShader;
class DELPHICLASS TGLSLLatticeShader;
class DELPHICLASS TGLCustomGLSLSemShader;
class DELPHICLASS TGLSLSemShader;
class DELPHICLASS TGLCustomGLSLToonShader;
class DELPHICLASS TGLSLToonShader;
class DELPHICLASS TGLCustomGLSLVertexDisplacementShader;
class DELPHICLASS TGLSLVertexDisplacementShader;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLCelShaderOption : unsigned char { csoOutlines, csoTextured, csoNoBuildShadeTexture };

typedef System::Set<TGLCelShaderOption, TGLCelShaderOption::csoOutlines, TGLCelShaderOption::csoNoBuildShadeTexture> TGLCelShaderOptions;

typedef void __fastcall (__closure *TGLCelShaderGetIntensity)(System::TObject* Sender, System::Byte &intensity);

class PASCALIMPLEMENTATION TGLCelShader : public Gls::Material::TGLShader
{
	typedef Gls::Material::TGLShader inherited;
	
private:
	float FOutlineWidth;
	TGLCelShaderOptions FCelShaderOptions;
	Gls::Context::TGLARBVertexProgramHandle* FVPHandle;
	Gls::Texture::TGLTexture* FShadeTexture;
	TGLCelShaderGetIntensity FOnGetIntensity;
	bool FOutlinePass;
	bool FUnApplyShadeTexture;
	Stage::Color::TGSColor* FOutlineColor;
	
protected:
	void __fastcall SetCelShaderOptions(const TGLCelShaderOptions val);
	void __fastcall SetOutlineWidth(const float val);
	void __fastcall SetOutlineColor(Stage::Color::TGSColor* const val);
	void __fastcall BuildShadeTexture();
	virtual void __fastcall Loaded();
	System::UnicodeString __fastcall GenerateVertexProgram();
	
public:
	__fastcall virtual TGLCelShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCelShader();
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	__property Gls::Texture::TGLTexture* ShadeTexture = {read=FShadeTexture};
	
__published:
	__property TGLCelShaderOptions CelShaderOptions = {read=FCelShaderOptions, write=SetCelShaderOptions, nodefault};
	__property Stage::Color::TGSColor* OutlineColor = {read=FOutlineColor, write=SetOutlineColor};
	__property float OutlineWidth = {read=FOutlineWidth, write=SetOutlineWidth};
	__property TGLCelShaderGetIntensity OnGetIntensity = {read=FOnGetIntensity, write=FOnGetIntensity};
};


class PASCALIMPLEMENTATION TGLCustomGLSLSimpleErosionShader : public Glsl::Shader::TGLCustomGLSLShader
{
	typedef Glsl::Shader::TGLCustomGLSLShader inherited;
	
private:
	Gls::Material::TGLAbstractMaterialLibrary* FMaterialLibrary;
	Gls::Texture::TGLTexture* FMainTex;
	Gls::Texture::TGLTexture* FNoiseTex;
	Gls::Texture::TGLTexture* FErosionTex;
	Gls::Material::TGLLibMaterialName FMainTexName;
	Gls::Material::TGLLibMaterialName FNoiseTexName;
	Gls::Material::TGLLibMaterialName FErosionTexName;
	float FErosionScale;
	float FErosionFactor;
	float FIntensityFactor1;
	float FIntensityFactor2;
	Stage::Color::TGSColor* FSpecularColor;
	Stage::Color::TGSColor* FAmbientColor;
	float FAmbientFactor;
	float FDiffuseFactor;
	float FSpecularFactor;
	float FSpecularRoughness;
	float FAnisotropicRoughness;
	Gls::Material::TGLAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gls::Texture::TGLTexture* const Value);
	void __fastcall SetNoiseTexTexture(Gls::Texture::TGLTexture* const Value);
	void __fastcall SetErosionTexTexture(Gls::Texture::TGLTexture* const Value);
	Gls::Material::TGLLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gls::Material::TGLLibMaterialName Value);
	Gls::Material::TGLLibMaterialName __fastcall GetNoiseTexName();
	void __fastcall SetNoiseTexName(const Gls::Material::TGLLibMaterialName Value);
	Gls::Material::TGLLibMaterialName __fastcall GetErosionTexName();
	void __fastcall SetErosionTexName(const Gls::Material::TGLLibMaterialName Value);
	void __fastcall SetAmbientColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetSpecularColor(Stage::Color::TGSColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gls::Material::TGLAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLCustomGLSLSimpleErosionShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLSimpleErosionShader();
	__property Gls::Material::TGLAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gls::Texture::TGLTexture* MainTexture = {read=FMainTex, write=SetMainTexTexture};
	__property Gls::Material::TGLLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
	__property Gls::Texture::TGLTexture* NoiseTexture = {read=FNoiseTex, write=SetNoiseTexTexture};
	__property Gls::Material::TGLLibMaterialName NoiseTextureName = {read=GetNoiseTexName, write=SetNoiseTexName};
	__property Gls::Texture::TGLTexture* ErosionTexture = {read=FErosionTex, write=SetErosionTexTexture};
	__property Gls::Material::TGLLibMaterialName ErosionTextureName = {read=GetErosionTexName, write=SetErosionTexName};
	__property float ErosionFactor = {read=FErosionFactor, write=FErosionFactor};
	__property float ErosionScale = {read=FErosionFactor, write=FErosionFactor};
	__property float IntensityFactor1 = {read=FIntensityFactor1, write=FIntensityFactor1};
	__property float IntensityFactor2 = {read=FIntensityFactor2, write=FIntensityFactor2};
	__property Stage::Color::TGSColor* SpecularColor = {read=FSpecularColor, write=SetSpecularColor};
	__property Stage::Color::TGSColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property float AmbientFactor = {read=FAmbientFactor, write=FAmbientFactor};
	__property float DiffuseFactor = {read=FDiffuseFactor, write=FDiffuseFactor};
	__property float SpecularFactor = {read=FSpecularFactor, write=FSpecularFactor};
	__property float SpecularRoughness = {read=FSpecularRoughness, write=FSpecularRoughness};
	__property float AnisotropicRoughness = {read=FAnisotropicRoughness, write=FAnisotropicRoughness};
};


class PASCALIMPLEMENTATION TGLSLSimpleErosionShader : public TGLCustomGLSLSimpleErosionShader
{
	typedef TGLCustomGLSLSimpleErosionShader inherited;
	
__published:
	__property MaterialLibrary;
	__property MainTexture;
	__property MainTextureName = {default=0};
	__property NoiseTexture;
	__property NoiseTextureName = {default=0};
	__property ErosionTexture;
	__property ErosionTextureName = {default=0};
	__property ErosionScale = {default=0};
	__property ErosionFactor = {default=0};
	__property IntensityFactor1 = {default=0};
	__property IntensityFactor2 = {default=0};
	__property SpecularColor;
	__property AmbientColor;
	__property AmbientFactor = {default=0};
	__property DiffuseFactor = {default=0};
	__property SpecularFactor = {default=0};
	__property SpecularRoughness = {default=0};
	__property AnisotropicRoughness = {default=0};
public:
	/* TGLCustomGLSLSimpleErosionShader.Create */ inline __fastcall virtual TGLSLSimpleErosionShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLSimpleErosionShader(AOwner) { }
	/* TGLCustomGLSLSimpleErosionShader.Destroy */ inline __fastcall virtual ~TGLSLSimpleErosionShader() { }
	
};


class PASCALIMPLEMENTATION TGLCustomGLSLGlassShader : public Glsl::Shader::TGLCustomGLSLShader
{
	typedef Glsl::Shader::TGLCustomGLSLShader inherited;
	
private:
	Stage::Color::TGSColor* FDiffuseColor;
	float FDepth;
	float FMix;
	float FAlpha;
	Gls::Material::TGLAbstractMaterialLibrary* FMaterialLibrary;
	Gls::Texture::TGLTexture* FMainTexture;
	Gls::Material::TGLLibMaterialName FMainTexName;
	Gls::Texture::TGLTexture* FRefractionTexture;
	Gls::Material::TGLLibMaterialName FRefractionTexName;
	Gls::Scene::TGLBaseSceneObject* FOwnerObject;
	Gls::State::TGLBlendFunction FBlendSrc;
	Gls::State::TGLBlendFunction FBlendDst;
	Gls::Material::TGLAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gls::Texture::TGLTexture* const Value);
	Gls::Material::TGLLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gls::Material::TGLLibMaterialName Value);
	void __fastcall SetRefractionTexTexture(Gls::Texture::TGLTexture* const Value);
	Gls::Material::TGLLibMaterialName __fastcall GetRefractionTexName();
	void __fastcall SetRefractionTexName(const Gls::Material::TGLLibMaterialName Value);
	void __fastcall SetDiffuseColor(Stage::Color::TGSColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gls::Material::TGLAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLCustomGLSLGlassShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLGlassShader();
	__property Stage::Color::TGSColor* DiffuseColor = {read=FDiffuseColor, write=SetDiffuseColor};
	__property float Depth = {read=FDepth, write=FDepth};
	__property float Mix = {read=FMix, write=FMix};
	__property float Alpha = {read=FAlpha, write=FAlpha};
	__property Gls::Material::TGLAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gls::Texture::TGLTexture* MainTexture = {read=FMainTexture, write=SetMainTexTexture};
	__property Gls::Material::TGLLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
	__property Gls::Texture::TGLTexture* RefractionTexture = {read=FRefractionTexture, write=SetRefractionTexTexture};
	__property Gls::Material::TGLLibMaterialName RefractionTextureName = {read=GetRefractionTexName, write=SetRefractionTexName};
	__property Gls::Scene::TGLBaseSceneObject* OwnerObject = {read=FOwnerObject, write=FOwnerObject};
	__property Gls::State::TGLBlendFunction BlendSrc = {read=FBlendSrc, write=FBlendSrc, default=6};
	__property Gls::State::TGLBlendFunction BlendDst = {read=FBlendDst, write=FBlendDst, default=8};
};


class PASCALIMPLEMENTATION TGLSLGlassShader : public TGLCustomGLSLGlassShader
{
	typedef TGLCustomGLSLGlassShader inherited;
	
__published:
	__property DiffuseColor;
	__property Depth = {default=0};
	__property Mix = {default=0};
	__property Alpha = {default=0};
	__property MaterialLibrary;
	__property MainTexture;
	__property MainTextureName = {default=0};
	__property RefractionTexture;
	__property RefractionTextureName = {default=0};
	__property OwnerObject;
	__property BlendSrc = {default=6};
	__property BlendDst = {default=8};
public:
	/* TGLCustomGLSLGlassShader.Create */ inline __fastcall virtual TGLSLGlassShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLGlassShader(AOwner) { }
	/* TGLCustomGLSLGlassShader.Destroy */ inline __fastcall virtual ~TGLSLGlassShader() { }
	
};


class PASCALIMPLEMENTATION TGLCustomGLSLSimpleGoochShader : public Glsl::Shader::TGLCustomGLSLShader
{
	typedef Glsl::Shader::TGLCustomGLSLShader inherited;
	
private:
	Stage::Color::TGSColor* FDiffuseColor;
	Stage::Color::TGSColor* FWarmColor;
	Stage::Color::TGSColor* FCoolColor;
	Stage::Color::TGSColor* FSpecularColor;
	Stage::Color::TGSColor* FAmbientColor;
	float FDiffuseWarm;
	float FDiffuseCool;
	float FAmbientFactor;
	float FDiffuseFactor;
	float FSpecularFactor;
	Glsl::Customshader::TGLBlendingModeEx FBlendingMode;
	void __fastcall SetDiffuseColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetAmbientColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetSpecularColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetWarmColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetCoolColor(Stage::Color::TGSColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
public:
	__fastcall virtual TGLCustomGLSLSimpleGoochShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLSimpleGoochShader();
	__property Stage::Color::TGSColor* DiffuseColor = {read=FDiffuseColor, write=SetDiffuseColor};
	__property Stage::Color::TGSColor* WarmColor = {read=FWarmColor, write=SetWarmColor};
	__property Stage::Color::TGSColor* CoolColor = {read=FCoolColor, write=SetCoolColor};
	__property Stage::Color::TGSColor* SpecularColor = {read=FSpecularColor, write=SetSpecularColor};
	__property Stage::Color::TGSColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property float WarmFactor = {read=FDiffuseWarm, write=FDiffuseWarm};
	__property float CoolFactor = {read=FDiffuseCool, write=FDiffuseCool};
	__property float AmbientFactor = {read=FAmbientFactor, write=FAmbientFactor};
	__property float DiffuseFactor = {read=FDiffuseFactor, write=FDiffuseFactor};
	__property float SpecularFactor = {read=FSpecularFactor, write=FSpecularFactor};
	__property Glsl::Customshader::TGLBlendingModeEx BlendingMode = {read=FBlendingMode, write=FBlendingMode, default=0};
};


class PASCALIMPLEMENTATION TGLSLSimpleGoochShader : public TGLCustomGLSLSimpleGoochShader
{
	typedef TGLCustomGLSLSimpleGoochShader inherited;
	
__published:
	__property DiffuseColor;
	__property WarmColor;
	__property CoolColor;
	__property SpecularColor;
	__property AmbientColor;
	__property WarmFactor = {default=0};
	__property CoolFactor = {default=0};
	__property AmbientFactor = {default=0};
	__property DiffuseFactor = {default=0};
	__property SpecularFactor = {default=0};
public:
	/* TGLCustomGLSLSimpleGoochShader.Create */ inline __fastcall virtual TGLSLSimpleGoochShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLSimpleGoochShader(AOwner) { }
	/* TGLCustomGLSLSimpleGoochShader.Destroy */ inline __fastcall virtual ~TGLSLSimpleGoochShader() { }
	
};


class PASCALIMPLEMENTATION TGLCustomGLSLFurShader : public Glsl::Shader::TGLCustomGLSLShader
{
	typedef Glsl::Shader::TGLCustomGLSLShader inherited;
	
private:
	Gls::Material::TGLAbstractMaterialLibrary* FMaterialLibrary;
	int FCurrentPass;
	float FPassCount;
	float FFurLength;
	float FMaxFurLength;
	float FFurScale;
	bool FRandomFurLength;
	Stage::Color::TGSColor* FColorScale;
	Stage::Color::TGSColor* FAmbient;
	Stage::Coordinates::TGSCoordinates* FGravity;
	float FLightIntensity;
	Gls::Texture::TGLTexture* FMainTex;
	Gls::Texture::TGLTexture* FNoiseTex;
	Gls::Material::TGLLibMaterialName FNoiseTexName;
	Gls::Material::TGLLibMaterialName FMainTexName;
	Gls::State::TGLBlendFunction FBlendSrc;
	Gls::State::TGLBlendFunction FBlendDst;
	Gls::Material::TGLAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gls::Texture::TGLTexture* const Value);
	void __fastcall SetNoiseTexTexture(Gls::Texture::TGLTexture* const Value);
	Gls::Material::TGLLibMaterialName __fastcall GetNoiseTexName();
	void __fastcall SetNoiseTexName(const Gls::Material::TGLLibMaterialName Value);
	Gls::Material::TGLLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gls::Material::TGLLibMaterialName Value);
	void __fastcall SetGravity(Stage::Coordinates::TGSCoordinates* APosition);
	void __fastcall SetAmbient(Stage::Color::TGSColor* AValue);
	void __fastcall SetColorScale(Stage::Color::TGSColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gls::Material::TGLAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLCustomGLSLFurShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLFurShader();
	__property float PassCount = {read=FPassCount, write=FPassCount};
	__property float FurLength = {read=FFurLength, write=FFurLength};
	__property float MaxFurLength = {read=FMaxFurLength, write=FMaxFurLength};
	__property float FurDensity = {read=FFurScale, write=FFurScale};
	__property bool RandomFurLength = {read=FRandomFurLength, write=FRandomFurLength, nodefault};
	__property Stage::Color::TGSColor* ColorScale = {read=FColorScale, write=SetColorScale};
	__property Stage::Color::TGSColor* Ambient = {read=FAmbient, write=SetAmbient};
	__property Gls::Material::TGLAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gls::Texture::TGLTexture* MainTexture = {read=FMainTex, write=SetMainTexTexture};
	__property Gls::Material::TGLLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
	__property Gls::Texture::TGLTexture* NoiseTexture = {read=FNoiseTex, write=SetNoiseTexTexture};
	__property Gls::Material::TGLLibMaterialName NoiseTextureName = {read=GetNoiseTexName, write=SetNoiseTexName};
	__property Gls::State::TGLBlendFunction BlendSrc = {read=FBlendSrc, write=FBlendSrc, default=2};
	__property Gls::State::TGLBlendFunction BlendDst = {read=FBlendDst, write=FBlendDst, default=5};
	__property Stage::Coordinates::TGSCoordinates* Gravity = {read=FGravity, write=SetGravity};
	__property float LightIntensity = {read=FLightIntensity, write=FLightIntensity};
};


class PASCALIMPLEMENTATION TGLSLFurShader : public TGLCustomGLSLFurShader
{
	typedef TGLCustomGLSLFurShader inherited;
	
__published:
	__property PassCount = {default=0};
	__property FurLength = {default=0};
	__property MaxFurLength = {default=0};
	__property FurDensity = {default=0};
	__property RandomFurLength;
	__property ColorScale;
	__property Ambient;
	__property LightIntensity = {default=0};
	__property Gravity;
	__property BlendSrc = {default=2};
	__property BlendDst = {default=5};
	__property MainTexture;
	__property MainTextureName = {default=0};
	__property NoiseTexture;
	__property NoiseTextureName = {default=0};
public:
	/* TGLCustomGLSLFurShader.Create */ inline __fastcall virtual TGLSLFurShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLFurShader(AOwner) { }
	/* TGLCustomGLSLFurShader.Destroy */ inline __fastcall virtual ~TGLSLFurShader() { }
	
};


class PASCALIMPLEMENTATION TGLCustomGLSLIvoryShader : public Glsl::Shader::TGLCustomGLSLShader
{
	typedef Glsl::Shader::TGLCustomGLSLShader inherited;
	
protected:
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
public:
	__fastcall virtual TGLCustomGLSLIvoryShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLIvoryShader();
};


class PASCALIMPLEMENTATION TGLSLIvoryShader : public TGLCustomGLSLIvoryShader
{
	typedef TGLCustomGLSLIvoryShader inherited;
	
public:
	/* TGLCustomGLSLIvoryShader.Create */ inline __fastcall virtual TGLSLIvoryShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLIvoryShader(AOwner) { }
	/* TGLCustomGLSLIvoryShader.Destroy */ inline __fastcall virtual ~TGLSLIvoryShader() { }
	
};


class PASCALIMPLEMENTATION TGLCustomGLSLSimpleLatticeShader : public Glsl::Shader::TGLCustomGLSLShader
{
	typedef Glsl::Shader::TGLCustomGLSLShader inherited;
	
private:
	Stage::Coordinates::TGSCoordinates2* FLatticeScale;
	Stage::Coordinates::TGSCoordinates2* FLatticeThreshold;
	void __fastcall SetLatticeScale(Stage::Coordinates::TGSCoordinates2* const Value);
	void __fastcall SetLatticeThreshold(Stage::Coordinates::TGSCoordinates2* const Value);
	
protected:
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
public:
	__fastcall virtual TGLCustomGLSLSimpleLatticeShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLSimpleLatticeShader();
	__property Stage::Coordinates::TGSCoordinates2* LatticeScale = {read=FLatticeScale, write=SetLatticeScale};
	__property Stage::Coordinates::TGSCoordinates2* LatticeThreshold = {read=FLatticeThreshold, write=SetLatticeThreshold};
};


class PASCALIMPLEMENTATION TGLCustomGLSLLatticeShader : public TGLCustomGLSLSimpleLatticeShader
{
	typedef TGLCustomGLSLSimpleLatticeShader inherited;
	
private:
	Stage::Color::TGSColor* FAmbientColor;
	Stage::Color::TGSColor* FDiffuseColor;
	Stage::Color::TGSColor* FSpecularColor;
	Gls::Material::TGLAbstractMaterialLibrary* FMaterialLibrary;
	Gls::Texture::TGLTexture* FMainTexture;
	Gls::Material::TGLLibMaterialName FMainTexName;
	float FSpecularPower;
	float FLightPower;
	Gls::Material::TGLAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gls::Texture::TGLTexture* const Value);
	Gls::Material::TGLLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gls::Material::TGLLibMaterialName Value);
	void __fastcall SetDiffuseColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetAmbientColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetSpecularColor(Stage::Color::TGSColor* AValue);
	
protected:
	virtual void __fastcall DoInitialize(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall SetMaterialLibrary(Gls::Material::TGLAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLCustomGLSLLatticeShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLLatticeShader();
	__property Stage::Color::TGSColor* DiffuseColor = {read=FDiffuseColor, write=SetDiffuseColor};
	__property Stage::Color::TGSColor* SpecularColor = {read=FSpecularColor, write=SetSpecularColor};
	__property Stage::Color::TGSColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property Gls::Material::TGLAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gls::Texture::TGLTexture* MainTexture = {read=FMainTexture, write=SetMainTexTexture};
	__property Gls::Material::TGLLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
	__property float SpecularPower = {read=FSpecularPower, write=FSpecularPower};
	__property float LightPower = {read=FLightPower, write=FLightPower};
};


class PASCALIMPLEMENTATION TGLSLSimpleLatticeShader : public TGLCustomGLSLSimpleLatticeShader
{
	typedef TGLCustomGLSLSimpleLatticeShader inherited;
	
__published:
	__property LatticeScale;
	__property LatticeThreshold;
public:
	/* TGLCustomGLSLSimpleLatticeShader.Create */ inline __fastcall virtual TGLSLSimpleLatticeShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLSimpleLatticeShader(AOwner) { }
	/* TGLCustomGLSLSimpleLatticeShader.Destroy */ inline __fastcall virtual ~TGLSLSimpleLatticeShader() { }
	
};


class PASCALIMPLEMENTATION TGLSLLatticeShader : public TGLCustomGLSLLatticeShader
{
	typedef TGLCustomGLSLLatticeShader inherited;
	
__published:
	__property LatticeScale;
	__property LatticeThreshold;
	__property AmbientColor;
	__property DiffuseColor;
	__property SpecularColor;
	__property MainTexture;
	__property SpecularPower = {default=0};
	__property LightPower = {default=0};
public:
	/* TGLCustomGLSLLatticeShader.Create */ inline __fastcall virtual TGLSLLatticeShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLLatticeShader(AOwner) { }
	/* TGLCustomGLSLLatticeShader.Destroy */ inline __fastcall virtual ~TGLSLLatticeShader() { }
	
};


class PASCALIMPLEMENTATION TGLCustomGLSLSemShader : public Glsl::Shader::TGLCustomGLSLShader
{
	typedef Glsl::Shader::TGLCustomGLSLShader inherited;
	
private:
	Stage::Color::TGSColor* FAmbientColor;
	Stage::Color::TGSColor* FSpecularColor;
	float FAmbientFactor;
	float FDiffuseFactor;
	float FSpecularFactor;
	Gls::Material::TGLAbstractMaterialLibrary* FMaterialLibrary;
	Gls::Texture::TGLTexture* FMainTexture;
	Gls::Material::TGLLibMaterialName FMainTexName;
	Gls::Material::TGLAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gls::Texture::TGLTexture* const Value);
	Gls::Material::TGLLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gls::Material::TGLLibMaterialName Value);
	void __fastcall SetAmbientColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetSpecularColor(Stage::Color::TGSColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gls::Material::TGLAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLCustomGLSLSemShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLSemShader();
	__property Stage::Color::TGSColor* SpecularColor = {read=FSpecularColor, write=SetSpecularColor};
	__property Stage::Color::TGSColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property float AmbientFactor = {read=FAmbientFactor, write=FAmbientFactor};
	__property float DiffuseFactor = {read=FDiffuseFactor, write=FDiffuseFactor};
	__property float SpecularFactor = {read=FSpecularFactor, write=FSpecularFactor};
	__property Gls::Material::TGLAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gls::Texture::TGLTexture* MainTexture = {read=FMainTexture, write=SetMainTexTexture};
	__property Gls::Material::TGLLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
};


class PASCALIMPLEMENTATION TGLSLSemShader : public TGLCustomGLSLSemShader
{
	typedef TGLCustomGLSLSemShader inherited;
	
__published:
	__property AmbientColor;
	__property SpecularColor;
	__property AmbientFactor = {default=0};
	__property DiffuseFactor = {default=0};
	__property SpecularFactor = {default=0};
	__property MaterialLibrary;
	__property MainTexture;
	__property MainTextureName = {default=0};
public:
	/* TGLCustomGLSLSemShader.Create */ inline __fastcall virtual TGLSLSemShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLSemShader(AOwner) { }
	/* TGLCustomGLSLSemShader.Destroy */ inline __fastcall virtual ~TGLSLSemShader() { }
	
};


class PASCALIMPLEMENTATION TGLCustomGLSLToonShader : public Glsl::Shader::TGLCustomGLSLShader
{
	typedef Glsl::Shader::TGLCustomGLSLShader inherited;
	
private:
	Stage::Color::TGSColor* FHighlightColor;
	Stage::Color::TGSColor* FMidColor;
	Stage::Color::TGSColor* FLightenShadowColor;
	Stage::Color::TGSColor* FDarkenShadowColor;
	Stage::Color::TGSColor* FOutlineColor;
	float FHighlightSize;
	float FMidSize;
	float FShadowSize;
	float FOutlineWidth;
	void __fastcall SetHighLightColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetMidColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetLightenShadowColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetDarkenShadowColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetOutlineColor(Stage::Color::TGSColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	
public:
	__fastcall virtual TGLCustomGLSLToonShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLToonShader();
	__property Stage::Color::TGSColor* HighlightColor = {read=FHighlightColor, write=SetHighLightColor};
	__property Stage::Color::TGSColor* MidColor = {read=FMidColor, write=SetMidColor};
	__property Stage::Color::TGSColor* LightenShadowColor = {read=FLightenShadowColor, write=SetLightenShadowColor};
	__property Stage::Color::TGSColor* DarkenShadowrColor = {read=FDarkenShadowColor, write=SetDarkenShadowColor};
	__property Stage::Color::TGSColor* OutlinetColor = {read=FOutlineColor, write=SetOutlineColor};
	__property float HighlightSize = {read=FHighlightSize, write=FHighlightSize};
	__property float MidSize = {read=FMidSize, write=FMidSize};
	__property float ShadowSize = {read=FShadowSize, write=FShadowSize};
	__property float OutlineWidth = {read=FOutlineWidth, write=FOutlineWidth};
};


class PASCALIMPLEMENTATION TGLSLToonShader : public TGLCustomGLSLToonShader
{
	typedef TGLCustomGLSLToonShader inherited;
	
__published:
	__property HighlightColor;
	__property MidColor;
	__property LightenShadowColor;
	__property DarkenShadowrColor;
	__property OutlinetColor;
	__property HighlightSize = {default=0};
	__property MidSize = {default=0};
	__property ShadowSize = {default=0};
	__property OutlineWidth = {default=0};
public:
	/* TGLCustomGLSLToonShader.Create */ inline __fastcall virtual TGLSLToonShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLToonShader(AOwner) { }
	/* TGLCustomGLSLToonShader.Destroy */ inline __fastcall virtual ~TGLSLToonShader() { }
	
};


class PASCALIMPLEMENTATION TGLCustomGLSLVertexDisplacementShader : public Glsl::Shader::TGLCustomGLSLShader
{
	typedef Glsl::Shader::TGLCustomGLSLShader inherited;
	
private:
	Stage::Color::TGSColor* FAmbientColor;
	Stage::Color::TGSColor* FSpecularColor;
	float FAmbientFactor;
	float FDiffuseFactor;
	float FSpecularFactor;
	Gls::Material::TGLAbstractMaterialLibrary* FMaterialLibrary;
	Gls::Texture::TGLTexture* FMainTexture;
	Gls::Material::TGLLibMaterialName FMainTexName;
	float FElapsedTime;
	float FNoise;
	float FDisplacementScale;
	float FNoiseScale;
	float FTurbulenceFactor;
	float FNoisePeriod;
	float FTimeFactor;
	Gls::Material::TGLAbstractMaterialLibrary* __fastcall GetMaterialLibrary();
	void __fastcall SetMainTexTexture(Gls::Texture::TGLTexture* const Value);
	Gls::Material::TGLLibMaterialName __fastcall GetMainTexName();
	void __fastcall SetMainTexName(const Gls::Material::TGLLibMaterialName Value);
	void __fastcall SetAmbientColor(Stage::Color::TGSColor* AValue);
	void __fastcall SetSpecularColor(Stage::Color::TGSColor* AValue);
	
protected:
	virtual void __fastcall DoApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gls::Rendercontextinfo::TGLRenderContextInfo &rci);
	virtual void __fastcall SetMaterialLibrary(Gls::Material::TGLAbstractMaterialLibrary* const Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TGLCustomGLSLVertexDisplacementShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TGLCustomGLSLVertexDisplacementShader();
	__property Stage::Color::TGSColor* SpecularColor = {read=FSpecularColor, write=SetSpecularColor};
	__property Stage::Color::TGSColor* AmbientColor = {read=FAmbientColor, write=SetAmbientColor};
	__property float AmbientFactor = {read=FAmbientFactor, write=FAmbientFactor};
	__property float DiffuseFactor = {read=FDiffuseFactor, write=FDiffuseFactor};
	__property float SpecularFactor = {read=FSpecularFactor, write=FSpecularFactor};
	__property Gls::Material::TGLAbstractMaterialLibrary* MaterialLibrary = {read=GetMaterialLibrary, write=SetMaterialLibrary};
	__property Gls::Texture::TGLTexture* MainTexture = {read=FMainTexture, write=SetMainTexTexture};
	__property Gls::Material::TGLLibMaterialName MainTextureName = {read=GetMainTexName, write=SetMainTexName};
	__property float ElapsedTime = {read=FElapsedTime, write=FElapsedTime};
	__property float NoiseFactor = {read=FNoise, write=FNoise};
	__property float NoiseScale = {read=FNoiseScale, write=FNoiseScale};
	__property float TurbulenceFactor = {read=FTurbulenceFactor, write=FTurbulenceFactor};
	__property float NoisePeriod = {read=FNoisePeriod, write=FNoisePeriod};
	__property float DisplacementScale = {read=FDisplacementScale, write=FDisplacementScale};
	__property float TimeFactor = {read=FTimeFactor, write=FTimeFactor};
};


class PASCALIMPLEMENTATION TGLSLVertexDisplacementShader : public TGLCustomGLSLVertexDisplacementShader
{
	typedef TGLCustomGLSLVertexDisplacementShader inherited;
	
__published:
	__property AmbientColor;
	__property SpecularColor;
	__property AmbientFactor = {default=0};
	__property DiffuseFactor = {default=0};
	__property SpecularFactor = {default=0};
	__property MaterialLibrary;
	__property MainTexture;
	__property MainTextureName = {default=0};
	__property ElapsedTime = {default=0};
	__property NoiseFactor = {default=0};
	__property NoiseScale = {default=0};
	__property TurbulenceFactor = {default=0};
	__property NoisePeriod = {default=0};
	__property DisplacementScale = {default=0};
	__property TimeFactor = {default=0};
public:
	/* TGLCustomGLSLVertexDisplacementShader.Create */ inline __fastcall virtual TGLSLVertexDisplacementShader(System::Classes::TComponent* AOwner) : TGLCustomGLSLVertexDisplacementShader(AOwner) { }
	/* TGLCustomGLSLVertexDisplacementShader.Destroy */ inline __fastcall virtual ~TGLSLVertexDisplacementShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Shapeshaders */
}	/* namespace Glsl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLSL_SHAPESHADERS)
using namespace Glsl::Shapeshaders;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLSL)
using namespace Glsl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLSL_ShapeShadersHPP
