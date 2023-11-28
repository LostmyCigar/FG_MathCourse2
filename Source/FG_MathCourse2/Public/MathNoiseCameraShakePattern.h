// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleCameraShakePattern.h"
#include "MathNoiseCameraShakePattern.generated.h"

struct FCameraShakeScrubParams;
struct FCameraShakeStartParams;
struct FCameraShakeUpdateParams;
struct FCameraShakeUpdateResult;

USTRUCT(BlueprintType)
struct FMathNoiseShaker
{
	GENERATED_BODY()

	/** Amplitude of the perlin noise. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PerlinNoise)
	float Amplitude;

	/** Frequency of the sinusoidal oscillation. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PerlinNoise)
	float Frequency;

	/** Creates a new perlin noise shaker. */
	FMathNoiseShaker()
		: Amplitude(1.f)
		, Frequency(1.f)
	{}

	/** Advances the shake time and returns the current value */
	float Update(float DeltaTime, float AmplitudeMultiplier, float FrequencyMultiplier, float& InOutCurrentOffset) const;
};

UCLASS()
class FG_MATHCOURSE2_API UMathNoiseCameraShakePattern : public USimpleCameraShakePattern
{
	GENERATED_BODY()


	UMathNoiseCameraShakePattern(const FObjectInitializer& ObjInit);

public:

	/** Amplitude multiplier for all location shake */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Location)
	float LocationAmplitudeMultiplier = 1.f;

	/** Frequency multiplier for all location shake */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Location)
	float LocationFrequencyMultiplier = 1.f;

	/** Shake in the X axis. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Location)
	FMathNoiseShaker X;

	/** Shake in the Y axis. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Location)
	FMathNoiseShaker Y;

	/** Shake in the Z axis. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Location)
	FMathNoiseShaker Z;

	/** Amplitude multiplier for all rotation shake */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
	float RotationAmplitudeMultiplier = 1.f;

	/** Frequency multiplier for all rotation shake */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
	float RotationFrequencyMultiplier = 1.f;

	/** Pitch shake. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
	FMathNoiseShaker Pitch;

	/** Yaw shake. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
	FMathNoiseShaker Yaw;

	/** Roll shake. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
	FMathNoiseShaker Roll;

	/** FOV shake. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FOV)
	FMathNoiseShaker FOV;

private:

	// UCameraShakePattern interface
	virtual void StartShakePatternImpl(const FCameraShakeStartParams& Params) override;
	virtual void UpdateShakePatternImpl(const FCameraShakeUpdateParams& Params, FCameraShakeUpdateResult& OutResult) override;
	virtual void ScrubShakePatternImpl(const FCameraShakeScrubParams& Params, FCameraShakeUpdateResult& OutResult) override;

	void UpdatePerlinNoise(float DeltaTime, FCameraShakeUpdateResult& OutResult);

private:

	/** Initial perlin noise offset for location oscillation. */
	FVector3f InitialLocationOffset;
	/** Current perlin noise offset for location oscillation. */
	FVector3f CurrentLocationOffset;

	/** Initial perlin noise offset for rotation oscillation. */
	FVector3f InitialRotationOffset;
	/** Current perlin noise offset for rotation oscillation. */
	FVector3f CurrentRotationOffset;

	/** Initial perlin noise offset for FOV oscillation */
	float InitialFOVOffset;
	/** Current perlin noise offset for FOV oscillation */
	float CurrentFOVOffset;
	
};
