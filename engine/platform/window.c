
#include "window.h"

static void	set_pixel_data(t_window *win, int w, int h)
{
	win->addr = mlx_get_data_addr(
			win->backbuf,
			&win->bpp,
			&win->line_len,
			&win->endian
			);
	win->width = w;
	win->height = h;
}

int	window_create(void *mlx, t_window *win, int width, int height, const char *title)
{
	ft_memset(win, 0, sizeof(*win));
	win->handle = mlx_new_window(mlx, width, height, (char *)title);
	if (!win->handle)
		return (0);
	win->backbuf = mlx_new_image(mlx, width, height);
	if (!win->backbuf)
	{
		mlx_destroy_window(mlx, win->handle);
		ft_memset(win, 0, sizeof(*win));
		return (0);
	}
	set_pixel_data(win, w, h);
	return (1);
}

void	window_destroy(void *mlx, t_window *w)
{
	if (!w)
		return ;
	if (w->backbuf)
		mlx_destroy_image(mlx, w->backbuf);
	if (w->handle)
		mlx_destroy_window(mlx, w->handle);
	ft_memset(w, 0, sizeof(*w));
}

void	push_frame(void	*mlx, const t_window *w)
{
	if (!w || !w->handle || !w->backbuf)
		return ;
	mlx_put_image_to_window(mlx, w->handle, w->backbuf, 0, 0);
}
