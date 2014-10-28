// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/WorldSettings.h"
#include "MyWorldSettings.generated.h"

/**
 * 
 */
UCLASS()
class CUBELAND_API AMyWorldSettings : public AWorldSettings
{
	GENERATED_UCLASS_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "VictoryBPLibrary")
	TArray<FString> loadGrid(FName map);
};
