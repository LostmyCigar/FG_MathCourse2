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

	UFUNCTION(BlueprintCallable)
	void MoveContextActors(TArray<APositionContextActor*> contextActors, bool shouldMove) {

		for (int i = 0; i < contextActors.Num(); i++)
		{
			if (contextActors[i])
				contextActors[i]->bCanMove = shouldMove;
		}
	}
};
