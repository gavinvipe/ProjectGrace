// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Library/StructEnumLibrary.h"
#include "RideableMovementComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup = (Movement), meta=(BlueprintSpawnableComponent) )
class PROJECTGRACE_API URideableMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URideableMovementComponent();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable|Movement")
	void SetSteeringInput(float Steering);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable|Movement")
	void SetThrottleInput(float Throttle);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable|Movement")
	void SetBrakeInput(float Brake);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable|Movement")
	void JumpTrick();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable|Movement")
	void GrabRide();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable|Movement")
	void GetOnRide();

	//var
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable|Movement", meta = (AllowProtectedAcess = "true"))
	void WheelPlacement();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable|Grind", meta = (AllowProtectedAcess = "true"))
	FGrindable CheckGrindable();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable|Grind", meta = (AllowProtectedAcess = "true"))
	void GrindMove();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rideable|Grind", meta = (AllowProtectedAcess = "true"))
	void UpdateGrindLocationRotation(float DeltaSeconds);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	FName SocketTrace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	bool CanHoldRide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	bool IsHoldingRide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	bool CanThrottle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	bool bIsBraking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	bool bIsGrinding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	bool bIsPushing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	float GrindSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	bool bDisableGroundAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	FGrindable GrindableDetails;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Movement")
	TSoftObjectPtr<class UAnimMontage> RideAnim;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
