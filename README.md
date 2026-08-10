# EMBERFALL

Phase 0 Unreal Engine 5 prototype for a premium stylized isometric action RPG.

## Current scope

This repository starts the project from zero and targets the first playable
vertical slice described in the Master GDD:

- Berserker combat actions with data-driven ability hooks
- data-driven progression, inventory and build-changing item effects
- Kip companion behavior, collection and upgrade state
- Phase 0 enemy roster, boss phase logic and debug commands
- Deepstone/Frostvein Mines prototype environment
- local versioned save foundation
- deterministic gameplay test seams

The repository intentionally contains no multiplayer, seasons, monetization,
or full procedural-generation implementation yet.

## Requirements

- Unreal Engine 5.8 (the configured development target)
- Visual Studio 2022 with the Game development with C++ workload
- Windows 10 SDK 10.0.19041.0 or a UE5.8-supported Windows SDK
- Windows PC target

## Opening the project

Open `Emberfall.uproject` in Unreal Editor. Generate project files if prompted,
then build the `EmberfallEditor` target from Visual Studio.

The current environment has Unreal Engine 5.8 installed, but it does not have
the Visual Studio/Windows SDK toolchain required for a Win64 build. See
`docs/PHASE_0_AUDIT.md` for the current verification boundary and remaining
editor work.

## Canonical design

The supplied Emberfall Master Game Design & Codex Specification is the
canonical product specification. Keep a complete copy at
`docs/MASTER_GDD.md` when the source document is imported into the repository.
