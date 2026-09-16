#pragma once

#include "CoreMinimal.h"
#include "StructEnumLibrary.generated.h"


UENUM(BlueprintType, meta = (ScriptName = "InteractableType"))
enum class EInteractableType : uint8
{
	Pickup,
	Container,
	Device,
	NPC,
	Mount,
	Examine,
	Custom
};

UENUM(BlueprintType, meta = (ScriptName = "Assisted Aim"))
enum class EAssistedAim : uint8
{
	Free UMETA(DisplayName = "Free Aim"),
	Partial UMETA(DisplayName = "Assisted Aim - Partial"),
	Full UMETA(DisplayName = "Assisted Aim - Full")
};

UENUM(BlueprintType, meta = (ScriptName = "Inventory Add Msg"))
enum class EInventoryAddMsg : uint8
{
	Inventory UMETA(DisplayName = "Added to Inventory"),
	Stack UMETA(DisplayName = "Added to Stack"),
	Full UMETA(DisplayName = "Inventory Full")
};

UENUM(BlueprintType, meta = (ScriptName = "Inventory Rem Msg"))
enum class EInventoryRemMsg : uint8
{
	Inventory UMETA(DisplayName = "Rem from Inventory"),
	Stack UMETA(DisplayName = "Rem from Stack")
};

UENUM(BlueprintType, meta = (ScriptName = "Debug Severity"))
enum class EDebugSeverity : uint8
{
	Info,
	Success,
	Warning,
	Danger
};

UENUM(BlueprintType, meta = (Bitflags))
enum class EImGuiTreeNodeFlags : uint8
{
	None = 0,
	Selected = 1 << 0,
	Framed = 1 << 1,
	DefaultOpen = 1 << 2,
	Bullet = 1 << 3,
	Collapsing = 1 << 4,
};

UENUM(BlueprintType, meta = (ScriptName = "Camera Type"))
enum class ECameraType : uint8
{
	FP UMETA(DisplayName = "FirstPerson"),
	TP UMETA(DisplayName = "ThirdPerson"),
	OS UMETA(DisplayName = "OverShoulder")
};

UENUM(BlueprintType, meta = (ScriptName = "Vehicle Type"))
enum class EVehicleType : uint8
{
	Skate,
	Bike,
	Car
};


UENUM(BlueprintType, meta = (ScriptName = "WeaponType"))
enum class EWeaponType : uint8
{
	Melee,
	Ranged,
	Explosive
};

UENUM(BlueprintType, meta = (ScriptName = "SportType"))
enum class ESportType : uint8
{
	Soccer,
	Football,
	Basketball
};

UENUM(BlueprintType, meta = (ScriptName = "BoundaryType"))
enum class EBoundaryType : uint8
{
	Lateral,
	Endline,
	Scoring,
	Restricted,
	OuterPerimeter
};

UENUM(BlueprintType, meta = (ScriptName = "Clique"))
enum class EClique : uint8
{
	None,
	Nerd,
	Prep,
	Jock,
	Troll,
	Dropouts,
	AltKid UMETA(DisplayName = "Alt-Kid")
};

UENUM(BlueprintType, meta = (ScriptName = "Faction"))
enum class EFaction : uint8
{
	Student,
	Staff,
	Prefect,
	Police,
	Gang,
	Outsider
};

UENUM(BlueprintType, meta = (ScriptName = "Task"))
enum class ETask : uint8
{
	MoveTo,
	Flee,
	Work,
	Hide,
	Attack
};

//struct
USTRUCT(BlueprintType)
struct FGrindable
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Grind")
	bool bIsGrindable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Grind")
	class USplineComponent* Spline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Grind")
	float GrindPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Grind")
	float GrindDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rideable|Grind")
	float GrindOffset;

};

USTRUCT(BlueprintType)
struct FIdentity
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Identity")
	FName ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Identity")
	FText Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Identity")
	EFaction Faction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Identity")
	EClique Clique;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Identity")
	int32 AuthorityLevel;

};

USTRUCT(BlueprintType)
struct FRelationship
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Relationship")
	TMap<FName, int32> Relationhip;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Relationship")
	TMap<EClique, int32> CliqueRelationhip;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Relationship")
	TMap<EFaction, int32> FactionRelationhip;

};

USTRUCT(BlueprintType)
struct FBehavior
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Behavior")
	int32 Confidence;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Behavior")
	int32 Mood;

};

USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item")
	class UItemDataAsset* DataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item")
	int32 StackSize;

};

USTRUCT(BlueprintType)
struct FUtilityContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Context")
	class AAIController* AIController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Context")
	class AActor* Owner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Context")
	class AActor* Target;

};

USTRUCT(BlueprintType)
struct FUtilityConsiderationStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Consideration")
	class UUtilityConsideration* Consideration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Consideration")
	float Weight = 1.f;

};

USTRUCT(BlueprintType)
struct FUtilityTaskStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Task")
	TSubclassOf<class UUtilityTask> Task;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Task")
	float Weight = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Task")
	bool bCanExecute = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility|Task")
	bool bCanBeInterrupted = true;

};

USTRUCT(BlueprintType)
struct FScheduleStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Schedule")
	FName ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Schedule")
	float StartTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Schedule")
	float EndTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Schedule")
	FUtilityTaskStruct ScheduleTask;

};