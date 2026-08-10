#include "Core/EmberfallPrototypePlayerController.h"

#include "Debug/EmberfallDebugCheatManager.h"

AEmberfallPrototypePlayerController::AEmberfallPrototypePlayerController()
{
    CheatClass = UEmberfallDebugCheatManager::StaticClass();
}
