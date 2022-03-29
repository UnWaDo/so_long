/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:13:07 by lalex             #+#    #+#             */
/*   Updated: 2022/03/29 01:13:09 by lalex            ###   ########.fr       */
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
	free(mlx);
}
