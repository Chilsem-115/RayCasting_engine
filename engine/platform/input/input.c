
#include "libft.h"
#include "input.h"

int     input_is_held(const t_input *in, int keycode)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return (in->keyboard.held[keycode] != 0);
	return (0);
}

int     input_pressed(const t_input *in, int keycode)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return (in->keyboard.pressed[keycode] != 0);
	return (0);
}

int     input_released(const t_input *in, int keycode)
{
	if (keycode >= 0 && keycode < KEY_MAX)
		return (in->keyboard.released[keycode] != 0);
	return (0);
}

void	input_frame_begin(t_input *in)
{
	ft_memset(in->keyboard.pressed, 0, sizeof(in->keyboard.pressed));
	ft_memset(in->keyboard.released, 0, sizeof(in->keyboard.released));
	in->mouse.mouse_dx = 0;
	in->mouse.mouse_dy = 0;
	in->mouse.wheel   = 0;
}
