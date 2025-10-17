
#include <stdlib.h>
#include "platform.h"
#include "window.h"
#include "libft.h"
#include "mlx.h"

int		platform_init(t_platform *P, int width, int height, const char *title)
{
	P->main_index = -1;
	P->mlx = mlx_init();
	if (!P->mlx)
		return (0);
	if (!window_create(P->mlx, &P->windows[0], width, height, title))
	{
		mlx_destroy_display(P->mlx);
		free(P->mlx);
		ft_memset(P, 0, sizeof(*P));
		return (0);
	}
	P->window_count = 1;
	P->main_index = 0;
	ft_memset(&P->input, 0, sizeof(P->input));
	return (1);
}

void	platform_shutdown(t_platform *P)
{
	int	i;

	i = 0;
	while (i < P->window_count)
		window_destroy(P->mlx, &P->windows[i++]);
	if (P->mlx)
	{
		mlx_destroy_display(P->mlx);
		free(P->mlx);
	}
	ft_memset(P, 0, sizeof(*P));
	P->main_index = -1;
}
