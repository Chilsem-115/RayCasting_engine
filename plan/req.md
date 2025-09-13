
# ENGINE vs GAME SPLIT

## ENGINE RESPONSIBILITIES
- **Platform Core**
  - Window, backbuffer (MLX)
  - Timing, logging
  - Input abstraction (keys/mouse)

- **Rendering**
  - Raycasting walls, floor/ceiling
  - Sprites, z-buffer
  - Fog/light hooks
  - Post-FX (vignette, shake, grain)

- **World Data**
  - Tile map representation
  - Door mechanics (open/close, timed)
  - Triggers (volumes/buttons, generic)

- **Collision**
  - Movement vs walls
  - Ray queries (visibility, hits)
  - Simple BFS helper for pathing

- **Assets I/O**
  - Load textures (XPM/raw)
  - Parse text maps
  - Optional audio backend (stubbed if off)

- **Event Bus**
  - Subscribe/emit events (doors, triggers, resize, etc.)

- **API Surface**
  - Opaque handles
  - Getters/setters
  - Modules (raycast, audio, etc.)

## GAME RESPONSIBILITIES
- **Gameplay Logic**
  - Win/lose conditions
  - Stamina, crouch rules

- **AI Behaviors**
  - Enemy state machines
  - Patrol/search/chase
  - Uses engine BFS/LOS helpers

- **Content**
  - Maps, textures, sounds
  - Entity placement

- **Interaction Semantics**
  - Meaning of keys, triggers
  - Puzzle logic
  - Door unlock rules

- **UI/UX**
  - Menus, prompts, inventory
  - Overlays, difficulty options

- **Audio Direction**
  - Decide which sounds play when
  - Mixing choices

## DECISION RULE
- Generic, reusable system → **Engine**
- Specific to horror design or balance → **Game**

## OPEN QUESTIONS
- Doors: engine = mechanics only? game = key requirements?  
- Triggers: engine = emit event, game = interpret action?  
- AI helpers: engine = BFS/LOS, game = behavior states?  
- PostFX: engine = toggles, game = when/why to enable?  
