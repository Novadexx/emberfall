#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "EmberfallDebugCheatManager.generated.h"

UCLASS()
class EMBERFALL_API UEmberfallDebugCheatManager : public UCheatManager
{
    GENERATED_BODY()

public:
    UFUNCTION(Exec)
    void EmberfallGrantXP(int32 Amount);

    UFUNCTION(Exec)
    void EmberfallSetLevel(int32 Level);

    UFUNCTION(Exec)
    void EmberfallSpawnWorker();

    UFUNCTION(Exec)
    void EmberfallSpawnBoss();

    UFUNCTION(Exec)
    void EmberfallResetSave();

    UFUNCTION(Exec)
    void EmberfallTeleportToArena();

    UFUNCTION(Exec)
    void EmberfallInvulnerable(bool bEnabled);

    UFUNCTION(Exec)
    void EmberfallGrantItem(const FString& ItemId);

    UFUNCTION(Exec)
    void EmberfallVisualizeHitboxes(bool bEnabled);

    UFUNCTION(Exec)
    void EmberfallDisplayAIState();

    UFUNCTION(Exec)
    void EmberfallDisplayFPS();
};
