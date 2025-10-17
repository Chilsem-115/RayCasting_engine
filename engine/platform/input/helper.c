
#include "libft.h"
#include "input.h"

/* Key pressed this frame */
void	input_key_down(t_input *in, int keycode)
{
	if (!(keycode >= 0 && keycode < KEY_MAX))
		return ;
	if (!in->keyboard.held[keycode])
	{
		in->keyboard.held[keycode]     = 1;
		in->keyboard.pressed[keycode]  = 1;
	}
}

/* Key released this frame */
void	input_key_up(t_input *in, int keycode)
{
	if (!(keycode >= 0 && keycode < KEY_MAX))
		return;
	if (in->keyboard.held[keycode])
		in->keyboard.released[keycode] = 1;
	in->keyboard.held[keycode] = 0;
}

/* Mouse move: update delta from last position */
void	input_mouse_move(t_input *in, int x, int y)
{
	int dx = x - in->mouse.mouse_x;
	int dy = y - in->mouse.mouse_y;
	in->mouse.mouse_dx += dx;
	in->mouse.mouse_dy += dy;
	in->mouse.mouse_x = x;
	in->mouse.mouse_y = y;
}

/* Wheel: accumulate this frame (caller passes +1/-1 or larger steps) */
void	input_wheel(t_input *in, int delta)
{
	in->mouse.wheel += delta;
}

/* Focus change: on loss, clear held & edges to avoid stuck keys */
void	input_focus(t_input *in, int has_focus)
{
	in->has_focus = has_focus;
	if (!has_focus)
	{
		ft_memset(in->keyboard.held,     0, sizeof(in->keyboard.held));
		ft_memset(in->keyboard.pressed,  0, sizeof(in->keyboard.pressed));
		ft_memset(in->keyboard.released, 0, sizeof(in->keyboard.released));
		in->mouse.mouse_dx = 0;
		in->mouse.mouse_dy = 0;
		in->mouse.wheel    = 0;
	}
}
