// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/WeaponDataAsset.h"
#include "GameplayTagContainer.h"
#include "RangedDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGRACE_API URangedDataAsset : public UWeaponDataAsset
{
	GENERATED_BODY()

public:
	URangedDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	int32 Ammo = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	int32 MaxAmmo = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	bool bHasInfiniteAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	bool bIsHitscan = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	float TraceDeviation = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	float FireRate = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Projectile")
	TSoftClassPtr<class AWeaponProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Projectile")
	TSoftObjectPtr<class UStaticMesh> ProjectileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Projectile")
	float ProjectileSpeed = 2000.f;
	
};
