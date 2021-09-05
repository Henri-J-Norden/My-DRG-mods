// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "FSDGameState.generated.h"

//UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMissionTimeUpdated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBoscoReviveCounterChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerJoined);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerLeave);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerCharacterRegistered);
UCLASS(Blueprintable, ClassGroup=(Custom) )
class FSD_API AFSDGameState : public AGameState
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnMissionTimeUpdated OnMissionTimeUpdated;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnBoscoReviveCounterChanged OnBoscoReviveCounterChanged;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerJoined OnPlayerJoined;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerLeave OnPlayerLeave;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerCharacterRegistered OnPlayerCharacterRegistered;
	//UPROPERTY(BlueprintAssignable, VisibleAnywhere) OnEnemyKilledEvent

	//UPROPERTY(BlueprintReadOnly) int32 CurrentLevel;
	UPROPERTY(BlueprintReadWrite) int32 BoscoReviveCounter;
	UPROPERTY(BlueprintReadOnly) int32 MissionTime;
	UPROPERTY(BlueprintReadOnly) bool IsOnSpaceRig;

	UFUNCTION(BlueprintCallable)
		void PostGameMessage(FString Msg);
};
