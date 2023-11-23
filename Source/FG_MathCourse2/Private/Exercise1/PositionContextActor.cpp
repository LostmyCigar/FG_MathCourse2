// Fill out your copyright notice in the Description page of Project Settings.

#include "Exercise1/PositionContextActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

APositionContextActor::APositionContextActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APositionContextActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//Interpolation / Movement
	TValue = BounceValue(TValue, 0, 1, Speed, DeltaTime, DirectionBool);

	if (ShouldMoveX)
		MoveX(DeltaTime);
	if (ShouldMoveY)
		MoveY(DeltaTime);
	if (ShouldMoveZ)
		MoveZ(DeltaTime);





	//Debug drawings

	const FVector Cross = FVector::CrossProduct(GetActorForwardVector(), GetActorRightVector());

	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f, FColor::Red);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + GetActorRightVector() * 100.f, FColor::Green);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + Cross * 100.f, FColor::Blue);


	if (!DrawArc)
		return;

	DrawDebugCone(
		GetWorld(),
		GetActorLocation(),
		GetActorForwardVector(),
		400,
		FMath::DegreesToRadians(45 * .5f),
		0.f,
		1,
		FColor::Green
	);

}

bool APositionContextActor::ShouldTickIfViewportsOnly() const
{
	return true;
}





void APositionContextActor::MoveX(float deltaTime)
{
}

void APositionContextActor::MoveY(float deltaTime)
{
}

void APositionContextActor::MoveZ(float deltaTime)
{
}

float APositionContextActor::BounceValue(float value, float min, float max, float speed, float deltaTime, bool& directionBool)
{
	float T = value;

	if (T >= max || T <= min)
		directionBool = !directionBool;

	int multiplier = directionBool ? 1 : -1;

	T += deltaTime * speed * multiplier;

	T = FMath::Clamp(T, min, max);

	return T;
}
