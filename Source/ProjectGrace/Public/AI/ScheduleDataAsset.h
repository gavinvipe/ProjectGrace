// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ScheduleDataAsset.generated.h"

/**
 * 
 */
struct FScheduleStruct;

UCLASS()
class PROJECTGRACE_API UScheduleDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Schedule")
	TArray<FScheduleStruct> Schedules;

};
