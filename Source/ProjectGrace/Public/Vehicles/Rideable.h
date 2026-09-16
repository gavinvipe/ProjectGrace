// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup/Item.h"
#include "Rideable.generated.h"

struct FStreamableHandle;

UCLASS()
class PROJECTGRACE_API ARideable : public AItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARideable();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable")
	FName LeftFoot_Marker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable")
	FName RightFoot_Marker;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rideable")
	class USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rideable")
	class URideableDataAsset* DataAsset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UFUNCTION()
	void OnAssetLoaded();

	TSharedPtr<FStreamableHandle> MeshGroupHandle;
};
