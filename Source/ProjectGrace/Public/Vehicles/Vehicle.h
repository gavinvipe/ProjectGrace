// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "Vehicle.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGRACE_API AVehicle : public AWheeledVehiclePawn
{
	GENERATED_BODY()
	
public:
	AVehicle();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interact")
	class UInteractableComponent* InteractableComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vehicle", meta = (ExposeOnSpawn = true))
	class UVehicleDataAsset* VehicleData;
};
