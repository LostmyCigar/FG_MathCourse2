// Fill out your copyright notice in the Description page of Project Settings.


#include "Exercise1/PositionContextActor.h"

APositionContextActor::APositionContextActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APositionContextActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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