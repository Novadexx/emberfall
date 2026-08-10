# Phase 0 architecture

The C++ module is organized by responsibility so Blueprint content can extend
the systems without owning core rules.

```text
Source/Emberfall/
  Core/          module-wide types, gameplay tags, logging
  Character/     player and Berserker foundations
  Combat/        attributes, damage, cooldown and hit interfaces
  Abilities/     ability definitions and execution seams
  AI/            enemy interfaces and encounter state
  Items/         item definitions, affixes and serialization seams
  Loot/          rarity and loot-table seams
  Progression/   XP, levels and reward definitions
  Kip/           companion state and upgrade definitions
  Save/          versioned local persistence
  UI/            presentation-facing interfaces
  Debug/         development commands and diagnostics
  Tests/         deterministic automation tests
```

The first source milestone only establishes stable seams. Content assets,
animations, VFX, audio and maps should be added in the editor after the module
compiles, rather than represented as hundreds of fragile generated files.

