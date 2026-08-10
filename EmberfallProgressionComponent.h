#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Progression/EmberfallProgressionData.h"
#include "Progression/EmberfallProgressionTypes.h"
#include "EmberfallProgressionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEmberfallLevelChanged, int32, OldLevel, int32, NewLevel);

UCLASS(ClassGroup=(Emberfall), meta=(BlueprintSpawnableComponent))
class EMBERFALL_API UEmberfallProgressionComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UEmberfallProgressionComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Progression")
    TObjectPtr<UEmberfallProgressionData> Definition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Progression")
    FEmberfallProgressionState State;

    UPROPERTY(BlueprintAssignable, Category="Progression")
    FEmberfallLevelChanged OnLevelChanged;

    UFUNCTION(BlueprintCallable, Category="Progression")
    int32 GrantExperience(int32 Amount);

    UFUNCTION(BlueprintCallable, Category="Progression")
    void SetLevel(int32 NewLevel);

    UFUNCTION(BlueprintPure, Category="Progression")
    int32 GetExperienceRequiredForNextLevel() const;
};

