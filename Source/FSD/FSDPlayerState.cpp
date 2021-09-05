// Fill out your copyright notice in the Description page of Project Settings.


#include "FSDPlayerState.h"

bool AFSDPlayerState::HasNormalOwnerStatus() { return false; }

int32 AFSDPlayerState::GetPlayerRank() { return -9; }
int32 AFSDPlayerState::GetUIPing() { return -1; }
int32 AFSDPlayerState::GetSelectedCharacterLevel() { return -1; }

float AFSDPlayerState::GetSupplyHealthStatus() { return -1;  }
float AFSDPlayerState::GetSupplyAmmoStatus() { return -1; }

struct FCharacterProgress AFSDPlayerState::GetSelectCharacterProgress() { return *(FCharacterProgress*)NULL; }
//struct FCharacterProgress AFSDPlayerState::GetCharacterProgress(struct UPlayerCharacterID* characterID) { return *(FCharacterProgress*)NULL; }
APlayerCharacter* AFSDPlayerState::GetSelectedCharacter() { return NULL; }

void AFSDPlayerState::Server_NewMessage(FString Sender, FString Text, enum class EChatSenderType SenderType) { }
