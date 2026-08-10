#pragma once

#include "CoreMinimal.h"
#include "EmberfallItemTypes.generated.h"

UENUM(BlueprintType)
enum class EEmberfallRarity : uint8
{
    Common,
    Magic,
    Rare,
    Epic,
    Legendary,
    Unique,
    Mythic
};

USTRUCT(BlueprintType)
struct FEmberfallItemDefinition
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FName ItemId;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FText DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    EEmberfallRarity Rarity = EEmberfallRarity::Common;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FName BuildChangingEffectId;
};

