#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ShowroomManager.generated.h"

class AShowroomStage;
class UTextureRenderTarget2D;
class UShowroomController;

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class UShowroomManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ShowroomLocation;
    
protected:
    UPROPERTY(BlueprintReadWrite, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AShowroomStage> CurrentStage;
    
    UPROPERTY(BlueprintReadWrite, Transient, meta=(AllowPrivateAccess=true))
    AShowroomStage* StageInstance;
    
    UPROPERTY(BlueprintReadWrite, Transient, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RenderTarget;
    
public:
    UShowroomManager();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UShowroomController* GetController();
    
    UFUNCTION(BlueprintCallable)
    void ClearShowroom();
    
};

