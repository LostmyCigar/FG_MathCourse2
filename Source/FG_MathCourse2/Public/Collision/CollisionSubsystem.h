// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CollisionComponent.h"
#include "CollisionSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FG_MATHCOURSE2_API UCollisionSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TArray<UCollisionComponent*> CollisionComponents;

public:
	virtual void Tick(float DeltaTime) override;

public:
	void RegisterComponent(UCollisionComponent* Components);
	void UnregisterComponent(UCollisionComponent* Components);

	virtual TStatId GetStatId() const override;
};
