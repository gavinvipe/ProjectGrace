// Fill out your copyright notice in the Description page of Project Settings.


#include "Vehicles/Rideable.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InteractableComponent.h"
#include "DataAsset/RideableDataAsset.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/AssetManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/StreamableManager.h"

// Sets default values
ARideable::ARideable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ARideable::BeginPlay()
{
	Super::BeginPlay();

	if (ItemDataAsset->ItemSkeletalMesh)
	{
		FStreamableManager& StreamableManager = UAssetManager::GetStreamableManager();
		FSoftObjectPath AssetPath = ItemDataAsset->ItemSkeletalMesh.ToSoftObjectPath();


		MeshGroupHandle = StreamableManager.RequestAsyncLoad(
			AssetPath,
			FStreamableDelegate::CreateUObject(this, &ARideable::OnAssetLoaded)
		);
	}
	
	DataAsset = Cast<URideableDataAsset>(ItemDataAsset);

	if (!DataAsset)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), "Rideable Data asset is invalid", true, true, FLinearColor::Yellow, 5.f);
		return;
	}

}

void ARideable::OnAssetLoaded()
{
	if (!GetWorld()) return;

	if (!MeshGroupHandle.IsValid() && !MeshGroupHandle->HasLoadCompleted()) return;

	UObject* LoadedObject = MeshGroupHandle->GetLoadedAsset();
	USkeletalMesh* LoadedMesh = Cast<USkeletalMesh>(LoadedObject);

	if (!LoadedMesh) UKismetSystemLibrary::PrintString(GetWorld(), "Rideable skeletal mesh asset is invalid", true, true, FLinearColor::Yellow, 5.f);

	if (LoadedMesh)
	{
		Mesh->SetSkeletalMeshAsset(LoadedMesh);
	}

}