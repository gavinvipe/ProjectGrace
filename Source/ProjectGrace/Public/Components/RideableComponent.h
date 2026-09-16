// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Library/StructEnumLibrary.h"
#include "RideableComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup = (ProjectGrace), meta = (BlueprintSpawnableComponent))
class PROJECTGRACE_API URideableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URideableComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Rideable")
	EVehicleType RideableType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Rideable")
	bool bHasRide;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Rideable")
	class ARideable* CurrentRideable;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Rideable")
	class URideableMovementComponent* RideableMovementComponent;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable")
	void Mount(AActor* Rideable);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable")
	void Unmount();

};
