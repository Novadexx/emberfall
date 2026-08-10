#include "Core/EmberfallGameplayTags.h"

namespace EmberfallGameplayTags
{
    FGameplayTag CombatStateDead()
    {
        return FGameplayTag::RequestGameplayTag(TEXT("Combat.State.Dead"));
    }

    FGameplayTag CombatStateInvulnerable()
    {
        return FGameplayTag::RequestGameplayTag(TEXT("Combat.State.Invulnerable"));
    }

    FGameplayTag AbilityBerserkerWhirlwind()
    {
        return FGameplayTag::RequestGameplayTag(TEXT("Ability.Berserker.Whirlwind"));
    }

    FGameplayTag AbilityBerserkerLeap()
    {
        return FGameplayTag::RequestGameplayTag(TEXT("Ability.Berserker.Leap"));
    }

    FGameplayTag AbilityBerserkerGroundbreaker()
    {
        return FGameplayTag::RequestGameplayTag(TEXT("Ability.Berserker.Groundbreaker"));
    }

    FGameplayTag AbilityBerserkerWarCry()
    {
        return FGameplayTag::RequestGameplayTag(TEXT("Ability.Berserker.WarCry"));
    }
}

