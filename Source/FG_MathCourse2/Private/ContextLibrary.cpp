// Fill out your copyright notice in the Description page of Project Settings.


#include "ContextLibrary.h"

FRelativeContext UContextLibrary::GetAllPositionContext(AActor* sourceActor, AActor* targetActor)
{
	FRelativeContext ReturnContext;
	
	//Doing the calculations in every function is a bit awkward but then they are easier to use in isolation
	//and im to lazy for method overloading here

	GetXAxisContext(sourceActor, targetActor, ReturnContext);
	GetYAxisContext(sourceActor, targetActor, ReturnContext);
	GetZAxisContext(sourceActor, targetActor, ReturnContext);

	GetDistanceContext(sourceActor, targetActor, ReturnContext);

	GetFacingContext(sourceActor, targetActor, ReturnContext);

	return ReturnContext;
}

void UContextLibrary::GetXAxisContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext)
{
	const auto OtherLocation = targetActor->GetActorLocation();
	const auto LocalSpaceLocation = sourceActor->GetActorTransform().InverseTransformPosition(OtherLocation);

	if (LocalSpaceLocation.X > 0)
		relativeContext.XContext = EPositionXContext::InFront;
	else if (LocalSpaceLocation.X < 0)
		relativeContext.XContext = EPositionXContext::Behind;
}

void UContextLibrary::GetYAxisContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext)
{
	const auto OtherLocation = targetActor->GetActorLocation();
	const auto LocalSpaceLocation = sourceActor->GetActorTransform().InverseTransformPosition(OtherLocation);

	if (LocalSpaceLocation.Y > 0)
		relativeContext.YContext = EPositionYContext::ToTheRight;
	else if (LocalSpaceLocation.Y < 0)
		relativeContext.YContext = EPositionYContext::ToTheLeft;
}

void UContextLibrary::GetZAxisContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext)
{
	const auto OtherLocation = targetActor->GetActorLocation();
	const auto LocalSpaceLocation = sourceActor->GetActorTransform().InverseTransformPosition(OtherLocation);

	if (LocalSpaceLocation.Z > 0)
		relativeContext.ZContext = EPositionZContext::Above;
	else if (LocalSpaceLocation.Z < 0)
		relativeContext.ZContext = EPositionZContext::Below;
}

void UContextLibrary::GetDistanceContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext)
{
	const auto TargetLocation = sourceActor->GetActorLocation();
	const auto OtherLocation = targetActor->GetActorLocation();
	const auto Direction = OtherLocation - TargetLocation;

	if (Direction.Length() > 1000)
		relativeContext.DistanceContext = EDistanceContext::Far;
	else relativeContext.DistanceContext = EDistanceContext::Close;
}

void UContextLibrary::GetFacingContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext)
{
	const auto FacingDot = FVector::DotProduct(sourceActor->GetActorForwardVector(), targetActor->GetActorForwardVector());

	if (FacingDot > 0.5)
		relativeContext.FacingContext = EFacingContext::FacingSame;
	else relativeContext.FacingContext = EFacingContext::FacingOpposite;

}
