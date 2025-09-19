
#ifndef WINDOW_H
#define WINDOW_H

# include "mlx.h"
# include "libft.h"

typedef struct s_window
{
	void	*handle;
	void	*backbuf;
	void	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_window;

int		window_create(void *mlx, t_window *win, int w, int h, const char *title);
void	window_destroy(void *mlx, t_window *win);
void	push_frame(void	*mlx, const t_window *w);

#endif
