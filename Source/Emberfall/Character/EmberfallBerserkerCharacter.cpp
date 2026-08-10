#include "Character/EmberfallBerserkerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "TimerManager.h"
#include "DrawDebugHelpers.h"
#include "Save/EmberfallSaveGame.h"
#include "Save/EmberfallSaveLibrary.h"

AEmberfallBerserkerCharacter::AEmberfallBerserkerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    Progression = CreateDefaultSubobject<UEmberfallProgressionComponent>(TEXT("Progression"));
    Inventory = CreateDefaultSubobject<UEmberfallInventoryComponent>(TEXT("Inventory"));

    Health.Maximum = 100.0f;
    Health.Current = Health.Maximum;
    Rage.Type = EEmberfallResourceType::Rage;
    Rage.Maximum = 100.0f;
    Rage.Current = 0.0f;

    BasicAttackTuning.Cooldown = 0.45f;
    BasicAttackTuning.Damage = 10.0f;
    BasicAttackTuning.Range = 150.0f;

    DodgeTuning.Cooldown = 0.8f;
    DodgeTuning.ResourceCost = 20.0f;
    DodgeTuning.Range = 350.0f;

    WhirlwindTuning.Cooldown = 5.0f;
    WhirlwindTuning.ResourceCost = 25.0f;
    WhirlwindTuning.Damage = 24.0f;
    WhirlwindTuning.Range = 300.0f;

    LeapTuning.Cooldown = 4.0f;
    LeapTuning.ResourceCost = 20.0f;
    LeapTuning.Damage = 42.0f;
    LeapTuning.Range = 500.0f;

    GroundbreakerTuning.Cooldown = 6.0f;
    GroundbreakerTuning.ResourceCost = 30.0f;
    GroundbreakerTuning.Damage = 58.0f;
    GroundbreakerTuning.Range = 260.0f;

    WarCryTuning.Cooldown = 12.0f;
    WarCryTuning.ResourceCost = 25.0f;
    WarCryTuning.Range = 450.0f;

    bUseControllerRotationYaw = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 900.0f;
    CameraBoom->SetRelativeRotation(FRotator(-55.0f, 0.0f, 0.0f));
    CameraBoom->bDoCollisionTest = false;

    IsometricCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("IsometricCamera"));
    IsometricCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    IsometricCamera->bUsePawnControlRotation = false;
}

void AEmberfallBerserkerCharacter::BeginPlay()
{
    Super::BeginPlay();
    Health.Reset();
}

void AEmberfallBerserkerCharacter::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    BasicAttackRuntime.Advance(DeltaSeconds);
    DodgeRuntime.Advance(DeltaSeconds);
    WhirlwindRuntime.Advance(DeltaSeconds);
    LeapRuntime.Advance(DeltaSeconds);
    GroundbreakerRuntime.Advance(DeltaSeconds);
    WarCryRuntime.Advance(DeltaSeconds);
    WarCryRemaining = FMath::Max(0.0f, WarCryRemaining - DeltaSeconds);
}

void AEmberfallBerserkerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AEmberfallBerserkerCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AEmberfallBerserkerCharacter::MoveRight);
    PlayerInputComponent->BindAction(TEXT("BasicAttack"), IE_Pressed, this, &AEmberfallBerserkerCharacter::InputBasicAttack);
    PlayerInputComponent->BindAction(TEXT("Dodge"), IE_Pressed, this, &AEmberfallBerserkerCharacter::InputDodge);
    PlayerInputComponent->BindAction(TEXT("Whirlwind"), IE_Pressed, this, &AEmberfallBerserkerCharacter::InputWhirlwind);
    PlayerInputComponent->BindAction(TEXT("Leap"), IE_Pressed, this, &AEmberfallBerserkerCharacter::InputLeap);
    PlayerInputComponent->BindAction(TEXT("Groundbreaker"), IE_Pressed, this, &AEmberfallBerserkerCharacter::InputGroundbreaker);
    PlayerInputComponent->BindAction(TEXT("WarCry"), IE_Pressed, this, &AEmberfallBerserkerCharacter::InputWarCry);
}

void AEmberfallBerserkerCharacter::MoveForward(const float AxisValue)
{
    Move(FVector2D(0.0f, AxisValue));
}

void AEmberfallBerserkerCharacter::MoveRight(const float AxisValue)
{
    Move(FVector2D(AxisValue, 0.0f));
}

void AEmberfallBerserkerCharacter::InputBasicAttack()
{
    TryBasicAttack();
}

void AEmberfallBerserkerCharacter::InputDodge()
{
    const FVector InputDirection = GetLastMovementInputVector().GetSafeNormal2D();
    TryDodge(InputDirection.IsNearlyZero() ? GetActorForwardVector() : InputDirection);
}

void AEmberfallBerserkerCharacter::InputWhirlwind()
{
    TryWhirlwind();
}

void AEmberfallBerserkerCharacter::InputLeap()
{
    const FVector InputDirection = GetLastMovementInputVector().GetSafeNormal2D();
    TryLeap(InputDirection.IsNearlyZero() ? GetActorForwardVector() : InputDirection);
}

void AEmberfallBerserkerCharacter::InputGroundbreaker()
{
    TryGroundbreaker();
}

void AEmberfallBerserkerCharacter::InputWarCry()
{
    TryWarCry();
}

float AEmberfallBerserkerCharacter::TakeDamage(const float DamageAmount, FDamageEvent const& DamageEvent,
    AController* EventInstigator, AActor* DamageCauser)
{
    if (bDeathHandled || bInvulnerable || DamageAmount <= 0.0f)
    {
        return 0.0f;
    }

    const float AppliedDamage = Health.ApplyDamage(DamageAmount);
    if (Health.IsDead())
    {
        Die();
    }

    return AppliedDamage;
}

void AEmberfallBerserkerCharacter::Move(const FVector2D& Input)
{
    if (bDeathHandled || Controller == nullptr)
    {
        return;
    }

    const FRotator ControlRotation = Controller->GetControlRotation();
    const FRotator YawRotation(0.0f, ControlRotation.Yaw, 0.0f);
    const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    AddMovementInput(Forward, Input.Y);
    AddMovementInput(Right, Input.X);
}

bool AEmberfallBerserkerCharacter::TrySpendRage(const float Amount)
{
    return !bDeathHandled && Rage.Spend(Amount);
}

bool AEmberfallBerserkerCharacter::TryBasicAttack()
{
    if (bDeathHandled || !BasicAttackRuntime.TryActivate(BasicAttackTuning, Rage))
    {
        return false;
    }

    ExecuteBasicAttack();
    return true;
}

bool AEmberfallBerserkerCharacter::TryDodge(const FVector& Direction)
{
    if (bDeathHandled || Direction.IsNearlyZero() || !DodgeRuntime.TryActivate(DodgeTuning, Rage))
    {
        return false;
    }

    const FVector SafeDirection = Direction.GetSafeNormal2D();
    LaunchCharacter(SafeDirection * DodgeTuning.Range, true, true);
    if (HasEquippedEffect(TEXT("DodgeBurnTrail")))
    {
        OnBuildChangingEffectTriggered(TEXT("DodgeBurnTrail"));
    }
    return true;
}

bool AEmberfallBerserkerCharacter::TryWhirlwind()
{
    if (bDeathHandled || !WhirlwindRuntime.TryActivate(WhirlwindTuning, Rage))
    {
        return false;
    }

    const bool bHasPullEffect = HasEquippedEffect(TEXT("WhirlwindPull"));
    const float Radius = bHasPullEffect ? WhirlwindTuning.Range * 1.25f : WhirlwindTuning.Range;
    const int32 HitCount = ExecuteAreaAttack(EEmberfallAbilityId::Whirlwind, GetActorLocation(), Radius, WhirlwindTuning.Damage);
    if (bHasPullEffect)
    {
        OnBuildChangingEffectTriggered(TEXT("WhirlwindPull"));
    }
    OnAbilityActivated(EEmberfallAbilityId::Whirlwind);
    OnAbilityHit(EEmberfallAbilityId::Whirlwind, HitCount);
    return true;
}

bool AEmberfallBerserkerCharacter::TryLeap(const FVector& TargetDirection)
{
    if (bDeathHandled || TargetDirection.IsNearlyZero() || !LeapRuntime.TryActivate(LeapTuning, Rage))
    {
        return false;
    }

    const FVector Direction = TargetDirection.GetSafeNormal2D();
    PendingLeapImpactLocation = GetActorLocation() + Direction * LeapTuning.Range;
    LaunchCharacter(Direction * LeapTuning.Range + FVector(0.0f, 0.0f, 260.0f), true, true);
    OnAbilityActivated(EEmberfallAbilityId::Leap);

    if (GetWorld() != nullptr)
    {
        GetWorld()->GetTimerManager().SetTimer(LeapImpactTimer, this, &AEmberfallBerserkerCharacter::ExecuteLeapImpact, 0.35f, false);
    }
    return true;
}

bool AEmberfallBerserkerCharacter::TryGroundbreaker()
{
    if (bDeathHandled || !GroundbreakerRuntime.TryActivate(GroundbreakerTuning, Rage))
    {
        return false;
    }

    const int32 HitCount = ExecuteAreaAttack(EEmberfallAbilityId::Groundbreaker, GetActorLocation(), GroundbreakerTuning.Range, GroundbreakerTuning.Damage);
    if (HasEquippedEffect(TEXT("GroundbreakerShockwave")))
    {
        ExecuteAreaAttack(EEmberfallAbilityId::Groundbreaker,
            GetActorLocation() + GetActorForwardVector() * GroundbreakerTuning.Range * 0.75f,
            GroundbreakerTuning.Range * 0.65f, GroundbreakerTuning.Damage * 0.5f);
        OnBuildChangingEffectTriggered(TEXT("GroundbreakerShockwave"));
    }
    OnAbilityActivated(EEmberfallAbilityId::Groundbreaker);
    OnAbilityHit(EEmberfallAbilityId::Groundbreaker, HitCount);
    return true;
}

bool AEmberfallBerserkerCharacter::TryWarCry()
{
    if (bDeathHandled || !WarCryRuntime.TryActivate(WarCryTuning, Rage))
    {
        return false;
    }

    WarCryRemaining = 6.0f;
    RestoreRage(10.0f);
    OnAbilityActivated(EEmberfallAbilityId::WarCry);
    return true;
}

void AEmberfallBerserkerCharacter::RestoreRage(const float Amount)
{
    if (!bDeathHandled)
    {
        Rage.Restore(Amount);
    }
}

void AEmberfallBerserkerCharacter::ResetAfterDeath()
{
    Health.Reset();
    Rage.Current = 0.0f;
    BasicAttackRuntime.Reset();
    DodgeRuntime.Reset();
    WhirlwindRuntime.Reset();
    LeapRuntime.Reset();
    GroundbreakerRuntime.Reset();
    WarCryRuntime.Reset();
    WarCryRemaining = 0.0f;
    PendingLeapImpactLocation = FVector::ZeroVector;
    bDeathHandled = false;
}

bool AEmberfallBerserkerCharacter::SaveProfile()
{
    UEmberfallSaveGame* SaveGame = NewObject<UEmberfallSaveGame>();
    if (SaveGame == nullptr)
    {
        return false;
    }

    if (Progression != nullptr)
    {
        SaveGame->Progression = Progression->State;
    }
    if (Inventory != nullptr)
    {
        SaveGame->InventoryItems = Inventory->InventoryItems;
        SaveGame->EquippedItems = Inventory->EquippedItems;
    }
    if (KipCompanion != nullptr)
    {
        SaveGame->KipState = KipCompanion->State;
    }
    SaveGame->SavedHealth = Health.Current;
    SaveGame->SavedResource = Rage.Current;
    return UEmberfallSaveLibrary::SaveProfile(SaveGame);
}

bool AEmberfallBerserkerCharacter::LoadProfile()
{
    UEmberfallSaveGame* SaveGame = UEmberfallSaveLibrary::LoadProfile();
    if (SaveGame == nullptr)
    {
        return false;
    }

    if (Progression != nullptr)
    {
        Progression->State = SaveGame->Progression;
    }
    if (Inventory != nullptr)
    {
        Inventory->InventoryItems = SaveGame->InventoryItems;
        Inventory->EquippedItems = SaveGame->EquippedItems;
    }
    if (KipCompanion != nullptr)
    {
        KipCompanion->State = SaveGame->KipState;
    }
    Health.Current = FMath::Clamp(SaveGame->SavedHealth, 0.0f, Health.Maximum);
    Rage.Current = FMath::Clamp(SaveGame->SavedResource, 0.0f, Rage.Maximum);
    bDeathHandled = Health.IsDead();
    return true;
}

bool AEmberfallBerserkerCharacter::IsDead() const
{
    return bDeathHandled || Health.IsDead();
}

void AEmberfallBerserkerCharacter::ExecuteBasicAttack()
{
    const FVector Forward = GetActorForwardVector().GetSafeNormal2D();
    const FVector QueryOrigin = GetActorLocation() + Forward * (BasicAttackTuning.Range * 0.5f);
    LastBasicAttackHitCount = ExecuteAreaAttack(EEmberfallAbilityId::BasicAttack, QueryOrigin, BasicAttackTuning.Range * 0.5f, BasicAttackTuning.Damage);
    if (HasEquippedEffect(TEXT("CriticalEcho")) && LastBasicAttackHitCount > 0)
    {
        OnBuildChangingEffectTriggered(TEXT("CriticalEcho"));
    }
    OnAbilityActivated(EEmberfallAbilityId::BasicAttack);
    OnAbilityHit(EEmberfallAbilityId::BasicAttack, LastBasicAttackHitCount);
}

void AEmberfallBerserkerCharacter::ExecuteLeapImpact()
{
    if (bDeathHandled)
    {
        return;
    }

    const int32 HitCount = ExecuteAreaAttack(EEmberfallAbilityId::Leap, PendingLeapImpactLocation, LeapTuning.Range * 0.45f, LeapTuning.Damage);
    OnAbilityHit(EEmberfallAbilityId::Leap, HitCount);
}

int32 AEmberfallBerserkerCharacter::ExecuteAreaAttack(const EEmberfallAbilityId AbilityId, const FVector& Origin, const float Radius, const float Damage)
{
    if (GetWorld() == nullptr || Radius <= 0.0f || Damage <= 0.0f)
    {
        return 0;
    }

    const FCollisionShape QueryShape = FCollisionShape::MakeSphere(Radius);
    if (bVisualizeHitboxes)
    {
        DrawDebugSphere(GetWorld(), Origin, Radius, 24, FColor::Orange, false, 0.25f, 0, 2.0f);
    }
    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(EmberfallAbility), false, this);
    TArray<FOverlapResult> Overlaps;
    if (!GetWorld()->OverlapMultiByObjectType(Overlaps, Origin, FQuat::Identity,
        FCollisionObjectQueryParams(ECC_Pawn), QueryShape, QueryParams))
    {
        return 0;
    }

    const float DamageMultiplier = WarCryRemaining > 0.0f ? 1.25f : 1.0f;
    TSet<AActor*> DamagedActors;
    int32 HitCount = 0;
    for (const FOverlapResult& Overlap : Overlaps)
    {
        AActor* Target = Overlap.GetActor();
        if (Target == nullptr || Target == this || DamagedActors.Contains(Target))
        {
            continue;
        }

        DamagedActors.Add(Target);
        UGameplayStatics::ApplyDamage(Target, Damage * DamageMultiplier, GetController(), this, nullptr);
        ++HitCount;
    }
    return HitCount;
}

bool AEmberfallBerserkerCharacter::HasEquippedEffect(const FName EffectId) const
{
    return Inventory != nullptr && Inventory->HasBuildChangingEffect(EffectId);
}

void AEmberfallBerserkerCharacter::Die()
{
    if (bDeathHandled)
    {
        return;
    }

    bDeathHandled = true;
    GetCharacterMovement()->StopMovementImmediately();
    DisableInput(nullptr);
}
