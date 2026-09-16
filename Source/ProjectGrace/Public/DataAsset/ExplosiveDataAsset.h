// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/WeaponDataAsset.h"
#include "ExplosiveDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGRACE_API UExplosiveDataAsset : public UWeaponDataAsset
{
	GENERATED_BODY()

public:
	UExplosiveDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Projectile")
	float FuseTime = 2.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Projectile")
	TSoftClassPtr<class AWeaponProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Projectile")
	TSoftObjectPtr<class UStaticMesh> ProjectileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Projectile")
	float ProjectileSpeed = 2000.f;
};
