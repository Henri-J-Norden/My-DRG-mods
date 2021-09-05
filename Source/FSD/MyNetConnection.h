// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetConnection.h"
#include "MyNetConnection.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (Custom))
class FSD_API UMyNetConnection : public UNetConnection
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	virtual FString LowLevelGetRemoteAddress(bool bAppendPort = false) PURE_VIRTUAL(UNetConnection::LowLevelGetRemoteAddress, return TEXT(""););
};
