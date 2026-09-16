// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/InteractInterface.h"
#include "SportBall.generated.h"


UCLASS()
class PROJECTGRACE_API ASportBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASportBall();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SportBall")
	class UStaticMeshComponent* BallMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SportBall")
	class USphereComponent* BallRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SportBall")
	class USphereComponent* BallCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport|Ball")
	AActor* LastTouchPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sport|Ball")
	class ASportManager* SportManager;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Sport")
	void LaunchBall(FVector Velocity);

};
