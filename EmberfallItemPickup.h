#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items/EmberfallItemTypes.h"
#include "EmberfallItemPickup.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEmberfallItemPickedUp, FName, ItemId);

UCLASS()
class EMBERFALL_API AEmberfallItemPickup : public AActor
{
    GENERATED_BODY()

public:
    AEmberfallItemPickup();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Loot")
    bool TryPickUp(AActor* Picker);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Emberfall|Loot")
    FEmberfallItemDefinition Item;

    UPROPERTY(BlueprintAssignable, Category="Emberfall|Loot")
    FEmberfallItemPickedUp OnPickedUp;

private:
    bool bPickedUp = false;
};

