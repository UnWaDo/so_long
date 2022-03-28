#include "so_long_map.h"
#include "ft_printf.h"

static int	check_walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width && map->map[0][x] == WALL_CODE
		&& map->map[map->height - 1][x] == WALL_CODE)
		x++;
	y = 0;
	while (y < map->height && map->map[y][0] == WALL_CODE
		&& map->map[y][map->width - 1] == WALL_CODE)
		y++;
	if (x < map->width || y < map->height)
	{
		ft_printf("Error\n%s\n", MAP_WALL_ERR);
		return (-1);
	}
	return (0);
}

static void	clean_mand(char mand[3])
{
	mand[0] = 0;
	mand[1] = 0;
	mand[2] = 0;
}

static int	check_mand(char mand[3])
{
	int	res;

	res = 0;
	if (mand[0] != 1)
		res = -1;
	else if (mand[1] != 1)
		res = -2;
	else if (mand[2] < 1)
		res = -3;
	if (res == -1)
		ft_printf("Error\n%s\n", MAP_HERO_ERR);
	else if (res == -2)
		ft_printf("Error\n%s\n", MAP_EXIT_ERR);
	else if (res == -3)
		ft_printf("Error\n%s\n", MAP_COLL_ERR);
	return (res);
}

static char	check_iteration(char mand[3], char c)
{
	char	*pos;

	mand[0] += c == HERO_CODE;
	mand[1] += c == EXIT_CODE;
	mand[2] += c == COLL_CODE;
	pos = ft_strchr(ALLOWED_CHARS, c);
	if (pos)
		return (0);
	return (c);
}

int	check_map(t_map *map)
{
	t_pos	crds;
	char	mand[3];
	char	s;

	if (check_walls(map))
		return (-1);
	crds = (t_pos){.y = 1};
	clean_mand(mand);
	s = 0;
	while (crds.y < map->height && !s)
	{
		crds.x = 1;
		while (crds.x < map->width && !s)
		{
			s = check_iteration(mand, map->map[crds.y][crds.x]);
			crds.x++;
		}
		crds.y++;
	}
	if (s)
		ft_printf("Error\n%s: %c\n", MAP_INV_ERR, s);
	else
		return (check_mand(mand));
	return (s);
}
