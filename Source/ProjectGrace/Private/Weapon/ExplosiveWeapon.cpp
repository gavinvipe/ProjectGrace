// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/ExplosiveWeapon.h"
#include "Components/StaticMeshComponent.h"
#include "DataAsset/ExplosiveDataAsset.h"
//#include "Engine/AssetManager.h"
#include "Engine/StaticMesh.h"
//#include "Engine/StreamableManager.h"

AExplosiveWeapon::AExplosiveWeapon()
{
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponType = EWeaponType::Explosive;

	StaticMeshComponent = Cast<UStaticMeshComponent>(WeaponMesh);
}

void AExplosiveWeapon::BeginPlay()
{
	Super::BeginPlay();

	DataAsset = Cast<UExplosiveDataAsset>(DataAsset);

	if (!DataAsset)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), "RangedWeapon Data asset is invalid", true, true, FLinearColor::Yellow, 5.f);
		return;
	}

	ProjectileSpeed = DataAsset->ProjectileSpeed;
	ProjectileClass = DataAsset->ProjectileClass;
	FuseTime = DataAsset->FuseTime;

	//if (DataAsset->ItemStaticMesh)
	//{
	//	FStreamableManager& StreamableManager = UAssetManager::GetStreamableManager();
	//	FSoftObjectPath AssetPath = DataAsset->ItemStaticMesh.ToSoftObjectPath();

	//	MeshGroupHandle = StreamableManager.RequestAsyncLoad(
	//		AssetPath,
	//		FStreamableDelegate::CreateUObject(this, &AExplosiveWeapon::OnAssetLoaded)
	//	);
	//}
}

//void AExplosiveWeapon::OnAssetLoaded()
//{
//	UStaticMesh* LoadedMesh = DataAsset->ItemStaticMesh.Get();
//
//	if (LoadedMesh)
//	{
//		StaticMeshComponent->SetStaticMesh(LoadedMesh);
//	}
//}