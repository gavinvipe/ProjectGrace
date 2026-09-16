// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VehicleDataAsset.generated.h"

/**
 * 
 */

//USTRUCT()
//struct FWheelSetup
//{
//	GENERATED_USTRUCT_BODY()
//
//	// The wheel class to use
//	UPROPERTY(EditAnywhere, Category = WheelSetup)
//	TSubclassOf<UChaosVehicleWheel> WheelClass;
//
//	// Bone name on mesh to create wheel at
//	//UPROPERTY(EditAnywhere, Category = WheelSetup)
//	//FName SteeringBoneName;
//
//	// Bone name on mesh to create wheel at
//	UPROPERTY(EditAnywhere, Category = WheelSetup)
//	FName BoneName;
//
//	// Additional offset to give the wheels for this axle.
//	UPROPERTY(EditAnywhere, Category = WheelSetup)
//	FVector AdditionalOffset;
//
//};

UCLASS()
class PROJECTGRACE_API UVehicleDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Vehicle")
	TSoftObjectPtr<class USkeletalMesh> SkeletalMesh;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Vehicle")
	//TArray<FWheelSetup> WheelSetup;
};
