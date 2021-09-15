// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BoscoController.h"
#include "enums.h"
#include "Bosco.generated.h"

//struct FMulticastInlineDelegate OnReviveused;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReviveused);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStateChanged);
UCLASS(Blueprintable, ClassGroup = (Custom))
class FSD_API ABosco : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABosco();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnReviveused OnReviveused;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnStateChanged OnStateChanged;

	UPROPERTY(BlueprintReadOnly) ABoscoController* DroneController;

	UFUNCTION(BlueprintCallable, Category = "Bosco") EDroneAIState GetCurrentState();
	UFUNCTION(BlueprintCallable, Category = "Bosco") int32 GetReviveCharges();
	UFUNCTION(BlueprintCallable, Category = "Bosco") void ReviveCounterChanged(int32 remainingCharges);
	UFUNCTION(BlueprintCallable, Category = "Bosco") void UseABillity();

};
