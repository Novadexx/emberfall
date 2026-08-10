#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/EmberfallUIState.h"
#include "EmberfallHUDWidget.generated.h"

UCLASS()
class EMBERFALL_API UEmberfallHUDWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Emberfall|UI")
    void SetHUDState(const FEmberfallHUDState& NewState);

    UFUNCTION(BlueprintPure, Category="Emberfall|UI")
    FEmberfallHUDState GetHUDState() const { return State; }

protected:
    UPROPERTY(BlueprintReadOnly, Category="Emberfall|UI")
    FEmberfallHUDState State;
};
