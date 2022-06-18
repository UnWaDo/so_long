/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:09:59 by lalex             #+#    #+#             */
/*   Updated: 2022/06/18 20:20:20 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_mlx.h"
#include "so_long.h"

static void	clear_so_long(t_so_long *so_long)
{
	free(so_long->hero);
	delete_map(so_long->map);
	clear_mlx(so_long->mlx);
	free(so_long);
}

int	close_ok(t_so_long *so_long)
{
	game_over(so_long->hero);
	clear_so_long(so_long);
	exit(EXIT_SUCCESS);
}

int	close_error(t_so_long *so_long)
{
	game_over(so_long->hero);
	clear_so_long(so_long);
	exit(EXIT_FAILURE);
}
