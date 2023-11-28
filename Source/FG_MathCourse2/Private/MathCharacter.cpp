// Fill out your copyright notice in the Description page of Project Settings.


#include "MathCharacter.h"

AMathCharacter::AMathCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMathCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMathCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMathCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMathCharacter::CameraShake()
{
	GetWorld()->GetFirstPlayerController()->PlayerCameraManager->StartCameraShake(CameraShakeClass, 1);
}

