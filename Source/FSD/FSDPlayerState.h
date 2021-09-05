// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayerCharacter.h"
#include "structs.h"
#include "FSDPlayerState.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnemyKilledEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerCharacterSpawned);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelectedCharacterChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSupplyStatusChangedEvent);
UCLASS(Blueprintable, ClassGroup = (Custom))
class FSD_API AFSDPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	//int32_t GetCharacterLevel(struct UPlayerCharacterID* characterID);
	// UFUNCTION(BlueprintCallable, Category = "FSDPlayerState")
	UFUNCTION(BlueprintCallable, Category = "FSDPlayerState") bool HasNormalOwnerStatus();
	UFUNCTION(BlueprintCallable, Category = "FSDPlayerState") int32 GetPlayerRank();
	UFUNCTION(BlueprintCallable, Category = "FSDPlayerState") int32 GetUIPing();
	UFUNCTION(BlueprintCallable, Category = "FSDPlayerState") int32 GetSelectedCharacterLevel();
	UFUNCTION(BlueprintCallable, Category = "FSDPlayerState") struct FCharacterProgress GetSelectCharacterProgress();
	//UFUNCTION(BlueprintCallable, Category = "FSDPlayerState") struct FCharacterProgress GetCharacterProgress(struct UPlayerCharacterID* characterID);
	UFUNCTION(BlueprintCallable, Category = "FSDPlayerState") APlayerCharacter* GetSelectedCharacter();
	UFUNCTION(BlueprintCallable, Category = "FSDPlayerState") float GetSupplyHealthStatus();
	UFUNCTION(BlueprintCallable, Category = "FSDPlayerState") float GetSupplyAmmoStatus();
	UFUNCTION(BlueprintCallable, Category = "FSDPlayerState") void Server_NewMessage(FString Sender, FString Text, EChatSenderType SenderType);

	UPROPERTY(BlueprintReadOnly) bool IsOnSpaceRig;
	UPROPERTY(BlueprintReadOnly) bool IsInMission;
	UPROPERTY(BlueprintReadOnly) bool IsTalking;
	UPROPERTY(BlueprintReadOnly) bool HasGeneratedLevel;
	UPROPERTY(BlueprintReadOnly) bool HasSelectedCharacter; 
	UPROPERTY(BlueprintReadOnly) bool bIsServer;
	UPROPERTY(BlueprintReadOnly) FString LevelGenerationState; 
	UPROPERTY(BlueprintReadOnly) int32 PlayerSortId;
	UPROPERTY(BlueprintReadOnly) uint8 SupplyAmmoStatus;
	UPROPERTY(BlueprintReadOnly) uint8 SupplyHealthStatus;
	UPROPERTY(BlueprintReadOnly) APlayerCharacter* PlayerCharacter;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnEnemyKilledEvent OnEnemyKilledEvent;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerCharacterSpawned OnPlayerCharacterSpawned;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnSelectedCharacterChanged OnSelectedCharacterChanged;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnSupplyStatusChangedEvent OnSupplyStatusChangedEvent;
};
