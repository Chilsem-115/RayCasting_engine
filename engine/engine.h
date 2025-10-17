
#ifndef ENGINE_H
#define ENGINE_H

# include "platform/platform.h"
# include "core/actions/actions.h"
# include "_config.h"

/* forward declarations to avoid heavy includes here */
typedef struct s_timing		t_timing;
typedef struct s_render		t_render;
typedef struct s_events		t_events;

/* general engine state  */
typedef struct s_context
{
	t_platform	platform;
	/*
	t_timing	timing;
	t_render	render;
	t_events	events;
	*/
	t_actions	actions;
}	t_context;

/* Entry */
int		engine_runtime(void);

/* core components */

/* push to a specific window index */
void    engine_push_frame(t_context *ctx, int index);

#endif
