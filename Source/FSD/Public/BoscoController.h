#pragma once
#include "CoreMinimal.h"
#include "FollowTargetChangedDelegate.h"
#include "FSDAIController.h"
#include "LaserPointerTarget.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "EInputKeys.h"
#include "BoscoController.generated.h"

class UDroneUseComponent;
class AFSDPlayerState;
class UBehaviorTree;
class ACarriableItem;
class UTerrainMaterial;
class APlayerCharacter;
class AActor;
class UHealthComponentBase;

UCLASS()
class ABoscoController : public AFSDAIController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    UBehaviorTree* BehaviourTree;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float CheckOutOfTheWayInterval;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float DistCountAsSameHit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FFollowTargetChanged OnFollowTargetChangedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* HearthstoneCrystalMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float SearchForEnemiesInterval;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float SaluteDelay;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float SaluteCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float CheckGraberInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxThrowStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxThrowRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepairRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceCountedAsClose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery TargetQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery AttackOnOrderQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery AttackOnSightQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery DefendTageQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReviveHealthPercentage;
    
    UPROPERTY(BlueprintReadWrite, Export, Transient, meta=(AllowPrivateAccess=true))
    UDroneUseComponent* CurrentUse;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    ACarriableItem* TryingToPickGem;
    
public:
    ABoscoController();
    UFUNCTION(BlueprintCallable)
    void ReviveTarget();
    
    UFUNCTION(BlueprintCallable)
    void ResetToFollowState();
    
private:
    UFUNCTION(BlueprintCallable)
    void RegisterPlayer(APlayerCharacter* APlayerCharacter);
    
public:
    UFUNCTION(BlueprintCallable)
    void PickupGem();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnUseDone(int32 TimesUsed);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSecondaryLaserPointer(AActor* aTarget, const FVector& aLocation);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerShout(APlayerCharacter* APlayerCharacter);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerSalute(APlayerCharacter* aCharacater);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerLeave(AFSDPlayerState* APlayerState);
    
    UFUNCTION(BlueprintCallable)
    void OnLaserPointer(const FLaserPointerTarget& HitInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnJobFinished();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnEscortTargetDied(UHealthComponentBase* Health);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetPointNearPlayers() const;
    
    UFUNCTION(BlueprintCallable)
    AActor* GetFollowTarget();
    
    UFUNCTION(BlueprintCallable)
    void GenerateRelativeLocation(AActor* aTarget, float aRange, float aHeightRestriction, float aMinRange, bool aTryToStayOutOfTheWay, bool aStayBehind);
    
    UFUNCTION(BlueprintCallable)
    void GemUsed(APlayerCharacter* usedBy, EInputKeys Key);
    
    UFUNCTION(BlueprintCallable)
    void ConfirmPickup();
    
protected:
    UFUNCTION(BlueprintCallable)
    void CarriableDrop();
    
};

