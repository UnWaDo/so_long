/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:24:44 by lalex             #+#    #+#             */
/*   Updated: 2022/01/03 18:34:24 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft.h"
# include "ft_printf.h"
# include "so_long_map.h"
# include "so_long_hero.h"
# include "so_long_mlx.h"
# include "so_long_utils.h"

typedef struct s_so_long
{
	t_hero	*hero;
	t_map	*map;
	t_mlx	*mlx;
}	t_so_long;

t_so_long	*init_so_long(char *map);
int			close_ok(t_so_long *so_long);
int			close_error(t_so_long *so_long);

# define SL_ALLOC_ERR	"So long allocation failed"

# define WIDTH	640
# define HEIGHT	480
# define TITLE	"So long..."

#endif