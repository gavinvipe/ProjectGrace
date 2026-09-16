// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

AWeaponProjectile::AWeaponProjectile()
{
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	ProjectileCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Projectile Collision"));

	SetRootComponent(ProjectileCollision);
	ProjectileMeshComponent->SetupAttachment(ProjectileCollision);

	ProjectileMeshComponent->SetStaticMesh(ProjectileMesh);

}

