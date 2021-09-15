// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UObject/WeakObjectPtr.h"
#include "FSDPlayerState.h"
#include "PlayerCharacter.h"
#include "BoscoController.generated.h"

/**
 * 
 */

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLaserPointer, FLaserPointerTarget, HitInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMessageBehaviorTreeEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAlertedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFollowTargetChangedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUseDone, int32, TimesUsed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerShout, APlayerCharacter*, PlayerCharacter);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerSalute, APlayerCharacter*, PlayerCharacter);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerLeave, AFSDPlayerState*, PlayerState);
UCLASS(Blueprintable, ClassGroup = (Custom))
class FSD_API ABoscoController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnMessageBehaviorTreeEvent OnMessageBehaviorTreeEvent;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnAlertedEvent OnAlertedEvent;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnFollowTargetChangedDelegate OnFollowTargetChangedDelegate;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnUseDone OnUseDone;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerShout OnPlayerShout;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerSalute OnPlayerSalute;
	//UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerLeave OnPlayerLeave;
	//UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnLaserPointer OnLaserPointer;

	
	//UPROPERTY(BlueprintReadOnly) FWeakObjectPtr<APlayerCharacter> TargetedPlayer;

	UFUNCTION(BlueprintCallable, Category = "BoscoController") void RegisterPlayer(APlayerCharacter* APlayerCharacter);
	
};
