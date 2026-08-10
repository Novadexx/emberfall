#include "UI/EmberfallHUD.h"

#include "UI/EmberfallHUDWidget.h"

void AEmberfallHUD::BeginPlay()
{
    Super::BeginPlay();

    if (HUDWidgetClass != nullptr)
    {
        HUDWidget = CreateWidget<UEmberfallHUDWidget>(GetWorld(), HUDWidgetClass);
        if (HUDWidget != nullptr)
        {
            HUDWidget->AddToViewport();
        }
    }
}

