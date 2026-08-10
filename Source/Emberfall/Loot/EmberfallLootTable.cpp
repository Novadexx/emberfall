#include "Loot/EmberfallLootTable.h"

bool UEmberfallLootTable::IsValidLootTable() const
{
    float TotalWeight = 0.0f;
    for (const FEmberfallLootEntry& Entry : Entries)
    {
        if (Entry.ItemId.IsNone() || Entry.Weight <= 0.0f)
        {
            return false;
        }
        TotalWeight += Entry.Weight;
    }

    return !Entries.IsEmpty() && TotalWeight > 0.0f;
}

bool UEmberfallLootTable::TryChooseEntry(const float NormalizedRoll, FEmberfallLootEntry& OutEntry) const
{
    if (!IsValidLootTable())
    {
        return false;
    }

    float TotalWeight = 0.0f;
    for (const FEmberfallLootEntry& Entry : Entries)
    {
        TotalWeight += Entry.Weight;
    }

    float Remaining = FMath::Clamp(NormalizedRoll, 0.0f, 0.999999f) * TotalWeight;
    for (const FEmberfallLootEntry& Entry : Entries)
    {
        Remaining -= Entry.Weight;
        if (Remaining < 0.0f)
        {
            OutEntry = Entry;
            return true;
        }
    }

    OutEntry = Entries.Last();
    return true;
}

