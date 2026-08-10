#pragma once

#include "CoreMinimal.h"
#include "EmberfallAbilityTypes.generated.h"

UENUM(BlueprintType)
enum class EEmberfallAbilityId : uint8
{
    BasicAttack,
    Dodge,
    Whirlwind,
    Leap,
    Groundbreaker,
    WarCry
};

USTRUCT(BlueprintType)
struct FEmberfallAbilityTuning
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Cooldown = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float ResourceCost = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Damage = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Range = 0.0f;

    bool IsValid() const
    {
        return Cooldown >= 0.0f && ResourceCost >= 0.0f && Damage >= 0.0f && Range >= 0.0f;
    }
};

