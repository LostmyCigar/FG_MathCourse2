// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ContextLibrary.generated.h"

//We do be copypasting
#define TEST_BIT(Bitmask, Bit) (((Bitmask) & (1 << static_cast<int32>(Bit))) > 0)
#define TEST_BITS(Bitmask, Bit) (((Bitmask) & Bit) == Bit)

#define SET_BIT(Bitmask, Bit) (Bitmask |= 1 << static_cast<int32>(Bit))

#define CLEAR_BIT(Bitmask, Bit) (Bitmask &= ~(1 << static_cast<int32>(Bit)))

//This looks a bit like an awakward bit flag but i think this is
//clearer since its states and we only want to have one active at a time

UENUM(BlueprintType)
enum class EPositionXContext
{
	NoContext,

	Behind,
	InFront,
};

UENUM(BlueprintType)
enum class EPositionYContext
{
	NoContext,

	ToTheRight,
	ToTheLeft,
};

UENUM(BlueprintType)
enum class EPositionZContext
{
	NoContext,

	Above,
	Below,
};

UENUM(BlueprintType)
enum class EDistanceContext
{
	NoContext,

	Close,
	Far,
};

UENUM(BlueprintType)
enum class EFacingContext
{
	NoContext,

	FacingSame,
	FacingOpposite
};



USTRUCT(BlueprintType)
struct FG_MATHCOURSE2_API FRelativeContext {

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere);
	EPositionXContext XContext;
	UPROPERTY(EditAnywhere);
	EPositionYContext YContext;
	UPROPERTY(EditAnywhere);
	EPositionZContext ZContext;

	UPROPERTY(EditAnywhere);
	EDistanceContext DistanceContext;
	UPROPERTY(EditAnywhere);
	EFacingContext FacingContext;
};

UCLASS()
class FG_MATHCOURSE2_API UContextLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Context")
	static FRelativeContext GetAllPositionContext(AActor* sourceActor, AActor* targetActor);

	UFUNCTION(BlueprintCallable, Category = "Context")
	static void GetXAxisContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext);

	UFUNCTION(BlueprintCallable, Category = "Context")
	static void GetYAxisContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext);

	UFUNCTION(BlueprintCallable, Category = "Context")
	static void GetZAxisContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext);

	UFUNCTION(BlueprintCallable, Category = "Context")
	static void GetDistanceContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext);

	UFUNCTION(BlueprintCallable, Category = "Context")
	static void GetFacingContext(AActor* sourceActor, AActor* targetActor, FRelativeContext& relativeContext);
};
