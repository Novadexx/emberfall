#pragma once

#include "CoreMinimal.h"
#include "EmberfallCooldownState.generated.h"

USTRUCT(BlueprintType)
struct FEmberfallCooldownState
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Duration = 0.0f;

    UPROPERTY(BlueprintReadOnly)
    float Remaining = 0.0f;

    bool IsReady() const
    {
        return Remaining <= 0.0f;
    }

    bool TryStart(const float CooldownDuration)
    {
        if (!IsReady() || CooldownDuration < 0.0f)
        {
            return false;
        }

        Duration = CooldownDuration;
        Remaining = CooldownDuration;
        return true;
    }

    void Advance(const float DeltaSeconds)
    {
        Remaining = FMath::Max(0.0f, Remaining - FMath::Max(0.0f, DeltaSeconds));
    }

    void Reset()
    {
        Remaining = 0.0f;
    }
};

