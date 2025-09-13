
.
├── assets/
│   ├── maps/
│   ├── textures/
│   ├── sprites/
│   └── sounds/
├── build/
│   ├── bin/
│   ├── lib/
│   └── obj/
├── engine/                          # engine library (builds libengine.a)
│   ├── core/                        # lifecycle, timing, logging, errors, events
│   │   ├── app.c
│   │   ├── app.h                    # public: create/run/destroy (opaque handles live here)
│   │   ├── loop.c                   # internal
│   │   ├── time.c                   # internal
│   │   ├── log.c                    # internal
│   │   ├── errors.c                 # internal
│   │   ├── events.c                 # internal
│   │   └── events.h                 # public: event ids & payload structs (small)
│   ├── platform/                    # MLX + X11 glue (window, input)
│   │   ├── window.c
│   │   ├── window.h                 # public: window/backbuffer handles (opaque)
│   │   ├── input_linux.c
│   │   └── input.h                  # public: key/mouse enums & queries
│   ├── gfx/                         # backbuffer ops, present, postfx toggles
│   │   ├── gfx.c
│   │   └── gfx.h                    # public: present(), postfx toggles, fog params
│   ├── raycast/                     # renderer module (walls/floor/sprites)
│   │   ├── rc_module.c
│   │   ├── rc_render.c
│   │   ├── rc_map.c
│   │   ├── rc_sprite.c
│   │   └── rc.h                     # public: world/camera controls, ray queries
│   ├── world/                       # map data, collision, doors, triggers, BFS
│   │   ├── collision.c
│   │   ├── doors.c
│   │   ├── triggers.c
│   │   ├── path_bfs.c
│   │   └── world.h                  # public: map handle, collision helpers
│   ├── assets/                      # loaders (xpm/raw), file io
│   │   ├── file_io.c
│   │   ├── texture_xpm.c
│   │   └── assets.h                 # public: load/free textures, read files
│   ├── audio/                       # optional module (single-header backend)
│   │   ├── audio_module.c
│   │   └── audio.h                  # public: minimal play/stop (no-ops if disabled)
│   └── util/                        # misc helpers shared internally
│       ├── rng.c
│       ├── str.c
│       ├── mem.c
│       └── util_i.h                 # internal-only helpers (not included by game)
├── game/                            # your game (links libengine.a)
│   ├── main.c                       # (placeholder only; no code today)
│   └── gamecode/                    # ai, triggers→actions, etc. (later)
├── lib/
│   ├── mlx/
│   └── libft/
├── plan/
│   ├── overall.md
│   ├── req.md
│   ├── api_surface.md               # categories only (no signatures)
│   └── events_catalog.md            # v1 event types & dispatch timing
├── Makefile
└── README.md

