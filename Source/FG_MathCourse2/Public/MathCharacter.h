// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MathCharacter.generated.h"

UCLASS()
class FG_MATHCOURSE2_API AMathCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMathCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	UFUNCTION(BlueprintCallable)
	void CameraShake();

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UCameraShakeBase> CameraShakeClass;

};
