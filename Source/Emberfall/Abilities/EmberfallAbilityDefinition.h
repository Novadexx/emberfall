#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Abilities/EmberfallAbilityTypes.h"
#include "EmberfallAbilityDefinition.generated.h"

UCLASS(BlueprintType)
class EMBERFALL_API UEmberfallAbilityDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability")
    EEmberfallAbilityId AbilityId = EEmberfallAbilityId::BasicAttack;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability")
    FText DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability")
    FEmberfallAbilityTuning Tuning;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability")
    FName GameplayEffectId;

    UFUNCTION(BlueprintPure, Category="Ability")
    bool IsValidAbilityDefinition() const;
};

