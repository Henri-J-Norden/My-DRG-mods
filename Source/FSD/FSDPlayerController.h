// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FSDPlayerController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (Custom))
class FSD_API AFSDPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:

		UFUNCTION(BlueprintCallable, Category = "FSDPlayerController")
			virtual UNetConnection* GetNetConnection() const override;
	
};
