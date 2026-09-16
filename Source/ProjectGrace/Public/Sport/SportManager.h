// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SportManager.generated.h"


UCLASS()
class PROJECTGRACE_API ASportManager : public AActor
{
	GENERATED_BODY()
	
public:
	ASportManager();


	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	class USportDataAsset* CurrentSportData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	TMap<FName, int32> TeamScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	class ASportBall* ActiveBall;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Sport")
	void HandleBoundaryVoilation(AActor* Victim, EBoundaryType BoundaryType);

	//variable


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Sport")
	void StartNewMatch(USportDataAsset* SportData);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Sport")
	void EndMatch();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Sport")
	void RegisterScore(int32 TeamID, int32 Point);
};