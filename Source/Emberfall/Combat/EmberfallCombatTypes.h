#pragma once

#include "CoreMinimal.h"
#include "EmberfallCombatTypes.generated.h"

UENUM(BlueprintType)
enum class EEmberfallResourceType : uint8
{
    Rage,
    Mana,
    Focus
};

USTRUCT(BlueprintType)
struct FEmberfallCombatResource
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EEmberfallResourceType Type = EEmberfallResourceType::Rage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Current = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Maximum = 100.0f;

    bool CanSpend(const float Amount) const
    {
        return Amount >= 0.0f && Current >= Amount;
    }

    bool Spend(const float Amount)
    {
        if (!CanSpend(Amount))
        {
            return false;
        }

        Current = FMath::Clamp(Current - Amount, 0.0f, Maximum);
        return true;
    }

    void Restore(const float Amount)
    {
        Current = FMath::Clamp(Current + FMath::Max(0.0f, Amount), 0.0f, Maximum);
    }
};

