// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Weapon.h"
#include "RangedWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGRACE_API ARangedWeapon : public AWeapon
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Debug")
	TEnumAsByte<EDrawDebugTrace::Type> DrawMainDebugTrace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Ammo")
	int32 CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Ammo")
	int32 CurrentMaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Ammo")
	bool HasInfiniteAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	float FireRate = 0.1;

	virtual void BeginPlay() override;

	virtual void WeaponTrace() override;

	//virtual void OnAssetLoaded() override;

public:
	ARangedWeapon();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	class USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	float TraceDistance = 500.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	class URangedDataAsset* DataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Trace")
	float TraceDeviation = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Projectile")
	float ProjectileSpeed = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged")
	bool bIsHitscan;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|Ranged|Ammo")
	int32 Ammo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|Ranged|Ammo")
	int32 MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Trace")
	TEnumAsByte<ETraceTypeQuery> TraceChannel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Trace")
	FHitResult HitResult;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|Trace")
	FName TracePoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Ranged|Projectile")
	TSoftClassPtr<class AWeaponProjectile> ProjectileClass;


	UFUNCTION(BlueprintCallable, Category = "Weapon|Ranged|Ammo")
	bool CheckAmmo() const;

	UFUNCTION(BlueprintCallable, Category = "Weapon|Ranged|Ammo")
	void ConsumeAmmo();

	UFUNCTION(BLueprintImplementableEvent, BlueprintCallable, Category = "Weapon|Ranged")
	void Reload();

	

};
