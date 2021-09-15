// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "structs.h"
#include "enums.h"
#include "Item.h"
#include "InventoryComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemEquipped);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemsLoaded);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FSD_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TArray<AItem*> Items; // 0x170(0x10)
	AItem* EquippedItem; // 0x260(0x08)

	AItem* GetItem(EItemCategory Category); // Function FSD.InventoryComponent.GetItem
		
};

/*
	struct FMulticastInlineDelegate OnItemsLoaded; // 0xb0(0x10)
	struct FMulticastInlineDelegate OnItemClicked; // 0xc0(0x10)
	struct FMulticastInlineDelegate OnItemEquipped; // 0xd0(0x10)
	struct FMulticastInlineDelegate OnItemUnequipped; // 0xe0(0x10)
	struct FMulticastInlineDelegate OnGrenadeCountChanged; // 0xf0(0x10)
	struct FMulticastInlineDelegate OnFlareCountChanged; // 0x100(0x10)
	struct FMulticastInlineDelegate OnMaxFlareCountChanged; // 0x110(0x10)
	struct FMulticastInlineDelegate OnFlareProduction; // 0x120(0x10)
	struct FMulticastInlineDelegate OnResuppliedEvent; // 0x130(0x10)
	struct FMulticastInlineDelegate OnCarriableChangedEvent; // 0x140(0x10)
	bool bItemsLoaded; // 0x150(0x01)
	char UnknownData_151[0xf]; // 0x151(0x0f)
	struct UInventoryList* InventoryList; // 0x160(0x08)
	struct AThrownGrenadeItem* ThrownGrenadeClass; // 0x168(0x08)
	struct TArray<struct AItem*> Items; // 0x170(0x10)
	struct TArray<struct AItem*> UnlistedItems; // 0x180(0x10)
	struct APickaxeItem* MiningItem; // 0x190(0x08)
	struct AThrownGrenadeItem* GrenadeItem; // 0x198(0x08)
	struct ALaserPointerItem* LaserPointerItem; // 0x1a0(0x08)
	struct ATerrainScannerItem* TerrainScannerItem; // 0x1a8(0x08)
	struct ARecallableSentryGunItem* RecallableSentryGunItem; // 0x1b0(0x08)
	struct AItem* PickedUpItem; // 0x1b8(0x08)
	struct ARessuplyPodItem* ResupplyItem; // 0x1c0(0x08)
	struct AItem* PreviousItem; // 0x1c8(0x08)
	struct TArray<struct AItem*> EquipHistory; // 0x1d0(0x10)
	char UnknownData_1E0[0x8]; // 0x1e0(0x08)
	struct FCarriedItemState CarriedItem; // 0x1e8(0x10)
	struct FVector FlareOffset; // 0x1f8(0x0c)
	char UnknownData_204[0x4]; // 0x204(0x04)
	struct USoundCue* OutOfFlaresSound; // 0x208(0x08)
	struct UDialogDataAsset* OutOfFlaresShout; // 0x210(0x08)
	char UnknownData_218[0x4]; // 0x218(0x04)
	float FlareAngle; // 0x21c(0x04)
	float FlareCooldown; // 0x220(0x04)
	float FlareProductionTime; // 0x224(0x04)
	struct FLinearColor FlareChromaColor; // 0x228(0x10)
	float FlareProductionTimeLeft; // 0x238(0x04)
	int32_t MaxFlares; // 0x23c(0x04)
	int32_t Flares; // 0x240(0x04)
	float FlareCooldownRemaining; // 0x244(0x04)
	struct AFlare* flareClass; // 0x248(0x08)
	struct TArray<struct UItemUpgrade*> FlareUpgrades; // 0x250(0x10)
	struct AItem* EquippedItem; // 0x260(0x08)
	char UnknownData_268[0x8]; // 0x268(0x08)

	void StartGrenadeThrow(); // Function FSD.InventoryComponent.StartGrenadeThrow
	void Server_ThrowFlare(); // Function FSD.InventoryComponent.Server_ThrowFlare
	void Server_Equip(struct AItem* Item); // Function FSD.InventoryComponent.Server_Equip
	void Server_DropCarriedItem(); // Function FSD.InventoryComponent.Server_DropCarriedItem
	void Resupply(float percentage); // Function FSD.InventoryComponent.Resupply
	void PickupItemInstance(struct AItem* Item); // Function FSD.InventoryComponent.PickupItemInstance
	struct AItem* PickupItem(struct AItem* itemClass); // Function FSD.InventoryComponent.PickupItem
	void OnRep_PickedUpItem(); // Function FSD.InventoryComponent.OnRep_PickedUpItem
	void OnRep_Items(); // Function FSD.InventoryComponent.OnRep_Items
	void OnRep_EquippedItem(struct AItem* oldItem); // Function FSD.InventoryComponent.OnRep_EquippedItem
	void OnRep_CarriedItem(struct FCarriedItemState LastCarriedItem); // Function FSD.InventoryComponent.OnRep_CarriedItem
	void OnCharacterStateChanged(enum class ECharacterState NewState); // Function FSD.InventoryComponent.OnCharacterStateChanged
	bool IsTerrainScannerEquipped(); // Function FSD.InventoryComponent.IsTerrainScannerEquipped
	bool HasPickedUpItem(); // Function FSD.InventoryComponent.HasPickedUpItem
	bool HasDrink(); // Function FSD.InventoryComponent.HasDrink
	int32_t GetTotalAmmoLeft(); // Function FSD.InventoryComponent.GetTotalAmmoLeft
	struct ARecallableSentryGunItem* GetRecallableSentryGunItem(); // Function FSD.InventoryComponent.GetRecallableSentryGunItem
	struct AItem* GetItem(enum class EItemCategory Category); // Function FSD.InventoryComponent.GetItem
	struct AActor* GetCarriedItem(); // Function FSD.InventoryComponent.GetCarriedItem
	struct TArray<struct AItem*> GetAllItems(); // Function FSD.InventoryComponent.GetAllItems
	void EquipLastItem(bool ignoreUsing); // Function FSD.InventoryComponent.EquipLastItem
	bool EquipCategory(enum class EItemCategory Category); // Function FSD.InventoryComponent.EquipCategory
	void EquipAtIndex(int32_t Index, bool ignoreUsing); // Function FSD.InventoryComponent.EquipAtIndex
	void Equip(struct AItem* Item, bool ignoreIsUsing); // Function FSD.InventoryComponent.Equip
	void EndGrenadeThrow(); // Function FSD.InventoryComponent.EndGrenadeThrow
	void DropPickedupItem(); // Function FSD.InventoryComponent.DropPickedupItem
	void CreateStartingEquipmentWhenItemsLoaded(); // Function FSD.InventoryComponent.CreateStartingEquipmentWhenItemsLoaded
	void Client_Resupply(float percentage); // Function FSD.InventoryComponent.Client_Resupply
	void Client_DropPickedUpItem(); // Function FSD.InventoryComponent.Client_DropPickedUpItem
	void AnimationNotify2(); // Function FSD.InventoryComponent.AnimationNotify2
	void AnimationNotify1(); // Function FSD.InventoryComponent.AnimationNotify1*/
