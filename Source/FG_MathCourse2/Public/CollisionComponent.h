// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Collision/IntersectionLibrary.h"
#include "ComponentVisualizer.h"
#include "CollisionComponent.generated.h"

#define PRINT(msg) GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Cyan, msg);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCollision, FVector, CollisionPoint, AActor*, HitActor, UActorComponent*, HitComponent);


USTRUCT(Blueprintable) //here we add info for all the collisionshapes
struct FCollisionShapeInfo {

	GENERATED_BODY()

	FCollisionShapeInfo();


public:
	UPROPERTY(EditAnywhere)
	float Radius = 10.0;

};

UCLASS( Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FG_MATHCOURSE2_API UCollisionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCollisionComponent();


	UPROPERTY(EditAnywhere);
	FCollisionShapeInfo ShapeInfo;


public:
	virtual void BeginPlay() override;
	virtual void Destroy(AActor* destroyedActor);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual bool CheckCollision(UCollisionComponent* OtherCollisionComponent, FVector& collisionPoint) { return false; };

	virtual void OnCollisionOngoing(FVector collisionPoint, AActor* hitActor, UActorComponent* hitComponent) {
		OnCollisionOngoingEvent.Broadcast(collisionPoint, hitActor, hitComponent);
	}


public:
	UPROPERTY()
	TEnumAsByte<ECustomCollisionShape> CollisionShape;


public:

	//Only doing ongoing cause im lazy and dont need to optimize >:)
	//Also, can live without the practiaclity of it atm

	UPROPERTY(BlueprintAssignable, Category = "Collision", DisplayName = "OnComponentCollisionOngoing")
	FOnCollision OnCollisionOngoingEvent;

	UPROPERTY(BlueprintAssignable, Category = "Collision", DisplayName = "OnComponentCollisionEnter")
	FOnCollision OnCollisionEnterEvent;

	UPROPERTY(BlueprintAssignable, Category = "Collision", DisplayName = "OnComponentCollisionExit")
	FOnCollision OnCollisionExitEvent;
};
