// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StructEnumLibrary.h"
#include "DebugFunctionLibrary.generated.h"

/**
 * 
 */


DECLARE_LOG_CATEGORY_EXTERN(LogDebugLibrary, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogSuccess, Log, All);

UCLASS()
class PROJECTGRACE_API UDebugFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Debug", meta=(DevelopmentOnly, WorldContext="WorldContextObject",
		Keywords = "print debug log"))
	static void DebugPrint(UObject* WorldContextObject, FString Category, FString Message = "Message", EDebugSeverity Severity = EDebugSeverity::Info, bool bPrintToScreen = true, bool bPrintToLog = false, float Duration = 5.f, bool bUseCategoryAsKey = false, FName Key = "None");
	
	// ---- Windows / Layout ----
	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Window", meta = (
		DevelopmentOnly,
		DisplayName = "Begin ImGui Window",
		ToolTip = "Starts an ImGui window with optional close button and flags.",
		Keywords = "imgui window ui debug",
		AutoCreateRefTerm = "bOpen", Bitmask, BitmaskEnum = "EImGuiWindowFlags"
		))
	static void BeginWindow(const FString& Title, bool bAutoResize, bool bMenuBar, bool bShowClose, bool& bOpen);


	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Window",  meta=(DevelopmentOnly))
	static void EndWindow();

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static void EditFloat(UObject* Target, FName VariableName, float Min = 0.0f, float Max = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static void EditBool(UObject* Target, FName VariableName);

	/** Edit an int property on any object. */
	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static void EditInt(UObject* Target, FName VariableName, int32 Min = 0, int32 Max = 100);

	/** Edit a vector property on any object. */
	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property")
	static void EditVector(UObject* Target, FName VariableName, float Speed = 0.1f);

	/** Edit a rotator property on any object. */
	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static void EditRotator(UObject* Target, FName VariableName, float Speed = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static void EditTransform(AActor* Target, FName VariableName);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui Debug|Property",  meta=(DevelopmentOnly))
	static void EditColor(AActor* Target, FName VariableName);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static void EditQuat(AActor* Target, FName VariableName);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static void EditStruct(AActor* Target, FName VariableName);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static void EditEnum(AActor* Target, FName VariableName);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Widget", meta=(DevelopmentOnly))
	static void Separator();

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Widget",  meta=(DevelopmentOnly))
	static void Spacing(int32 Count = 1);

	// ---- Text & Buttons ----
	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Widget",  meta=(DevelopmentOnly))
	static void Text(const FString& Message);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Widget",  meta=(DevelopmentOnly))
	static bool Button(const FString& Label, FVector2D Size = FVector2D(0, 0));

	// ---- Tabs ----
	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Tab", meta = (
		DisplayName = "Begin Tab Bar",
		ToolTip = "Starts an ImGui Tab Bar container. Call EndTabBar() after adding tabs.",
		Keywords = "imgui tab tabs container header begin end",
		DevelopmentOnly
		))
	static bool BeginTabBar(const FString& TabBarName);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Tab",  meta=(DevelopmentOnly))
	static bool BeginTab(const FString& TabName);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Tab",  meta=(DevelopmentOnly))
	static void EndTab();

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Tab",  meta=(DevelopmentOnly))
	static void EndTabBar();

	// ---- Menus ----
	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Menu", meta = (
		DisplayName = "Begin Main Menu Bar",
		ToolTip = "Starts the main menu bar at the top of the window.",
		Keywords = "imgui menu bar main begin", DevelopmentOnly
		))
	static bool BeginMainMenuBar();

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Menu", meta = (
		DisplayName = "End Main Menu Bar",
		ToolTip = "Ends the main menu bar started by BeginMainMenuBar.",
		Keywords = "imgui menu bar main end", DevelopmentOnly
		))
	static void EndMainMenuBar();


	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Menu", meta = (
		DisplayName = "Begin Menu",
		ToolTip = "Starts a new menu inside a menu bar or popup. Call EndMenu() to close it.",
		Keywords = "imgui menu begin start bar popup", DevelopmentOnly
		))
	static bool BeginMenu(const FString& Label, bool bEnabled = true);


	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Menu", meta = (
		DisplayName = "Menu Item",
		ToolTip = "Creates an interactive item inside a menu. Can toggle a bool or trigger an action.",
		Keywords = "imgui menu item button toggle option entry", DevelopmentOnly
		))
	static bool MenuItem(const FString& Label, bool bSelected = false, bool bEnabled = true);


	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Menu", meta = (
		DisplayName = "End Menu",
		ToolTip = "Closes the current ImGui menu section started with BeginMenu.",
		Keywords = "imgui menu end close finish", DevelopmentOnly
		))
	static void EndMenu();

	// ---- Dropdown ----
	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Widget",  meta=(DevelopmentOnly))
	static int32 Dropdown(const FString& Label, const TArray<FString>& Options, int32 CurrentIndex);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static void ApplySingleProperty(UObject* Target, FName PropertyName);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Widget", meta = (DisplayName = "Collapsing Header", DevelopmentOnly))
	static bool CollapsingHeader(const FString& Label, EImGuiTreeNodeFlags Flags = EImGuiTreeNodeFlags::None);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Widget", meta = (DisplayName = "Tooltip", DevelopmentOnly))
	static void Tooltip(const FString& Text);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Widget",  meta=(DevelopmentOnly))
	static FString InputText(const FString& Label, const FString& InValue);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Widget", meta = (DisplayName = "Colored Text", DevelopmentOnly))
	static void TextColored(const FLinearColor& Color, const FString& Text);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static bool EditActorReference(AActor* Target, const FName& VariableName);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Widget", meta = (DisplayName = "Plot Lines", DevelopmentOnly))
	static void PlotLines(const FString& Label, const TArray<float>& Values, int NumValuesToShow = 0,
		float ScaleMin = -3.0f, float ScaleMax = 3.0f, float Width = 0.0f, float Height = 100.0f);

	UFUNCTION(BlueprintCallable, Category = "Debug|Imgui|Property",  meta=(DevelopmentOnly))
	static void EditActorClassProperty(UObject* TargetObject, const FString& VariableName);
};
