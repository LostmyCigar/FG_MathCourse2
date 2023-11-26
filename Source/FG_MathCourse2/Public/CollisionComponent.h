// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComponentVisualizer.h"
#include "CollisionComponent.generated.h"

#define PRINT(msg) GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Cyan, msg);

UENUM(BlueprintType)
enum ECustomCollisionShape : uint8
{
	//Im only doing sphere for now its good enough
	NoShape,
	Sphere
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCollision, FVector, CollisionPoint, AActor*, HitActor, UActorComponent*, HitComponent);


UCLASS( Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FG_MATHCOURSE2_API UCollisionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCollisionComponent();

public:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual bool CheckCollision(UCollisionComponent* OtherCollisionComponent, FVector& collisionPoint) { return false; };

	virtual void OnCollision(FVector collisionPoint, AActor* hitActor, UActorComponent* hitComponent) {
		OnCollisionEvent.Broadcast(collisionPoint, hitActor, hitComponent);
	}

public:
	UPROPERTY()
	TEnumAsByte<ECustomCollisionShape> CollisionShape;


public:
	UPROPERTY(BlueprintAssignable, Category = "Collision", DisplayName = "OnComponentCollision")
	FOnCollision OnCollisionEvent;
};
