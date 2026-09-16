// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/InteractInterface.h"
#include "Pickup.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UInteractableComponent;

UCLASS()
class PROJECTGRACE_API APickup : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	USphereComponent* PickupRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	UInteractableComponent* InteractableComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual FName GetInteractableItemID_Implementation() const override;

	virtual EInteractableType GetInteractableItemType_Implementation() const override;

};
