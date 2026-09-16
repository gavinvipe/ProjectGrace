// Fill out your copyright notice in the Description page of Project Settings.


#include "Vehicles/Vehicle.h"
#include "Components/InteractableComponent.h"

AVehicle::AVehicle()
{
	InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interactable"));

	InteractableComponent->InteractableType = EInteractableType::Mount;
}
