#pragma once

#include "CoreMinimal.h"
#include "EmberfallUIState.generated.h"

USTRUCT(BlueprintType)
struct FEmberfallHUDState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    int32 Level = 1;

    UPROPERTY(BlueprintReadOnly)
    float Health = 100.0f;

    UPROPERTY(BlueprintReadOnly)
    float MaxHealth = 100.0f;

    UPROPERTY(BlueprintReadOnly)
    float Resource = 0.0f;

    UPROPERTY(BlueprintReadOnly)
    float MaxResource = 100.0f;

    UPROPERTY(BlueprintReadOnly)
    int32 Experience = 0;
};

USTRUCT(BlueprintType)
struct FEmberfallInventoryViewState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    TArray<FName> ItemIds;

    UPROPERTY(BlueprintReadOnly)
    FName SelectedItemId;
};

USTRUCT(BlueprintType)
struct FEmberfallKipViewState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    int32 SyncLevel = 1;

    UPROPERTY(BlueprintReadOnly)
    TArray<FName> UnlockedModules;

    UPROPERTY(BlueprintReadOnly)
    FName LastReaction;
};

