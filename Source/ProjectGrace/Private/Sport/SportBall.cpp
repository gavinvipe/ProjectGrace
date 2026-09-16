// Fill out your copyright notice in the Description page of Project Settings.


#include "Sport/SportBall.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ASportBall::ASportBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	BallRadius = CreateDefaultSubobject<USphereComponent>(TEXT("BallRadius"));
	BallCollision = CreateDefaultSubobject<USphereComponent>(TEXT("BallCollision"));

	SetRootComponent(BallRadius);
	BallCollision->SetupAttachment(BallRadius);
	BallMesh->SetupAttachment(BallCollision);


	BallMesh->SetSimulatePhysics(true);
	BallMesh->SetCollisionProfileName(TEXT("PhysicsActor"));

}

// Called when the game starts or when spawned
void ASportBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASportBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



