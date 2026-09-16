// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Weapon.h"
#include "Components/EquipComponent.h"
#include "DataAsset/WeaponDataAsset.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	UWeaponDataAsset* DataAsset = Cast<UWeaponDataAsset>(ItemDataAsset);
	if (DataAsset)
	{
		WeaponDamage = DataAsset->WeaponDamage;

	}
}

void AWeapon::WeaponTrace()
{
	return;
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AWeapon::OnAssetLoaded()
//{
//	return;
//}