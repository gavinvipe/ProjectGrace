// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CoverComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(ProjectGrace), meta=(BlueprintSpawnableComponent) )
class PROJECTGRACE_API UCoverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCoverComponent();


	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cover")
	bool bIsInCover;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cover")
	bool bCanPeekRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cover")
	bool bCanPeekLeft;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cover")
	bool bIsMovingToCover;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cover")
	float ObjectHeight;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Cover")
	void TakeCover();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Cover")
	void ExitCover();

};
