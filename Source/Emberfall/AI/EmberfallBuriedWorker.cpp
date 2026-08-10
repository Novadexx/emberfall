#include "AI/EmberfallBuriedWorker.h"

AEmberfallBuriedWorker::AEmberfallBuriedWorker()
{
    EnemyId = TEXT("Buried.Worker");
    Health.Maximum = 60.0f;
    Health.Current = Health.Maximum;
    AttackDamage = 8.0f;
    AttackRange = 120.0f;
    AttackInterval = 1.25f;
}

