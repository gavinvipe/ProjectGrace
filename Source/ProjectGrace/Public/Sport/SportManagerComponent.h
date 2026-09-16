// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SportManagerComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(ProjectGrace), meta=(BlueprintSpawnableComponent) )
class PROJECTGRACE_API USportManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USportManagerComponent();


	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	class USportDataAsset* CurrentSportData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	TMap<FName, int32> TeamScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport")
	class AActor* ActiveBall;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Sport")
	void HandleBoundaryVoilation(AActor* Victim, EBoundaryType BoundaryType);

	//variable


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sport")
	void StartNewMatch(USportDataAsset* SportData);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sport")
	void EndMatch();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sport")
	void RegisterScore(int32 TeamID, int32 Point);

};
