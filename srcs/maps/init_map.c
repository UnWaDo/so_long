#include "so_long.h"
#include "libft.h"

static t_map	*alloc_map(t_map *map)
{
	int	i;

	map->map = malloc(map->height * sizeof(*(map->map)));
	if (map->map == NULL)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		map->map[i] = malloc(map->width * sizeof(**(map->map)));
		if (map->map[i] == NULL)
		{
			while (i--)
				free(map->map[i]);
			free(map->map);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static int	get_width(t_list *map_lines)
{
	size_t	width;

	width = ft_strlen(map_lines->content);
	while (map_lines)
	{
		if (ft_strlen(map_lines->content) != width)
			return (0);
		map_lines = map_lines->next;
	}
	if (width > __INT_MAX__)
		return (0);
	return ((int) width);
}

t_map	*init_map(t_list *map_lines)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	if (!map)
	{
		ft_printf("Error\n%s\n", MAP_ALLOC_ERR);
		return (NULL);
	}
	map->height = ft_lstsize(map_lines);
	map->width = get_width(map_lines);
	if (map->width <= 2 || map->height <= 2)
	{
		ft_printf("Error\n%s\n", MAP_SHAPE_ERR);
		free(map);
		return (NULL);
	}
	if (alloc_map(map) == NULL)
	{
		ft_printf("Error\n%s\n", MAP_ALLOC_ERR);
		return (NULL);
	}
	map->canvas = NULL;
	return (map);
}
