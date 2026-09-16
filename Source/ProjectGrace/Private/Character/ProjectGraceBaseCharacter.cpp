// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ProjectGraceBaseCharacter.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayAbilitySystem/BasicAttributeSet.h"
#include "Components/IdentityComponent.h"
#include "Components/BehaviorComponent.h"
#include "Components/TagManager.h"

// Sets default values
AProjectGraceBaseCharacter::AProjectGraceBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	BasicAttributeSet = CreateDefaultSubobject<UBasicAttributeSet>(TEXT("BasicAttributeSet"));
	IdentityComponent = CreateDefaultSubobject<UIdentityComponent>(TEXT("IdentityComponent"));
	BehaviorComponent = CreateDefaultSubobject<UBehaviorComponent>(TEXT("BehaviorComponent"));
	TagManager = CreateDefaultSubobject<UTagManager>(TEXT("TagManger"));

}

// Called when the game starts or when spawned
void AProjectGraceBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectGraceBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		GrantAbilities(DefaultAbilities);
	}
}

// Called every frame
void AProjectGraceBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AProjectGraceBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AProjectGraceBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

TArray<FGameplayAbilitySpecHandle> AProjectGraceBaseCharacter::GrantAbilities(TArray<TSubclassOf<UGameplayAbility>> Abilities)
{
	if (!AbilitySystemComponent) return TArray<FGameplayAbilitySpecHandle>();

	TArray<FGameplayAbilitySpecHandle> AbilityHandles;

	for (TSubclassOf<UGameplayAbility> Ability : Abilities)
	{
		FGameplayAbilitySpecHandle SpecHandle = AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, 1, -1, this));
		AbilityHandles.Add(SpecHandle);
	}

	SendAbilitiesChangedEvent();
	return AbilityHandles;

}

void AProjectGraceBaseCharacter::RemoveAbilities(TArray<FGameplayAbilitySpecHandle> AbilityHandles)
{
	if (!AbilitySystemComponent) return;

	for (FGameplayAbilitySpecHandle AbiltityHandle : AbilityHandles)
	{
		AbilitySystemComponent->ClearAbility(AbiltityHandle);
	}

	SendAbilitiesChangedEvent();
}

void AProjectGraceBaseCharacter::SendAbilitiesChangedEvent()
{
	FGameplayEventData EventData;
	EventData.EventTag = FGameplayTag::RequestGameplayTag(FName("Event.Abilities.Changed"));
	EventData.Instigator = this;
	EventData.Target = this;

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(this, EventData.EventTag, EventData);
}

