// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
//#include "FSDPlayerState.h"
#include "FSDPlayerController.generated.h"


/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerSpawnBegin, int32, PlayerId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerStateSelectedCharacterChanged, APlayerCharacter*, CharacterClass);
UCLASS(Blueprintable, ClassGroup = (Custom))
class FSD_API AFSDPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerSpawnBegin OnPlayerSpawnBegin;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerStateSelectedCharacterChanged OnPlayerStateSelectedCharacterChanged;

	UFUNCTION(BlueprintCallable, Category = "FSDPlayerController")
		virtual UNetConnection* GetNetConnection() const override;

	//UFUNCTION(BlueprintCallable, Category = "FSDPlayerController") AFSDPlayerState* GetFSDPlayerState();
	
};
