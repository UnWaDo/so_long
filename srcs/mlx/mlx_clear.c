/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:13:07 by lalex             #+#    #+#             */
/*   Updated: 2022/06/18 20:06:08 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mlx.h"

void	clear_mlx(t_mlx *mlx)
{
	t_list	*el;
	t_list	*next;

	if (mlx == NULL)
		return ;
	el = mlx->images;
	while (el)
	{
		next = el->next;
		mlx_destroy_image(mlx->mlx, ((t_img *)(el->content))->img);
		free(el->content);
		free(el);
		el = next;
	}
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx)
		free(mlx);
}
