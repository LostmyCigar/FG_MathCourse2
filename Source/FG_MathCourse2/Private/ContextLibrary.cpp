// Fill out your copyright notice in the Description page of Project Settings.


#include "ContextLibrary.h"

FRelativeContext UContextLibrary::GetAllPositionContext(AActor* sourceActor, AActor* targetActor)
{
	FRelativeContext ReturnContext;
	
	GetXAxisContext(sourceActor, targetActor, ReturnContext);
	GetYAxisContext(sourceActor, targetActor, ReturnContext);
	GetZAxisContext(sourceActor, targetActor, ReturnContext);

	GetDistanceContext(sourceActor, targetActor, ReturnContext);

	GetFacingContext(sourceActor, targetActor, ReturnContext);

	return ReturnContext;
}

void UContextLibrary::GetXAxisContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext)
{

}

void UContextLibrary::GetYAxisContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext)
{
}

void UContextLibrary::GetZAxisContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext)
{
}

void UContextLibrary::GetDistanceContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext)
{
}

void UContextLibrary::GetFacingContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext)
{
}
