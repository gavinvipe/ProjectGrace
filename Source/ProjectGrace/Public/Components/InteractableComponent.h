// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Library/StructEnumLibrary.h"
#include "InteractableComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(ProjectGrace), meta=(BlueprintSpawnableComponent) )
class PROJECTGRACE_API UInteractableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractableComponent();

	//variables

protected:      
	// Called when the game starts
	virtual void BeginPlay() override;

	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	EInteractableType InteractableType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable|Item", meta = (EditCondition = "InteractableType == EInteractableType::Pickup", EditConditionHides))
	FDataTableRowHandle ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable", meta = (EditCondition = "InteractableType == EInteractableType::Mount", EditConditionHides))
	FDataTableRowHandle VehicleType;
};
