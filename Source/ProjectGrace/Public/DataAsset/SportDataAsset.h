// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Library/StructEnumLibrary.h"
#include "SportDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGRACE_API USportDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Sport")
	FText SportNanme;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Sport")
	ESportType SportType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Sport")
	int32 MaxPlayerPerTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Sport")
	float MatchDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Sport")
	TSoftClassPtr<class ASportBall> Ball;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Sport")
	int32 PointsPerGoal;
};
