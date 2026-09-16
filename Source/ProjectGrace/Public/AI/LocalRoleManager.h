// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "LocalRoleManager.generated.h"


UCLASS()
class PROJECTGRACE_API ALocalRoleManager : public AActor
{
	GENERATED_BODY()
	
public:
	ALocalRoleManager();


	//variables

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocalRoleManager")
	int32 MaxActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocalRoleManager")
	TArray<FGameplayTag> Roles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocalRoleManager")
	int32 MaxActorToMange;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocalRoleManager", meta = (AllowProtectedAcess = "true"))
	AActor* ManagedActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocalRoleManager", meta = (AllowProtectedAcess = "true"))
	TMap<AActor*, FGameplayTag> AssignedRoles;

	// Called when the game starts
	virtual void BeginPlay() override;

	//variable


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LocalRoleManger")
	void RegisterActor(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LocalRoleManger")
	void UnregisterActor(AActor* Actor);
};