#pragma once

#include "CoreMinimal.h"
#include "Items/EmberfallItemTypes.h"
#include "EmberfallLootTypes.generated.h"

USTRUCT(BlueprintType)
struct FEmberfallLootEntry
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FName ItemId;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    EEmberfallRarity Rarity = EEmberfallRarity::Common;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Weight = 1.0f;
};

