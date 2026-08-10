#include "Progression/EmberfallProgressionData.h"

int32 UEmberfallProgressionData::GetLevelForExperience(const int32 Experience) const
{
    if (CumulativeExperience.IsEmpty())
    {
        return 1;
    }

    const int32 SafeExperience = FMath::Max(0, Experience);
    int32 ResolvedLevel = 1;

    for (int32 Index = 0; Index < CumulativeExperience.Num(); ++Index)
    {
        if (SafeExperience < CumulativeExperience[Index])
        {
            break;
        }
        ResolvedLevel = Index + 1;
    }

    return FMath::Clamp(ResolvedLevel, 1, FMath::Max(1, MaxLevel));
}

int32 UEmberfallProgressionData::GetExperienceRequiredForLevel(const int32 Level) const
{
    if (CumulativeExperience.IsEmpty())
    {
        return 0;
    }

    const int32 SafeLevel = FMath::Clamp(Level, 1, CumulativeExperience.Num());
    return CumulativeExperience[SafeLevel - 1];
}

bool UEmberfallProgressionData::TryGetRewardForLevel(const int32 Level, FEmberfallLevelReward& OutReward) const
{
    for (const FEmberfallLevelReward& Reward : LevelRewards)
    {
        if (Reward.Level == Level)
        {
            OutReward = Reward;
            return true;
        }
    }

    return false;
}

bool UEmberfallProgressionData::IsValidProgressionData() const
{
    if (MaxLevel < 1 || CumulativeExperience.Num() != MaxLevel || CumulativeExperience[0] != 0)
    {
        return false;
    }

    for (int32 Index = 1; Index < CumulativeExperience.Num(); ++Index)
    {
        if (CumulativeExperience[Index] <= CumulativeExperience[Index - 1])
        {
            return false;
        }
    }

    for (const FEmberfallLevelReward& Reward : LevelRewards)
    {
        if (Reward.Level < 1 || Reward.Level > MaxLevel || Reward.RewardId.IsNone())
        {
            return false;
        }
    }

    return true;
}
