// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "FSDGameMode.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMatchStarted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerLoggedIn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDonkeyCalled);
UCLASS(Blueprintable, ClassGroup = (Custom))
class FSD_API AFSDGameMode : public AGameMode
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "FSDGameMode") bool AllPlayersHaveSelectedCharacter();

	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnMatchStarted OnMatchStarted;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerLoggedIn OnPlayerLoggedIn;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnDonkeyCalled OnDonkeyCalled;
	
	//UPROPERTY(BlueprintReadOnly) bool PreventAllLatejoin; // will not compile
	
};
