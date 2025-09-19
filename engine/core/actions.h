
#ifndef ACTIONS_H
#define ACTIONS_H

# include "../platform/input.h"

#ifndef ACTION_MAX
# define ACTION_MAX 54
#endif

typedef int	t_action_id;

typedef enum e_action_trigger
{
	ACTION_ON_PRESS = 0,
	ACTION_ON_RELEASE,
	ACTION_WHILE_HELD,
	ACTION_AXIS_KEYS
}	t_action_trigger;

typedef struct	s_action_state
{
	float			value;
	unsigned char	pressed;
	unsigned char	released;
}	t_action_state;

typedef struct s_actions
{
	t_action_state	state[ACTION_MAX];
}	t_actions;

/* lifecycle */
void	action_init();
void	action_clear();

/* action registration*/
t_action_id	actions_register(t_actions *A, const char *name);

/* binding helpers */
void	actions_bind_key(t_actions *A, t_action_id id, int key, t_action_trigger trig, int mods);
void	actions_bind_axis_keys(t_actions *A, t_action_id id, int key_pos, int key_neg, int mods);

/* per-frame handling */
void	actions_begin_frame(t_actions *A);
void	actions_update_from_input(t_actions *A, const t_input *I);

/* queries */
float	action_value(const t_actions *A, t_actions_id id);
int		action_pressed(const t_actions *A, t_actions_id id);
int		action_released(const t_actions *A, t_actions_id id);

#endif
