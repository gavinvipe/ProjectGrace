// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Library/StructEnumLibrary.h"
#include "BehaviorComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup = (ProjectGrace), meta = (BlueprintSpawnableComponent))
class PROJECTGRACE_API UBehaviorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBehaviorComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Relationship")
	FRelationship Relationhip;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Behavior")
	FBehavior Behavior;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
