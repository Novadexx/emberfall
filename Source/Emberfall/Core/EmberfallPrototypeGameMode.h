#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EmberfallPrototypeGameMode.generated.h"

UCLASS()
class EMBERFALL_API AEmberfallPrototypeGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AEmberfallPrototypeGameMode();

protected:
    virtual void BeginPlay() override;
};
