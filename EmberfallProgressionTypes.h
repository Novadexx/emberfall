#pragma once

#include "CoreMinimal.h"
#include "EmberfallProgressionTypes.generated.h"

USTRUCT(BlueprintType)
struct FEmberfallLevelReward
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 Level = 1;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FName RewardId;
};

USTRUCT(BlueprintType)
struct FEmberfallProgressionState
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Experience = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 KipSyncLevel = 1;
};

