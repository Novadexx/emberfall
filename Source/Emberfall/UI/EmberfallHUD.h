#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EmberfallHUD.generated.h"

UCLASS()
class EMBERFALL_API AEmberfallHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Emberfall|UI")
    TSubclassOf<class UEmberfallHUDWidget> HUDWidgetClass;

private:
    UPROPERTY()
    TObjectPtr<class UEmberfallHUDWidget> HUDWidget;
};

