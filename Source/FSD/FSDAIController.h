// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PlayerCharacter.h"
#include "FSDAIController.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAlertedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMessageBehaviorTreeEvent);
UCLASS(Blueprintable, ClassGroup = (Custom))
class FSD_API AFSDAIController : public AAIController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnAlertedEvent OnAlertedEvent;
	UPROPERTY(BlueprintAssignable, VisibleAnywhere) FOnMessageBehaviorTreeEvent OnMessageBehaviorTreeEvent;

	UPROPERTY(BlueprintReadWrite) APlayerCharacter* TargetedPlayer;
	
	UFUNCTION(BlueprintCallable, Category = "FSDAIController") void SetAlerted(bool isAlerted); // Function FSD.FSDAIController.SetAlerted
	UFUNCTION(BlueprintCallable, Category = "FSDAIController") void ResumeLogic(); // Function FSD.FSDAIController.ResumeLogic
	//UFUNCTION(BlueprintCallable, Category = "FSDAIController") void RegisterBlackboardChanges(struct FName Key); // Function FSD.FSDAIController.RegisterBlackboardChanges
	//UFUNCTION(BlueprintCallable, Category = "FSDAIController") void Recieve_BlackboardValueChanged(struct FName KeyName); // Function FSD.FSDAIController.Recieve_BlackboardValueChanged
	UFUNCTION(BlueprintCallable, Category = "FSDAIController") void PauseLogic(); // Function FSD.FSDAIController.PauseLogic
	//UFUNCTION(BlueprintCallable, Category = "FSDAIController") void OnAttackingChanged(bool attacking); // Function FSD.FSDAIController.OnAttackingChanged
	UFUNCTION(BlueprintCallable, Category = "FSDAIController") bool GetIsAlerted(); // Function FSD.FSDAIController.GetIsAlerted
};
