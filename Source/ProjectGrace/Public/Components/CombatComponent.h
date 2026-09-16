// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollisionShape.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CombatComponent.generated.h"

UENUM(BlueprintType, meta = (ScriptName = "CombatState"))
enum class ECombatState : uint8
{
	None,
	Attacking,
	Blocking,
	Parrying
};


UCLASS(Blueprintable, BlueprintType, ClassGroup=(ProjectGrace), meta=(BlueprintSpawnableComponent) )
class PROJECTGRACE_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();

	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Attack")
	bool bCanAttack = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Attack")
	int32 CurrentAttackToken = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Damage")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Trace")
	float TraceRadius = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Trace")
	float TraceLength = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Cache")
	float CachedAttackInputTime = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Cache")
	float CachedParryInputTime = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Trace")
	float CacheTime = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Debug")
	TEnumAsByte<EDrawDebugTrace::Type> DebugTrace = EDrawDebugTrace::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Trace")
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Debug")
	float DrawDebugTime = 3.0f;


protected:
	//variables
	UPROPERTY(BlueprintReadWrite, Category = "Combat|Attack")
	bool bIsAttacking;

	UPROPERTY(BlueprintReadWrite, Category = "Combat|Evade")
	bool bIsBlocking;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	ECombatState CombatState;

	UPROPERTY(BlueprintReadWrite, Category = "Combat|Attack")
	bool bIsLightAttack;

	UPROPERTY(BlueprintReadWrite, Category = "Combat|Attack")
	bool bIsHeavyAttack;
		
	UPROPERTY(BlueprintReadWrite, Category = "Combat|Evade")
	bool bIsParrying;

	UPROPERTY(BlueprintReadWrite, Category = "Combat|Combo")
	bool bIsCombo;

	UPROPERTY(BlueprintReadWrite, Category = "Combat|Evade")
	bool bIsParryWindowOpened;

	UPROPERTY(BlueprintReadWrite, Category = "Combat|Combo")
	int32 ComboCount;

	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly, Category = "Combat|Trace")
	TArray<FHitResult> HitResults;

	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Combat|Attack")
	void CheckCachedAttackInput();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Combat|Evade")
	void ParryWindow(bool bOpenWindow);

	UFUNCTION(BlueprintCallable, Category = "Combat|Trace")
	void AttackTrace(FName BoneName);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Combat")
	void PlayCombatAnim();


private:

	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Combat|Attack")
	void PerformLightAttack();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Combat|Attack")
	void PerformHeavyAttack();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Combat|Evade")
	void Block(bool bShouldBlock);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Combat|Evade")
	void AttemptParry();

	UFUNCTION(BlueprintCallable, Category = "Combat|Attack")
	bool RequestAttackToken(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Combat|Attack")
	void ReturnAttackToken(int32 Amount);
		
};
