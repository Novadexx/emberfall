#include "Abilities/EmberfallAbilityDefinition.h"

bool UEmberfallAbilityDefinition::IsValidAbilityDefinition() const
{
    return !DisplayName.IsEmpty() && Tuning.IsValid();
}

