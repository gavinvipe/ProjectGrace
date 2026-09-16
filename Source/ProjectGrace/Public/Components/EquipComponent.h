// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EquipComponent.generated.h"


class AActor;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(ProjectGrace), meta=(BlueprintSpawnableComponent) )
class PROJECTGRACE_API UEquipComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEquipComponent();

	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Equip")
	bool IsEquipping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Equip")
	bool IsUnEquipping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Equip")
	FName EquippedItemID;

protected:

	// Called when the game starts
	virtual void BeginPlay() override;

	//variables

	UPROPERTY(BlueprintReadWrite, category = "Equip")
	AActor* CurrentEquippedItem;

	UPROPERTY(BlueprintReadWrite, category = "Equip")
	AActor* PreviousEquippedItem;
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Inventory")
	void EquipItem(FName ItemID, AActor* ItemPickup);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Inventory")
	void UnequipItem(FName ItemID);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Inventory")
	void SwitchItem(FName ItemID);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Inventory")
	void UseStackItem();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Inventory")
	FName GetEquipedItemId(AActor* Item) const;
};
