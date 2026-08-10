# EMBERFALL Phase 0 audit

Audit date: 2026-08-10

## Verified in this environment

- Complete supplied Master GDD imported at `docs/MASTER_GDD.md`
- UE5 project descriptor, module targets, build dependencies and config files
- UnrealBuildTool target discovery succeeds and reports both `Emberfall` and
  `EmberfallEditor` targets
- Berserker character source with health, rage, movement, dodge, basic attack,
  Whirlwind, Leap, Groundbreaker and War Cry execution seams
- Isometric camera component and keyboard/controller input mappings
- Forward melee overlap with self-hit and duplicate-hit protection
- Enemy base with damage, death, reset, approach and cooldown attack behavior
- Concrete Buried Worker definition
- Versioned save object and local save/load library
- Progression data validation, default level-1-to-10 XP thresholds and reward logic
- Live progression component with XP awards, multiple level gains and level-change events
- Ability tuning, cooldown and resource activation logic
- Weighted loot table selection and Kip module unlock state
- Kip companion actor with smooth follow, light, collection, identification,
  contextual dialogue, elite/secret reactions and visible module-upgrade hooks
- Concrete 20-item prototype catalog with five-plus transformative effects and
  a live inventory/equipment component
- Required Phase 0 enemy class roster with source-side unique mechanics and
  Last Foreman boss phase state
- Single-use item pickup actor and wired debug cheat command definitions
- Data-driven HUD, inventory and Kip view state with a HUD viewport host
- Live Berserker save/load integration for progression, health, resource,
  inventory, equipment and Kip state
- Deterministic automation test definitions for the above systems (19 tests)

## Not verified because the Unreal toolchain is blocked in this environment

- C++ compilation, Unreal Header Tool output and linker correctness. UE5.8 is
  installed and UBT now reaches platform validation, but the host has no
  recognized Win64 SDK: `Platform Win64 is not a valid platform to build` and
  `Sdk: not found. Required version 10.0.19041.0`. Visual Studio's `vswhere.exe`
  and the Windows Kits 10 SDK root are also absent on this host.
- Visual Studio project-file generation is also blocked when UBT attempts to
  write the engine-owned `C:\Program Files\Epic Games\UE_5.8\Engine\Intermediate\ProjectFiles`
  directory.
- Editor startup, map loading and Play-In-Editor flow
- Automation test execution inside Unreal
- Collision channels and overlap behavior in an authored level
- Input behavior on keyboard, mouse and controller
- Animation, VFX, audio, hit reactions and camera feel
- Save file round-trip on disk
- 60 FPS target and runtime profiling

## Still required for a complete playable Phase 0

- Authored Deepstone/Frostvein Mines map with rails, bridges, crystals, chasm,
  machinery, secret room and boss arena
- Berserker animation/VFX/audio assets and ability presentation
- Buried Worker, roster enemy and boss visual/animation assets, encounter
  behaviors, boss arena interactions and final phase mechanics
- Authored Kip screen and final visual model-upgrade assets
- Blueprint inventory, equipment, skill, Kip, HUD, tooltip and level-up widget assets
- XP award presentation and item pickup/drop presentation
- At least 20 editor-configured item assets, including five transformative effects
- Runtime save round-trip and actual command execution verification

## Audit conclusion

The source foundation is modular and data-driven, but Phase 0 is not yet a
playable, shippable vertical slice. The remaining work is primarily Unreal
Editor content integration and runtime verification. UE5.8 is present and the
UBA cache path is redirected to the project workspace, but compilation remains
blocked by the missing Win64 SDK/toolchain.
