// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "UtilityTask.generated.h"

/**
 * 
 */
struct FUtiltiyContext;

UCLASS(Blueprintable)
//UCLASS(Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class PROJECTGRACE_API UUtilityTask : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Task")
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Task")
	float Weight = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Task")
	TArray<TObjectPtr<class UUtilityConsideration>> Considerations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Task")
	bool bCanExecute = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Task")
	bool bCanBeInterrupted = true;

	UPROPERTY(BlueprintReadOnly, Category = "Task")
	class UStateTreeComponent* StateTreeComp;


	//functions
	UFUNCTION(BlueprintCallable, Category = "Utility|Task")
	float CalculateScore(FUtilityContext Context);

	UFUNCTION()
	void Initialize();

	UFUNCTION(BlueprintCallable, Category = "Utility|Task")
	void ExecuteTask();

};
