// Fill out your copyright notice in the Description page of Project Settings.


#include "VSCompositingElementTransform.h"

#include "CompositingElements/ICompositingTextureLookupTable.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"

void UComposureKeyColorMaterialTransform::SetMaterialParams(float ChromaBoundValue, float ChromaContrastValue, float LumaLogBoundValue,
                                   float LumaLogContrastValue, float PreBlurKernalSizeValue, float PreBlurSamplesValue, float DevignetteOuterValue,
                                   float DevignetteInnerValue, float DevignetteAmountValue, float AlphaBiasValue, float BlackClipValue,
                                   float WhiteClipValue)
 {

	if (KeyerMaterial.ApplyParamOverrides(PrePassLookupTable))
	{
		KeyerMaterial.SetScalarOverride(FName(TEXT("ChromaBound")), ChromaBoundValue);
		KeyerMaterial.SetScalarOverride(FName(TEXT("ChromaContrast")), ChromaContrastValue);
		KeyerMaterial.SetScalarOverride(FName(TEXT("LumaLogBound")), LumaLogBoundValue);
		KeyerMaterial.SetScalarOverride(FName(TEXT("LumaLogContrast")), LumaLogContrastValue);
		
		KeyerMaterial.SetScalarOverride(FName(TEXT("PreBlurKernalSize")), PreBlurKernalSizeValue);
		KeyerMaterial.SetScalarOverride(FName(TEXT("PreBlurSamples")), PreBlurSamplesValue);
		KeyerMaterial.SetScalarOverride(FName(TEXT("DevignetteOuter")), DevignetteOuterValue);
		KeyerMaterial.SetScalarOverride(FName(TEXT("DevignetteInner")), DevignetteInnerValue);
		KeyerMaterial.SetScalarOverride(FName(TEXT("DevignetteAmount")), DevignetteAmountValue);
	
		KeyerMaterial.SetScalarOverride(FName(TEXT("AlphaBias")), AlphaBiasValue);
		KeyerMaterial.SetScalarOverride(FName(TEXT("BlackClip")), BlackClipValue);
		KeyerMaterial.SetScalarOverride(FName(TEXT("WhiteClip")), WhiteClipValue);

		//ApplyMaterialParams(Material.GetMID());

		KeyerMaterial.ApplyParamOverrides(PrePassLookupTable);
	}
#if WITH_EDITORONLY_DATA
#endif
}

void UComposureKeyColorMaterialTransform::SetKey(FLinearColor Color)
{
	if (!KeyColors.IsEmpty())
	{
		KeyColors[0] = FLinearColor(Color);
	}
	else
	{
		KeyColors.Add(FLinearColor(Color));
	}
}

void UComposureKeyColorMaterialTransform::SetMaterial(UMaterialInterface* MyMaterial)
{
	//static ConstructorHelpers::FObjectFinder<UMaterialInterface> GKeyerMaterial(TEXT("/Composure/Materials/ChromaKeying/M_SinglePassChromaKeyer"));
	KeyerMaterial.Material = MyMaterial;
}



//////////////////////////////////////////////////////////////////////////////////////

void UComposureScalarMaterialTransform::SetMaterialParams(float value)
{
	

	Material.SetScalarOverride(FName(TEXT("ChromaBound")), value);
	//Material.RequiredMaterialParams
//	Material.ApplyParamOverrides(PrePassLookupTable);
	
	if (Material.ApplyParamOverrides(PrePassLookupTable))
	{
		ApplyMaterialParams(Material.GetMID());
		
	}
#if WITH_EDITORONLY_DATA
#endif
}

void UComposureScalarMaterialTransform::SetMaterialColorParams(FLinearColor value)
{
	Material.SetVectorOverride(FName(TEXT("KeyColor")), value);
}

void UComposureScalarMaterialTransform::SetMaterial(UMaterialInterface* MyMaterial)
{
	//static ConstructorHelpers::FObjectFinder<UMaterialInterface> GKeyerMaterial(TEXT("/Composure/Materials/ChromaKeying/M_SinglePassChromaKeyer"));

	Material.Material = MyMaterial;
	#if WITH_EDITORONLY_DATA
	//Material.RequiredMaterialParams
	#endif
}

void UComposureScalarMaterialTransform::GetMaterialParamsName(UMaterialInterface* MyMaterial)
{
	TMap<FMaterialParameterInfo, FMaterialParameterMetadata> OutParameters;
	Material.Material->GetAllParametersOfType(EMaterialParameterType::Scalar, OutParameters);

	TArray<float> Param;
	TArray<FMaterialParameterInfo> KeyArray;
	OutParameters.GenerateKeyArray(KeyArray);

	for (const FMaterialParameterInfo& ParamInf : KeyArray)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s = FloatVariable"), *ParamInf.ToString()));
	}
}

void UComposureScalarMaterialTransform::GetMaterialParamsNum()
{
	TMap<FMaterialParameterInfo, FMaterialParameterMetadata> OutParameters;
	Material.Material->GetAllParametersOfType(EMaterialParameterType::Scalar, OutParameters);
	
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%d = FloatVariable"), OutParameters.Num()));
	 /*// TEXTURE PARAMS
	TArray<FMaterialParameterInfo> TexParamInfos;
	TArray<FGuid> TexParamIds;
	Material.Material->GetAllTextureParameterInfo(TexParamInfos, TexParamIds);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%d = FloatVariable"), TexParamInfos.Num()));*/
	
}

void UComposureScalarMaterialTransform::TestFoo()
{
	
}


/*
//////////////////////////////////////////////////////////////////////////////////////

void UChromakey3::SetKey(FLinearColor Color)
{
	/*if (!KeyColors.IsEmpty())
	{
		KeyColors[0] = FLinearColor(Color);
	}
	else
	{
		KeyColors.Add(FLinearColor(0,255,255));
	}#1#
}

void UChromakey3::SetMaterial(UMaterialInterface* MyMaterial)
{
	
}
*/
