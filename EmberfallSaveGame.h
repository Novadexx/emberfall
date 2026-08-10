#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Progression/EmberfallProgressionTypes.h"
#include "Items/EmberfallItemTypes.h"
#include "Kip/EmberfallKipTypes.h"
#include "EmberfallSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FEmberfallSaveSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MasterVolume = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bReducedFlash = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bReducedScreenShake = false;
};

UCLASS()
class EMBERFALL_API UEmberfallSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    static constexpr int32 CurrentSaveVersion = 1;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Save")
    int32 SaveVersion = CurrentSaveVersion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Progression")
    FEmberfallProgressionState Progression;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float SavedHealth = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    float SavedResource = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Items")
    TArray<FEmberfallItemDefinition> EquippedItems;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Items")
    TArray<FEmberfallItemDefinition> InventoryItems;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skills")
    TArray<FName> SelectedSkills;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Kip")
    FEmberfallKipState KipState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Save")
    FEmberfallSaveSettings Settings;

    UFUNCTION(BlueprintPure, Category="Save")
    bool IsSupportedVersion() const
    {
        return SaveVersion > 0 && SaveVersion <= CurrentSaveVersion;
    }

    UFUNCTION(BlueprintCallable, Category="Save")
    void ResetToDefaults()
    {
        SaveVersion = CurrentSaveVersion;
        Progression = FEmberfallProgressionState();
        EquippedItems.Reset();
        InventoryItems.Reset();
        SelectedSkills.Reset();
        KipState = FEmberfallKipState();
        Settings = FEmberfallSaveSettings();
    }
};
