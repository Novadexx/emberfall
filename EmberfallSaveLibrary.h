#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Save/EmberfallSaveGame.h"
#include "EmberfallSaveLibrary.generated.h"

UCLASS()
class EMBERFALL_API UEmberfallSaveLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    static const FString DefaultSlotName;

    UFUNCTION(BlueprintCallable, Category="Emberfall|Save")
    static bool SaveProfile(const UEmberfallSaveGame* SaveGame, int32 UserIndex = 0);

    UFUNCTION(BlueprintCallable, Category="Emberfall|Save")
    static UEmberfallSaveGame* LoadProfile(int32 UserIndex = 0);
};

