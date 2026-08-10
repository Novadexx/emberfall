#include "Progression/EmberfallProgressionComponent.h"

UEmberfallProgressionComponent::UEmberfallProgressionComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    Definition = CreateDefaultSubobject<UEmberfallProgressionData>(TEXT("ProgressionDefinition"));
    Definition->MaxLevel = 10;
    Definition->CumulativeExperience = {0, 100, 250, 450, 700, 1000, 1400, 1850, 2350, 3000};
    Definition->LevelRewards = {
        {1, TEXT("BasicAttack")},
        {2, TEXT("DodgeImprovement")},
        {3, TEXT("PassivePoint")},
        {4, TEXT("Leap")},
        {5, TEXT("WhirlwindModifier")},
        {6, TEXT("WeaponMastery")},
        {7, TEXT("Groundbreaker")},
        {8, TEXT("KipCollection")},
        {9, TEXT("AttributeBreakpoint")},
        {10, TEXT("WarCry")}
    };
}

int32 UEmberfallProgressionComponent::GrantExperience(const int32 Amount)
{
    if (Amount <= 0)
    {
        return 0;
    }

    const int32 OldLevel = State.Level;
    State.Experience = FMath::Max(0, State.Experience + Amount);
    const int32 NewLevel = Definition != nullptr
        ? Definition->GetLevelForExperience(State.Experience)
        : State.Level;

    State.Level = FMath::Max(State.Level, NewLevel);
    if (State.Level != OldLevel)
    {
        OnLevelChanged.Broadcast(OldLevel, State.Level);
    }

    return State.Level - OldLevel;
}

void UEmberfallProgressionComponent::SetLevel(const int32 NewLevel)
{
    const int32 OldLevel = State.Level;
    const int32 MaxLevel = Definition != nullptr ? Definition->MaxLevel : 100;
    State.Level = FMath::Clamp(NewLevel, 1, FMath::Max(1, MaxLevel));
    if (State.Level != OldLevel)
    {
        OnLevelChanged.Broadcast(OldLevel, State.Level);
    }
}

int32 UEmberfallProgressionComponent::GetExperienceRequiredForNextLevel() const
{
    if (Definition == nullptr || State.Level >= Definition->MaxLevel)
    {
        return 0;
    }

    return Definition->GetExperienceRequiredForLevel(State.Level + 1);
}
