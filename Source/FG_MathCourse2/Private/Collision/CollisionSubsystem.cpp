// Fill out your copyright notice in the Description page of Project Settings.

#include "Collision/CollisionSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"


void UCollisionSubsystem::RegisterComponent(UCollisionComponent* Component)
{
	if (!CollisionComponents.Contains(Component))
		CollisionComponents.Add(Component);

}

void UCollisionSubsystem::UnregisterComponent(UCollisionComponent* Component)
{
	if (CollisionComponents.Contains(Component))
		CollisionComponents.Remove(Component);
}


void UCollisionSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int i = 0; i < CollisionComponents.Num(); i++)
	{
		//Destroying things became a bit awkward
		if (!CollisionComponents[i]) {
			CollisionComponents.Remove(CollisionComponents[i]);
			continue;
		}

		for (int j = i + 1; j < CollisionComponents.Num(); j++) // Starting at i + 1 should skip already tested collisions 
		{
			if (!CollisionComponents[j]) {
				CollisionComponents.Remove(CollisionComponents[j]);
				continue;
			}

			FVector collisionPoint;
			if (CollisionComponents[i]->CheckCollision(CollisionComponents[j], collisionPoint)) {

				CollisionComponents[i]->OnCollisionOngoing(collisionPoint, CollisionComponents[j]->GetOwner(), CollisionComponents[j]);
				CollisionComponents[j]->OnCollisionOngoing(collisionPoint, CollisionComponents[i]->GetOwner(), CollisionComponents[i]);
			}
		}
	}
}

TStatId UCollisionSubsystem::GetStatId() const
{
	return GetStatID();
}