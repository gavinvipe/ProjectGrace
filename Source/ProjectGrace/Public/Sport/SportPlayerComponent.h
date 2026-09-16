// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SportPlayerComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(ProjectGrace), meta=(BlueprintSpawnableComponent) )
class PROJECTGRACE_API USportPlayerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USportPlayerComponent();


	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	bool bIsPlaying;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	FName TeamID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	FName PlayerID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	bool bHasBallPossession;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	FName BallAttachSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	class AActor* CurrentBall;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//variable


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sport")
	void PerformLongPass(float Strenght);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sport")
	void PerformShortPass(float Strenght);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sport")
	void PerformShot(float Strenght);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sport")
	void PerformDribble();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sport")
	void PerformTackle();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sport")
	void PerformHeader(float Strenght);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sport")
	void TryBlock(float Strenght);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Sport")
	void PeformAwee();

};
