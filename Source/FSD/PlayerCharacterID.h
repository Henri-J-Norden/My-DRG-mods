// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerCharacterID.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (Custom))
class FSD_API UPlayerCharacterID : public UDataAsset
{
	GENERATED_BODY()
public:

	//FSoftClassProperty Character;
	UPROPERTY(BlueprintReadOnly) FGuid SavegameID; // 0x38(0x10)
	UPROPERTY(BlueprintReadOnly) FName AssetName; // 0x48(0x08)
	UPROPERTY(BlueprintReadOnly) FString AnalyticsID; // 0x78(0x10)

	//struct APlayerCharacter* GetCharacter(); // Function FSD.PlayerCharacterID.GetCharacter
};
