#pragma once

#include "CoreMinimal.h"
#include "EmberfallHealthState.generated.h"

USTRUCT(BlueprintType)
struct FEmberfallHealthState
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Current = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Maximum = 100.0f;

    bool IsDead() const
    {
        return Current <= 0.0f;
    }

    float ApplyDamage(const float Damage)
    {
        const float AppliedDamage = FMath::Clamp(Damage, 0.0f, FMath::Max(0.0f, Current));
        Current = FMath::Max(0.0f, Current - AppliedDamage);
        return AppliedDamage;
    }

    void Restore(const float Amount)
    {
        Current = FMath::Clamp(Current + FMath::Max(0.0f, Amount), 0.0f, FMath::Max(0.0f, Maximum));
    }

    void Reset()
    {
        Current = FMath::Max(0.0f, Maximum);
    }
};

