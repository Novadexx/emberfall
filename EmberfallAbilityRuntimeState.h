#pragma once

#include "CoreMinimal.h"
#include "Abilities/EmberfallAbilityTypes.h"
#include "Combat/EmberfallCombatTypes.h"
#include "Combat/EmberfallCooldownState.h"
#include "EmberfallAbilityRuntimeState.generated.h"

USTRUCT(BlueprintType)
struct FEmberfallAbilityRuntimeState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FEmberfallCooldownState Cooldown;

    bool TryActivate(const FEmberfallAbilityTuning& Tuning, FEmberfallCombatResource& Resource)
    {
        if (!Tuning.IsValid() || !Cooldown.IsReady() || !Resource.Spend(Tuning.ResourceCost))
        {
            return false;
        }

        Cooldown.TryStart(Tuning.Cooldown);
        return true;
    }

    void Advance(const float DeltaSeconds)
    {
        Cooldown.Advance(DeltaSeconds);
    }

    void Reset()
    {
        Cooldown.Reset();
    }
};

