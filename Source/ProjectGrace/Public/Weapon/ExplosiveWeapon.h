// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Weapon.h"
#include "ExplosiveWeapon.generated.h"


UCLASS()
class PROJECTGRACE_API AExplosiveWeapon : public AWeapon
{
	GENERATED_BODY()
	
public:
	AExplosiveWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Explosive")
	float FuseTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Explosive|Projectile")
	float ProjectileSpeed = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Explosive|Projectile")
	TSoftClassPtr<class AWeaponProjectile> ProjectileClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	class UExplosiveDataAsset* DataAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	class UStaticMeshComponent* StaticMeshComponent;

protected:
	virtual void BeginPlay() override;

	//virtual void OnAssetLoaded() override;

};
