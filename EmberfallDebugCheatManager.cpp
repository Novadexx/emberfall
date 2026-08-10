#include "Debug/EmberfallDebugCheatManager.h"

#include "AI/EmberfallBuriedWorker.h"
#include "AI/EmberfallPhase0Enemies.h"
#include "Character/EmberfallBerserkerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Save/EmberfallSaveLibrary.h"
#include "Items/EmberfallPrototypeItemCatalog.h"
#include "Engine/Engine.h"
#include "Misc/App.h"

void UEmberfallDebugCheatManager::EmberfallGrantXP(const int32 Amount)
{
    if (AEmberfallBerserkerCharacter* Player = Cast<AEmberfallBerserkerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0)))
    {
        if (Player->Progression != nullptr)
        {
            Player->Progression->GrantExperience(Amount);
        }
    }
}

void UEmberfallDebugCheatManager::EmberfallSetLevel(const int32 Level)
{
    if (AEmberfallBerserkerCharacter* Player = Cast<AEmberfallBerserkerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0)))
    {
        if (Player->Progression != nullptr)
        {
            Player->Progression->SetLevel(Level);
        }
    }
}

void UEmberfallDebugCheatManager::EmberfallSpawnWorker()
{
    if (UWorld* World = GetWorld())
    {
        World->SpawnActor<AEmberfallBuriedWorker>(AEmberfallBuriedWorker::StaticClass(), FVector(300.0f, 0.0f, 100.0f), FRotator::ZeroRotator);
    }
}

void UEmberfallDebugCheatManager::EmberfallSpawnBoss()
{
    if (UWorld* World = GetWorld())
    {
        World->SpawnActor<AEmberfallLastForeman>(AEmberfallLastForeman::StaticClass(), FVector(500.0f, 0.0f, 100.0f), FRotator::ZeroRotator);
    }
}

void UEmberfallDebugCheatManager::EmberfallResetSave()
{
    UGameplayStatics::DeleteGameInSlot(UEmberfallSaveLibrary::DefaultSlotName, 0);
}

void UEmberfallDebugCheatManager::EmberfallTeleportToArena()
{
    if (ACharacter* Player = UGameplayStatics::GetPlayerCharacter(this, 0))
    {
        Player->SetActorLocation(FVector(1200.0f, 0.0f, 100.0f));
    }
}

void UEmberfallDebugCheatManager::EmberfallInvulnerable(const bool bEnabled)
{
    if (AEmberfallBerserkerCharacter* Player = Cast<AEmberfallBerserkerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0)))
    {
        Player->SetInvulnerable(bEnabled);
    }
}

void UEmberfallDebugCheatManager::EmberfallGrantItem(const FString& ItemId)
{
    if (AEmberfallBerserkerCharacter* Player = Cast<AEmberfallBerserkerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0)))
    {
        if (Player->Inventory == nullptr)
        {
            return;
        }

        const FName RequestedId(*ItemId);
        for (const FEmberfallItemDefinition& Item : EmberfallPrototypeItems::BuildCatalog())
        {
            if (Item.ItemId == RequestedId || Item.DisplayName.ToString().Equals(ItemId, ESearchCase::IgnoreCase))
            {
                Player->Inventory->AddItem(Item);
                return;
            }
        }
    }
}

void UEmberfallDebugCheatManager::EmberfallVisualizeHitboxes(const bool bEnabled)
{
    if (AEmberfallBerserkerCharacter* Player = Cast<AEmberfallBerserkerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0)))
    {
        Player->SetVisualizeHitboxes(bEnabled);
    }
}

void UEmberfallDebugCheatManager::EmberfallDisplayAIState()
{
    if (GEngine != nullptr)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, TEXT("Emberfall AI: approach / attack cooldown state active"));
    }
}

void UEmberfallDebugCheatManager::EmberfallDisplayFPS()
{
    if (GEngine != nullptr)
    {
        const float DeltaSeconds = FApp::GetDeltaTime();
        const float FPS = DeltaSeconds > SMALL_NUMBER ? 1.0f / DeltaSeconds : 0.0f;
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("FPS: %.1f"), FPS));
    }
}
