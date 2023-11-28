// Fill out your copyright notice in the Description page of Project Settings.


#include "NoiseCameraShake.h"
#include "PerlinNoiseCameraShakePattern.h"
#include "MathNoiseCameraShakePattern.h"



UNoiseCameraShake::UNoiseCameraShake(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer
	.SetDefaultSubobjectClass<UMathNoiseCameraShakePattern>(TEXT("RootShakePattern")))
{

}