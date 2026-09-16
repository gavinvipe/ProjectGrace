// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/ItemDataAsset.h"
#include "Library/StructEnumLibrary.h"
#include "GameplayTagContainer.h"
#include "WeaponDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGRACE_API UWeaponDataAsset : public UItemDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float WeaponDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FGameplayTag GameplayCueTag;

};
