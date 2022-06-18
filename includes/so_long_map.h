/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:09:17 by lalex             #+#    #+#             */
/*   Updated: 2022/06/18 20:19:34 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MAP_H
# define SO_LONG_MAP_H

# include "so_long_mlx.h"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	t_img	*canvas;
}	t_map;

t_map	*read_map(const char *file);
t_map	*init_map(t_list *map_lines);
t_list	*get_map_lines(const char *file);
int		check_map(t_map *map);
void	draw_map(t_mlx *mlx, t_map *map);
void	delete_map(t_map *map);

# define CELL_WIDTH		64

# define ALLOWED_CHARS	"01CEPR"
# define MAP_FILE_ERR	"Invalid map file"
# define MAP_ALLOC_ERR	"Map allocation failed"
# define MAP_READ_ERR	"Map reading error"
# define MAP_SHAPE_ERR	"Map has an invalid format"
# define MAP_WALL_ERR	"Map is not surrounded by walls"
# define MAP_INV_ERR	"Invalid map char"
# define MAP_HERO_ERR	"Zero or several hero positions"
# define MAP_EXIT_ERR	"Zero or several exit positions"
# define MAP_COLL_ERR	"Map must have at least 1 collectible"

# define EMPTY_CODE		'0'
# define WALL_CODE		'1'
# define HERO_CODE		'P'
# define COLL_CODE		'C'
# define EXIT_CODE		'E'
# define ENEMY_CODE		'R'

# define BG_COLOR		0055110110

#endif