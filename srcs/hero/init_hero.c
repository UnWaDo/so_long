/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:09:52 by lalex             #+#    #+#             */
/*   Updated: 2022/03/29 01:09:52 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_hero.h"
#include "ft_printf.h"

t_pos	get_hero_pos(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == HERO_CODE)
				return ((t_pos){.x = x, .y = y});
			x++;
		}
		y++;
	}
	return ((t_pos){.x = -1, .y = -1});
}

t_hero	*init_hero(t_map *map)
{
	t_hero	*hero;

	hero = malloc(sizeof(*hero));
	if (!hero)
	{
		ft_printf("Error\n%s\n", HERO_ALLOC_ERR);
		return (NULL);
	}
	hero->pos = get_hero_pos(map);
	if (hero->pos.x == -1)
	{
		ft_printf("Error\n%s\n", HERO_UNDEF_ERR);
		free(hero);
		return (NULL);
	}
	hero->hp = 100;
	hero->xp = 0;
	hero->status = STATUS_HEALTHY;
	hero->steps_done = 0;
	return (hero);
}
