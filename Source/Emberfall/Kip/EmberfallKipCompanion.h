#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kip/EmberfallKipTypes.h"
#include "Items/EmberfallItemPickup.h"
#include "EmberfallKipCompanion.generated.h"

UCLASS()
class EMBERFALL_API AEmberfallKipCompanion : public AActor
{
    GENERATED_BODY()

public:
    AEmberfallKipCompanion();

    virtual void Tick(float DeltaSeconds) override;

    UFUNCTION(BlueprintCallable, Category="Emberfall|Kip")
    void ReactToElite();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Kip")
    void ReactToSecret();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Kip")
    int32 CollectNearbyItems(float Radius = 260.0f);

    UFUNCTION(BlueprintPure, Category="Emberfall|Kip")
    FName IdentifyItem(const FName ItemId) const;

    UFUNCTION(BlueprintCallable, Category="Emberfall|Kip")
    bool UpgradeModule(EEmberfallKipModule Module);

    UFUNCTION(BlueprintPure, Category="Emberfall|Kip")
    FText GetContextualDialogue() const;

    UFUNCTION(BlueprintImplementableEvent, Category="Emberfall|Kip|Presentation")
    void OnModuleUpgraded(EEmberfallKipModule Module);

    UFUNCTION(BlueprintPure, Category="Emberfall|Kip")
    FName GetLastReaction() const { return LastReaction; }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Emberfall|Kip")
    FEmberfallKipState State;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Emberfall|Kip")
    float FollowDistance = 180.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Emberfall|Kip")
    float FollowHeight = 90.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Emberfall|Kip")
    TArray<FText> ContextualDialogue;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere)
    class UPointLightComponent* CompanionLight;

    FName LastReaction;
};
