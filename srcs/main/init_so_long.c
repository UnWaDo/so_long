#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "so_long.h"

static int	init_images(t_so_long *sl)
{
	int	lst_size;

	sl->map->canvas = create_new_image(sl->mlx, \
		(t_pos){.x = WIDTH, .y = HEIGHT}, I_MAP_CODE);
	if (sl->map->canvas == NULL)
		return (-1);
	lst_size = ft_lstsize(sl->mlx->images);
	load_xpm_image(sl->mlx, HERO_IMG, I_HERO_CODE);
	if (ft_lstsize(sl->mlx->images) == lst_size)
	{
		ft_printf("Error\n%s\n", MLX_IMG_ERR);
		return (-1);
	}
	lst_size++;
	load_xpm_image(sl->mlx, WALL_IMG, I_WALL_CODE);
	if (ft_lstsize(sl->mlx->images) == lst_size)
	{
		ft_printf("Error\n%s\n", MLX_IMG_ERR);
		return (-1);
	}
	lst_size++;
	load_xpm_image(sl->mlx, EMPTY_IMG, I_EMPTY_CODE);
	if (ft_lstsize(sl->mlx->images) == lst_size)
	{
		ft_printf("Error\n%s\n", MLX_IMG_ERR);
		return (-1);
	}
	lst_size++;
	load_xpm_image(sl->mlx, COLL_IMG, I_COLL_CODE);
	if (ft_lstsize(sl->mlx->images) == lst_size)
	{
		ft_printf("Error\n%s\n", MLX_IMG_ERR);
		return (-1);
	}
	lst_size++;
	load_xpm_image(sl->mlx, ENEMY_IMG, I_ENEMY_CODE);
	if (ft_lstsize(sl->mlx->images) == lst_size)
	{
		ft_printf("Error\n%s\n", MLX_IMG_ERR);
		return (-1);
	}
	lst_size++;
	load_xpm_image(sl->mlx, EXIT_IMG, I_EXIT_CODE);
	if (ft_lstsize(sl->mlx->images) == lst_size)
	{
		ft_printf("Error\n%s\n", MLX_IMG_ERR);
		return (-1);
	}
	return (0);
	// sl->hero->icon = create_new_image(sl->mlx)
}

static void	clean_up(t_so_long *sl)
{
	if (sl->map)
		delete_map(sl->map);
	if (sl->hero)
		free(sl->hero);
	if (sl->mlx)
		clear_mlx(sl->mlx->mlx);
}

t_so_long	*init_so_long(char *map_path)
{
	t_so_long	*sl;

	sl = ft_calloc(1, sizeof(*sl));
	if (!sl)
	{
		ft_printf("Error\n%s\n", SL_ALLOC_ERR);
		return (NULL);
	}
	sl->map = read_map(map_path);
	if (sl->map == NULL)
	{
		free(sl);
		return (NULL);
	}
	sl->hero = init_hero(sl->map);
	if (sl->hero == NULL)
	{
		clean_up(sl);
		return (NULL);
	}
	sl->mlx = start_mlx_win((t_pos){.x = WIDTH, .y = HEIGHT}, TITLE);
	if (sl->mlx == NULL)
	{
		clean_up(sl);
		return (NULL);
	}
	if (init_images(sl))
	{
		delete_map(sl->map);
		free(sl->hero);
		clear_mlx(sl->mlx);
		free(sl);
		return (NULL);
	}
	return (sl);
}
