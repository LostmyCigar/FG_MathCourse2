// Fill out your copyright notice in the Description page of Project Settings.


#include "Collision/CollisionSubsystem.h"


void UCollisionSubsystem::RegisterComponent(UCollisionComponent* Components)
{
	if (!CollisionComponents.Contains(Components))
		CollisionComponents.Add(Components);
}

void UCollisionSubsystem::UnregisterComponent(UCollisionComponent* Components)
{
	if (CollisionComponents.Contains(Components))
		CollisionComponents.Remove(Components);
}


void UCollisionSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	for (int i = 0; i < CollisionComponents.Num(); i++)
	{
		for (int j = 0; j < CollisionComponents.Num(); j++)
		{
			if (CollisionComponents[i] == CollisionComponents[j])
				continue;



		}
	}


	// Resolve Collisions
	//for (const auto DemonstratorA : CollisionDemonstrators)
	//{
	//	for (const auto DemonstratorB : CollisionDemonstrators)
	//	{
	//		if (DemonstratorA == DemonstratorB)
	//			continue;

	//		if (DemonstratorA->CollisionType == ECollisionType::SphereCollider)
	//		{
	//			FVector ContactPoint;

	//			if (DemonstratorB->CollisionType == ECollisionType::SphereCollider)
	//			{
	//				if (UIntersectionUtility::SphereSphere(
	//					DemonstratorA->GetActorLocation(),
	//					DemonstratorA->GetRadius(),
	//					DemonstratorB->GetActorLocation(),
	//					DemonstratorB->GetRadius(),
	//					ContactPoint))
	//				{
	//					DemonstratorA->AddForce(-DemonstratorA->Velocity * 2.f);
	//					DrawDebugPoint(GetWorld(), ContactPoint, 25.f, FColor::Purple, false, 1.5f);
	//				}
	//			}

	//			if (DemonstratorB->CollisionType == ECollisionType::PlaneCollider)
	//			{
	//				if (UIntersectionUtility::SpherePlane(
	//					DemonstratorA->GetActorLocation(),
	//					DemonstratorA->GetRadius(),
	//					DemonstratorB->GetActorLocation(),
	//					DemonstratorB->GetActorUpVector(),
	//					ContactPoint))
	//				{
	//					DemonstratorA->AddForce(-DemonstratorA->Velocity * 2.f);
	//					DrawDebugPoint(GetWorld(), ContactPoint, 25.f, FColor::Purple, false, 1.5f);
	//				}
	//			}
	//		}
	//	}
	//}


}

TStatId UCollisionSubsystem::GetStatId() const
{
	return GetStatID();
}