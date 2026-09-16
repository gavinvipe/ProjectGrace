// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/WeaponDataAsset.h"
#include "MeleeDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGRACE_API UMeleeDataAsset : public UWeaponDataAsset
{
	GENERATED_BODY()
	
public:
	UMeleeDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Melee")
	float TraceRaduis = 25.f;

};
