// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ContextLibrary.h"
#include "Exercise2/InterpolationHelpers.h"
#include "PositionContextActor.generated.h"

#define PRINT(msg) GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Cyan, msg);

//a little bit of copy paste
UCLASS(BlueprintType, hidecategories = (Input, Movement, Collision, Rendering, HLOD, WorldPartition, DataLayers, Replication, Networking, Actor, LevelInstance, Cooking))
class FG_MATHCOURSE2_API APositionContextActor : public AActor
{
	GENERATED_BODY()
	
public:	
	APositionContextActor();


public:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//virtual bool ShouldTickIfViewportsOnly() const override;


/// <summary>
/// Movement
/// </summary

public:

	UPROPERTY(EditAnywhere)
	bool bCanMove = true;

	UPROPERTY(EditAnywhere)
	FVector MinPositionOffset;
	UPROPERTY(EditAnywhere)
	FVector MaxPositionOffset;

	UPROPERTY(EditAnywhere)
	bool ShouldMoveX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ShouldMoveX", EditConditionHides))
	TEnumAsByte<EEasingType> XEasing;

	UPROPERTY(EditAnywhere)
	bool ShouldMoveY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ShouldMoveY", EditConditionHides))
	TEnumAsByte<EEasingType> YEasing;

	UPROPERTY(EditAnywhere)
	bool ShouldMoveZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ShouldMoveZ", EditConditionHides))
	TEnumAsByte<EEasingType> ZEasing;

	UPROPERTY(EditAnywhere)
	float Speed;

public:

	void HandleMovement(float deltaTime);

	void MoveX(float deltaTime);
	void MoveY(float deltaTime);
	void MoveZ(float deltaTime);

	float BounceValue(float value, float min, float max, float speed, float deltaTime, bool& directionBool);


private:
	FVector StartPosition;
	FVector MinPosition;
	FVector MaxPosition;
	float TValue;
	bool DirectionBool;


/// <summary>
/// /Color
/// </summary>
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRelativeContext ContextToCentralActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor ColorBasedOnContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanChangeColor;

public:

	UFUNCTION(BlueprintCallable)
	void SetColorBasedOnContext(FRelativeContext& context) {
		FColor color;
		color.R = GetXColorValue(context.XContext) + GetDistanceColorValue(context.DistanceContext);
		color.G = GetYColorValue(context.YContext) + GetDistanceColorValue(context.DistanceContext);
		color.B = GetZColorValue(context.ZContext) + GetDistanceColorValue(context.DistanceContext);
		color.A = 255;

		//This is just so we can check the details
		ColorBasedOnContext = color;

		ChangeColor(color);
	}

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ChangeColor(FColor color);

	UFUNCTION(BlueprintCallable)
	void SetContext(FRelativeContext context) {
		ContextToCentralActor = context;
		SetColorBasedOnContext(context);
	}

private:
	uint8 GetXColorValue(EPositionXContext context) {
		if (context == EPositionXContext::Behind)
			return 170;
		return 0;
	}

	uint8 GetYColorValue(EPositionYContext context) {
		if (context == EPositionYContext::ToTheLeft)
			return 170;
		return 0;
	}

	uint8 GetZColorValue(EPositionZContext context) {
		if (context == EPositionZContext::Above)
			return 170;
		return 0;
	}

	uint8 GetDistanceColorValue(EDistanceContext context) {
		if (context == EDistanceContext::Close)
			return 75;
		return 0;
	}


public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Context")
	bool DrawArc;
};
