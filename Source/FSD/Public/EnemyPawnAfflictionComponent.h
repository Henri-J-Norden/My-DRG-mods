#pragma once
#include "CoreMinimal.h"
#include "PawnAfflictionComponent.h"
#include "EnemyPawnAfflictionComponent.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class UEnemyPawnAfflictionComponent : public UPawnAfflictionComponent {
    GENERATED_BODY()
public:
    UEnemyPawnAfflictionComponent();
};
