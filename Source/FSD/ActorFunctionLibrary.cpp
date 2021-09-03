// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorFunctionLibrary.h"

int32 UActorFunctionLibrary::i;

int32 UActorFunctionLibrary::GetPlayerCount(const UObject* WorldContextObject) {
	// World context https://answers.unrealengine.com/questions/918645/how-to-getworld-in-a-blueprint.html
	//UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	return 6;
}

int32 UActorFunctionLibrary::GetNextInt() {
	return UActorFunctionLibrary::i++;
}
