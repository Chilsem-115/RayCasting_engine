
# Engine Public API Surface — Planning Document

## Purpose
Define the **categories** of functions and systems that the engine will expose,  
so any game can build on top of it.  
(No implementation details, no function signatures yet.)

---

## Core Areas

### 1. Lifecycle & Core
- Application creation, run loop, destruction #explain
- Configuration system (window size, title, fps target, audio toggle)  
- Timing (now, delta, fixed-step option)  
- Logging system (info, warn, error)  
- Error reporting (human-readable last error)  
- Feature flags (runtime toggles for optional systems)

### 2. Events
- Central event bus  
- Subscribing/unsubscribing to events  
- Emitting events (from engine or game)  
- Stable event types (e.g., input, trigger, door, resize)  

### 3. Input
- Keyboard state (held, pressed)  
- Mouse position and deltas  
- Future: controller abstraction (optional)

### 4. Graphics
- Backbuffer access + present  
- Camera control (position, rotation, FOV)  
- Post-processing toggles (fog, vignette, shake, palette, etc.)  
- Lighting/fog parameters  

### 5. World & Collision
- World/map loading and management  
- Collision helpers (movement vs. walls, ray queries)  
- Grid BFS/pathfinding helper  
- Door mechanics (open/close, states)  
- Trigger mechanics (generic areas or buttons that emit events)  

### 6. Raycasting Renderer Module
- Rendering pipeline (walls, floors/ceilings, sprites)  
- Depth management (z-buffer)  
- Texture sampling and sprite projection  
- Hooks for fog, lighting, post-fx  

### 7. Assets & I/O
- Texture loading and freeing  
- Generic file I/O helpers  
- Map/Entity format parsers (engine reads core fields, ignores unknown keys)  
- Optional audio backend (stubs if disabled)  

### 8. Modules & Extensibility
- Modules as independent units with init/update/render lifecycle  
- Game registers only what it needs  
- Module order defines update/render order  
- Each module can expose its own optional mini-API  
- Compile-time feature flags (`EN_FEAT_*`) and runtime toggles  

---

## Design Principles
- **Opaque types** in public headers  
- **Minimal, composable APIs** (small functions that do one job)  
- **Event-driven, not hardwired** (engine emits → game decides meaning)  
- **Data-driven formats** (engine ignores unknown keys, forwards to game)  
- **Determinism option** (fixed timestep + seedable RNG)  
- **Semantic versioning** for API (stable / provisional / internal classification)  

---

## Division of Responsibility

**Engine handles:**
- Technical systems, reusable across games  
- Rendering, collision, events, map mechanics  
- Doors/triggers as mechanics only  

**Game handles:**
- Semantics and rules (what triggers do, what doors require)  
- AI behaviors (engine only gives BFS/LOS helpers)  
- Content (maps, textures, sounds, entities)  
- UI/UX, menus, inventory, audio direction  

---

## Open Questions to Finalize
1. **Doors:** engine = mechanics only? game = keys/requirements?  
2. **Triggers:** engine = event emitter, game = action decider?  
3. **AI:** engine = BFS/LOS helpers, game = state machines?  
4. **PostFX:** engine = toggles, game = decides when to use?  

---
