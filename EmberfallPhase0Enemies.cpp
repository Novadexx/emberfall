#include "AI/EmberfallPhase0Enemies.h"

#include "Kismet/GameplayStatics.h"

AEmberfallTunneler::AEmberfallTunneler()
{
    EnemyId = TEXT("Buried.Tunneler");
    Health.Maximum = 45.0f;
    AttackDamage = 10.0f;
    RepositionCooldown.TryStart(3.0f);
}

void AEmberfallTunneler::OnCombatUpdate(const float DeltaSeconds)
{
    RepositionCooldown.Advance(DeltaSeconds);
    ACharacter* Player = UGameplayStatics::GetPlayerCharacter(this, 0);
    if (Player == nullptr || IsDead() || !RepositionCooldown.IsReady())
    {
        return;
    }

    const FVector ToPlayer = Player->GetActorLocation() - GetActorLocation();
    if (ToPlayer.SizeSquared2D() < FMath::Square(350.0f))
    {
        return;
    }

    SetActorLocation(Player->GetActorLocation() - ToPlayer.GetSafeNormal2D() * 220.0f, true);
    RepositionCooldown.TryStart(6.0f);
    OnTunnelerEmerged();
}

AEmberfallLanternman::AEmberfallLanternman()
{
    EnemyId = TEXT("Buried.Lanternman");
    Health.Maximum = 35.0f;
    AttackDamage = 4.0f;
    AttackInterval = 1.75f;
    EmpowerCooldown.TryStart(1.0f);
}

void AEmberfallLanternman::OnCombatUpdate(const float DeltaSeconds)
{
    EmpowerCooldown.Advance(DeltaSeconds);
    if (IsDead() || !EmpowerCooldown.IsReady())
    {
        return;
    }

    int32 EmpoweredCount = 0;
    TArray<AActor*> NearbyActors;
    UGameplayStatics::GetAllActorsOfClass(this, AEmberfallEnemyBase::StaticClass(), NearbyActors);
    for (AActor* Actor : NearbyActors)
    {
        AEmberfallEnemyBase* Enemy = Cast<AEmberfallEnemyBase>(Actor);
        if (Enemy != nullptr && Enemy != this && !Enemy->IsDead() &&
            FVector::DistSquared2D(GetActorLocation(), Enemy->GetActorLocation()) <= FMath::Square(600.0f))
        {
            Enemy->ApplyAttackEmpowerment(1.35f, 3.0f);
            ++EmpoweredCount;
        }
    }
    EmpowerCooldown.TryStart(5.0f);
    OnLanternmanEmpowered(EmpoweredCount);
}

AEmberfallCrystalBrute::AEmberfallCrystalBrute()
{
    EnemyId = TEXT("Buried.CrystalBrute");
    Health.Maximum = 180.0f;
    AttackDamage = 22.0f;
    AttackRange = 160.0f;
    AttackInterval = 2.0f;
}

float AEmberfallCrystalBrute::TakeDamage(const float DamageAmount, FDamageEvent const& DamageEvent,
    AController* EventInstigator, AActor* DamageCauser)
{
    if (IsDead())
    {
        return 0.0f;
    }

    const float MitigatedDamage = bCrystalArmorBroken ? DamageAmount : DamageAmount * 0.45f;
    const float AppliedDamage = Super::TakeDamage(MitigatedDamage, DamageEvent, EventInstigator, DamageCauser);
    if (!bCrystalArmorBroken && Health.Current <= Health.Maximum * 0.5f)
    {
        bCrystalArmorBroken = true;
        OnCrystalArmorBroken();
    }
    return AppliedDamage;
}

AEmberfallBuriedForeman::AEmberfallBuriedForeman()
{
    EnemyId = TEXT("Buried.Foreman");
    Health.Maximum = 260.0f;
    AttackDamage = 18.0f;
    AttackRange = 180.0f;
    AttackInterval = 1.5f;
    CommandCooldown.TryStart(2.0f);
}

void AEmberfallBuriedForeman::OnCombatUpdate(const float DeltaSeconds)
{
    CommandCooldown.Advance(DeltaSeconds);
    if (IsDead() || !CommandCooldown.IsReady())
    {
        return;
    }

    TArray<AActor*> NearbyActors;
    UGameplayStatics::GetAllActorsOfClass(this, AEmberfallEnemyBase::StaticClass(), NearbyActors);
    for (AActor* Actor : NearbyActors)
    {
        AEmberfallEnemyBase* Enemy = Cast<AEmberfallEnemyBase>(Actor);
        if (Enemy != nullptr && Enemy != this && !Enemy->IsDead() &&
            FVector::DistSquared2D(GetActorLocation(), Enemy->GetActorLocation()) <= FMath::Square(700.0f))
        {
            Enemy->ApplyAttackEmpowerment(1.2f, 4.0f);
        }
    }
    CommandCooldown.TryStart(7.0f);
}

AEmberfallLastForeman::AEmberfallLastForeman()
{
    EnemyId = TEXT("Boss.LastForeman");
    Health.Maximum = 1200.0f;
    AttackDamage = 30.0f;
    AttackRange = 220.0f;
    AttackInterval = 1.0f;
    MaximumBossPhase = 5;
}

float AEmberfallLastForeman::TakeDamage(const float DamageAmount, FDamageEvent const& DamageEvent,
    AController* EventInstigator, AActor* DamageCauser)
{
    const float AppliedDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
    const float HealthFraction = Health.Maximum > 0.0f ? Health.Current / Health.Maximum : 0.0f;
    const int32 NewPhase = FMath::Clamp(1 + FMath::FloorToInt((1.0f - HealthFraction) * MaximumBossPhase), 1, MaximumBossPhase);
    while (BossPhase < NewPhase)
    {
        AdvanceBossPhase();
    }
    return AppliedDamage;
}

void AEmberfallLastForeman::AdvanceBossPhase()
{
    BossPhase = FMath::Clamp(BossPhase + 1, 1, FMath::Max(1, MaximumBossPhase));
    OnBossPhaseChanged(BossPhase);
}

void AEmberfallLastForeman::OnCombatUpdate(const float DeltaSeconds)
{
    if (IsDead())
    {
        return;
    }

    const float HealthFraction = Health.Maximum > 0.0f ? Health.Current / Health.Maximum : 0.0f;
    const int32 NewPhase = FMath::Clamp(1 + FMath::FloorToInt((1.0f - HealthFraction) * MaximumBossPhase), 1, MaximumBossPhase);
    while (BossPhase < NewPhase)
    {
        AdvanceBossPhase();
    }
}
