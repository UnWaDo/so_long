/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:10:06 by lalex             #+#    #+#             */
/*   Updated: 2022/03/29 01:16:33 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"
#include "so_long_hero.h"

static void	put_object(t_mlx *mlx, t_img *img, t_pos loc, int code)
{
	loc.x *= CELL_WIDTH;
	loc.y *= CELL_WIDTH;
	put_img(img, get_loaded_img(mlx->images, I_EMPTY_CODE), loc);
	if (code == HERO_CODE)
		put_img(img, get_loaded_img(mlx->images, I_HERO_CODE), loc);
	else if (code == WALL_CODE)
		put_img(img, get_loaded_img(mlx->images, I_WALL_CODE), loc);
	else if (code == ENEMY_CODE)
		put_img(img, get_loaded_img(mlx->images, I_ENEMY_CODE), loc);
	else if (code == COLL_CODE)
		put_img(img, get_loaded_img(mlx->images, I_COLL_CODE), loc);
	else if (code == EXIT_CODE)
		put_img(img, get_loaded_img(mlx->images, I_EXIT_CODE), loc);
}

static t_pos	get_start(t_map *map, t_pos imgwh, t_pos hero)
{
	t_pos	loc;

	imgwh = (t_pos){.x = imgwh.x / CELL_WIDTH + ((imgwh.x % CELL_WIDTH) != 0),
		.y = imgwh.y / CELL_WIDTH + ((imgwh.y % CELL_WIDTH) != 0)};
	if (imgwh.x >= map->width || hero.x < imgwh.x / 2)
		loc.x = 0;
	else if (hero.x > map->width - imgwh.x / 2)
		loc.x = map->width - imgwh.x;
	else if (hero.x >= imgwh.x / 2)
		loc.x = hero.x - imgwh.x / 2;
	if (imgwh.y >= map->height || hero.y < imgwh.y / 2)
		loc.y = 0;
	else if (hero.y > map->height - imgwh.y / 2)
		loc.y = map->height - imgwh.y;
	else if (hero.y >= imgwh.y / 2)
		loc.y = hero.y - imgwh.y / 2;
	return (loc);
}

static t_pos	get_end(t_map *map, t_pos imgwh, t_pos hero)
{
	t_pos	loc;

	imgwh = (t_pos){.x = imgwh.x / CELL_WIDTH + ((imgwh.x % CELL_WIDTH) != 0),
		.y = imgwh.y / CELL_WIDTH + ((imgwh.y % CELL_WIDTH) != 0)};
	if (imgwh.x >= map->width || hero.x > map->width - imgwh.x / 2)
		loc.x = map->width;
	else if (hero.x < imgwh.x / 2)
		loc.x = imgwh.x;
	else if (hero.x <= map->width - imgwh.x / 2)
		loc.x = hero.x + imgwh.x / 2;
	if (imgwh.y >= map->height || hero.y > map->height - imgwh.y / 2)
		loc.y = map->height;
	else if (hero.y < imgwh.y / 2)
		loc.y = imgwh.y;
	else if (hero.y <= map->height - imgwh.y / 2)
		loc.y = hero.y + imgwh.y / 2;
	return (loc);
}

void	draw_map(t_mlx *mlx, t_map *map)
{
	t_pos	loc;
	t_pos	start;
	t_pos	end;
	t_pos	hero;
	char	code;

	fill_with_img(map->canvas, get_loaded_img(mlx->images, I_BACKG_CODE));
	hero = get_hero_pos(map);
	start = get_start(map, map->canvas->w_h, hero);
	end = get_end(map, map->canvas->w_h, hero);
	loc.y = 0;
	while (start.y + loc.y < end.y)
	{
		loc.x = 0;
		while (start.x + loc.x < end.x)
		{
			code = map->map[start.y + loc.y][start.x + loc.x];
			put_object(mlx, map->canvas, loc, code);
			loc.x++;
		}
		loc.y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, map->canvas->img, 0, 0);
}
