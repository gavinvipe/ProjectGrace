// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CombatComponent.h"
#include "components/SkeletalMeshComponent.h"
#include "GameFrameWork/Character.h"

// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// ...
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UCombatComponent::RequestAttackToken(int32 Amount)
{
	if (Amount <= CurrentAttackToken)
	{
		CurrentAttackToken -= Amount;
		return true;
	}
	return false;
}

void UCombatComponent::ReturnAttackToken(int32 Amount)
{
	CurrentAttackToken += Amount;
}

void UCombatComponent::AttackTrace(FName BoneName)
{
	USkeletalMeshComponent* Mesh = Cast<ACharacter>(GetOwner())->GetMesh();

	if (!Mesh) return;
	
	FVector Start = Mesh->GetSocketLocation(BoneName);
	FVector End = Start + (GetOwner()->GetActorForwardVector() * TraceLength);

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());

	bool bHit = UKismetSystemLibrary::SphereTraceMultiForObjects(
		GetWorld(),
		Start,
		End,
		TraceRadius,
		ObjectTypes,
		false,
		ActorsToIgnore,
		DebugTrace,
		HitResults,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		DrawDebugTime
	);


}

