// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActorFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FSD_API UActorFunctionLibrary : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

public:
	static int32 i;

	UFUNCTION(BlueprintCallable)
		static int32 GetNextInt();

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static int32 GetPlayerCount(const UObject* WorldContextObject);

};
