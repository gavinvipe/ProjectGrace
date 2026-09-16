// Fill out your copyright notice in the Description page of Project Settings.


#include "Sport/SportManager.h"

// Sets default values
ASportManager::ASportManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ASportManager::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ASportManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
