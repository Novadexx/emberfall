#include "Save/EmberfallSaveLibrary.h"

#include "Emberfall.h"
#include "Kismet/GameplayStatics.h"

const FString UEmberfallSaveLibrary::DefaultSlotName = TEXT("EmberfallProfile");

bool UEmberfallSaveLibrary::SaveProfile(const UEmberfallSaveGame* SaveGame, const int32 UserIndex)
{
    if (SaveGame == nullptr || !SaveGame->IsSupportedVersion())
    {
        UE_LOG(LogEmberfall, Warning, TEXT("Save rejected: missing or unsupported save version."));
        return false;
    }

    return UGameplayStatics::SaveGameToSlot(SaveGame, DefaultSlotName, UserIndex);
}

UEmberfallSaveGame* UEmberfallSaveLibrary::LoadProfile(const int32 UserIndex)
{
    if (!UGameplayStatics::DoesSaveGameExist(DefaultSlotName, UserIndex))
    {
        return nullptr;
    }

    USaveGame* LoadedSave = UGameplayStatics::LoadGameFromSlot(DefaultSlotName, UserIndex);
    UEmberfallSaveGame* EmberfallSave = Cast<UEmberfallSaveGame>(LoadedSave);
    if (EmberfallSave == nullptr || !EmberfallSave->IsSupportedVersion())
    {
        UE_LOG(LogEmberfall, Warning, TEXT("Load rejected: save is missing or unsupported."));
        return nullptr;
    }

    return EmberfallSave;
}

