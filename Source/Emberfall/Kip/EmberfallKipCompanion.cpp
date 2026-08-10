#include "Kip/EmberfallKipCompanion.h"

#include "Components/PointLightComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"

AEmberfallKipCompanion::AEmberfallKipCompanion()
{
    PrimaryActorTick.bCanEverTick = true;

    USceneComponent* SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

    CompanionLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("CompanionLight"));
    CompanionLight->SetupAttachment(RootComponent);
    CompanionLight->Intensity = 900.0f;
    CompanionLight->AttenuationRadius = 650.0f;
    CompanionLight->LightColor = FColor(100, 190, 255);
    CompanionLight->bUseInverseSquaredFalloff = true;
}

void AEmberfallKipCompanion::BeginPlay()
{
    Super::BeginPlay();
    State.SyncLevel = FMath::Max(1, State.SyncLevel);
    if (ContextualDialogue.Num() == 0)
    {
        ContextualDialogue = {
            FText::FromString(TEXT("The stone remembers a different shift.")),
            FText::FromString(TEXT("That light is not from the forge.")),
            FText::FromString(TEXT("Something nearby is still listening."))
        };
    }
}

void AEmberfallKipCompanion::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    ACharacter* Player = UGameplayStatics::GetPlayerCharacter(this, 0);
    if (Player == nullptr)
    {
        return;
    }

    const FVector DesiredLocation = Player->GetActorLocation()
        - Player->GetActorForwardVector() * FollowDistance
        + FVector::UpVector * FollowHeight;
    SetActorLocation(FMath::VInterpTo(GetActorLocation(), DesiredLocation, DeltaSeconds, 6.0f));
}

void AEmberfallKipCompanion::ReactToElite()
{
    LastReaction = TEXT("EliteDetected");
}

void AEmberfallKipCompanion::ReactToSecret()
{
    LastReaction = TEXT("SecretDetected");
}

int32 AEmberfallKipCompanion::CollectNearbyItems(const float Radius)
{
    if (!State.HasModule(EEmberfallKipModule::Collection) || GetWorld() == nullptr)
    {
        return 0;
    }

    TArray<AActor*> Pickups;
    UGameplayStatics::GetAllActorsOfClass(this, AEmberfallItemPickup::StaticClass(), Pickups);
    int32 CollectedCount = 0;
    for (AActor* Actor : Pickups)
    {
        AEmberfallItemPickup* Pickup = Cast<AEmberfallItemPickup>(Actor);
        if (Pickup != nullptr && FVector::DistSquared(GetActorLocation(), Pickup->GetActorLocation()) <= FMath::Square(FMath::Max(0.0f, Radius)) &&
            Pickup->TryPickUp(UGameplayStatics::GetPlayerCharacter(this, 0)))
        {
            ++CollectedCount;
        }
    }
    return CollectedCount;
}

FName AEmberfallKipCompanion::IdentifyItem(const FName ItemId) const
{
    return State.HasModule(EEmberfallKipModule::Insight) ? ItemId : NAME_None;
}

bool AEmberfallKipCompanion::UpgradeModule(const EEmberfallKipModule Module)
{
    if (!State.UnlockModule(Module))
    {
        return false;
    }

    State.SyncLevel = FMath::Max(State.SyncLevel, State.UnlockedModules.Num() + 1);
    CompanionLight->Intensity = 900.0f + State.SyncLevel * 125.0f;
    SetActorScale3D(FVector(1.0f + State.SyncLevel * 0.03f));
    OnModuleUpgraded(Module);
    return true;
}

FText AEmberfallKipCompanion::GetContextualDialogue() const
{
    if (ContextualDialogue.Num() == 0)
    {
        return FText::GetEmpty();
    }

    const int32 Index = FMath::Abs(GetTypeHash(LastReaction)) % ContextualDialogue.Num();
    return ContextualDialogue[Index];
}
