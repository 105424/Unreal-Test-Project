// Fill out your copyright notice in the Description page of Project Settings.

#include "CubeLand.h"
#include "MyWorldSettings.h"


AMyWorldSettings::AMyWorldSettings(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}


TArray<FString> AMyWorldSettings::loadGrid(FName map)
{

	TArray<FString> Levels;

	int currentX = 0, currentY = 0, standartWidth = 12000, standartHeight = 12000;

	int i = 0;
	for (size_t x = -1; x < 2; x++){
		for (size_t y = -1; y < 2; y++){
			int spawnX = currentX - standartWidth * x;
			int spawnY = currentY - standartHeight * y;

			UClass* StreamingClass = ULevelStreamingKismet::StaticClass();
			ULevelStreaming* StreamingTile = Cast<ULevelStreaming>(StaticConstructObject(StreamingClass, GetWorld(), NAME_None, RF_Transient, NULL));

			//StreamingTile->PackageName = FName(*MapPath);
			StreamingTile->PackageNameToLoad = map;
			StreamingTile->bShouldBeVisible = true;
			StreamingTile->bShouldBeLoaded = true;

			StreamingTile->LevelTransform = FTransform(FRotator(0, 0, 0), FVector(0, 0, 0), FVector(0, 0, 0));

			UWorld* CurrentWorld = GetWorld();
			CurrentWorld->StreamingLevels.Add(StreamingTile);

			Levels.Add(StreamingTile->GetName());
		}
	}

	return Levels;
}