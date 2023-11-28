// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraShakeBase.h"
#include "NoiseCameraShake.generated.h"

/**
 * 
 */
UCLASS()
class FG_MATHCOURSE2_API UNoiseCameraShake : public UCameraShakeBase
{
	GENERATED_BODY()
	

public:
	UNoiseCameraShake(const FObjectInitializer& ObjectInitializer);
};
