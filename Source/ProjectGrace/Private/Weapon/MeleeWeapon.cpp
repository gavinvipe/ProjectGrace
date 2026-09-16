// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/MeleeWeapon.h"
#include "Components/StaticMeshComponent.h"
#include "DataAsset/MeleeDataAsset.h"
//#include "Engine/AssetManager.h"
#include "Engine/StaticMesh.h"
//#include "Engine/StreamableManager.h"


AMeleeWeapon::AMeleeWeapon()
{
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponType = EWeaponType::Melee;

	StaticMeshComponent = Cast<UStaticMeshComponent>(WeaponMesh);
}

void AMeleeWeapon::WeaponTrace()
{
	FVector Start  = WeaponMesh->GetSocketLocation(TraceStartPoint);
	FVector End = WeaponMesh->GetSocketLocation(TraceEndPoint);

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());

	bool bHit = UKismetSystemLibrary::SphereTraceMultiForObjects(
		GetWorld(),
		Start,
		End,
		TraceRaduis,
		ObjectTypes,
		false,
		ActorsToIgnore,
		DrawDebugTrace,
		HitResults,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		DrawTime
	);
}

void AMeleeWeapon::BeginPlay()
{
	Super::BeginPlay();

	DataAsset = Cast<UMeleeDataAsset>(DataAsset);

	if (!DataAsset)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), "RangedWeapon Data asset is invalid", true, true, FLinearColor::Yellow, 5.f);
		return;
	}

	TraceRaduis = DataAsset->TraceRaduis;

	//if (DataAsset->ItemStaticMesh)
	//{
	//	FStreamableManager& StreamableManager = UAssetManager::GetStreamableManager();
	//	FSoftObjectPath AssetPath = DataAsset->ItemStaticMesh.ToSoftObjectPath();

	//	MeshGroupHandle = StreamableManager.RequestAsyncLoad(
	//		AssetPath,
	//		FStreamableDelegate::CreateUObject(this, &AMeleeWeapon::OnAssetLoaded)
	//	);
	//}
}

//void AMeleeWeapon::OnAssetLoaded()
//{
//	UStaticMesh* LoadedMesh = DataAsset->ItemStaticMesh.Get();
//
//	if (LoadedMesh)
//	{
//		StaticMeshComponent->SetStaticMesh(LoadedMesh);
//	}
//}