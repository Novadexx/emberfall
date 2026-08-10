#pragma once

#include "CoreMinimal.h"
#include "EmberfallKipTypes.generated.h"

UENUM(BlueprintType)
enum class EEmberfallKipModule : uint8
{
    Collection,
    Insight,
    Traversal,
    Logistics,
    Support,
    Resonance
};

USTRUCT(BlueprintType)
struct FEmberfallKipState
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SyncLevel = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<EEmberfallKipModule> UnlockedModules;

    bool UnlockModule(const EEmberfallKipModule Module)
    {
        if (UnlockedModules.Contains(Module))
        {
            return false;
        }

        UnlockedModules.Add(Module);
        return true;
    }

    bool HasModule(const EEmberfallKipModule Module) const
    {
        return UnlockedModules.Contains(Module);
    }
};

