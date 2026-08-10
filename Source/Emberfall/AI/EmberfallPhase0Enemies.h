#pragma once

#include "CoreMinimal.h"
#include "AI/EmberfallEnemyBase.h"
#include "EmberfallPhase0Enemies.generated.h"

UCLASS()
class EMBERFALL_API AEmberfallTunneler : public AEmberfallEnemyBase
{
    GENERATED_BODY()
public:
    AEmberfallTunneler();

    UFUNCTION(BlueprintImplementableEvent, Category="Emberfall|Enemy|Presentation")
    void OnTunnelerEmerged();

protected:
    virtual void OnCombatUpdate(float DeltaSeconds) override;

private:
    FEmberfallCooldownState RepositionCooldown;
};

UCLASS()
class EMBERFALL_API AEmberfallLanternman : public AEmberfallEnemyBase
{
    GENERATED_BODY()
public:
    AEmberfallLanternman();

    UFUNCTION(BlueprintImplementableEvent, Category="Emberfall|Enemy|Presentation")
    void OnLanternmanEmpowered(int32 EmpoweredCount);

protected:
    virtual void OnCombatUpdate(float DeltaSeconds) override;

private:
    FEmberfallCooldownState EmpowerCooldown;
};

UCLASS()
class EMBERFALL_API AEmberfallCrystalBrute : public AEmberfallEnemyBase
{
    GENERATED_BODY()
public:
    AEmberfallCrystalBrute();

    virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
        AController* EventInstigator, AActor* DamageCauser) override;

    UFUNCTION(BlueprintPure, Category="Emberfall|Enemy")
    bool IsCrystalArmorBroken() const { return bCrystalArmorBroken; }

    UFUNCTION(BlueprintImplementableEvent, Category="Emberfall|Enemy|Presentation")
    void OnCrystalArmorBroken();

private:
    bool bCrystalArmorBroken = false;
};

UCLASS()
class EMBERFALL_API AEmberfallBuriedForeman : public AEmberfallEnemyBase
{
    GENERATED_BODY()
public:
    AEmberfallBuriedForeman();

protected:
    virtual void OnCombatUpdate(float DeltaSeconds) override;

private:
    FEmberfallCooldownState CommandCooldown;
};

UCLASS()
class EMBERFALL_API AEmberfallLastForeman : public AEmberfallEnemyBase
{
    GENERATED_BODY()

public:
    AEmberfallLastForeman();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Boss")
    void AdvanceBossPhase();

    UFUNCTION(BlueprintPure, Category="Emberfall|Boss")
    int32 GetBossPhase() const { return BossPhase; }

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emberfall|Boss")
    int32 MaximumBossPhase = 5;

    UFUNCTION(BlueprintImplementableEvent, Category="Emberfall|Boss|Presentation")
    void OnBossPhaseChanged(int32 NewPhase);

    virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
        AController* EventInstigator, AActor* DamageCauser) override;

protected:
    virtual void OnCombatUpdate(float DeltaSeconds) override;

private:
    UPROPERTY(BlueprintReadOnly, Category="Emberfall|Boss", meta=(AllowPrivateAccess="true"))
    int32 BossPhase = 1;
};
