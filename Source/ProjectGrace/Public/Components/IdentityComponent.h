// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Library/StructEnumLibrary.h"
#include "IdentityComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup = (ProjectGrace), meta = (BlueprintSpawnableComponent))
class PROJECTGRACE_API UIdentityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UIdentityComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Identity")
	FIdentity Identity;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Identity")

};
