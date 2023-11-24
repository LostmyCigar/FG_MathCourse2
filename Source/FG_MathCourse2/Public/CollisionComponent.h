// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollisionComponent.generated.h"

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

	virtual bool CheckCollision(ECustomCollisionShape OtherObjectCollisionShape) { return false; };

public:
	UPROPERTY()
	TEnumAsByte<ECustomCollisionShape> CollisionShape;


public:
	UPROPERTY(BlueprintAssignable, Category = "Collision")
	FOnCollision OnCollision;
};
