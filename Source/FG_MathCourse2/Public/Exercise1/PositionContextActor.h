// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Context")
	bool DrawArc;
};
