#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Combat/EmberfallHealthState.h"
#include "Combat/EmberfallCooldownState.h"
#include "EmberfallEnemyBase.generated.h"

UCLASS()
class EMBERFALL_API AEmberfallEnemyBase : public ACharacter
{
    GENERATED_BODY()

public:
    AEmberfallEnemyBase();

    virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
        AController* EventInstigator, AActor* DamageCauser) override;

    UFUNCTION(BlueprintPure, Category="Emberfall|Enemy")
    bool IsDead() const;

    UFUNCTION(BlueprintCallable, Category="Emberfall|Enemy")
    void ResetEnemy();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Enemy|Combat")
    void ApplyAttackEmpowerment(float DamageMultiplier, float Duration);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emberfall|Enemy")
    FName EnemyId = TEXT("Buried.Worker");

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emberfall|Enemy")
    FEmberfallHealthState Health;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emberfall|Enemy|Combat")
    float AttackDamage = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emberfall|Enemy|Combat")
    float AttackRange = 120.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emberfall|Enemy|Combat")
    float AttackInterval = 1.25f;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void OnCombatUpdate(float DeltaSeconds) {}

    UFUNCTION(BlueprintPure, Category="Emberfall|Enemy|Combat")
    float GetEffectiveAttackDamage() const;

private:
    void Die();
    void UpdateCombat(float DeltaSeconds);
    bool bDeathHandled = false;
    FEmberfallCooldownState AttackCooldown;
    float AttackEmpowermentMultiplier = 1.0f;
    float AttackEmpowermentRemaining = 0.0f;
};
