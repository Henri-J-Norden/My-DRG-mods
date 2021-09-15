// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerCharacterID.h"
#include "structs.generated.h"


// ScriptStruct FSD.CharacterProgress
// Size: 0x20 (Inherited: 0x00)
USTRUCT(BlueprintType)
struct FCharacterProgress {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly) UPlayerCharacterID* characterID; // 0x00(0x08)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Level; // 0x08(0x04)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Progress; // 0x0c(0x04)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentXP; // 0x10(0x04)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 NextLevelXP; // 0x14(0x04)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 TimesRetired; // 0x18(0x04)
	uint8 UnknownData_1C[0x4]; // 0x1c(0x04)
};

// ScriptStruct FSD.HeroInfo
// Size: 0x88 (Inherited: 0x00)
USTRUCT(BlueprintType)
struct FHeroInfo {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly) FText HeroName; // 0x00(0x18)
	UPROPERTY(EditAnywhere, BlueprintReadOnly) UTexture2D* HeroIcon; // 0x18(0x08)
	UPROPERTY(EditAnywhere, BlueprintReadOnly) UTexture2D* SmallHeroIcon; // 0x20(0x08)
	UPROPERTY(EditAnywhere, BlueprintReadOnly) UTexture2D* HeroFullSizeImage; // 0x28(0x08)
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FLinearColor HeroColor; // 0x30(0x10)
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FText HeroShortDescription; // 0x40(0x18)
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FText HeroLongDescription; // 0x58(0x18)
	UPROPERTY(EditAnywhere, BlueprintReadOnly) FText SwitchToMessage; // 0x70(0x18)
};


class FSD_API structs
{
public:
	structs();
	~structs();
};
