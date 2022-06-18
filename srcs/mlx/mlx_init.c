/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:10:32 by lalex             #+#    #+#             */
/*   Updated: 2022/06/18 20:20:57 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mlx.h"
#include "so_long_utils.h"
#include "ft_printf.h"

t_mlx	*start_mlx_win(int w, int h, char *title)
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
	mlx->win = mlx_new_window(mlx->mlx, w, h, title);
	if (mlx->win == NULL)
	{
		ft_printf("Error\n%s\n", MLX_WIN_ERR);
		free(mlx);
		return (NULL);
	}
	mlx->images = NULL;
	return (mlx);
}
