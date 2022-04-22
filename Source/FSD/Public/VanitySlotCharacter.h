#pragma once
#include "CoreMinimal.h"
#include "VanitySlotStore.h"
#include "VanitySlotCharacter.generated.h"

class UPlayerCharacterID;

USTRUCT(BlueprintType)
struct FVanitySlotCharacter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UPlayerCharacterID*, FVanitySlotStore> Characters;
    
    FSD_API FVanitySlotCharacter();
};

