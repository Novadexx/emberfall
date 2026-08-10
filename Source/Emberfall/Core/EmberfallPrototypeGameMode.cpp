#include "Core/EmberfallPrototypeGameMode.h"

#include "Character/EmberfallBerserkerCharacter.h"
#include "AI/EmberfallBuriedWorker.h"
#include "Debug/EmberfallDebugCheatManager.h"
#include "UI/EmberfallHUD.h"
#include "Kip/EmberfallKipCompanion.h"
#include "Core/EmberfallPrototypePlayerController.h"
#include "Kismet/GameplayStatics.h"

AEmberfallPrototypeGameMode::AEmberfallPrototypeGameMode()
{
    DefaultPawnClass = AEmberfallBerserkerCharacter::StaticClass();
    HUDClass = AEmberfallHUD::StaticClass();
    PlayerControllerClass = AEmberfallPrototypePlayerController::StaticClass();
}

void AEmberfallPrototypeGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld() != nullptr)
    {
        if (AEmberfallBerserkerCharacter* Player = Cast<AEmberfallBerserkerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0)))
        {
            if (AEmberfallKipCompanion* ExistingKip = Cast<AEmberfallKipCompanion>(UGameplayStatics::GetActorOfClass(GetWorld(), AEmberfallKipCompanion::StaticClass())))
            {
                Player->SetKipCompanion(ExistingKip);
            }
            else
            {
                FActorSpawnParameters KipSpawnParameters;
                KipSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
                AEmberfallKipCompanion* Kip = GetWorld()->SpawnActor<AEmberfallKipCompanion>(
                    AEmberfallKipCompanion::StaticClass(), Player->GetActorLocation() + FVector(0.0f, 0.0f, 90.0f),
                    FRotator::ZeroRotator, KipSpawnParameters);
                Player->SetKipCompanion(Kip);
            }
        }
    }

    if (GetWorld() == nullptr || UGameplayStatics::GetActorOfClass(GetWorld(), AEmberfallBuriedWorker::StaticClass()) != nullptr)
    {
        return;
    }

    FActorSpawnParameters SpawnParameters;
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
    GetWorld()->SpawnActor<AEmberfallBuriedWorker>(
        AEmberfallBuriedWorker::StaticClass(),
        FVector(300.0f, 0.0f, 100.0f),
        FRotator::ZeroRotator,
        SpawnParameters);
}
