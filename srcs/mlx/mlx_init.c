#include "so_long_mlx.h"
#include "so_long_utils.h"
#include "ft_printf.h"

t_mlx	*start_mlx_win(t_pos w_h, char *title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(*mlx));
	if (!mlx)
	{
		ft_printf("Error\n%s\n", MLX_ALLOC_ERR);
		return (NULL);
	}
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
	{
		ft_printf("Error\n%s\n", MLX_INIT_ERR);
		free(mlx);
		return (NULL);
	}
	mlx->win = mlx_new_window(mlx->mlx, w_h.x, w_h.y, title);
	if (mlx->win == NULL)
	{
		ft_printf("Error\n%s\n", MLX_WIN_ERR);
		mlx_destroy_display(mlx->mlx);
		free(mlx);
		return (NULL);
	}
	mlx->images = NULL;
	return (mlx);
}
