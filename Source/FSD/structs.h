// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "structs.generated.h"

// Class FSD.PlayerCharacterID
// Size: 0x88 (Inherited: 0x30)
struct UPlayerCharacterID : UDataAsset {
	uint8 UnknownData_30[0x8]; // 0x30(0x08)
	FGuid SavegameID; // 0x38(0x10)
	FName AssetName; // 0x48(0x08)
	uint8 Filler[0x32]; // 0x56(0x32)

	//struct APlayerCharacter* GetCharacterClass(); // Function FSD.PlayerCharacterID.GetCharacterClass
	//struct APlayerCharacter* GetCharacter(); // Function FSD.PlayerCharacterID.GetCharacter
};


// ScriptStruct FSD.CharacterProgress
// Size: 0x20 (Inherited: 0x00)
USTRUCT(BlueprintType)
struct FCharacterProgress {
	GENERATED_BODY();

	UPlayerCharacterID* characterID; // 0x00(0x08)
	int32 Level; // 0x08(0x04)
	float Progress; // 0x0c(0x04)
	int32 CurrentXP; // 0x10(0x04)
	int32 NextLevelXP; // 0x14(0x04)
	int32 TimesRetired; // 0x18(0x04)
	uint8 UnknownData_1C[0x4]; // 0x1c(0x04)
};

// ScriptStruct FSD.HeroInfo
// Size: 0x88 (Inherited: 0x00)
USTRUCT(BlueprintType)
struct FHeroInfo {
	GENERATED_BODY();

	FText HeroName; // 0x00(0x18)
	UTexture2D* HeroIcon; // 0x18(0x08)
	UTexture2D* SmallHeroIcon; // 0x20(0x08)
	UTexture2D* HeroFullSizeImage; // 0x28(0x08)
	FLinearColor HeroColor; // 0x30(0x10)
	FText HeroShortDescription; // 0x40(0x18)
	FText HeroLongDescription; // 0x58(0x18)
	FText SwitchToMessage; // 0x70(0x18)
};


// Enum FSD.EChatSenderType
UENUM(BlueprintType)
enum class EChatSenderType : uint8 {
	NormalUser,
	DeluxUser,
	Developer,
	Streamer,
	Modder,
	EChatSenderType_MAX,
};


class FSD_API structs
{
public:
	structs();
	~structs();
};
