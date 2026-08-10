#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"
#include "Combat/EmberfallHealthState.h"
#include "Combat/EmberfallCombatTypes.h"
#include "Abilities/EmberfallAbilityRuntimeState.h"
#include "Progression/EmberfallProgressionComponent.h"
#include "Items/EmberfallInventoryComponent.h"
#include "Kip/EmberfallKipCompanion.h"
#include "EmberfallBerserkerCharacter.generated.h"

UCLASS()
class EMBERFALL_API AEmberfallBerserkerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AEmberfallBerserkerCharacter();

    virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
        AController* EventInstigator, AActor* DamageCauser) override;

    UFUNCTION(BlueprintCallable, Category="Emberfall|Combat")
    void Move(const FVector2D& Input);

    UFUNCTION(BlueprintCallable, Category="Emberfall|Combat")
    bool TrySpendRage(float Amount);

    UFUNCTION(BlueprintCallable, Category="Emberfall|Combat")
    bool TryBasicAttack();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Combat")
    bool TryDodge(const FVector& Direction);

    UFUNCTION(BlueprintCallable, Category="Emberfall|Combat")
    bool TryWhirlwind();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Combat")
    bool TryLeap(const FVector& TargetDirection);

    UFUNCTION(BlueprintCallable, Category="Emberfall|Combat")
    bool TryGroundbreaker();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Combat")
    bool TryWarCry();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Combat")
    void RestoreRage(float Amount);

    UFUNCTION(BlueprintCallable, Category="Emberfall|Combat")
    void ResetAfterDeath();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Save")
    bool SaveProfile();

    UFUNCTION(BlueprintCallable, Category="Emberfall|Save")
    bool LoadProfile();

    UFUNCTION(BlueprintPure, Category="Emberfall|Combat")
    bool IsDead() const;

    UFUNCTION(BlueprintCallable, Category="Emberfall|Debug")
    void SetInvulnerable(bool bEnabled) { bInvulnerable = bEnabled; }

    UFUNCTION(BlueprintCallable, Category="Emberfall|Debug")
    void SetVisualizeHitboxes(bool bEnabled) { bVisualizeHitboxes = bEnabled; }

    UFUNCTION(BlueprintPure, Category="Emberfall|Debug")
    bool IsInvulnerable() const { return bInvulnerable; }

    UFUNCTION(BlueprintPure, Category="Emberfall|Combat")
    bool IsWarCryActive() const { return WarCryRemaining > 0.0f; }

    UFUNCTION(BlueprintPure, Category="Emberfall|Combat")
    float GetWarCryRemaining() const { return WarCryRemaining; }

    UFUNCTION(BlueprintImplementableEvent, Category="Emberfall|Presentation")
    void OnAbilityActivated(EEmberfallAbilityId AbilityId);

    UFUNCTION(BlueprintImplementableEvent, Category="Emberfall|Presentation")
    void OnAbilityHit(EEmberfallAbilityId AbilityId, int32 HitCount);

    UFUNCTION(BlueprintImplementableEvent, Category="Emberfall|Presentation")
    void OnBuildChangingEffectTriggered(FName EffectId);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emberfall|Combat")
    FEmberfallHealthState Health;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emberfall|Combat")
    FEmberfallCombatResource Rage;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Emberfall|Progression")
    TObjectPtr<UEmberfallProgressionComponent> Progression;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Emberfall|Inventory")
    TObjectPtr<UEmberfallInventoryComponent> Inventory;

    UPROPERTY(BlueprintReadOnly, Category="Emberfall|Kip")
    TObjectPtr<AEmberfallKipCompanion> KipCompanion;

    UFUNCTION(BlueprintCallable, Category="Emberfall|Kip")
    void SetKipCompanion(AEmberfallKipCompanion* Companion) { KipCompanion = Companion; }

    UPROPERTY(BlueprintReadOnly, Category="Emberfall|Combat")
    int32 LastBasicAttackHitCount = 0;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
    void MoveForward(float AxisValue);
    void MoveRight(float AxisValue);
    void InputBasicAttack();
    void InputDodge();
    void InputWhirlwind();
    void InputLeap();
    void InputGroundbreaker();
    void InputWarCry();
    void Die();
    void ExecuteBasicAttack();
    void ExecuteLeapImpact();
    int32 ExecuteAreaAttack(EEmberfallAbilityId AbilityId, const FVector& Origin, float Radius, float Damage);
    bool HasEquippedEffect(FName EffectId) const;
    bool bDeathHandled = false;

    FEmberfallAbilityRuntimeState BasicAttackRuntime;
    FEmberfallAbilityRuntimeState DodgeRuntime;
    FEmberfallAbilityRuntimeState WhirlwindRuntime;
    FEmberfallAbilityRuntimeState LeapRuntime;
    FEmberfallAbilityRuntimeState GroundbreakerRuntime;
    FEmberfallAbilityRuntimeState WarCryRuntime;
    FEmberfallAbilityTuning BasicAttackTuning;
    FEmberfallAbilityTuning DodgeTuning;
    FEmberfallAbilityTuning WhirlwindTuning;
    FEmberfallAbilityTuning LeapTuning;
    FEmberfallAbilityTuning GroundbreakerTuning;
    FEmberfallAbilityTuning WarCryTuning;
    FTimerHandle LeapImpactTimer;
    FVector PendingLeapImpactLocation = FVector::ZeroVector;
    float WarCryRemaining = 0.0f;
    bool bInvulnerable = false;
    bool bVisualizeHitboxes = false;

    UPROPERTY(VisibleAnywhere, Category="Emberfall|Camera")
    class USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, Category="Emberfall|Camera")
    class UCameraComponent* IsometricCamera;
};
