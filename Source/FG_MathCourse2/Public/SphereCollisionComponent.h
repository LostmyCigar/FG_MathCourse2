// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "SphereCollisionComponent.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, meta = (BlueprintSpawnableComponent))
class FG_MATHCOURSE2_API USphereCollisionComponent : public UCollisionComponent
{
	GENERATED_BODY()
	

public:
	UPROPERTY(EditAnywhere)
	float SphereRadius;

public:
	bool CheckCollision(ECustomCollisionShape OtherObjectCollisionShape) {
	
		if (OtherObjectCollisionShape == ECustomCollisionShape::Sphere) {
		} 

		return false;
	};

public:
	void BeginPlay() override {
		Super::BeginPlay();
		CollisionShape = Sphere;
	}

	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override {
		Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	}
};
