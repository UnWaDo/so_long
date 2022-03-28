#include "so_long.h"
#include "libft.h"
#include "so_long_map.h"

void	delete_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

static void	read_lines(t_map *map, t_list *map_lines)
{
	char	*line;
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		line = map_lines->content;
		while (x < map->width)
		{
			map->map[y][x] = line[x];
			x++;
		}
		map_lines = map_lines->next;
		y++;
	}
}

t_map	*read_map(const char *file)
{
	t_map	*map;
	t_list	*map_lines;

	map_lines = get_map_lines(file);
	if (!map_lines)
		return (NULL);
	map = init_map(map_lines);
	if (!map)
	{
		ft_lstclear(&map_lines, &free);
		return (NULL);
	}
	read_lines(map, map_lines);
	ft_lstclear(&map_lines, &free);
	if (check_map(map))
	{
		delete_map(map);
		return (NULL);
	}
	return (map);
}
