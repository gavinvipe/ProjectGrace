// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponProjectile.generated.h"


UCLASS()
class PROJECTGRACE_API AWeaponProjectile : public AActor
{
	GENERATED_BODY()
	

public:
	AWeaponProjectile();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	class UStaticMeshComponent* ProjectileMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile", meta = (ExposeOnSpawn = true))
	class UStaticMesh* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	class USphereComponent* ProjectileCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Explosive", meta = (ExposeOnSpawn = true))
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Explosive")
	float FuseTime;

};
