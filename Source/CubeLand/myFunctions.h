// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "myFunctions.generated.h"

/**
 * 
 */
UCLASS()
class CUBELAND_API AmyFunctions : public AActor
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "VictoryBPLibrary")
	static FString GetHappyMessage();

	/** Saves text to filename of your choosing, make sure include whichever file extension you want in the filename, ex: SelfNotes.txt . Make sure to include the entire file path in the save directory, ex: C:\MyGameDir\BPSavedTextFiles */
	UFUNCTION(BlueprintCallable, Category = "VictoryBPLibrary")
	static bool SaveStringTextToFile(FString SaveDirectory, FString FileName, FString SaveText, bool AllowOverWriting = false);

	UFUNCTION(BlueprintCallable, Category = "VictoryBPLibrary")
	TArray<FString> checkGrid(FName map);
};