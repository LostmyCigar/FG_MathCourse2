// Fill out your copyright notice in the Description page of Project Settings.


#include "ContextLibrary.h"

TArray<ERelativeContext> UContextLibrary::GetAllPositionContext(AActor* sourceActor, AActor* targetActor)
{
	auto relativeContextArray = TArray<ERelativeContext>();
	
	GetXAxisContext(sourceActor, targetActor, relativeContextArray);
	GetYAxisContext(sourceActor, targetActor, relativeContextArray);
	GetZAxisContext(sourceActor, targetActor, relativeContextArray);

	GetDistanceContext(sourceActor, targetActor, relativeContextArray);

	GetFacingContext(sourceActor, targetActor, relativeContextArray);

	return relativeContextArray;
}

void UContextLibrary::GetXAxisContext(AActor* sourceActor, AActor* targetActor, TArray<ERelativeContext>& relativeContextArray)
{

}

void UContextLibrary::GetYAxisContext(AActor* sourceActor, AActor* targetActor, TArray<ERelativeContext>& relativeContextArray)
{
}

void UContextLibrary::GetZAxisContext(AActor* sourceActor, AActor* targetActor, TArray<ERelativeContext>& relativeContextArray)
{
}

void UContextLibrary::GetDistanceContext(AActor* sourceActor, AActor* targetActor, TArray<ERelativeContext>& relativeContextArray)
{
}

void UContextLibrary::GetFacingContext(AActor* sourceActor, AActor* targetActor, TArray<ERelativeContext>& relativeContextArray)
{
}
