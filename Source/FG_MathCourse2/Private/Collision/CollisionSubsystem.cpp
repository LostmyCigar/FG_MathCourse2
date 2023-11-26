// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Collision/CollisionSubsystem.h"


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
		for (int j = i + 1; j < CollisionComponents.Num(); j++) // Starting at i + 1 should skip already tested collisions 
		{

			FVector collisionPoint;
			if (CollisionComponents[i]->CheckCollision(CollisionComponents[j], collisionPoint)) {

				CollisionComponents[i]->OnCollision(collisionPoint, CollisionComponents[j]->GetOwner(), CollisionComponents[j]);
				CollisionComponents[j]->OnCollision(collisionPoint, CollisionComponents[i]->GetOwner(), CollisionComponents[i]);
			}
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