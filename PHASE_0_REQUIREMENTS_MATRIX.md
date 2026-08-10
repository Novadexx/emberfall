# EMBERFALL Phase 0 requirements matrix

Evidence basis: `docs/MASTER_GDD.md` sections 43–50 and the current source tree.

| Requirement | Status | Evidence / gap |
|---|---|---|
| Unreal Engine 5 primary target | Implemented | `Emberfall.uproject`, UE5 target files, module build rules, and successful UBT target discovery |
| 20–30 minute repeatable combat slice | Unverified | Runtime loop is not launch-tested; no authored map exists |
| Deepstone/Frostvein Mines section | Editor-required | Source/config references exist; map, geometry and props are absent |
| Berserker basic attack | Source implemented | `AEmberfallBerserkerCharacter::TryBasicAttack` and melee overlap |
| Directional dodge | Source implemented | `TryDodge`, cooldown/resource gate and launch movement |
| Whirlwind, Leap, Groundbreaker, War Cry | Source implemented with presentation hooks | Cooldown/resource gates, area/impact execution and War Cry state exist; authored animation/VFX/audio remain |
| Health, rage, cooldown and death | Source implemented | Health/resource/cooldown structs and character/enemy paths |
| Kip follow and light | Source implemented | `AEmberfallKipCompanion` follow tick and point light |
| Kip collection, identification and reactions | Source implemented with editor presentation gap | Collection, identification, dialogue and reaction hooks exist; authored UI/dialogue presentation remains |
| Kip upgrade with visible model change | Source implemented with editor presentation gap | Module unlock changes light intensity and actor scale; authored upgrade screen/model asset remains |
| Buried Worker | Source implemented | Concrete class and enemy combat loop |
| Tunneler, Lanternman, Crystal Brute, Buried Foreman | Source implemented with editor presentation gap | Reposition, empowerment, crystal armor and command-buff logic exist; authored encounter assets remain |
| The Last Foreman | Source implemented with editor presentation gap | Health-driven phase transitions and Blueprint phase hooks exist; drill/debris/machinery/adds need authored encounter implementation |
| Levels 1–10 | Source implemented with editor presentation gap | Default level-1-to-10 XP thresholds and reward IDs are populated; level-up widgets/reward presentation remain |
| 20 prototype items | Source implemented | 20-item catalog exists |
| Five transformative item effects | Source implemented with gameplay hooks | Five-plus effect IDs exist; equipped-effect queries and representative combat hooks are wired; full VFX/secondary systems remain |
| Loot rarity/table selection | Source implemented | Weighted data-driven loot table and tests |
| HUD | Source foundation | HUD state/widget host exists; Blueprint widget assets are absent |
| Inventory/equipment/skills/Kip screens | Source foundation | Live inventory/equipment and Kip state exist; functional widgets/assets are absent |
| Loot tooltip and level-up presentation | Editor-required | No authored widget implementation/assets |
| Versioned local save | Source implemented | Save object, save/load library and live Berserker integration |
| Save round-trip | Unverified | Requires Unreal runtime and disk test; source path is integrated |
| Debug commands | Source implemented, runtime unverified | Cheat manager is wired through the prototype player controller; Unreal execution remains unverified |
| Automated deterministic tests | Defined, not executed | 19 test definitions; Unreal automation runner unavailable |
| Performance target | Unverified | Requires representative hardware and runtime profiling |
| Multiplayer | Intentionally out of scope | Correctly deferred by Phase 0 specification |

## Conclusion

The repository contains the complete source-side foundation that can be
validated without a functioning UnrealBuildTool/editor run. UE5.8 is installed,
and the UBA cache is redirected into the project workspace, but UBT reports no
recognized Win64 SDK (`10.0.19041.0` required). Phase 0 is not yet a verified
playable slice: map/content assets, Blueprint presentation, runtime compilation,
automation execution and performance testing remain open.
