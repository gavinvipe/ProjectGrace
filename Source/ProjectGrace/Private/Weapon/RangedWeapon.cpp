// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/RangedWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "DataAsset/RangedDataAsset.h"
//#include "Engine/AssetManager.h"
#include "Engine/SkeletalMesh.h"
//#include "Engine/StreamableManager.h"

ARangedWeapon::ARangedWeapon()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponType = EWeaponType::Ranged;

	SkeletalMeshComponent = Cast <USkeletalMeshComponent> (WeaponMesh);

}

bool ARangedWeapon::CheckAmmo() const
{
	if (HasInfiniteAmmo) return true;
	else if (CurrentAmmo > 0) return true;
	return false;
}

void ARangedWeapon::ConsumeAmmo()
{
	if (CurrentAmmo <= 0) return;
	CurrentAmmo--;
}

void ARangedWeapon::WeaponTrace()
{

	FVector EyeLocation;
	FRotator EyeRotation;

	GetOwner()->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	FVector TraceEnd = EyeLocation + (EyeRotation.Vector() * TraceDistance);

	FHitResult Hit;

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());

	bool EyeHit = UKismetSystemLibrary::LineTraceSingle(
		GetWorld(),
		EyeLocation,
		TraceEnd,
		TraceChannel,
		false,
		ActorsToIgnore,
		DrawMainDebugTrace,
		Hit,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		DrawTime
	);


	FVector TargetPoint = EyeHit ? Hit.ImpactPoint : TraceEnd;

	FVector MuzzleLoc = WeaponMesh->GetSocketLocation(TracePoint);
	FVector MuzzleDir= (TargetPoint - MuzzleLoc).GetSafeNormal();

	FVector MuzzleEnd = MuzzleLoc + (MuzzleDir * TraceDistance);
	
	if (!bIsHitscan)
	{
		HitResult = Hit;
		return;
	}

	bool bHit = UKismetSystemLibrary::LineTraceSingle(
		GetWorld(),
		MuzzleLoc,
		MuzzleEnd,
		TraceChannel,
		false,
		ActorsToIgnore,
		DrawDebugTrace,
		HitResult,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		DrawTime
	);

}

void ARangedWeapon::BeginPlay()
{
	Super::BeginPlay();

	DataAsset = Cast<URangedDataAsset>(ItemDataAsset);

	if (!DataAsset)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), "RangedWeapon Data asset is invalid", true, true, FLinearColor::Yellow, 5.f);
		return;
	}

	Ammo = DataAsset->Ammo;
	MaxAmmo = DataAsset->MaxAmmo;
	HasInfiniteAmmo = DataAsset->bHasInfiniteAmmo;
	bIsHitscan = DataAsset->bIsHitscan;
	TraceDeviation = DataAsset->TraceDeviation;
	ProjectileSpeed = DataAsset->ProjectileSpeed;
	ProjectileClass = DataAsset->ProjectileClass;
	FireRate = DataAsset->FireRate;

	CurrentAmmo = Ammo;
	CurrentMaxAmmo = MaxAmmo;

	//if (DataAsset->ItemSkeletalMesh)
	//{
	//	FStreamableManager& StreamableManager = UAssetManager::GetStreamableManager();
	//	FSoftObjectPath AssetPath = DataAsset->ItemSkeletalMesh.ToSoftObjectPath();

	//	MeshGroupHandle = StreamableManager.RequestAsyncLoad(
	//		AssetPath, 
	//		FStreamableDelegate::CreateUObject(this, &ARangedWeapon::OnAssetLoaded)
	//	);
	//}
}

//void ARangedWeapon::OnAssetLoaded()
//{
//	USkeletalMesh* LoadedMesh = DataAsset->ItemSkeletalMesh.Get();
//
//	if (LoadedMesh)
//	{
//		SkeletalMeshComponent->SetSkeletalMeshAsset(LoadedMesh);
//	}
//}