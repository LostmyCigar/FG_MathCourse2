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
	bool CheckCollision(UCollisionComponent* OtherCollisionComponent, FVector& collisionPoint) override {
		
		//If things are destroyed with bad timing this might be needed
		if (!OtherCollisionComponent)
			return false;


		switch (OtherCollisionComponent->CollisionShape)
		{

		case Sphere:
			return UIntersectionLibrary::SphereSphere(GetOwner()->GetActorLocation(), ShapeInfo.Radius,
				OtherCollisionComponent->GetOwner()->GetActorLocation(), OtherCollisionComponent->ShapeInfo.Radius, collisionPoint);
		default:
			break;
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
