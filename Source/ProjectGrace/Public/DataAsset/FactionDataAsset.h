// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FactionDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGRACE_API UFactionDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faction")
	FText FactionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faction")
	FText Description;

};
