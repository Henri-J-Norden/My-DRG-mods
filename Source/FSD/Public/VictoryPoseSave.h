#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VictoryPoseSave.generated.h"

USTRUCT(BlueprintType)
struct FVictoryPoseSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FGuid EquippedVictoryPose;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FGuid> UnlockedVictoryPoses;
    
protected:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FGuid> EquippedVictoryPoses;
    
public:
    FSD_API FVictoryPoseSave();
};
