// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
//#include "GameplayTagContainer.h"
#include "UtilityConsideration.generated.h"

/**
 * 
 */
struct FUtilityContext;

//UCLASS(Blueprintable, EditInlineNew)
UCLASS(Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class PROJECTGRACE_API UUtilityConsideration : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Consideration")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Consideration")
	float Weight = 1.f;

	//Function

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Consideration")
	float Evaluate(FUtilityContext Context);

};
