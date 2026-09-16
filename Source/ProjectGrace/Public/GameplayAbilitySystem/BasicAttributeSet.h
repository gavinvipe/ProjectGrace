// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BasicAttributeSet.generated.h"


#define PLAY_ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayAttributeEvent, float, EffectMagnitude, float, NewValue);

/**
 * 
 */
UCLASS()
class PROJECTGRACE_API UBasicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UBasicAttributeSet();

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	//Health
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Health;
	PLAY_ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Health);

	UPROPERTY(BlueprintAssignable, EditAnywhere)
	FPlayAttributeEvent OnHealthUpdated;

	//Max Health
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;
	PLAY_ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxHealth);

	UPROPERTY(BlueprintAssignable, EditAnywhere)
	FPlayAttributeEvent OnMaxHealthUpdated;

	//Skill
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Skill;
	PLAY_ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Skill);

	UPROPERTY(BlueprintAssignable, EditAnywhere)
	FPlayAttributeEvent OnSkillUpdated;

	//Max Skill
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxSkill;
	PLAY_ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxSkill);

	UPROPERTY(BlueprintAssignable, EditAnywhere)
	FPlayAttributeEvent OnMaxSkillUpdated;

	//Stamina
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Stamina;
	PLAY_ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Stamina);

	UPROPERTY(BlueprintAssignable, EditAnywhere)
	FPlayAttributeEvent OnStaminaUpdated;

	//Max Stamina
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxStamina;
	PLAY_ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxStamina);

	UPROPERTY(BlueprintAssignable, EditAnywhere)
	FPlayAttributeEvent OnMaxStaminaUpdated;
};
