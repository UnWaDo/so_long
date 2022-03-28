#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "so_long.h"

static int	key_released(int keycode, t_so_long *sl)
{
	if (keycode == KEYCODE_W)
		move_hero_rel(sl->hero, sl->map, (t_pos){.x = 0, .y = -1});
	else if (keycode == KEYCODE_S)
		move_hero_rel(sl->hero, sl->map, (t_pos){.x = 0, .y = 1});
	else if (keycode == KEYCODE_A)
		move_hero_rel(sl->hero, sl->map, (t_pos){.x = -1, .y = 0});
	else if (keycode == KEYCODE_D)
		move_hero_rel(sl->hero, sl->map, (t_pos){.x = 1, .y = 0});
	else if (keycode == KEYCODE_ESCAPE)
		close_ok(sl);
	else
		return (-1);
	if ((sl->hero->status & STATUS_WON) || (sl->hero->status & STATUS_DEAD))
		close_ok(sl);
	draw_map(sl->mlx, sl->map);
	print_hero_status(sl->hero);
	return (0);
}

int	main(int argc, char **argv)
{
	t_so_long	*sl;

	if (argc != 2)
	{
		ft_printf("Usage: %s path_to_map.ber\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	sl = init_so_long(argv[1]);
	if (sl == NULL)
		exit(EXIT_FAILURE);
	draw_map(sl->mlx, sl->map);
	print_hero_status(sl->hero);
	mlx_key_hook(sl->mlx->win, &key_released, sl);
	mlx_hook(sl->mlx->win, ON_DESTROY, 0, &close_ok, sl);
	mlx_loop(sl->mlx->mlx);
	return (0);
}
