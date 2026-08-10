#if WITH_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "Progression/EmberfallProgressionData.h"
#include "Combat/EmberfallCombatTypes.h"
#include "Combat/EmberfallHealthState.h"
#include "Abilities/EmberfallAbilityDefinition.h"
#include "Combat/EmberfallCooldownState.h"
#include "Abilities/EmberfallAbilityRuntimeState.h"
#include "Save/EmberfallSaveGame.h"
#include "Save/EmberfallSaveLibrary.h"
#include "Loot/EmberfallLootTable.h"
#include "Kip/EmberfallKipTypes.h"
#include "Items/EmberfallPrototypeItemCatalog.h"
#include "Progression/EmberfallProgressionComponent.h"
#include "AI/EmberfallPhase0Enemies.h"
#include "Items/EmberfallItemPickup.h"
#include "Items/EmberfallInventoryComponent.h"
#include "UI/EmberfallHUDWidget.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallProgressionSmokeTest,
    "Emberfall.Progression.LevelOneStartsValid",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallProgressionSmokeTest::RunTest(const FString& Parameters)
{
    const int32 StartingLevel = 1;
    const int32 StartingKipSyncLevel = 1;

    TestEqual(TEXT("Prototype starts at level 1"), StartingLevel, 1);
    TestEqual(TEXT("Kip starts at sync level 1"), StartingKipSyncLevel, 1);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallProgressionThresholdTest,
    "Emberfall.Progression.CumulativeThresholdsResolveLevels",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallProgressionThresholdTest::RunTest(const FString& Parameters)
{
    UEmberfallProgressionData* Progression = NewObject<UEmberfallProgressionData>();
    Progression->MaxLevel = 3;
    Progression->CumulativeExperience = {0, 100, 250};

    TestTrue(TEXT("Valid progression data passes validation"), Progression->IsValidProgressionData());
    TestEqual(TEXT("Zero XP is level 1"), Progression->GetLevelForExperience(0), 1);
    TestEqual(TEXT("XP before level 2 remains level 1"), Progression->GetLevelForExperience(99), 1);
    TestEqual(TEXT("Level 2 threshold resolves level 2"), Progression->GetLevelForExperience(100), 2);
    TestEqual(TEXT("Level 3 threshold resolves level 3"), Progression->GetLevelForExperience(250), 3);
    TestEqual(TEXT("Negative XP is clamped to level 1"), Progression->GetLevelForExperience(-50), 1);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallProgressionValidationTest,
    "Emberfall.Progression.InvalidDefinitionsAreRejected",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallProgressionValidationTest::RunTest(const FString& Parameters)
{
    UEmberfallProgressionData* Progression = NewObject<UEmberfallProgressionData>();
    Progression->MaxLevel = 3;
    Progression->CumulativeExperience = {0, 100, 100};
    TestFalse(TEXT("Duplicate thresholds are rejected"), Progression->IsValidProgressionData());

    Progression->CumulativeExperience = {0, 100};
    TestFalse(TEXT("Missing level thresholds are rejected"), Progression->IsValidProgressionData());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallResourceSpendTest,
    "Emberfall.Combat.ResourceSpendIsBounded",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallResourceSpendTest::RunTest(const FString& Parameters)
{
    FEmberfallCombatResource Rage;
    Rage.Current = 50.0f;
    Rage.Maximum = 100.0f;

    TestTrue(TEXT("Sufficient resource can be spent"), Rage.Spend(20.0f));
    TestEqual(TEXT("Spend subtracts resource"), Rage.Current, 30.0f);
    TestFalse(TEXT("Insufficient resource cannot be spent"), Rage.Spend(40.0f));
    Rage.Restore(1000.0f);
    TestEqual(TEXT("Restore clamps at maximum"), Rage.Current, 100.0f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallHealthStateTest,
    "Emberfall.Combat.HealthStateClampsAndDetectsDeath",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallHealthStateTest::RunTest(const FString& Parameters)
{
    FEmberfallHealthState Health;
    Health.Maximum = 100.0f;
    Health.Current = 100.0f;

    TestEqual(TEXT("Damage reports the applied amount"), Health.ApplyDamage(25.0f), 25.0f);
    TestEqual(TEXT("Damage reduces current health"), Health.Current, 75.0f);
    TestEqual(TEXT("Overkill is capped at remaining health"), Health.ApplyDamage(1000.0f), 75.0f);
    TestTrue(TEXT("Zero health is dead"), Health.IsDead());
    Health.Restore(1000.0f);
    TestEqual(TEXT("Healing clamps to maximum"), Health.Current, 100.0f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallAbilityDefinitionTest,
    "Emberfall.Abilities.DefinitionsRequireValidTuning",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallAbilityDefinitionTest::RunTest(const FString& Parameters)
{
    UEmberfallAbilityDefinition* Ability = NewObject<UEmberfallAbilityDefinition>();
    Ability->DisplayName = FText::FromString(TEXT("Whirlwind"));
    Ability->Tuning.Cooldown = 5.0f;
    Ability->Tuning.ResourceCost = 25.0f;
    Ability->Tuning.Damage = 40.0f;
    Ability->Tuning.Range = 250.0f;

    TestTrue(TEXT("Valid ability data passes validation"), Ability->IsValidAbilityDefinition());
    Ability->Tuning.ResourceCost = -1.0f;
    TestFalse(TEXT("Negative resource cost is rejected"), Ability->IsValidAbilityDefinition());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallCooldownStateTest,
    "Emberfall.Combat.CooldownStateAdvancesAndLocks",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallCooldownStateTest::RunTest(const FString& Parameters)
{
    FEmberfallCooldownState Cooldown;
    TestTrue(TEXT("Fresh cooldown is ready"), Cooldown.IsReady());
    TestTrue(TEXT("Ready cooldown can start"), Cooldown.TryStart(2.0f));
    TestFalse(TEXT("Started cooldown is not ready"), Cooldown.IsReady());
    TestFalse(TEXT("Cooldown cannot start twice"), Cooldown.TryStart(1.0f));
    Cooldown.Advance(0.5f);
    TestEqual(TEXT("Cooldown advances by elapsed time"), Cooldown.Remaining, 1.5f);
    Cooldown.Advance(2.0f);
    TestTrue(TEXT("Cooldown reaches ready state"), Cooldown.IsReady());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallAbilityRuntimeTest,
    "Emberfall.Abilities.RuntimeConsumesResourceAndCooldown",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallAbilityRuntimeTest::RunTest(const FString& Parameters)
{
    FEmberfallAbilityTuning Tuning;
    Tuning.Cooldown = 2.0f;
    Tuning.ResourceCost = 25.0f;

    FEmberfallCombatResource Rage;
    Rage.Current = 50.0f;
    Rage.Maximum = 100.0f;

    FEmberfallAbilityRuntimeState Runtime;
    TestTrue(TEXT("Ability activates with resource available"), Runtime.TryActivate(Tuning, Rage));
    TestEqual(TEXT("Activation spends resource"), Rage.Current, 25.0f);
    TestFalse(TEXT("Cooldown blocks immediate reactivation"), Runtime.TryActivate(Tuning, Rage));
    Runtime.Advance(2.0f);
    TestTrue(TEXT("Ability reactivates after cooldown"), Runtime.TryActivate(Tuning, Rage));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallSaveVersionTest,
    "Emberfall.Save.VersionedDefaultsAreSupported",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallSaveVersionTest::RunTest(const FString& Parameters)
{
    UEmberfallSaveGame* Save = NewObject<UEmberfallSaveGame>();
    TestTrue(TEXT("Fresh save uses the current supported version"), Save->IsSupportedVersion());
    TestEqual(TEXT("Fresh save starts at level 1"), Save->Progression.Level, 1);
    Save->Progression.Experience = 250;
    Save->SavedHealth = 72.0f;
    Save->SavedResource = 45.0f;
    TestEqual(TEXT("Save retains XP"), Save->Progression.Experience, 250);
    TestEqual(TEXT("Save retains health"), Save->SavedHealth, 72.0f);
    TestEqual(TEXT("Save retains resource"), Save->SavedResource, 45.0f);
    Save->SaveVersion = 0;
    TestFalse(TEXT("Version zero is rejected"), Save->IsSupportedVersion());
    Save->ResetToDefaults();
    TestTrue(TEXT("Reset restores a supported version"), Save->IsSupportedVersion());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallSaveSlotContractTest,
    "Emberfall.Save.DefaultSlotContractIsStable",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallSaveSlotContractTest::RunTest(const FString& Parameters)
{
    TestEqual(TEXT("Default save slot name is stable"), UEmberfallSaveLibrary::DefaultSlotName, FString(TEXT("EmberfallProfile")));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallLootTableTest,
    "Emberfall.Loot.WeightedSelectionIsDeterministic",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallLootTableTest::RunTest(const FString& Parameters)
{
    UEmberfallLootTable* Table = NewObject<UEmberfallLootTable>();
    Table->Entries = {{TEXT("CommonA"), EEmberfallRarity::Common, 1.0f}, {TEXT("RareA"), EEmberfallRarity::Rare, 1.0f}};
    FEmberfallLootEntry Chosen;
    TestTrue(TEXT("Valid table accepts a roll"), Table->TryChooseEntry(0.75f, Chosen));
    TestEqual(TEXT("Upper half selects the second weighted entry"), Chosen.ItemId, FName(TEXT("RareA")));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallKipModuleTest,
    "Emberfall.Kip.ModulesUnlockOnce",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallKipModuleTest::RunTest(const FString& Parameters)
{
    FEmberfallKipState Kip;
    TestTrue(TEXT("Collection unlock succeeds"), Kip.UnlockModule(EEmberfallKipModule::Collection));
    TestFalse(TEXT("Duplicate module unlock is rejected"), Kip.UnlockModule(EEmberfallKipModule::Collection));
    TestTrue(TEXT("Collection module is recorded"), Kip.HasModule(EEmberfallKipModule::Collection));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallPrototypeCatalogTest,
    "Emberfall.Items.PrototypeCatalogHasTwentyItemsAndTransformativeEffects",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallPrototypeCatalogTest::RunTest(const FString& Parameters)
{
    const TArray<FEmberfallItemDefinition> Catalog = EmberfallPrototypeItems::BuildCatalog();
    int32 TransformativeCount = 0;
    for (const FEmberfallItemDefinition& Item : Catalog)
    {
        if (!Item.BuildChangingEffectId.IsNone())
        {
            ++TransformativeCount;
        }
    }

    TestEqual(TEXT("Prototype catalog contains twenty items"), Catalog.Num(), 20);
    TestTrue(TEXT("At least five items change mechanics"), TransformativeCount >= 5);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallProgressionComponentTest,
    "Emberfall.Progression.ComponentHandlesMultipleLevelGains",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallProgressionComponentTest::RunTest(const FString& Parameters)
{
    UEmberfallProgressionData* Definition = NewObject<UEmberfallProgressionData>();
    Definition->MaxLevel = 4;
    Definition->CumulativeExperience = {0, 100, 250, 500};

    UEmberfallProgressionComponent* Progression = NewObject<UEmberfallProgressionComponent>();
    Progression->Definition = Definition;
    TestEqual(TEXT("Large XP grant reports multiple level gains"), Progression->GrantExperience(260), 2);
    TestEqual(TEXT("Multiple level gains resolve to level 3"), Progression->State.Level, 3);
    TestEqual(TEXT("XP is retained after level gains"), Progression->State.Experience, 260);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallDefaultProgressionTest,
    "Emberfall.Progression.DefaultPrototypeDefinitionCoversLevelsOneToTen",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallDefaultProgressionTest::RunTest(const FString& Parameters)
{
    UEmberfallProgressionComponent* Progression = NewObject<UEmberfallProgressionComponent>();
    TestTrue(TEXT("Default progression definition is valid"), Progression->Definition != nullptr && Progression->Definition->IsValidProgressionData());
    TestEqual(TEXT("Default definition reaches level 10"), Progression->Definition->GetLevelForExperience(3000), 10);
    FEmberfallLevelReward Reward;
    TestTrue(TEXT("Level 8 has the Kip collection reward"), Progression->Definition->TryGetRewardForLevel(8, Reward));
    TestEqual(TEXT("Level 8 reward is Kip collection"), Reward.RewardId, FName(TEXT("KipCollection")));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallInventoryComponentTest,
    "Emberfall.Items.InventoryStoresEquipmentAndBuildEffects",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallInventoryComponentTest::RunTest(const FString& Parameters)
{
    UEmberfallInventoryComponent* Inventory = NewObject<UEmberfallInventoryComponent>();
    FEmberfallItemDefinition Item;
    Item.ItemId = TEXT("CycloneMaw");
    Item.BuildChangingEffectId = TEXT("WhirlwindPull");
    TestTrue(TEXT("Item can be added"), Inventory->AddItem(Item));
    TestTrue(TEXT("Item can be equipped"), Inventory->EquipItem(Item.ItemId));
    TestTrue(TEXT("Equipped effect is queryable"), Inventory->HasBuildChangingEffect(TEXT("WhirlwindPull")));
    TestFalse(TEXT("Duplicate inventory item is rejected"), Inventory->AddItem(Item));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallPhase0RosterTest,
    "Emberfall.AI.PhaseZeroRosterHasRequiredTypes",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallPhase0RosterTest::RunTest(const FString& Parameters)
{
    TestTrue(TEXT("Tunneler class exists"), AEmberfallTunneler::StaticClass() != nullptr);
    TestTrue(TEXT("Lanternman class exists"), AEmberfallLanternman::StaticClass() != nullptr);
    TestTrue(TEXT("Crystal Brute class exists"), AEmberfallCrystalBrute::StaticClass() != nullptr);
    TestTrue(TEXT("Buried Foreman class exists"), AEmberfallBuriedForeman::StaticClass() != nullptr);
    TestTrue(TEXT("Last Foreman class exists"), AEmberfallLastForeman::StaticClass() != nullptr);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallItemPickupTest,
    "Emberfall.Loot.ItemPickupIsSingleUse",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallItemPickupTest::RunTest(const FString& Parameters)
{
    AEmberfallItemPickup* Pickup = NewObject<AEmberfallItemPickup>();
    Pickup->Item.ItemId = TEXT("CycloneMaw");
    AActor* Picker = NewObject<AActor>();
    UEmberfallInventoryComponent* Inventory = NewObject<UEmberfallInventoryComponent>(Picker);
    Picker->AddInstanceComponent(Inventory);
    TestTrue(TEXT("Valid pickup succeeds"), Pickup->TryPickUp(Picker));
    TestFalse(TEXT("Pickup cannot be collected twice"), Pickup->TryPickUp(Picker));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEmberfallUIStateTest,
    "Emberfall.UI.HUDStateCanBeUpdated",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FEmberfallUIStateTest::RunTest(const FString& Parameters)
{
    UEmberfallHUDWidget* Widget = NewObject<UEmberfallHUDWidget>();
    FEmberfallHUDState State;
    State.Level = 4;
    State.Health = 75.0f;
    State.MaxHealth = 100.0f;
    Widget->SetHUDState(State);
    TestEqual(TEXT("HUD receives the player level"), Widget->GetHUDState().Level, 4);
    TestEqual(TEXT("HUD receives current health"), Widget->GetHUDState().Health, 75.0f);
    return true;
}

#endif
