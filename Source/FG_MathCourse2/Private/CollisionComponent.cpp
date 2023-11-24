// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionComponent.h"
#include "Collision/CollisionSubsystem.h"


UCollisionComponent::UCollisionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UCollisionComponent::BeginPlay()
{
	Super::BeginPlay();

	const auto Subsystem = GetWorld()->GetSubsystem<UCollisionSubsystem>();
	Subsystem->RegisterComponent(this);
	
}


void UCollisionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

