// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup/Item.h"
#include "CollisionShape.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Library/StructEnumLibrary.h"
#include "Weapon.generated.h"

class UMeshComponent;
class AWeaponPickup;
struct FStreamableHandle;


UCLASS()
class PROJECTGRACE_API AWeapon : public AItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Debug")
	TEnumAsByte<EDrawDebugTrace::Type> DrawDebugTrace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Debug")
	float DrawTime = 3.0f;

	TSharedPtr<FStreamableHandle> MeshGroupHandle;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Weapon|Trace")
	virtual void WeaponTrace();

	//UFUNCTION()
	//virtual void OnAssetLoaded();


public:	
	//var
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Identity")
	FName WeaponID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Identity")
	FName WeaponName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Identity")
	EWeaponType WeaponType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	UMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Identity")
	float WeaponDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	bool CanFire;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Weapon")
	void Fire();
};

//pinoc