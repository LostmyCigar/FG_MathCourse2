// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ContextLibrary.generated.h"

#pragma once

UENUM()
enum class ERelativeContext
{
	Behind,
	InFront,
	ToTheRight,
	ToTheLeft,
	Above,
	Below,
	Close,
	Far,
	Seen,
	Unseen,
	FacingSame,
	FacingOpposite
};



UCLASS()
class FG_MATHCOURSE2_API UContextLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Context")
	static TArray<ERelativeContext> GetAllPositionContext(AActor* sourceActor, AActor* targetActor);

	UFUNCTION(BlueprintCallable, Category = "Context")
	static void GetXAxisContext(AActor* sourceActor, AActor* targetActor, TArray<ERelativeContext>& relativeContextArray);

	UFUNCTION(BlueprintCallable, Category = "Context")
	static void GetYAxisContext(AActor* sourceActor, AActor* targetActor, TArray<ERelativeContext>& relativeContextArray);

	UFUNCTION(BlueprintCallable, Category = "Context")
	static void GetZAxisContext(AActor* sourceActor, AActor* targetActor, TArray<ERelativeContext>& relativeContextArray);

	UFUNCTION(BlueprintCallable, Category = "Context")
	static void GetDistanceContext(AActor* sourceActor, AActor* targetActor, TArray<ERelativeContext>& relativeContextArray);

	UFUNCTION(BlueprintCallable, Category = "Context")
	static void GetFacingContext(AActor* sourceActor, AActor* targetActor, TArray<ERelativeContext>& relativeContextArray);
};
