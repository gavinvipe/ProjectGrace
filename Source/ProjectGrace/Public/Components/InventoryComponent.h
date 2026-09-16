// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Library/StructEnumLibrary.h"
#include "InventoryComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(ProjectGrace), meta=(BlueprintSpawnableComponent) )
class PROJECTGRACE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	//variables
	//UPROPERTY(BlueprintReadWrite, category = "Equip")

	//function
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory")
	EInventoryAddMsg AddToInventory(FName ItemID);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Inventory")
	EInventoryRemMsg RemoveFromInventory(FName ItemID);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Inventory")
	int32 InventorySize;

protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Inventory", meta = (BlueprintProtected))
	int32 GetStackSize(FName ItemID) const;


	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	TMap<FName, FInventoryItem> Items;

	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
