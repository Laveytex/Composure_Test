// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CompositingElements/CompositingElementPasses.h"
#include "CompositingElements/CompositingElementTransforms.h"
#include "VSCompositingElementTransform.generated.h"

/**
 * 
 */
UCLASS(MinimalAPI)
class UVSCompositingElementTransform : public UCompositingElementTransform
{
	GENERATED_BODY()

	
};

UCLASS(BlueprintType, Blueprintable, MinimalAPI)
class UComposureKeyColorMaterialTransform : public UMultiPassChromaKeyer
{
	GENERATED_BODY()
public:
	//UChromakey();
	
	/*
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	FLinearColor KeyColors = FLinearColor(FColor(0,0,0));
	*/

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float ChromaBound = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float ChromaContrast = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float LumaLogBound = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float LumaLogContrast = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float PreBlurKernalSize = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float PreBlurSamples = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float DevignetteOuter = 0.65f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float DevignetteInner = 0.25;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float DevignetteAmount = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float AlphaBias = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float BlackClip = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (DisplayAfter = "PassName", EditCondition = "bEnabled"))
	float WhiteClip = 100.0f;
	
	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void SetMaterialParams(float ChromaBoundValue, float ChromaContrastValue, float LumaLogBoundValue,
		float LumaLogContrastValue, /*float TranslucencyValue,*/ float PreBlurKernalSizeValue,
		float PreBlurSamplesValue, float DevignetteOuterValue, float DevignetteInnerValue,
		float DevignetteAmountValue, float AlphaBiasValue, float BlackClipValue, float WhiteClipValue);

	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void SetKey(FLinearColor Color);

	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void SetMaterial(UMaterialInterface* MyMaterial);

protected:
	UPROPERTY(Transient)
	TObjectPtr<UTexture> WhiteTexture = nullptr;
	
};



///UMultiPassChromaKeyer
///UCompositingElementTransform
///

//////////////////////////////////////////////////////////////////////////////////////
UCLASS(BlueprintType, Blueprintable, MinimalAPI)
class UComposureScalarMaterialTransform : public UCompositingElementMaterialPass
{
	GENERATED_BODY()
public:
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compositing Pass", meta = (ShowOnlyInnerProperties, DisplayAfter = "PassName", EditCondition = "bEnabled"))
	FCompositingMaterial Material;*/

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compositing Pass", meta = (ShowOnlyInnerProperties, DisplayAfter = "PassName", EditCondition = "bEnabled"))
	UMaterial *MaterialBase;*/
	
	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void SetMaterialParams(float value);
	
	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void SetMaterialColorParams(FLinearColor value);

	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void SetMaterial(UMaterialInterface* MyMaterial);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compositing Pass", meta = (ShowOnlyInnerProperties, DisplayAfter = "PassName", EditCondition = "bEnabled"))
	TArray<const UMaterialExpression*> Params;
	
	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void GetMaterialParamsName(UMaterialInterface* MyMaterial);

	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void GetMaterialParamsNum();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compositing Pass", meta = (ShowOnlyInnerProperties, DisplayAfter = "PassName", EditCondition = "bEnabled"))
	int ParamsNum = 0;

	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void TestFoo();

	
};

UCLASS(BlueprintType, Blueprintable, MinimalAPI)
class UChromakey3 : public UCompositingElementTransform
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Compositing Pass", meta = (ShowOnlyInnerProperties, DisplayAfter = "PassName", EditCondition = "bEnabled"))
	FCompositingMaterial KeyerMaterial;
	
	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void SetKey(FLinearColor Color);

	UFUNCTION(BlueprintCallable, Category = "Compositing Pass")
	void SetMaterial(UMaterialInterface* MyMaterial);
};
