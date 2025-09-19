
#ifndef INPUT_H
#define INPUT_H

#ifndef KEY_MAX
# define KEY_MAX 512
#endif

/* related input to the keyboard */
typedef struct s_keyboard
{
	unsigned char	held[KEY_MAX];
	unsigned char	pressed[KEY_MAX];
	unsigned char	released[KEY_MAX];
	int				mods;
}	t_keyboard;

/* mouse related input */
typedef struct s_mouse
{
	int	mouse_x;
	int	mouse_y;
	int	mouse_dx;
	int	mouse_dy;
	int	wheel;
}	t_mouse;

/* main stucture */
typedef struct s_input
{
	t_keyboard	keyboard;
	t_mouse		mouse;
	int			has_focus;
}	t_input;

void	input_frame_begin();

#endif
