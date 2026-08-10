#pragma once

#include "CoreMinimal.h"
#include "Items/EmberfallItemTypes.h"

namespace EmberfallPrototypeItems
{
    inline TArray<FEmberfallItemDefinition> BuildCatalog()
    {
        return {
            {TEXT("Ashen Cleaver"), FText::FromString(TEXT("Ashen Cleaver")), EEmberfallRarity::Common, NAME_None},
            {TEXT("Deepstone Axe"), FText::FromString(TEXT("Deepstone Axe")), EEmberfallRarity::Magic, NAME_None},
            {TEXT("Forgeguard Helm"), FText::FromString(TEXT("Forgeguard Helm")), EEmberfallRarity::Rare, NAME_None},
            {TEXT("Crystalbound Belt"), FText::FromString(TEXT("Crystalbound Belt")), EEmberfallRarity::Rare, NAME_None},
            {TEXT("Minesworn Boots"), FText::FromString(TEXT("Minesworn Boots")), EEmberfallRarity::Magic, NAME_None},
            {TEXT("Cyclone Maw"), FText::FromString(TEXT("Cyclone Maw")), EEmberfallRarity::Legendary, TEXT("WhirlwindPull")},
            {TEXT("Emberwake"), FText::FromString(TEXT("Emberwake")), EEmberfallRarity::Legendary, TEXT("DodgeBurnTrail")},
            {TEXT("Foremans Grip"), FText::FromString(TEXT("Foreman's Grip")), EEmberfallRarity::Unique, TEXT("GroundbreakerShockwave")},
            {TEXT("Echo Fang"), FText::FromString(TEXT("Echo Fang")), EEmberfallRarity::Unique, TEXT("CriticalEcho")},
            {TEXT("Anchorbound Relic"), FText::FromString(TEXT("Anchorbound Relic")), EEmberfallRarity::Epic, TEXT("KipMarkedDrops")},
            {TEXT("Obsidian Heart"), FText::FromString(TEXT("Obsidian Heart")), EEmberfallRarity::Epic, TEXT("RageArmor")},
            {TEXT("Lanternwake"), FText::FromString(TEXT("Lanternwake")), EEmberfallRarity::Rare, TEXT("RevealHiddenEnemies")},
            {TEXT("Tunneler's Oath"), FText::FromString(TEXT("Tunneler's Oath")), EEmberfallRarity::Legendary, TEXT("LeapBurrow")},
            {TEXT("Bruteforge"), FText::FromString(TEXT("Bruteforge")), EEmberfallRarity::Unique, TEXT("LowHealthPower")},
            {TEXT("Frostvein Mantle"), FText::FromString(TEXT("Frostvein Mantle")), EEmberfallRarity::Epic, TEXT("DodgeFrostEcho")},
            {TEXT("Railbreakers Mark"), FText::FromString(TEXT("Railbreaker's Mark")), EEmberfallRarity::Rare, TEXT("RailDamage")},
            {TEXT("Hollow Crown"), FText::FromString(TEXT("Hollow Crown")), EEmberfallRarity::Unique, TEXT("DeathRefusal")},
            {TEXT("Deepworks Sigil"), FText::FromString(TEXT("Deepworks Sigil")), EEmberfallRarity::Epic, TEXT("AbilityChain")},
            {TEXT("Last Shift"), FText::FromString(TEXT("Last Shift")), EEmberfallRarity::Legendary, TEXT("ForemanBonus")},
            {TEXT("Emberfall Core"), FText::FromString(TEXT("Emberfall Core")), EEmberfallRarity::Mythic, TEXT("CorruptionResonance")}
        };
    }
}

