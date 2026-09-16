// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Weapon.h"
#include "MeleeWeapon.generated.h"

class USceneComponent;
/**
 * 
 */
UCLASS()
class PROJECTGRACE_API AMeleeWeapon : public AWeapon
{
	GENERATED_BODY()

public:
	AMeleeWeapon();

	//var
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Trace")
	float TraceRaduis = 20.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	class UMeleeDataAsset* DataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Trace")
	FName TraceStartPoint = "Start";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Trace")
	FName TraceEndPoint = "End";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Trace")
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	class UStaticMeshComponent* StaticMeshComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Trace")
	TArray<FHitResult> HitResults;

	virtual void WeaponTrace() override;

	virtual void BeginPlay() override;

	//virtual void OnAssetLoaded() override;
	
};
