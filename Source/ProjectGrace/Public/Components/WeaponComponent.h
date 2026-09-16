// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollisionShape.h"
#include "Kismet/KismetSystemLibrary.h"
#include "WeaponComponent.generated.h"


class AWeapon;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(ProjectGrace), meta=(BlueprintSpawnableComponent) )
class PROJECTGRACE_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();


	UFUNCTION(BlueprintCallable, Category = "Weapon")
	AWeapon* GetCurrentWeapon() const;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetCurrentWeapon(AWeapon* Weapon);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool HasWeapon() const;

protected:
	//variables
	UPROPERTY(BlueprintReadWrite)
	AWeapon* CurrentWeapon;

	// Called when the game starts
	virtual void BeginPlay() override;


private:

	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Weapon")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool GetCanFire() const;

};
