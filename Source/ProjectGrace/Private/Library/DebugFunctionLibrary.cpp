// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/DebugFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/Class.h"
#include "imgui.h"
#include "UObject/UnrealType.h"
#include "GameFramework/Actor.h"
#include "EngineUtils.h"

DEFINE_LOG_CATEGORY(LogDebugLibrary);
DEFINE_LOG_CATEGORY(LogSuccess);

#if !UE_BUILD_SHIPPING

void UDebugFunctionLibrary::DebugPrint(UObject* WorldContextObject, FString Category, FString Message, EDebugSeverity Severity, bool bPrintToScreen, bool bPrintToLog, float Duration, bool bUseCategoryAsKey, FName Key)
{
	FColor ScreenColor = FColor::White;
	FString FinalMsg = FString::Printf(TEXT("[%s]: %s"), *Category, *Message);
	FName KeyName = bUseCategoryAsKey ? FName(*Category) : Key;

	switch (Severity)
	{
	case EDebugSeverity::Info:
		ScreenColor = FColor::White;
		if (bPrintToLog) UE_LOG(LogDebugLibrary, Log, TEXT("%s"), *FinalMsg);
		break;
	case EDebugSeverity::Success:
		ScreenColor = FColor::Green;
		if (bPrintToLog) UE_LOG(LogSuccess, Log, TEXT("%s"), *FinalMsg);
		break;
	case EDebugSeverity::Warning:
		ScreenColor = FColor::Yellow;
		if (bPrintToLog) UE_LOG(LogDebugLibrary, Warning, TEXT("%s"), *FinalMsg);
		break;
	case EDebugSeverity::Danger:
		ScreenColor = FColor::Red;
		if (bPrintToLog) UE_LOG(LogDebugLibrary, Error, TEXT("%s"), *FinalMsg);
		break;
	}
	
	
	UKismetSystemLibrary::PrintString(WorldContextObject, FinalMsg, bPrintToScreen, false, ScreenColor, Duration, KeyName);

}

void UDebugFunctionLibrary::EditFloat(UObject* Target, FName VariableName, float Min, float Max)
{
	if (!Target)
		return;

	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (FFloatProperty* FloatProperty = CastField<FFloatProperty>(Property))
	{
		float Value = FloatProperty->GetPropertyValue_InContainer(Target);
		if (ImGui::SliderFloat(TCHAR_TO_ANSI(*VariableName.ToString()), &Value, Min, Max))
		{
			FloatProperty->SetPropertyValue_InContainer(Target, Value);
		}
	}
	else
	{
		if (FNumericProperty* NumericProperty = CastField<FNumericProperty>(Property))
		{
			if (NumericProperty->IsFloatingPoint())
			{
				float Value = NumericProperty->GetFloatingPointPropertyValue(Property->ContainerPtrToValuePtr<void>(Target));

				if (ImGui::SliderFloat(TCHAR_TO_ANSI(*VariableName.ToString()), &Value, Min, Max))
				{
					NumericProperty->SetFloatingPointPropertyValue(Property->ContainerPtrToValuePtr<void>(Target), Value);
				}
			}
		}
	}
}

void UDebugFunctionLibrary::EditBool(UObject* Target, FName VariableName)
{
	if (!Target)
		return;

	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (FBoolProperty* BoolProperty = CastField<FBoolProperty>(Property))
	{
		bool Value = BoolProperty->GetPropertyValue_InContainer(Target);
		if (ImGui::Checkbox(TCHAR_TO_ANSI(*VariableName.ToString()), &Value))
		{
			BoolProperty->SetPropertyValue_InContainer(Target, Value);
		}
	}
}

void UDebugFunctionLibrary::EditInt(UObject* Target, FName VariableName, int32 Min, int32 Max)
{
	if (!Target) return;
	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (FIntProperty* IntProp = CastField<FIntProperty>(Property))
	{
		int32 Value = IntProp->GetPropertyValue_InContainer(Target);
		if (ImGui::SliderInt(TCHAR_TO_ANSI(*VariableName.ToString()), &Value, Min, Max))
		{
			IntProp->SetPropertyValue_InContainer(Target, Value);
		}
	}
}

// --- Vector ---
void UDebugFunctionLibrary::EditVector(UObject* Target, FName VariableName, float Speed)
{
	if (!Target) return;
	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (FStructProperty* StructProp = CastField<FStructProperty>(Property))
	{
		if (StructProp->Struct == TBaseStructure<FVector>::Get())
		{
			FVector Value = *StructProp->ContainerPtrToValuePtr<FVector>(Target);
			float Vec[3] = { Value.X, Value.Y, Value.Z };

			if (ImGui::DragFloat3(TCHAR_TO_ANSI(*VariableName.ToString()), Vec, Speed))
			{
				Value = FVector(Vec[0], Vec[1], Vec[2]);
				*StructProp->ContainerPtrToValuePtr<FVector>(Target) = Value;
			}
		}
	}
}

// --- Rotator ---
void UDebugFunctionLibrary::EditRotator(UObject* Target, FName VariableName, float Speed)
{
	if (!Target) return;
	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (FStructProperty* StructProp = CastField<FStructProperty>(Property))
	{
		if (StructProp->Struct == TBaseStructure<FRotator>::Get())
		{
			FRotator Value = *StructProp->ContainerPtrToValuePtr<FRotator>(Target);
			float Rot[3] = { Value.Pitch, Value.Yaw, Value.Roll };

			if (ImGui::DragFloat3(TCHAR_TO_ANSI(*VariableName.ToString()), Rot, Speed))
			{
				Value = FRotator(Rot[0], Rot[1], Rot[2]);
				*StructProp->ContainerPtrToValuePtr<FRotator>(Target) = Value;
			}
		}
	}
}

void UDebugFunctionLibrary::EditTransform(AActor* Target, FName VariableName)
{
	if (!Target) return;

	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (Property && Property->IsA<FStructProperty>())
	{
		FStructProperty* StructProp = CastField<FStructProperty>(Property);
		if (StructProp->Struct == TBaseStructure<FTransform>::Get())
		{
			FTransform Transform = *StructProp->ContainerPtrToValuePtr<FTransform>(Target);

			FVector Loc = Transform.GetLocation();
			FRotator Rot = Transform.Rotator();
			FVector Scale = Transform.GetScale3D();

			ImGui::Text("%s", TCHAR_TO_ANSI(*VariableName.ToString()));
			ImGui::DragFloat3("Location", (float*)&Loc, 1.0f);
			ImGui::DragFloat3("Rotation", (float*)&Rot, 1.0f);
			ImGui::DragFloat3("Scale", (float*)&Scale, 0.01f);

			Transform.SetLocation(Loc);
			Transform.SetRotation(FQuat(Rot));
			Transform.SetScale3D(Scale);

			StructProp->CopyCompleteValue(StructProp->ContainerPtrToValuePtr<void>(Target), &Transform);
		}
	}
}

void UDebugFunctionLibrary::EditColor(AActor* Target, FName VariableName)
{
	if (!Target) return;

	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (Property && Property->IsA<FStructProperty>())
	{
		FStructProperty* StructProp = CastField<FStructProperty>(Property);
		if (StructProp->Struct == TBaseStructure<FColor>::Get())
		{
			FColor Color = *StructProp->ContainerPtrToValuePtr<FColor>(Target);
			float Col[4] = { Color.R / 255.f, Color.G / 255.f, Color.B / 255.f, Color.A / 255.f };

			if (ImGui::ColorEdit4(TCHAR_TO_ANSI(*VariableName.ToString()), Col))
			{
				Color.R = Col[0] * 255;
				Color.G = Col[1] * 255;
				Color.B = Col[2] * 255;
				Color.A = Col[3] * 255;

				StructProp->CopyCompleteValue(StructProp->ContainerPtrToValuePtr<void>(Target), &Color);
			}
		}
	}
}

void UDebugFunctionLibrary::EditQuat(AActor* Target, FName VariableName)
{
	if (!Target) return;

	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (Property && Property->IsA<FStructProperty>())
	{
		FStructProperty* StructProp = CastField<FStructProperty>(Property);
		if (StructProp->Struct == TBaseStructure<FQuat>::Get())
		{
			FQuat Quat = *StructProp->ContainerPtrToValuePtr<FQuat>(Target);
			float Values[4] = { Quat.X, Quat.Y, Quat.Z, Quat.W };

			if (ImGui::DragFloat4(TCHAR_TO_ANSI(*VariableName.ToString()), Values, 0.01f))
			{
				Quat = FQuat(Values[0], Values[1], Values[2], Values[3]);
				StructProp->CopyCompleteValue(StructProp->ContainerPtrToValuePtr<void>(Target), &Quat);
			}
		}
	}
}

// Recursive helper -- draw any UScriptStruct at a raw pointer
static void DrawStructRecursive(UScriptStruct* StructDef, void* StructPtr)
{
	if (!StructDef || !StructPtr) return;

	for (TFieldIterator<FProperty> It(StructDef); It; ++It)
	{
		FProperty* Field = *It;
		FString FieldNameF = Field->GetName();
		const char* FieldLabel = TCHAR_TO_UTF8(*FieldNameF);

		// Use pointer-based ID to avoid label collisions and temporary-string lifetime issues
		ImGui::PushID((const void*)Field);

		if (FFloatProperty* FloatProp = CastField<FFloatProperty>(Field))
		{
			float Val = FloatProp->GetPropertyValue_InContainer(StructPtr);
			if (ImGui::DragFloat(FieldLabel, &Val, 0.1f))
				FloatProp->SetPropertyValue_InContainer(StructPtr, Val);
		}
		else if (FIntProperty* IntProp = CastField<FIntProperty>(Field))
		{
			int32 Val = IntProp->GetPropertyValue_InContainer(StructPtr);
			if (ImGui::DragInt(FieldLabel, &Val, 1))
				IntProp->SetPropertyValue_InContainer(StructPtr, Val);
		}
		else if (FBoolProperty* BoolProp = CastField<FBoolProperty>(Field))
		{
			bool Val = BoolProp->GetPropertyValue_InContainer(StructPtr);
			if (ImGui::Checkbox(FieldLabel, &Val))
				BoolProp->SetPropertyValue_InContainer(StructPtr, Val);
		}
		else if (FStructProperty* SubStructProp = CastField<FStructProperty>(Field))
		{
			// Nested struct: print a heading and recurse into its memory location
			ImGui::TextUnformatted(FieldLabel);
			void* SubPtr = SubStructProp->ContainerPtrToValuePtr<void>(StructPtr);

			ImGui::Indent();
			DrawStructRecursive(SubStructProp->Struct, SubPtr);
			ImGui::Unindent();
		}
		// add other property types here (FName, FVector, FRotator, etc.) as needed

		ImGui::PopID();
	}
}

void UDebugFunctionLibrary::EditStruct(AActor* Target, FName VariableName)
{
	if (!Target) return;

	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (!Property) return;

	FStructProperty* StructProp = CastField<FStructProperty>(Property);
	if (!StructProp) return;

	UScriptStruct* StructDef = StructProp->Struct;
	void* StructPtr = StructProp->ContainerPtrToValuePtr<void>(Target);

	// Header / separators (use UTF-8 conversion)
	ImGui::Separator();
	ImGui::TextUnformatted(TCHAR_TO_UTF8(*VariableName.ToString()));
	ImGui::Separator();

	// Draw fields recursively
	DrawStructRecursive(StructDef, StructPtr);
}

//void UDebugFunctionLibrary::EditEnum(AActor* Target, FName VariableName)
//{
//	if (!Target) return;
//
//	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
//	if (!Property) return;
//
//	UEnum* Enum = nullptr;
//	int64 Value = 0;
//	void* ValuePtr = Property->ContainerPtrToValuePtr<void>(Target);
//
//	// Handle both enum types (FEnumProperty and FByteProperty)
//	if (FEnumProperty* EnumProp = CastField<FEnumProperty>(Property))
//	{
//		Enum = EnumProp->GetEnum();
//		Value = EnumProp->GetUnderlyingProperty()->GetSignedIntPropertyValue(ValuePtr);
//	}
//	else if (FByteProperty* ByteProp = CastField<FByteProperty>(Property))
//	{
//		if (ByteProp->Enum)
//		{
//			Enum = ByteProp->Enum;
//			Value = ByteProp->GetSignedIntPropertyValue(ValuePtr);
//		}
//	}
//
//	if (!Enum) return; // not an enum or invalid
//
//	const char* Label = TCHAR_TO_ANSI(*VariableName.ToString());
//	const char* CurrentName = TCHAR_TO_ANSI(*Enum->GetNameStringByValue(Value));
//
//	if (ImGui::BeginCombo(Label, CurrentName))
//	{
//		for (int32 i = 0; i < Enum->NumEnums() - 1; ++i)
//		{
//			int64 EnumValue = Enum->GetValueByIndex(i);
//			bool bSelected = (Value == EnumValue);
//			const char* ItemName = TCHAR_TO_ANSI(*Enum->GetNameStringByIndex(i));
//
//			if (ImGui::Selectable(ItemName, bSelected))
//			{
//				Value = EnumValue;
//
//				if (FEnumProperty* EnumProp = CastField<FEnumProperty>(Property))
//				{
//					EnumProp->GetUnderlyingProperty()->SetIntPropertyValue(ValuePtr, Value);
//				}
//				else if (FByteProperty* ByteProp = CastField<FByteProperty>(Property))
//				{
//					ByteProp->SetIntPropertyValue(ValuePtr, Value);
//				}
//			}
//
//			if (bSelected)
//				ImGui::SetItemDefaultFocus();
//		}
//		ImGui::EndCombo();
//	}
//}

void UDebugFunctionLibrary::EditEnum(AActor* Target, FName VariableName)
{
	if (!Target) return;

	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (!Property) return;

	UEnum* Enum = nullptr;
	int64 Value = 0;
	void* ValuePtr = Property->ContainerPtrToValuePtr<void>(Target);

	// Handle both enum property types (Blueprint and native)
	if (FEnumProperty* EnumProp = CastField<FEnumProperty>(Property))
	{
		Enum = EnumProp->GetEnum();
		Value = EnumProp->GetUnderlyingProperty()->GetSignedIntPropertyValue(ValuePtr);
	}
	else if (FByteProperty* ByteProp = CastField<FByteProperty>(Property))
	{
		if (ByteProp->Enum)
		{
			Enum = ByteProp->Enum;
			Value = ByteProp->GetSignedIntPropertyValue(ValuePtr);
		}
	}

	if (!Enum) return;

	// Use DisplayName instead of raw name
	FString CurrentDisplay = Enum->GetDisplayNameTextByValue(Value).ToString();
	const char* Label = TCHAR_TO_ANSI(*VariableName.ToString());
	const char* CurrentName = TCHAR_TO_ANSI(*CurrentDisplay);

	if (ImGui::BeginCombo(Label, CurrentName))
	{
		for (int32 i = 0; i < Enum->NumEnums() - 1; ++i) // skip hidden _MAX entries
		{
			int64 EnumValue = Enum->GetValueByIndex(i);
			bool bSelected = (Value == EnumValue);

			FString DisplayName = Enum->GetDisplayNameTextByIndex(i).ToString();
			const char* ItemName = TCHAR_TO_ANSI(*DisplayName);

			if (ImGui::Selectable(ItemName, bSelected))
			{
				Value = EnumValue;

				if (FEnumProperty* EnumProp = CastField<FEnumProperty>(Property))
				{
					EnumProp->GetUnderlyingProperty()->SetIntPropertyValue(ValuePtr, Value);
				}
				else if (FByteProperty* ByteProp = CastField<FByteProperty>(Property))
				{
					ByteProp->SetIntPropertyValue(ValuePtr, Value);
				}
			}

			if (bSelected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
}


void UDebugFunctionLibrary::BeginWindow(const FString& Title, bool bAutoResize, bool bMenuBar, bool bShowClose, bool& bOpen)
{
	// Prepare flags
	ImGuiWindowFlags Flags = ImGuiWindowFlags_None;
	if (bAutoResize) Flags |= ImGuiWindowFlags_AlwaysAutoResize;
	if (bMenuBar) Flags |= ImGuiWindowFlags_MenuBar;
	bOpen = bShowClose;

	ImGui::Begin(TCHAR_TO_ANSI(*Title), &bOpen, Flags);


	// Return whether you should draw content
}

void UDebugFunctionLibrary::EndWindow()
{
	ImGui::End();
}

void UDebugFunctionLibrary::Separator()
{
	ImGui::Separator();
}

void UDebugFunctionLibrary::Spacing(int32 Count)
{
	for (int32 i = 0; i < Count; i++)
		ImGui::Spacing();
}

void UDebugFunctionLibrary::Text(const FString& Message)
{
	ImGui::Text("%s", TCHAR_TO_ANSI(*Message));
}

bool UDebugFunctionLibrary::Button(const FString& Label, FVector2D Size)
{
	return ImGui::Button(TCHAR_TO_ANSI(*Label), ImVec2(Size.X, Size.Y));
}

// ---- Tabs ----
bool UDebugFunctionLibrary::BeginTabBar(const FString& TabBarName)
{
	return ImGui::BeginTabBar(TCHAR_TO_ANSI(*TabBarName));
}

bool UDebugFunctionLibrary::BeginTab(const FString& TabName)
{
	return ImGui::BeginTabItem(TCHAR_TO_ANSI(*TabName));
}

void UDebugFunctionLibrary::EndTab()
{
	ImGui::EndTabItem();
}

void UDebugFunctionLibrary::EndTabBar()
{
	ImGui::EndTabBar();
}

// ---- Menus ----
bool UDebugFunctionLibrary::BeginMainMenuBar()
{
	return ImGui::BeginMainMenuBar();
}

bool UDebugFunctionLibrary::BeginMenu(const FString& Label, bool bEnabled)
{
	const char* LabelAnsi = TCHAR_TO_ANSI(*Label);
	return ImGui::BeginMenu(LabelAnsi, bEnabled);
}

bool UDebugFunctionLibrary::MenuItem(const FString& Label, bool bSelected, bool bEnabled)
{
	const char* LabelAnsi = TCHAR_TO_ANSI(*Label);
	return ImGui::MenuItem(LabelAnsi, nullptr, bSelected, bEnabled);
}

void UDebugFunctionLibrary::EndMenu()
{
	ImGui::EndMenu();
}

void UDebugFunctionLibrary::EndMainMenuBar()
{
	ImGui::EndMainMenuBar();
}

// ---- Dropdown ----
int32 UDebugFunctionLibrary::Dropdown(const FString& Label, const TArray<FString>& Options, int32 CurrentIndex)
{
	int32 NewIndex = CurrentIndex;

	if (ImGui::BeginCombo(TCHAR_TO_ANSI(*Label), TCHAR_TO_ANSI(*Options[CurrentIndex])))
	{
		for (int32 i = 0; i < Options.Num(); i++)
		{
			bool Selected = (i == CurrentIndex);
			if (ImGui::Selectable(TCHAR_TO_ANSI(*Options[i]), Selected))
				NewIndex = i;
			if (Selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
	return NewIndex;
}

void UDebugFunctionLibrary::ApplySingleProperty(UObject* Target, FName PropertyName)
{
	if (!Target || PropertyName.IsNone())
		return;

	FProperty* ChangedProperty = Target->GetClass()->FindPropertyByName(PropertyName);
	if (!ChangedProperty)
	{
		UE_LOG(LogTemp, Warning, TEXT("ApplySingleProperty: Property '%s' not found on %s"),
			*PropertyName.ToString(), *Target->GetName());
		return;
	}

	// Mark object as modified (for undo/redo and save)
	Target->Modify();

	// Prepare property changed event for precise update
	/*FPropertyChangedEvent PropertyChangedEvent(ChangedProperty);
	Target->PostEditChangeProperty(PropertyChangedEvent);*/

	// If we’re in the editor, mark the package dirty
	if (UPackage* Package = Target->GetOutermost())
	{
		Package->SetDirtyFlag(true);
	}

	// If the target is an Actor, re-run construction or refresh components
	if (AActor* Actor = Cast<AActor>(Target))
	{
#if WITH_EDITOR
		if (!Actor->GetWorld()->IsGameWorld())
		{
			Actor->RerunConstructionScripts();
		}
#endif
		// Refresh render and transform state
		Actor->MarkComponentsRenderStateDirty();
		Actor->MarkComponentsRenderStateDirty();

		// If in game world, update networking
		if (Actor->GetWorld() && Actor->GetWorld()->IsGameWorld())
		{
			Actor->ForceNetUpdate();
		}
	}

	UE_LOG(LogTemp, Verbose, TEXT("ImGui: Applied single property '%s' on %s"),
		*PropertyName.ToString(), *Target->GetName());
}

bool UDebugFunctionLibrary::CollapsingHeader(const FString& Label, EImGuiTreeNodeFlags Flags)
{
	const char* LabelAnsi = TCHAR_TO_ANSI(*Label);
	return ImGui::CollapsingHeader(LabelAnsi, (int32)Flags);
}


void UDebugFunctionLibrary::Tooltip(const FString& Text)
{
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(350.0f);
		ImGui::TextUnformatted(TCHAR_TO_ANSI(*Text));
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void UDebugFunctionLibrary::TextColored(const FLinearColor& Color, const FString& Text)
{
	ImVec4 ImColor(Color.R, Color.G, Color.B, Color.A);
	ImGui::TextColored(ImColor, "%s", TCHAR_TO_ANSI(*Text));
}

void UDebugFunctionLibrary::PlotLines(const FString& Label, const TArray<float>& Values, int NumValuesToShow,
	float ScaleMin, float ScaleMax, float Width, float Height)
{
	if (Values.Num() == 0) return;

	// Limit number of points to display
	int Count = (NumValuesToShow > 0 && NumValuesToShow <= Values.Num()) ? NumValuesToShow : Values.Num();

	// Convert TArray<float> to a simple float array
	TArray<float> ValuesCopy = Values;
	float* Data = ValuesCopy.GetData();

	const char* LabelAnsi = TCHAR_TO_ANSI(*Label);

	// Plot the line graph
	ImGui::PlotLines(LabelAnsi, Data, Count, 0, nullptr, ScaleMin, ScaleMax, ImVec2(Width, Height));
}

FString UDebugFunctionLibrary::InputText(const FString& Label, const FString& InValue)
{
	TArray<char> Buffer;
	Buffer.SetNumZeroed(256); // ensures null termination

	// Use Strncpy instead of Strcpy (safe version)
	FCStringAnsi::Strncpy(Buffer.GetData(), TCHAR_TO_UTF8(*InValue), Buffer.Num());

	// Draw input text field
	if (ImGui::InputText(TCHAR_TO_UTF8(*Label), Buffer.GetData(), Buffer.Num()))
	{
		return FString(UTF8_TO_TCHAR(Buffer.GetData()));
	}

	return InValue;
}

void UDebugFunctionLibrary::EditActorClassProperty(UObject* TargetObject, const FString& VariableName)
{
	if (!TargetObject) return;

	FProperty* Property = TargetObject->GetClass()->FindPropertyByName(*VariableName);
	if (!Property) return;

	if (FClassProperty* ClassProp = CastField<FClassProperty>(Property))
	{
		void* ValuePtr = Property->ContainerPtrToValuePtr<void>(TargetObject);
		UClass* CurrentClass = Cast<UClass>(ClassProp->GetObjectPropertyValue(ValuePtr));

		FString CurrentName = CurrentClass ? CurrentClass->GetName() : TEXT("None");
		if (ImGui::BeginCombo(TCHAR_TO_ANSI(*VariableName), TCHAR_TO_ANSI(*CurrentName)))
		{
			for (TObjectIterator<UClass> It; It; ++It)
			{
				UClass* Class = *It;
				if (!Class->IsChildOf(ClassProp->MetaClass) || Class->HasAnyClassFlags(CLASS_Abstract))
					continue;

				FString ClassName = Class->GetName();
				bool bSelected = (Class == CurrentClass);
				if (ImGui::Selectable(TCHAR_TO_ANSI(*ClassName), bSelected))
				{
					ClassProp->SetObjectPropertyValue(ValuePtr, Class);
				}
			}
			ImGui::EndCombo();
		}
	}
}

// Function to edit an Actor reference variable inside a target actor
bool UDebugFunctionLibrary::EditActorReference(AActor* Target, const FName& VariableName)
{
	if (!Target)
		return false;

	bool bChanged = false;


	// Use reflection to get the property dynamically
	FProperty* Property = Target->GetClass()->FindPropertyByName(VariableName);
	if (!Property)
	{
		ImGui::TextColored(ImVec4(1, 0, 0, 1), "Property '%s' not found!", TCHAR_TO_ANSI(*VariableName.ToString()));
		return false;
	}

	// Check if it's an Actor reference
	FObjectProperty* ObjectProp = CastField<FObjectProperty>(Property);
	if (!ObjectProp || !ObjectProp->PropertyClass->IsChildOf(AActor::StaticClass()))
	{
		ImGui::TextColored(ImVec4(1, 0, 0, 1), "Property '%s' is not an Actor reference!", VariableName);
		return false;
	}

	// Get the current value
	AActor* CurrentActor = Cast<AActor>(ObjectProp->GetObjectPropertyValue_InContainer(Target));

	// UI Section
	ImGui::Text("Variable: %s", VariableName);
	const char* CurrentActorName = CurrentActor ? TCHAR_TO_ANSI(*CurrentActor->GetName()) : "None";
	ImGui::Text("Current: %s", CurrentActorName);

	if (ImGui::Button("Clear Reference"))
	{
		ObjectProp->SetObjectPropertyValue_InContainer(Target, nullptr);
		bChanged = true;
	}

	ImGui::SameLine();

	if (ImGui::Button("Select Actor"))
	{
		// Example: Select first valid actor in the world
		UWorld* World = Target->GetWorld();
		if (World)
		{
			for (TActorIterator<AActor> It(World); It; ++It)
			{
				if (*It != Target) // skip self
				{
					ObjectProp->SetObjectPropertyValue_InContainer(Target, *It);
					bChanged = true;
					break;
				}
			}
		}
	}

	return bChanged;
}

#endif