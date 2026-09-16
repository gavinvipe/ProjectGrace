// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilitySystem/BasicAttributeSet.h"
#include "GameplayEffectExtension.h"


UBasicAttributeSet::UBasicAttributeSet()
{
	Health = 100.f;
	MaxHealth = 100.f;
	Stamina = 100.f;
	MaxStamina = 100.f;
	Skill = 100.f;
	MaxSkill = 100.f;
}

void UBasicAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	//Health
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0, GetMaxHealth()));

		OnHealthUpdated.Broadcast(Data.EvaluatedData.Magnitude, GetHealth());
	}

	//Max Health
	if (Data.EvaluatedData.Attribute == GetMaxHealthAttribute())
	{
		OnMaxHealthUpdated.Broadcast(Data.EvaluatedData.Magnitude, GetHealth());
	}

	//Skill
	if (Data.EvaluatedData.Attribute == GetSkillAttribute())
	{
		SetSkill(FMath::Clamp(GetSkill(), 0, GetMaxSkill()));

		OnSkillUpdated.Broadcast(Data.EvaluatedData.Magnitude, GetSkill());
	}

	//Max Skill
	if (Data.EvaluatedData.Attribute == GetMaxSkillAttribute())
	{

		OnMaxSkillUpdated.Broadcast(Data.EvaluatedData.Magnitude, GetMaxSkill());
	}

	//Stamina
	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0, GetMaxStamina()));

		OnStaminaUpdated.Broadcast(Data.EvaluatedData.Magnitude, GetStamina());
	}

	//Max Stamina
	if (Data.EvaluatedData.Attribute == GetMaxStaminaAttribute())
	{

		OnMaxStaminaUpdated.Broadcast(Data.EvaluatedData.Magnitude, GetMaxStamina());
	}
}
