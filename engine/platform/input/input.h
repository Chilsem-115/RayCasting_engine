
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

/* frame lifecycle (call from core loop) */
void    input_frame_begin(t_input *in);

/* platform hook helpers (call from input_linux.c MLX callbacks) */
void    input_key_down(t_input *in, int keycode);
void    input_key_up(t_input *in, int keycode);
void    input_mouse_move(t_input *in, int x, int y);
void    input_wheel(t_input *in, int delta);
void    input_focus(t_input *in, int has_focus);

/* queries (ergonomics) */
int     input_is_held(const t_input *in, int keycode);
int     input_pressed(const t_input *in, int keycode);
int     input_released(const t_input *in, int keycode);


#endif
