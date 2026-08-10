#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Loot/EmberfallLootTypes.h"
#include "EmberfallLootTable.generated.h"

UCLASS(BlueprintType)
class EMBERFALL_API UEmberfallLootTable : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot")
    TArray<FEmberfallLootEntry> Entries;

    UFUNCTION(BlueprintPure, Category="Loot")
    bool IsValidLootTable() const;

    UFUNCTION(BlueprintPure, Category="Loot")
    bool TryChooseEntry(float NormalizedRoll, FEmberfallLootEntry& OutEntry) const;
};

