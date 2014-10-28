// Fill out your copyright notice in the Description page of Project Settings.

#include "CubeLand.h"
#include "myFunctions.h"


AmyFunctions::AmyFunctions(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}



FString AmyFunctions::GetHappyMessage()
{
	return FString("Victory! Victory BP Library Works!");
}

bool AmyFunctions::SaveStringTextToFile(
	FString SaveDirectory,
	FString FileName,
	FString SaveText,
	bool AllowOverWriting
	){
	//GFileManager?
	

	return true;
}


TArray<FString> AmyFunctions::checkGrid(FName map)
{

	TArray<FString> Levels;
	UWorld* CurrentWorld = GetWorld();

	CurrentWorld->FlushLevelStreaming();

	int currentX = 0, currentY = 0, standartWidth = 12000, standartHeight = 12000;

	int i = 0;
	for (int x = -1; x < 2; x++){
		for (int y = -1; y < 2; y++){
			int spawnX = currentX - standartWidth * x;
			int spawnY = currentY - standartHeight * y;

			/* FLatentActionInfo info = FLatentActionInfo();
			UGameplayStatics::LoadStreamLevel(GetWorld(), "balls", true, false, info);

			FName name = "balls";
			ULevelStreaming* tile = FStreamLevelAction::FindAndCacheLevelStreamingObject("balls", GetWorld());
			tile = tile->CreateInstance("balls2");

			tile->bShouldBeVisible = true;
			tile->bShouldBeLoaded = true;
			tile->LevelTransform = FTransform(FRotator(0, 0, 0), FVector(spawnX, spawnY, 0), FVector(0, 0, 0));

			UWorld* CurrentWorld = GetWorld();
			CurrentWorld->StreamingLevels.Add(tile);

			Levels.Add(tile->GetName()); */

			
			
			UClass* StreamingClass = ULevelStreamingKismet::StaticClass();
			ULevelStreaming* StreamingTile = Cast<ULevelStreaming>(StaticConstructObject(StreamingClass, GetWorld(), NAME_None, RF_Transient, NULL));

			//StreamingTile->PackageName_DEPRECATED = map;
			StreamingTile->SetWorldAssetByPackageName("Test");
			StreamingTile->PackageNameToLoad = map;
			StreamingTile->bShouldBeVisible = true;
			StreamingTile->bShouldBeLoaded = true;

			StreamingTile->LevelTransform = FTransform(FRotator(0, 0, 0), FVector(spawnX, spawnY, 0), FVector(0, 0, 0));

			CurrentWorld->StreamingLevels.Add(StreamingTile);

			Levels.Add(StreamingTile->GetName()); 
		}
	}
	CurrentWorld->FlushLevelStreaming();
	CurrentWorld->ProcessLevelStreamingVolumes();

	return Levels;
}