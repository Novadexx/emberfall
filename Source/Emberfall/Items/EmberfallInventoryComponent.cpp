#include "Items/EmberfallInventoryComponent.h"

bool UEmberfallInventoryComponent::AddItem(const FEmberfallItemDefinition& Item)
{
    if (Item.ItemId.IsNone() || ContainsItem(Item.ItemId))
    {
        return false;
    }

    InventoryItems.Add(Item);
    OnInventoryChanged.Broadcast(Item.ItemId);
    return true;
}

bool UEmberfallInventoryComponent::RemoveItem(const FName ItemId)
{
    const int32 Index = InventoryItems.IndexOfByPredicate([ItemId](const FEmberfallItemDefinition& Item)
    {
        return Item.ItemId == ItemId;
    });
    if (Index == INDEX_NONE)
    {
        return false;
    }

    InventoryItems.RemoveAt(Index);
    OnInventoryChanged.Broadcast(ItemId);
    return true;
}

bool UEmberfallInventoryComponent::EquipItem(const FName ItemId)
{
    const int32 Index = InventoryItems.IndexOfByPredicate([ItemId](const FEmberfallItemDefinition& Item)
    {
        return Item.ItemId == ItemId;
    });
    if (Index == INDEX_NONE)
    {
        return false;
    }

    EquippedItems.Add(InventoryItems[Index]);
    OnInventoryChanged.Broadcast(ItemId);
    return true;
}

void UEmberfallInventoryComponent::ClearInventory()
{
    InventoryItems.Reset();
    EquippedItems.Reset();
    OnInventoryChanged.Broadcast(NAME_None);
}

bool UEmberfallInventoryComponent::ContainsItem(const FName ItemId) const
{
    return InventoryItems.ContainsByPredicate([ItemId](const FEmberfallItemDefinition& Item)
    {
        return Item.ItemId == ItemId;
    });
}

bool UEmberfallInventoryComponent::HasBuildChangingEffect(const FName EffectId) const
{
    if (EffectId.IsNone())
    {
        return false;
    }

    return EquippedItems.ContainsByPredicate([EffectId](const FEmberfallItemDefinition& Item)
    {
        return Item.BuildChangingEffectId == EffectId;
    });
}
