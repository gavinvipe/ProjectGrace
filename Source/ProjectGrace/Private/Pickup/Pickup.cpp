// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup/Pickup.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/InteractableComponent.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupRadius = CreateDefaultSubobject<USphereComponent>(TEXT("PickupRadius"));

	SetRootComponent(PickupRadius);
	PickupMesh->SetupAttachment(PickupRadius);


	PickupMesh->SetSimulatePhysics(true);
	PickupMesh->SetCollisionProfileName(TEXT("PhysicsActor"));

	InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FName APickup::GetInteractableItemID_Implementation() const
{
	return InteractableComponent->ItemID.RowName;
}

EInteractableType APickup::GetInteractableItemType_Implementation() const
{
	return InteractableComponent->InteractableType;

}


