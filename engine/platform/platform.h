
#ifndef PLATFORM_H
#define PLATFORM_H

# include "libft.h"
# include "config.h"
# include "input.h"
# include "window.h"

/*
 * platform includes anything that can change from a platform to another
 * example: window creation, input...etc
 * */
typedef struct s_platform
{
	void		*mlx;
	t_window	windows[MAX_WINDOWS];
	int			window_count;
	int			main_index;
	t_input		input;
}	t_platform;

int		platform_init(t_platform *P, int width, int height, const char title);
void	platform_shutdown(t_platform *P);

#endif
