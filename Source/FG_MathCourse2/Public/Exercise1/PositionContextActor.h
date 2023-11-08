// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ContextLibrary.h"
#include "PositionContextActor.generated.h"

//a little bit of copy paste
UCLASS(BlueprintType, hidecategories = (Input, Movement, Collision, Rendering, HLOD, WorldPartition, DataLayers, Replication, Networking, Actor, LevelInstance, Cooking))
class FG_MATHCOURSE2_API APositionContextActor : public AActor
{
	GENERATED_BODY()
	
public:	
	APositionContextActor();


public:	
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly() const override;


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERelativeContext ContextToCentralActor;

public:

	/// <summary>
	/// This is where we wanna try to lerp stuff later but for now this will do
	/// </summary>
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetColorBasedOnContext(ERelativeContext& context) {

		

		uint8 R = 0;
		uint8 G = 0;
		uint8 B = 0;
		uint8 A = 0;






		FColor color;
		color.R = R;
		color.G = G;
		color.B = B;
		color.A = A;

		ChangeColor(color);
	}

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ChangeColor(FColor color);

	UFUNCTION(BlueprintCallable)
	void SetContext(ERelativeContext context) {
		ContextToCentralActor = context;
		SetColorBasedOnContext(context);
	}

private:
	uint8 GetXColorValue(EPositionXContext context) {
		if (context == EPositionXContext::Behind)
			return 255;
		return 0;
	}

	uint8 GetYColorValue(EPositionYContext context) {
		if (context == EPositionYContext::ToTheLeft)
			return 255;
		return 0;
	}

	uint8 GetZColorValue(EPositionZContext context) {
		if (context == EPositionZContext::Above)
			return 255;
		return 0;
	}

	uint8 GetDistanceColorValue(EDistanceContext context) {
		if (context == EDistanceContext::Close)
			return 255;
		return 0;
	}


public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Context")
	bool DrawArc;
};
