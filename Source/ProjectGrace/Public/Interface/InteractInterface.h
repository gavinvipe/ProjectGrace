// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Library/StructEnumLibrary.h"
#include "InteractInterface.generated.h"


USTRUCT(BlueprintType)
struct FHitReturn
{
	GENERATED_BODY()

	UPROPERTY()
	bool bHit = false;
	FHitResult HitResult;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTGRACE_API IInteractInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interact")
	EInteractableType GetInteractableItemType() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interact")
	FName GetInteractableItemID() const;

};
