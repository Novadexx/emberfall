#include "AI/EmberfallEnemyBase.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AEmberfallEnemyBase::AEmberfallEnemyBase()
{
    PrimaryActorTick.bCanEverTick = true;
    Health.Maximum = 50.0f;
    Health.Current = Health.Maximum;
    GetCharacterMovement()->bOrientRotationToMovement = true;
}

void AEmberfallEnemyBase::BeginPlay()
{
    Super::BeginPlay();
    Health.Reset();
    AttackCooldown.Reset();
}

void AEmberfallEnemyBase::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    AttackEmpowermentRemaining = FMath::Max(0.0f, AttackEmpowermentRemaining - DeltaSeconds);
    if (AttackEmpowermentRemaining <= 0.0f)
    {
        AttackEmpowermentMultiplier = 1.0f;
    }
    UpdateCombat(DeltaSeconds);
    OnCombatUpdate(DeltaSeconds);
}

float AEmberfallEnemyBase::TakeDamage(const float DamageAmount, FDamageEvent const& DamageEvent,
    AController* EventInstigator, AActor* DamageCauser)
{
    if (bDeathHandled || DamageAmount <= 0.0f)
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

bool AEmberfallEnemyBase::IsDead() const
{
    return bDeathHandled || Health.IsDead();
}

void AEmberfallEnemyBase::ResetEnemy()
{
    Health.Reset();
    bDeathHandled = false;
    AttackCooldown.Reset();
    AttackEmpowermentMultiplier = 1.0f;
    AttackEmpowermentRemaining = 0.0f;
    SetActorHiddenInGame(false);
    SetActorEnableCollision(true);
    SetActorTickEnabled(true);
}

void AEmberfallEnemyBase::Die()
{
    if (bDeathHandled)
    {
        return;
    }

    bDeathHandled = true;
    GetCharacterMovement()->StopMovementImmediately();
    SetActorEnableCollision(false);
    SetActorTickEnabled(false);
}

void AEmberfallEnemyBase::UpdateCombat(const float DeltaSeconds)
{
    AttackCooldown.Advance(DeltaSeconds);

    ACharacter* Player = UGameplayStatics::GetPlayerCharacter(this, 0);
    if (Player == nullptr || Player->IsPendingKillPending() || Player == this)
    {
        return;
    }

    const FVector ToPlayer = Player->GetActorLocation() - GetActorLocation();
    const float DistanceSquared = ToPlayer.SizeSquared2D();
    const float AttackRangeSquared = FMath::Square(FMath::Max(0.0f, AttackRange));

    if (DistanceSquared > AttackRangeSquared)
    {
        AddMovementInput(ToPlayer.GetSafeNormal2D(), 1.0f);
        return;
    }

    if (AttackCooldown.IsReady())
    {
        UGameplayStatics::ApplyDamage(Player, GetEffectiveAttackDamage(), GetController(), this, nullptr);
        AttackCooldown.TryStart(FMath::Max(0.0f, AttackInterval));
    }
}

void AEmberfallEnemyBase::ApplyAttackEmpowerment(const float DamageMultiplier, const float Duration)
{
    if (DamageMultiplier <= 0.0f || Duration <= 0.0f)
    {
        return;
    }

    AttackEmpowermentMultiplier = FMath::Max(AttackEmpowermentMultiplier, DamageMultiplier);
    AttackEmpowermentRemaining = FMath::Max(AttackEmpowermentRemaining, Duration);
}

float AEmberfallEnemyBase::GetEffectiveAttackDamage() const
{
    return AttackDamage * (AttackEmpowermentRemaining > 0.0f ? AttackEmpowermentMultiplier : 1.0f);
}
