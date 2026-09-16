// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Library/StructEnumLibrary.h"
#include "TargetingComponent.generated.h"

class AActor;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(ProjectGrace), meta=(BlueprintSpawnableComponent) )
class PROJECTGRACE_API UTargetingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTargetingComponent();


	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
	EAssistedAim AssitedAim;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowProtectedAccess = true), Category = "Targeting")
	AActor* CurrentTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowProtectedAccess = true), Category = "Targeting")
	TArray<AActor*> Targets;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Targeting")
	void ScanTargets();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Targeting")
	void UpdateLock();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Targeting")
	void ChangeTarget();

	UFUNCTION(BlueprintCallable, Category="Targeting")
	AActor* GetCurrentTarget() const;

	UFUNCTION(BlueprintCallable, Category="Targeting")
	void SetCurrentTarget(AActor* Target);

};
