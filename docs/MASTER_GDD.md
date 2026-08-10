# EMBERFALL --- Master Game Design & Codex Specification

**Version:** 0.3 --- Canonical Narrative + Unreal Phase 0
**Genre:** Isometric Action RPG / Hack & Slash
**Modes:** Solo + 2--4 Player Online Co-op
**Core Promise:** Every level matters. Every run progresses something.
Great loot changes gameplay.
**Tagline:** *Slay. Loot. Ascend.*

---

# 1. Vision

EMBERFALL is a premium isometric action RPG built around satisfying
combat, extraordinary loot moments, continuous meaningful progression,
deep but understandable character building, and highly replayable
solo/co-op adventures.

The game takes inspiration from the broad traditions of classic stylized
fantasy ARPGs without reproducing the protected characters, worlds,
assets, UI, lore, iconography, enemies, or distinctive designs of any
existing title.

The visual goal is **premium PC/console stylized fantasy**, not
photorealism and not mobile/F2P aesthetics.

The player should finish almost every meaningful session having changed
something: character level, skill mastery, weapon mastery, companion
bond, dungeon mastery, stronghold, equipment, crafting knowledge,
collection, account progression, challenge record, or leaderboard
position.

---

# 2. Core Pillars

## 2.1 Every Level Matters

Levels 1--100 must never become a sequence of meaningless numerical
increases. Every level provides a meaningful allocation, unlock,
evolution, breakpoint, system expansion, or immediately perceptible
improvement.

## 2.2 Exciting Ground Loot

Finding equipment is the emotional centerpiece of itemization. Crafting
improves good discoveries; it does not replace them.

## 2.3 Build-Changing Items

The most desirable effects alter mechanics.

Examples: - Whirlwind pulls enemies inward. - Fireball divides into
three projectiles. - Dodge leaves an exploding frost echo. - The
player's wolf becomes a permanent two-wolf pack. - Chain Lightning can
rebound through the caster and become empowered. - Leap produces an
earthquake. - Critical bow hits embed arrows that detonate
simultaneously.

## 2.4 Parallel Progression

Several progression systems advance naturally at once: - Character
Level - Skills - Weapon Mastery - Companion Bond - Dungeon Mastery -
Crafting - Stronghold - Collections - Account Mastery - Seasonal
Challenges - Personal Records

## 2.5 Solo First-Class

All campaign, standard bosses, progression systems and normal endgame
advancement are fully playable solo.

## 2.6 Effortless Co-op

Invite, join and fight. Individual loot, scalable encounters, revives
and drop-in/drop-out play.

## 2.7 Depth Without Homework

Players should be capable of making a strong build by understanding the
game itself. Advanced players can discover powerful synergies without
requiring external spreadsheets for basic competence.

## 2.8 Respect the Player

No energy systems, mandatory daily chores, pay-to-win, paid XP boosts,
paid drop-rate boosts, gambling-like paid loot boxes, or artificial
waiting mechanics.

---

# 3. Visual Identity

## 3.1 Overall Target

EMBERFALL uses **high-end stylized 3D fantasy rendered with modern
lighting and materials**.

The world should feel handcrafted, atmospheric and mature while
retaining color, personality and strong silhouettes.

It must not resemble: - a generic mobile ARPG, - a glossy F2P fantasy
game, - a photorealistic horror game, - a direct visual copy of another
ARPG.

## 3.2 Environment

Use: - painterly but physically believable materials, - modern PBR
rendering, - atmospheric depth, - volumetric fog, - dynamic/local
lighting, - rich but controlled environmental color, - strong
foreground/midground/background separation, - readable pathways, -
environmental motion, - weather, - restrained bloom, - detailed
architecture readable from the isometric camera.

Stone, wood, metal, vegetation and terrain should remain stylized rather
than photographic.

## 3.3 Character Proportions

Characters use mature, mostly realistic anatomy with deliberate
stylization.

Avoid: - chibi proportions, - huge heads, - toy-like armor, - extremely
stubby characters, - exaggerated mobile-game silhouettes.

Weapons and armor may be slightly oversized to improve isometric
readability.

## 3.4 Color

The environment uses controlled natural color.

Magic provides the strongest saturation.

Example palette logic: - Environment: restrained greens, slate, stone,
earth, steel, deep blues. - Fire: ember orange/red. - Lightning:
electric blue/violet. - Poison: acidic green. - Arcane: violet. -
Holy/radiant: warm ivory/gold.

Do not make every interactable object glow.

## 3.5 EMBERFALL Visual Signature

The game needs its own immediately recognizable visual language.

Core motifs: - blackened forged metal, - ember-lit cracks, - dark
stone, - ancient geometric structures, - fractured amber crystal, -
subtle triangular/hexagonal patterns, - ruined colossal mechanisms
embedded in fantasy landscapes.

The "Ember" corruption can progressively alter monsters, architecture
and terrain.

---

# 4. UI Art Bible

## 4.1 Philosophy

**Modern first. Fantasy second.**

The UI must feel like a premium contemporary PC/console product whose
materials belong to the EMBERFALL world.

Fantasy identity comes from subtle texture, typography, micro-animation
and accent materials---not massive ornamental borders.

## 4.2 UI Materials

Primary: - near-black charcoal - smoke-glass transparency - desaturated
steel - restrained blackened bronze - ember-orange highlights - subtle
warm ivory text

Rare accent gold is permitted for prestige elements but must not
dominate ordinary screens.

## 4.3 Explicitly Avoid

* giant gold frames
* glossy mobile buttons
* oversized beveled panels
* enormous decorative health globes
* casino-like reward presentation
* excessively colorful skill icons
* dozens of competing currencies
* giant "CLAIM" buttons
* mobile card grids as primary navigation
* red notification dots everywhere
* excessive bloom
* cluttered HUD borders
* faux-medieval unreadable body fonts

## 4.4 Typography

Use a distinctive display typeface for: - logo - region introductions -
bosses - major progression moments

Use an extremely readable modern typeface for: - statistics -
descriptions - menus - inventory - chat - quests - tooltips

Typography should communicate hierarchy through size, weight and spacing
rather than ornament.

---

# 5. Gameplay HUD

The HUD should disappear perceptually when the player is focused on
combat.

## Top Left

Compact: - portrait - HP - resource - status effects

Party members appear below only during co-op.

## Top Center

Normally empty.

Used temporarily for: - boss health - elite/champion identity - major
event status

## Top Right

Minimal minimap with: - objective - area name - difficulty/tier -
important markers

Quest text should collapse automatically during intense combat.

## Bottom Center

Compact skill bar: - 5--7 active actions depending on final control
scheme - potion - dodge/utility - cooldown visualization

No giant ornamental frame.

## XP / Mastery

A thin unobtrusive progression line can sit at the bottom edge.

When a mastery is near completion, a subtle preview appears.

---

# 6. Main Menu

The hero is rendered live in an atmospheric environment representing
current campaign/endgame progress.

Navigation:

* Continue
* Play
* Character
* Inventory
* Skills
* Stronghold
* Leaderboards
* Season
* Social
* Options
* Exit

The main menu is not a store lobby.

Seasonal information remains secondary.

The player's next meaningful progression milestone can appear
unobtrusively:

> Level 45 --- Berserker
> Next: Weapon Mastery 20 --- Execution Technique

---

# 7. Inventory

Inventory should feel premium, fast and information-rich.

Layout: - 3D hero render - equipment surrounding or adjacent to
character - clean inventory grid/list - currencies/materials secondary -
filter/search/sort - controller-friendly navigation

Comparison emphasizes:

1. Build-changing mechanics
2. Core stats
3. Relevant affixes
4. Detailed calculations on demand

Do not force players to visually parse dozens of tiny affixes every
minute.

---

# 8. Character Progression

Character levels: **1--100**.

Every level grants at least one meaningful benefit.

Milestone framework:

* Level 1 --- Class identity + first active skill
* Level 2 --- Second ability
* Level 3 --- First modifier
* Level 5 --- Passive branch
* Level 10 --- Class mechanic
* Level 15 --- Companion active
* Level 20 --- Specialization
* Level 25 --- Major skill evolution
* Level 30 --- Relic slot
* Level 35 --- Advanced crafting
* Level 40 --- Specialization keystone
* Level 50 --- Ascension I + higher world tier
* Level 60 --- Second major evolution
* Level 70 --- Mythic systems
* Level 80 --- Highest standard world tier
* Level 90 --- Final class keystone
* Level 100 --- Ascended status + endgame progression

Intermediate levels alternate skill, passive, attribute, mastery and
system-development rewards.

The entire progression table must be data-driven.

---

# 9. Classes

Initial full-game target: 5.

## Berserker

Heavy melee, Rage, momentum and brutal area attacks.

## Spellblade

Melee + elemental magic hybrid.

## Ranger

Bows, traps, precision and mobility.

## Druid

Nature magic, transformations and beasts.

## Shadow

Fast melee assassin, marks, critical attacks and shadow manipulation.

Each class needs multiple genuine archetypes rather than one optimal
developer-designed build.

---

# 10. Skill Evolution

Skills gain their own mastery XP.

A skill should visibly evolve over time.

Example --- Whirlwind:

**Base** Spin and damage nearby enemies.

**Mastery 5** Radius/efficiency choice.

**Mastery 10** Choose: - Vortex --- pulls enemies inward - Repulsion ---
knocks enemies outward

**Mastery 15** Movement/resource specialization.

**Mastery 20 --- Evolution** Choose: - Firestorm - Blood Cyclone -
Tempest

Evolution changes visuals, mechanics and build interactions.

---

# 11. Weapon Mastery

Weapon families progress independently:

* Sword
* Axe
* Mace
* Dagger
* Bow
* Crossbow
* Staff
* Focus
* Polearm

Mastery provides: - new attack properties, - passive choices, -
finishers, - weapon-family mechanics, - cosmetic proficiency indicators.

Switching weapon families remains viable without deleting months of
progress.

---

# 12. Companion System

Companions have:

* Bond Level
* active ability
* passive utility
* behavior selection
* evolution
* cosmetic customization

Potential utility: - collect selected loot, - limited town
selling/salvaging, - mark enemies, - retrieve resources.

Pets must never be paid power.

---

# 13. Loot

Rarities:

1. Common
2. Magic
3. Rare
4. Epic
5. Legendary
6. Unique
7. Mythic

Higher rarity increases potential, not automatic superiority.

The most desirable loot changes gameplay.

## Drop Feedback

High-tier drops use: - distinctive sound, - restrained vertical light, -
ground icon, - rarity label, - subtle environmental response for
exceptional drops.

A Mythic drop should be identifiable from audio alone.

Avoid turning the entire screen gold.

---

# 14. Target Farming

Randomness stays exciting, but players choose direction.

The in-game Codex identifies broad sources:

> Emberfang
> Increased chance: Ember Wastes bosses
> High chance: Forgemaster encounter
> Possible: World Tier IV+ global drop

Players know what to do without receiving a guaranteed timetable.

---

# 15. Crafting

Crafting supports drops.

Core systems: - salvage - improve - reroll one selected affix - socket -
extract power - imprint compatible power - upgrade - limited
deterministic enhancement

Costs and possible outcomes are visible.

Normal crafting should not require external calculators.

---

# 16. Combat

Combat goals:

* responsive movement
* immediate input
* strong animation timing
* readable telegraphs
* satisfying impact
* positional play
* controllable crowd density
* strong death reactions
* excellent sound feedback
* spectacular but readable abilities

Enemy tiers:

Normal → Veteran → Elite → Champion → Boss → Pinnacle Boss

Higher difficulty introduces mechanics, coordination and density in
addition to statistical scaling.

---

# 17. Solo

Everything important is playable solo:

* campaign
* side quests
* progression
* normal dungeons
* Nightmare Dungeons
* Rifts
* Trials
* bosses
* crafting
* target farming

Some optional community/world encounters may support larger
participation, but they cannot gate fundamental character progression.

---

# 18. Online Co-op

Party size: **1--4**

Features: - invite - friends - private/public party - matchmaking -
drop-in/drop-out - individual loot - enemy scaling - boss scaling -
revives - pings - shared objective state - reconnect support

Co-op scaling should alter enemy composition and mechanics, not simply
multiply health.

---

# 19. Networking & Competitive Integrity

Competitive/endgame sessions should become server-authoritative.

Client prediction maintains responsive movement/combat presentation.

Never trust: - client completion time - client leaderboard score -
client item generation - client progression claims

Leaderboard entries come from verified sessions.

---

# 20. Leaderboards

Categories:

* Solo Rift
* Duo Rift
* Trio Rift
* 4-Player Rift
* Fixed Trials
* Pinnacle Boss Time
* Class-specific
* Hardcore
* Seasonal
* Friends
* Regional
* Global

Entries may contain: - player - class - level - build snapshot - tier -
time - deaths - season - party composition - date - replay/ghost
metadata when supported

Rewards emphasize prestige: - titles - frames - armor appearances -
weapon appearances - trophies - pet cosmetics

Leaderboard rank does not grant combat power.

---

# 21. Endgame

## Nightmare Dungeons

Escalating dungeon tiers and modifiers.

## The Rift

Progressively harder randomized combat challenge.

## Trials

Fixed weekly layouts/conditions suitable for fair ranking.

## Pinnacle Bosses

Mechanically demanding encounters with distinctive reward pools.

## Hunts

Players influence the world toward a desired enemy/reward family.

## Ascension

Post-100 horizontal specialization and prestige progression.

Avoid infinite raw-stat scaling that invalidates competitive integrity.

---

# 22. Stronghold

A persistent hub physically develops with the player's achievements.

Potential services: - Blacksmith - Enchanter - Alchemist -
Cartographer - Pet Master - Training Arena - Trophy Hall - Storage -
Appearance station - Seasonal NPC

Major boss trophies physically appear.

The Stronghold provides a visible representation of long-term
progression.

---

# 23. World

Example regions:

### Ashen Highlands

Mountain fortresses, forests, abandoned foundries.

### Forgotten Catacombs

Crypts, underground cities and cult ruins.

### Frostgrave Tundra

Frozen settlements, glaciers and ancient constructs.

### Verdant Depths

Overgrown temples, rivers and corrupted wildlife.

### Ember Hollow

Volcanic high-level environment.

### Sunken Ruins

Flooded subterranean civilization.

### The Rift

Reality-breaking endgame environment.

Regions combine handcrafted overworld composition with modular
procedural dungeon interiors.

---

# 24. Procedural Dungeons

Use authored modular rooms assembled procedurally.

Variation: - route - room order - optional branches - events - enemy
families - elites - shrines - secrets - environmental modifiers - boss
selection where appropriate

Pure noise-based procedural environments are not acceptable as the
primary content strategy.

Every biome requires recognizable authored landmarks.

---

# 25. Seasons

Seasons add: - gameplay mechanic - chase items - challenges -
cosmetics - leaderboard reset/rotation - optional narrative development

Permanent characters remain available.

Do not create mandatory daily chore lists.

---

# 26. Monetization

Preferred: **premium base game + meaningful expansions + optional
cosmetics.**

Never sell: - power - XP advantage - loot advantage - leaderboard
advantage - paid random power - mandatory convenience designed around
artificial inconvenience

The game's UI must never resemble a storefront-first F2P title.

---

# 27. Accessibility

Include: - full remapping - controller support - UI scaling - subtitle
options - color-blind-safe rarity indicators - reduced flash - reduced
screen shake - damage number controls - loot filtering - hold/toggle
alternatives - independent audio controls

---

# 28. Audio Direction

Audio reinforces progression.

Unique recognizable cues: - level up - mastery level - skill evolution -
Legendary - Unique - Mythic - boss stagger - boss kill - Ascension -
personal record

Music should support atmosphere without exhausting the player during
long farming sessions.

---

# 29. Technical Direction

Recommended first prototype engine: **Godot 4.x**.

Before full production, compare the vertical slice against Unreal Engine
if visual or networking requirements exceed the practical Godot
pipeline.

Suggested project organization:

```text
/game
  actors/
  ai/
  combat/
  abilities/
  items/
  loot/
  progression/
  mastery/
  companions/
  dungeons/
  quests/
  stronghold/
  ui/
  audio/
  network/
  leaderboard/
  seasons/
  save/
  tests/

/data
  classes/
  skills/
  progression/
  items/
  affixes/
  loot_tables/
  enemies/
  bosses/
  dungeons/
  companions/
  seasons/
```

All balance values should be externalized wherever practical.

---

# 30. Codex Engineering Rules

Codex must:

1. Preserve existing working features unless explicitly replacing them.
2. Prefer modular systems over one-off scripts.
3. Keep balance values data-driven.
4. Add automated tests for deterministic gameplay systems.
5. Maintain a playable build after each milestone.
6. Fix root causes rather than suppress errors.
7. Log failures clearly.
8. Treat network inputs as untrusted.
9. Never accept client-generated leaderboard scores.
10. Maintain keyboard/mouse and controller parity.
11. Profile before major optimization.
12. Document major architecture decisions.
13. Avoid premature creation of hundreds of content assets.
14. Build reusable content pipelines before scaling content.

---

# 31. Definition of Done

A feature is complete only when:

* playable,
* integrated,
* stable,
* relevant edge cases handled,
* tests added where appropriate,
* UI feedback present,
* save implications handled,
* network implications handled,
* performance checked,
* data/config documented.

---

# 32. Production Roadmap

## Phase 0 --- Combat Prototype

One gray-box arena.

Build: - Berserker - movement - camera - basic attack - dodge -
Whirlwind - Leap - Groundbreaker - War Cry - health/resource - XP -
level up - 3 enemy archetypes - elite - boss - controller support

**Success criterion:** Combat is enjoyable without loot.

## Phase 1 --- Premium Visual Vertical Slice

Replace enough placeholder content to establish the actual visual
target.

Build: - one premium environment - one polished hero - one polished
enemy family - premium lighting - final-direction HUD - final-direction
inventory - representative VFX - representative audio

**Success criterion:** A screenshot looks like a premium PC/console
indie/AA ARPG, not a mobile game.

## Phase 2 --- Gameplay Vertical Slice

Build: - levels 1--15 - 1 region - stronghold - procedural dungeon
biome - ~8 enemies - 2 bosses - 40--60 items - 8--12 build-changing
powers - pet - skill mastery - crafting - save/load

**Success criterion:** 1--2 hours feels like a small complete ARPG.

## Phase 3 --- Progression

Expand to level 30.

Add: - specialization - skill evolution - weapon mastery - dungeon
mastery - stronghold progression - target farming - loot filter

**Success criterion:** repeated runs remain exciting.

## Phase 4 --- Co-op Prototype

Start with two players.

Build: - authoritative session - party - joining - leaving - individual
loot - scaling - revive - disconnect/reconnect - persistence validation

Only expand to four players after two-player synchronization is robust.

## Phase 5 --- Endgame

Build: - Nightmare Dungeons - Rift - Trial - Pinnacle Boss -
server-verified leaderboard - build snapshots

## Phase 6 --- Content Expansion

Add: - remaining classes - regions - levels 31--100 - bosses - quests -
item families - companions - stronghold content - endgame variety

## Phase 7 --- Alpha/Beta

Focus: - network load - performance - balancing - progression pacing -
economy - accessibility - anti-cheat - telemetry - bug fixing -
onboarding

---

# 33. Art Generation / Asset Brief

Use this as the baseline brief for concept generation:

> Premium PC/console isometric action RPG. Original stylized
> high-fantasy world with mature character proportions and painterly art
> direction. Modern physically based materials, atmospheric lighting,
> volumetric depth and detailed handcrafted environments. Restrained
> natural palette with vivid magical effects reserved for combat. Strong
> silhouettes readable from an elevated isometric camera. Blackened
> forged metal, dark stone, ember-lit cracks and fractured amber crystal
> form the game's distinctive visual language. UI is contemporary,
> minimal and sophisticated: charcoal translucent surfaces, subtle aged
> bronze, warm ivory typography and restrained ember-orange highlights.
> Thin borders, compact controls, generous negative space and excellent
> typography. Avoid mobile/F2P visual language, glossy buttons,
> oversized gold ornamentation, chibi proportions, excessive saturation,
> excessive currencies, giant reward banners and card-heavy navigation.
> The result should look like a premium €40--60 PC/console release.

This brief describes broad visual qualities only. Do not reproduce
specific characters, environments, interfaces, logos, icons or other
protected assets from existing games.

---

# 34. North-Star Player Experience

A dungeon ends.

The player:

* reaches Level 37,
* receives a meaningful passive choice,
* advances Whirlwind to Mastery 20,
* chooses a new Whirlwind evolution,
* raises Wolf Bond to 9 and unlocks Pounce,
* finds a Unique axe that makes Whirlwind kills explode,
* raises the dungeon's mastery,
* beats their personal Trial record.

Back at the Stronghold, the player equips the axe, modifies the build,
sees a new trophy appear and notices the next milestone is close.

The immediate thought should be:

**"I want to try this build one more time."**

That is the EMBERFALL progression fantasy.

---

# 35. First Codex Task

> Create EMBERFALL Phase 0 as a clean, modular Godot 4 project. Build an
> isometric 3D combat arena with responsive keyboard/mouse and
> controller movement. Implement one Berserker with a basic attack,
> dodge, Whirlwind, Leap, Groundbreaker and War Cry. Add health,
> resource, damage, cooldown, death, XP and level-up systems. Implement
> three enemy archetypes, one elite and one boss. All balance values
> must be data-driven. Add automated tests for damage, XP and cooldown
> calculations. Include a minimal premium dark UI rather than ornate
> fantasy/mobile UI. Use placeholders where final assets do not yet
> exist. The project must launch from a simple main menu into the arena
> and remain stable through repeated death/restart cycles. Do not begin
> multiplayer, procedural world generation, crafting or large-scale
> content until this prototype is verified as fun and stable.

---

# 36. CANONICAL NARRATIVE --- THE WORLD THAT FORGETS

## 36.1 The Weave

Reality in EMBERFALL is held together by an ancient underlying structure
called **the Weave**.

The Weave is not conventional magic. It is the world's memory. Places,
people, objects and events persist because reality retains their
pattern.

Magic manipulates those patterns temporarily.

Something is now failing.

Regions are not merely being destroyed. They are being **forgotten**. A
settlement can disappear and be replaced by terrain that suggests it
never existed. Most people lose every memory of it.

The player does not.

Neither does Kip.

## 36.2 Opening

The protagonist begins as a **Seeker**, one of many explorers and
mercenaries entering unstable regions to recover artifacts and
resources.

During an expedition into newly exposed mining ruins, the player
discovers a damaged floating construct.

The construct awakens when touched.

Its working name is **Kip**.

Kip remembers almost nothing about itself.

As the player escapes, rooms behind them begin disappearing from
reality.

Upon returning, nobody remembers the ruins ever existing.

Kip does.

This is the central mystery that begins the campaign.

## 36.3 Anchors

Kip is eventually revealed to be an ancient device called an **Anchor**.

Anchors preserve selected information inside the Weave.

Kip's damaged systems are restored throughout the campaign. Each
restoration simultaneously reveals story information and unlocks
gameplay/QoL functionality.

Example modules:

---

Module                  Narrative meaning       Gameplay function

---

Memory Lens             Restores material       Automatic item
cataloguing             identification

Attraction Core         Restores matter         Gold/material pickup
manipulation

Archive Chamber         Restores preserved      Additional storage
storage

Wayfinder               Recovers forgotten      Map improvement +
routes                  secret detection

Matter Gate             Restores short-range    Send selected loot to
transfer                town

Forge Memory            Recovers fabrication    Remote salvage
protocols

Echo Lens               Detects Weave           Elite/anomaly analysis
disturbances

Anchor Heart            Temporarily stabilizes  Limited emergency
a person                resurrection
------------------------------------

QoL progression must therefore feel like the companion itself is
evolving.

## 36.4 The Quieting

The ancient civilization that created the Anchors discovered that the
Weave had finite capacity.

Their solution was **the Quieting**: old portions of reality would
gradually be removed so new reality could continue to form.

Anchors were not originally designed to prevent the process.

They determined **what should remain**.

## 36.5 The Central Conflict

The apparent antagonist, provisionally called **the Curator**, is
accelerating the Quieting.

The Curator believes reality is approaching catastrophic overload and
that preserving everything will eventually destroy everything.

This antagonist must not be evil merely for the sake of being evil.
Their argument should remain credible enough that the player understands
the dilemma.

Factions eventually emerge around competing solutions:

* **Curators:** controlled forgetting is necessary.
* **Archivists:** preserve all possible reality.
* **Severed:** destroy the Weave and accept uncontrolled reality.
* **Expansion:** the player and Kip pursue the possibility of
  increasing what reality can contain.

## 36.6 Kip's Revelation

Late in the campaign, Kip recovers the memory that it participated in
the previous great Quieting.

It was not merely a witness.

It initiated or enabled the erasure of an enormous population.

Kip is horrified by its recovered identity.

The emotional center of the campaign becomes the relationship between
the player and a companion discovering that its original purpose may
have caused a civilization's disappearance.

## 36.7 Endgame Narrative

The Rift is not a generic magical portal.

It contains discarded or partially reconstructed realities: places,
civilizations and creatures removed from the Weave.

Kip eventually learns to navigate these remnants.

This provides an in-world explanation for highly variable and repeatable
endgame content.

The title **EMBERFALL** refers metaphorically to what remains after a
thing has otherwise disappeared: an ember of memory.

---

# 37. KIP --- CORE COMPANION SYSTEM

Kip is not a disposable pet. Kip is one of EMBERFALL's primary
characters and systems.

## 37.1 Design Goals

Kip must:

* be present from the opening;
* remain visually recognizable throughout the entire game;
* evolve physically;
* gain personality through dialogue and reactions;
* provide increasing quality-of-life functionality;
* participate lightly in combat without replacing the hero;
* function as the player's bestiary and memory archive;
* connect account-wide systems to the fiction;
* remain emotionally important at level 100.

## 37.2 Upgrade Categories

### Collection

Gold pickup, crafting-material pickup, configurable loot retrieval.

### Insight

Enemy analysis, weakness information, anomaly detection, bestiary
completion.

### Traversal

Secret detection, ancient doors, lifts, forgotten routes and
environmental mechanisms.

### Logistics

Additional storage, item transfer, remote salvage and town-related
conveniences.

### Support

Limited shields, emergency healing delivery, status assistance and
late-game stabilization.

### Resonance

Narrative/endgame capabilities involving the Weave and forgotten
realities.

Basic QoL should not require sacrificing combat power. Branches create
specialization, but universally desirable conveniences should remain
broadly obtainable.

## 37.3 Personality

Kip begins analytical, damaged and uncertain.

Its personality develops through recovered memories and player
experiences.

It should comment sparingly so it remains welcome rather than
irritating.

Kip may remember things nobody else can, notice procedural changes
between dungeon visits, react to Anomalies and gradually question its
own original instructions.

---

# 38. WORLD & BIOME DIRECTION --- CANONICAL

EMBERFALL should avoid relying heavily on generic lush forests and
tropical jungles.

The dominant world identity is:

**mineral + industrial + alpine + frozen + subterranean + volcanic +
forgotten**

Vegetation is used selectively for contrast.

## 38.1 Frostvein / Deepstone Mines

A major signature biome.

Elements:

* deep shafts;
* mine rails;
* suspended bridges;
* abandoned industrial machinery;
* elevators;
* excavation settlements;
* blue/turquoise crystal seams;
* dark rock;
* orange lanterns;
* hidden chambers;
* underground rivers;
* vertical chasms.

Kip can illuminate, scan mineral deposits, activate machinery and
discover forgotten routes.

## 38.2 The White Expanse

Extreme snow and ice.

Elements:

* buried villages;
* frozen mines;
* glaciers;
* abandoned mountain fortresses;
* blizzards;
* frozen machinery;
* turquoise ice caverns;
* preserved ruins inside glaciers.

## 38.3 Ember Deeps

Volcanic underworld.

Elements:

* obsidian;
* enormous magma rivers;
* molten waterfalls;
* ancient forges;
* blackened machinery;
* basalt architecture;
* Ember corruption;
* suspended industrial platforms.

## 38.4 Hollow Mountains

A colossal underground forgotten city discovered by descending through
ordinary-looking mines.

The reveal should be a major campaign spectacle.

Architecture stretches vertically into darkness. Ancient rail systems
cross impossible distances. Kip recognizes the location before
understanding why.

## 38.5 Glass Wastes

A region transformed into dark glass by an ancient catastrophe.

Lightning and fragments of forgotten structures can appear beneath or
within the glass.

## 38.6 Shattered Peaks

High-altitude snow, rock, fortresses, mines, avalanches and enormous
drops.

The geography should connect naturally:

**mountain → mine → deepworks → underground city → volcanic depths**

The world must feel geographically coherent rather than like
disconnected themed levels.

---

# 39. ENEMY ECOLOGY --- ECHOES

EMBERFALL's signature enemies are **Echoes**: beings reconstructed
incorrectly when the Weave combines incompatible memories.

Avoid making the main roster primarily generic goblins, skeletons,
zombies and demons.

## 39.1 The Buried

Primary mine family.

Forgotten workers, equipment, minerals and machinery reconstructed
together.

Examples:

* Buried Worker
* Tunneler
* Lanternman
* Hauler
* Crystal Brute
* Foreman

Possible mechanics include wall emergence, drilling charges, crystal
armor, support lanterns and machinery interactions.

## 39.2 The Preserved

Primary frozen family.

People, creatures and events partially protected from forgetting by ice.

Signature mechanic: memory-based restoration or movement replay.

Example: a Preserved Captain can return to its position/state from
several seconds earlier unless its memory anchor is interrupted.

## 39.3 The Forged

Primary volcanic family.

Ancient machines that continued repairing themselves with obsidian,
scrap and Ember after their civilization disappeared.

Some attempt to rebuild after death unless their cores are destroyed.

## 39.4 The Misremembered

One of the game's most recognizable enemy families.

Different historical memories have been combined into a single entity.

Examples:

* creature + ruined architecture;
* warrior + industrial mechanism;
* beast + mineral formation;
* multiple incompatible body configurations.

Animations can occasionally transition between remembered states.

## 39.5 The Hollow

People whose physical existence remained while identity and historical
context disappeared.

Not every Hollow is hostile.

This family supports quests and moral ambiguity.

## 39.6 The Unwritten

Late-game/Rift enemies.

They are generated from possibilities the Weave attempts to use to fill
missing information.

They can reconstruct or change form during battle.

## 39.7 Anomalies

Rare enemies that appear where they should not.

Kip detects them with unique behavior/dialogue.

Anomalies should create exceptional exploration moments and award
unusual loot, progression and bestiary entries.

---

# 40. BOSS DESIGN PHILOSOPHY

Bosses represent important memories or failures in reality rather than
simply oversized monsters.

Each major boss requires:

* unique silhouette;
* strong narrative identity;
* mechanically distinct phases;
* arena interaction;
* recognizable audiovisual signature;
* at least one mechanic connected to its lore;
* unique chase rewards.

Example concept:

## The King Who Never Existed

Historical records indicate that the forgotten civilization had no king.

Nevertheless, a throne room reconstructs itself and someone sits on the
throne.

During the encounter the empty arena progressively remembers a kingdom:
walls, soldiers, structures and hazards return as the boss becomes more
complete.

Kip recognizes the king but initially refuses or fails to explain why.

---

# 41. LOCKED VISUAL DIRECTION

The preferred visual baseline is **colorful, stylized, premium isometric
fantasy with modern rendering**.

The intention is to capture broad qualities such as warmth, readability,
exaggerated silhouettes and painterly charm while establishing original
EMBERFALL characters, monsters, environments, UI, lore and asset
language.

## 41.1 Rendering

* modern PBR materials;
* excellent global/local lighting;
* volumetric depth;
* painterly surface treatment;
* strong silhouettes;
* controlled saturation;
* vivid elemental effects;
* readable combat at isometric distance.

## 41.2 Character Style

* stylized mature proportions;
* chunky readable armor;
* slightly exaggerated weapons;
* expressive animation;
* recognizable silhouettes;
* not photorealistic;
* not chibi;
* not toy-like.

## 41.3 Signature Palette

Recurring visual relationship:

* snow/ice white;
* mineral turquoise/blue;
* obsidian/charcoal;
* ember orange;
* forged bronze;
* selective crystal violet.

## 41.4 Legal/Creative Originality Rule

Do not reproduce specific assets, characters, monsters, interfaces,
icons, logos, environments, story elements, names or distinctive designs
from existing games.

Reference broad genre qualities only.

---

# 42. MODERN UI --- FINAL DIRECTION

The UI should combine modern usability with subtle forged-fantasy
materials.

The gameplay view must remain dominant.

## 42.1 HUD

### Upper left

Compact hero portrait, level, health/resource and important statuses.

Kip appears as a small companion indicator below or integrated beside
the hero state when necessary.

### Upper center

Only used for bosses, major elites and temporary encounter information.

### Upper right

Clean minimap, region, tier and compact objective tracking.

### Bottom center

Compact ability strip.

Use: - thin dark translucent background; - restrained bronze/ember
accents; - clear cooldown visualization; - strong keyboard/controller
labels; - minimal ornament.

Avoid enormous classic health/mana globes as the default final UI.

## 42.2 Kip Interface

Kip's dedicated screen contains:

* 3D/animated Kip model;
* Sync Level;
* recovered memories;
* active modules;
* upgrade branches;
* Codex/bestiary;
* detected anomalies;
* story log.

Kip upgrades should visually modify the model.

## 42.3 Inventory

Premium dark interface with:

* large character model;
* equipment slots;
* clean item grid;
* strong filtering;
* mechanical effects emphasized;
* compact currencies;
* modern typography.

## 42.4 UI Motion

Use subtle: - panel fades; - ember traces; - scan lines from Kip; -
material shimmer; - responsive hover/focus states.

Avoid constant noisy animation.

---

# 43. PHASE 0 --- CODEX-READY PLAYABLE PROTOTYPE

## 43.1 Engine

Use **Unreal Engine 5.x** as the primary target for the visual prototype
unless a technical evaluation demonstrates a clear blocker.

Architecture should remain friendly to C++ plus Blueprint/data-driven
content.

Codex should prefer maintainable source-controlled systems over fragile
editor-only logic.

## 43.2 Prototype Goal

Create a polished **20--30 minute repeatable combat prototype** proving:

1. movement feels excellent;
2. attacks feel excellent;
3. enemies are enjoyable to fight;
4. Kip is useful and memorable;
5. level-ups feel meaningful;
6. loot creates excitement;
7. the visual direction reads as premium PC/console rather than mobile.

Do not implement full multiplayer yet.

## 43.3 Prototype Environment

One handcrafted/procedurally extendable section of the
**Deepstone/Frostvein Mines**.

Required elements:

* dark mine rock;
* rails;
* wooden/metal bridges;
* blue crystals;
* orange forge/lava lighting;
* vertical chasm;
* machinery;
* destructible props where practical;
* one secret room;
* one boss arena.

## 43.4 Playable Character

Prototype class: **Berserker**.

Required actions:

### Basic Attack

Responsive melee combo.

### Dodge

Directional evasive move with clear timing.

### Whirlwind

Mobile area attack.

### Leap

Targeted/aimed jump with impact.

### Groundbreaker

Heavy directional or radial impact attack.

### War Cry

Temporary combat utility/buff.

Every action needs animation, hit reaction, sound hook, VFX hook,
cooldown/resource logic where applicable and controller support.

## 43.5 Kip Prototype

Kip must:

* follow smoothly without obstructing combat;
* avoid obviously robotic pathing;
* illuminate dark areas subtly;
* collect nearby gold/materials;
* identify selected loot;
* react to elites;
* react to secret rooms;
* provide at least three contextual dialogue lines;
* possess an upgrade screen;
* visibly change after one prototype upgrade.

## 43.6 Prototype Enemies

### Buried Worker

Basic melee pressure.

### Tunneler

Can emerge from terrain/walls and reposition.

### Lanternman

Support unit that empowers or reveals nearby enemies.

### Crystal Brute

Slow heavy enemy with destructible/phase-based crystal armor.

### Buried Foreman --- Elite

Coordinates nearby Buried and introduces the player to elite mechanics.

## 43.7 Prototype Boss

**The Last Foreman**

Narrative: An ancient supervisor fused with mining machinery who
continues enforcing a work cycle that ended centuries ago.

Mechanics should include:

* drill/charge attack;
* machinery activation;
* falling debris telegraph;
* add phase;
* exposed core phase;
* environmental interaction;
* final desperate phase.

Kip should recognize fragments of the Foreman's commands.

## 43.8 Levels 1--10 Prototype Progression

Every level must produce a noticeable event.

Suggested structure:

**1:** Basic Attack + Whirlwind
**2:** Dodge improvement / first active choice
**3:** Passive point
**4:** Leap
**5:** Whirlwind modifier choice
**6:** Weapon mastery unlock
**7:** Groundbreaker
**8:** Kip Collection upgrade
**9:** Passive/attribute breakpoint
**10:** War Cry + first Class Mechanic milestone

Exact tuning remains data-driven.

## 43.9 Prototype Loot

Create at least 20 meaningful items.

At least 5 must change mechanics.

Examples:

**Cyclone Maw --- Axe**
Whirlwind gradually pulls enemies inward.

**Emberwake --- Boots**
Dodging leaves a short-lived burning trail.

**Foreman's Grip --- Gloves**
Groundbreaker fractures crystal armor more effectively and creates a
secondary shockwave.

**Echo Fang --- Weapon**
Critical hits can repeat a weaker echo of the attack.

**Anchorbound Relic**
Kip periodically marks a nearby enemy; killing the marked target
improves material drops.

These names and values are provisional and should be revised during
content development.

## 43.10 UI Prototype

Implement:

* minimal main menu;
* gameplay HUD;
* inventory;
* character equipment;
* skill screen;
* Kip screen;
* pause/settings;
* loot tooltip;
* level-up presentation.

No store UI.

No season UI required in Phase 0.

## 43.11 Save

Local prototype persistence:

* level;
* XP;
* equipment;
* inventory;
* skill selections;
* Kip upgrade;
* settings.

Use versioned save data.

## 43.12 Debugging

Provide development commands/tools for:

* invulnerability;
* grant XP;
* set level;
* spawn enemy;
* spawn boss;
* grant item;
* teleport to arena;
* reset save;
* visualize hitboxes;
* display AI state;
* display FPS/frame time.

---

# 44. PHASE 0 TECHNICAL ARCHITECTURE

Suggested Unreal organization:

```text
/Source/Emberfall
  /Core
  /Character
  /Combat
  /Abilities
  /AI
  /Items
  /Loot
  /Progression
  /Kip
  /Interaction
  /Save
  /UI
  /Debug

/Content/Emberfall
  /Characters
  /Enemies
  /Kip
  /Animations
  /Abilities
  /Items
  /Environment
  /VFX
  /Audio
  /UI
  /Maps
  /Data
```

Use Primary Data Assets/Data Tables where appropriate for:

* item definitions;
* enemy definitions;
* ability tuning;
* XP curves;
* level rewards;
* loot tables;
* Kip upgrades.

Gameplay systems must not require manually rewriting source code for
ordinary balance changes.

---

# 45. TEST REQUIREMENTS

Automated/unit-level coverage where practical:

* damage calculation;
* critical calculation;
* XP award;
* level thresholds;
* multiple level gains;
* cooldown state;
* resource consumption;
* loot rarity selection;
* item serialization;
* Kip upgrade prerequisites;
* save version loading.

Functional/integration checks:

* repeated death/restart;
* boss reset;
* inventory full;
* item pickup during combat;
* controller navigation;
* Kip teleport/recovery if separated;
* level-up during combat;
* save/load after level-up;
* changing maps;
* pausing during combat.

No milestone is accepted while critical crashes, progression blockers or
save corruption remain.

---

# 46. PERFORMANCE TARGETS

Prototype should be built with future scalability in mind.

Target PC baseline for the vertical slice:

* 60 FPS gameplay target on representative mid-range hardware at
  intended settings;
* no major hitch when spawning ordinary enemy packs;
* pooled/reused transient effects where appropriate;
* controlled transparent VFX overdraw;
* scalable shadow/VFX options;
* enemy counts profiled rather than guessed.

Do not prematurely optimize systems without profiling evidence.

---

# 47. MULTIPLAYER ROADMAP

Multiplayer begins only after the solo vertical slice is enjoyable and
stable.

Target final mode:

**1--4 player online co-op.**

Later requirements:

* authoritative gameplay;
* client prediction;
* party system;
* friends/invites;
* matchmaking;
* individual loot;
* reconnect;
* revive;
* scalable encounters;
* synchronized dungeon state;
* server-validated progression;
* server-validated leaderboard results.

First networking milestone must support **two players only**.

Do not jump directly to four-player production networking.

---

# 48. LEADERBOARD ROADMAP

Leaderboards are endgame systems, not prototype requirements.

Final categories include:

* Solo Rift;
* Duo;
* Trio;
* 4-player;
* class-specific;
* Hardcore;
* fixed weekly Trial;
* Pinnacle Boss time;
* Friends;
* Regional;
* Global;
* Seasonal.

Competitive submissions must never rely on client-reported completion
values.

---

# 49. CONTENT PIPELINE RULE

Before producing hundreds of enemies/items/rooms, Codex must prove
reusable pipelines.

Required scalable systems:

* data-driven item generator;
* affix system;
* loot tables;
* modular enemy behavior;
* reusable ability framework;
* modular dungeon-room assembly;
* encounter definitions;
* progression definitions;
* localization-ready text;
* reusable UI components.

Content quantity comes after system quality.

---

# 50. CODEX MASTER EXECUTION INSTRUCTION

Codex should treat this document as the canonical product specification.

However:

**Do not attempt to implement the entire document in one task.**

Work milestone by milestone.

For every milestone:

1. inspect the existing repository;
2. write a short implementation plan;
3. identify systems affected;
4. implement incrementally;
5. compile frequently;
6. run available automated tests;
7. launch/test the playable flow when possible;
8. fix regressions;
9. update documentation;
10. leave the repository in a playable state.

When a specification is ambiguous, prefer the solution that supports:

**responsive combat → meaningful progression → readable visuals →
maintainability → future co-op**

Never sacrifice the fundamental combat experience merely to complete a
feature checklist.

---

# 51. IMMEDIATE CODEX PROMPT

Use this as the first implementation instruction after the repository is
created:

> Read `/docs/MASTER_GDD.md` completely before making architectural
> decisions. We are building only Phase 0. Create the initial Unreal
> Engine 5 EMBERFALL project architecture and a playable Deepstone Mines
> combat prototype. Implement an isometric Berserker with responsive
> movement, basic melee combo, directional dodge, Whirlwind, Leap,
> Groundbreaker and War Cry. Add health, combat resource, damage,
> cooldown, death, XP and levels 1--10 using data-driven definitions.
> Implement Kip as a persistent floating companion with smooth
> following, light, gold/material collection, loot identification,
> elite/secret reactions and one visible upgrade. Add Buried Worker,
> Tunneler, Lanternman, Crystal Brute, Buried Foreman elite and The Last
> Foreman boss. Create at least 20 prototype items, including at least
> five mechanically transformative effects. Implement a clean modern
> dark HUD, inventory, equipment, skill and Kip interfaces. Add
> versioned local save data, debug commands and tests for deterministic
> systems. Use placeholders where necessary, but preserve the locked
> visual direction: premium colorful stylized isometric fantasy, mineral
> blue against ember orange, modern rendering and no mobile/F2P visual
> language. Do not implement multiplayer, seasons, monetization, full
> procedural generation or levels beyond 10 in this milestone. The
> deliverable is a stable, replayable 20--30 minute combat prototype.
