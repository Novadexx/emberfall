#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EmberfallProgressionTypes.h"
#include "EmberfallProgressionData.generated.h"

UCLASS(BlueprintType)
class EMBERFALL_API UEmberfallProgressionData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Progression")
    int32 MaxLevel = 10;

    /** Cumulative XP required to enter each level. Index 0 represents level 1. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Progression")
    TArray<int32> CumulativeExperience;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Progression")
    TArray<FEmberfallLevelReward> LevelRewards;

    UFUNCTION(BlueprintPure, Category="Progression")
    int32 GetLevelForExperience(int32 Experience) const;

    UFUNCTION(BlueprintPure, Category="Progression")
    int32 GetExperienceRequiredForLevel(int32 Level) const;

    UFUNCTION(BlueprintPure, Category="Progression")
    bool TryGetRewardForLevel(int32 Level, FEmberfallLevelReward& OutReward) const;

    UFUNCTION(BlueprintPure, Category="Progression")
    bool IsValidProgressionData() const;
};
