// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "structs.h"
#include "PlayerCharacter.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLaserPointerEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDamagedEnemy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaluteEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnToggleMapTool);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnToggleScanTool);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerShout);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReviveCallEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCallDonkey);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterStateChanged);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(F);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(F);
UCLASS(Blueprintable, ClassGroup = (Custom))
class FSD_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnLaserPointerEvent OnLaserPointerEvent;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnDamagedEnemy OnDamagedEnemy;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnSaluteEvent OnSaluteEvent;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnToggleMapTool OnToggleMapTool;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnToggleScanTool OnToggleScanTool;
//	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnPlayerShout OnPlayerShout;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnReviveCallEvent OnReviveCallEvent;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnCallDonkey OnCallDonkey;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnCharacterStateChanged OnCharacterStateChanged;


	UPROPERTY(BlueprintReadOnly) FString SteamClassID;
	UPROPERTY(BlueprintReadOnly) FHeroInfo HeroInfo; // 0xcc0(0x88)

	UFUNCTION(BlueprintCallable, Category = "PlayerCharacter") void Unparalyze();
	UFUNCTION(BlueprintCallable, Category = "PlayerCharacter") float GetTimeSinceLastRevival();


};
