#include "Items/EmberfallItemPickup.h"

#include "Items/EmberfallInventoryComponent.h"

AEmberfallItemPickup::AEmberfallItemPickup()
{
    PrimaryActorTick.bCanEverTick = false;
    SetActorEnableCollision(true);
}

bool AEmberfallItemPickup::TryPickUp(AActor* Picker)
{
    if (bPickedUp || Picker == nullptr || Item.ItemId.IsNone())
    {
        return false;
    }

    UEmberfallInventoryComponent* Inventory = Picker->FindComponentByClass<UEmberfallInventoryComponent>();
    if (Inventory == nullptr || !Inventory->AddItem(Item))
    {
        return false;
    }

    bPickedUp = true;
    OnPickedUp.Broadcast(Item.ItemId);
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);
    return true;
}
