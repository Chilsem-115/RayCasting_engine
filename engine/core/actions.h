
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


#endif
