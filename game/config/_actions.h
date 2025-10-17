
#ifndef _ACTION_H
#define _ACTION_H

enum e_game_actions
{
	ACT_MoveForward,
	ACT_MoveBackward,
	ACT_StrafeLeft,
	ACT_StrafeRight,
	ACT_Interact,
	ACT_Pause,
	ACT_COUNT
}

static inline void	game_bind_actions(t_actions *A, t_action_ids[ACT_COUNT])
{
	ids[ACT_MoveForward] = action_register(A, "MoveForward");
	ids[ACT_MoveBackward] = action_register(A, "MoveBackward");
	ids[ACT_StrafeLeft] = action_register(A, "StrafeLeft");
	ids[ACT_StrafeRight] = action_register(A, "StrafeRight");
	ids[ACT_Interact] = action_register(A, "Interact");
	ids[ACT_Pause] = action_register(A, "Pause");
	actions_bind_axis_keys(A, ids[ACT_MoveForward], KEY_W, KEY_S, 0);
	actions_bind_axis_keys(A, ids[ACT_MoveRight], KEY_D, KEY_A, 0);
	actions_bind_key(A, ids[ACT_Interact], KEY_E, ACTION_ON_PRESS, 0);
	actions_bind_key(A, ids[ACT_Pause], KEY_ESC, ACTION_ON_PRESS, 0);
}

#endif
