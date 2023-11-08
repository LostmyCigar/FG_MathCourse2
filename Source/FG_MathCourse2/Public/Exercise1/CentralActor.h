// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Exercise1/PositionContextActor.h"
#include "ContextLibrary.h"
#include "CentralActor.generated.h"

UCLASS()
class FG_MATHCOURSE2_API ACentralActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UFUNCTION(BlueprintCallable)
	void CheckContextOfActors(TArray<APositionContextActor*> contextActors);
};
