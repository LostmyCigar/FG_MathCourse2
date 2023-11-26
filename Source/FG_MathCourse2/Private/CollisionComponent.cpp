// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionComponent.h"
#include "Collision/CollisionSubsystem.h"

FCollisionShapeInfo::FCollisionShapeInfo()
{
}

UCollisionComponent::UCollisionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCollisionComponent::BeginPlay()
{
	Super::BeginPlay();

	const auto Subsystem = GetWorld()->GetSubsystem<UCollisionSubsystem>();
	Subsystem->RegisterComponent(this);

	GetOwner()->OnDestroyed.AddDynamic(this, &UCollisionComponent::Destroy);
}

void UCollisionComponent::Destroy(AActor* destroyedActor)
{
	const auto Subsystem = GetWorld()->GetSubsystem<UCollisionSubsystem>();
	Subsystem->UnregisterComponent(this);
}


void UCollisionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


