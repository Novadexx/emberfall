# Phase 0 implementation plan

## Goal

Deliver a repeatable 20–30 minute solo combat slice in Deepstone/Frostvein
Mines. The first milestone proves movement, attacks, enemy readability, Kip,
meaningful level-ups, exciting loot, and the locked visual direction.

## Milestones

1. **Project foundation** — module, gameplay tags, input model, test seams,
   source-controlled project settings. Gameplay tags, progression data assets,
   combat resource rules, validation and initial automation tests are now
   scaffolded and audited.
2. **Playable Berserker** — isometric movement, melee combo, dodge, resource,
   health, death and restart. Source-level character, enemy combat loop and
   prototype game mode are now in place; editor map creation and visual assets
   remain.
3. **Abilities** — Whirlwind, Leap, Groundbreaker and War Cry with data-driven
   tuning and hooks for animation, audio and VFX.
4. **Enemies and encounter loop** — Buried Worker, Tunneler, Lanternman,
   Crystal Brute, Buried Foreman and The Last Foreman.
5. **Progression and loot** — levels 1–10, XP, weapon mastery, 20 items and
   five transformative effects.
6. **Kip and UI** — companion behavior, collection, identification, reactions,
   upgrade screen, HUD, inventory and level-up presentation.
7. **Save and validation** — versioned local save, debug commands, automated
   deterministic tests and a packaged smoke-test checklist.

The versioned save object and default-reset behavior are now scaffolded early
so later progression and inventory work cannot silently create an incompatible
save format.

## Architecture rules

- Ordinary tuning belongs in Primary Data Assets or Data Tables.
- Gameplay systems remain independent of UI and presentation.
- Client-originated progression and leaderboard values are never trusted.
- Every feature must leave a playable path and include feedback for the player.
