// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InterpolationHelpers.generated.h"


UENUM(BlueprintType)
enum class EInterpolationType
{
	Lerp,
	SLerp,

};


UCLASS()
class FG_MATHCOURSE2_API UInterpolationHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
};
