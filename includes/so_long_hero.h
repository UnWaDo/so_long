#ifndef SO_LONG_HERO_H
# define SO_LONG_HERO_H

# include "so_long_map.h"
# include "so_long_mlx.h"
# include "so_long_utils.h"

typedef struct s_hero
{
	t_pos	pos;
	int		hp;
	int		xp;
	int		status;
	size_t	steps_done;
}	t_hero;

t_hero		*init_hero(t_map *map);
t_pos		get_hero_pos(t_map *map);
void		move_hero(t_hero *hero, t_map *map, t_pos pos);
void		move_hero_rel(t_hero *hero, t_map *map, t_pos pos);
int			damage_hero(t_hero *hero, int damage);
void		print_hero_status(t_hero *hero);
void		game_over(t_hero *hero);

# define HERO_ALLOC_ERR	"Hero allocation failed"
# define HERO_UNDEF_ERR	"Hero location is absent"

# define STATUS_HEALTHY	0b1
# define STATUS_HURT	0b10
# define STATUS_DAMAGED	0b100
# define STATUS_DEAD	0b1000
# define STATUS_WON		0b10000

#endif