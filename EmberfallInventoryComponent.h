#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/EmberfallItemTypes.h"
#include "EmberfallInventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEmberfallInventoryChanged, FName, ItemId);

UCLASS(ClassGroup=(Emberfall), meta=(BlueprintSpawnableComponent))
class EMBERFALL_API UEmberfallInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Emberfall|Inventory")
    bool AddItem(const FEmberfallItemDefinition& Item);

    UFUNCTION(BlueprintCallable, Category="Emberfall|Inventory")
    bool RemoveItem(FName ItemId);

    UFUNCTION(BlueprintCallable, Category="Emberfall|Inventory")
    bool EquipItem(FName ItemId);

    UFUNCTION(BlueprintCallable, Category="Emberfall|Inventory")
    void ClearInventory();

    UFUNCTION(BlueprintPure, Category="Emberfall|Inventory")
    bool ContainsItem(FName ItemId) const;

    UFUNCTION(BlueprintPure, Category="Emberfall|Inventory")
    bool HasBuildChangingEffect(FName EffectId) const;

    UFUNCTION(BlueprintPure, Category="Emberfall|Inventory")
    int32 GetItemCount() const { return InventoryItems.Num(); }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Emberfall|Inventory")
    TArray<FEmberfallItemDefinition> InventoryItems;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Emberfall|Inventory")
    TArray<FEmberfallItemDefinition> EquippedItems;

    UPROPERTY(BlueprintAssignable, Category="Emberfall|Inventory")
    FEmberfallInventoryChanged OnInventoryChanged;
};
