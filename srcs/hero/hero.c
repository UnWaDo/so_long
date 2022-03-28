#include "so_long_hero.h"
#include "ft_printf.h"

void	move_hero(t_hero *hero, t_map *map, t_pos pos)
{
	if (hero->status & STATUS_DEAD || hero->status & STATUS_WON)
		return ;
	pos.x = ((pos.x % map->width) + map->width) % map->width;
	pos.y = ((pos.y % map->height) + map->height) % map->height;
	if (map->map[pos.y][pos.x] == WALL_CODE)
	{
		damage_hero(hero, 10);
		return ;
	}
	else if (map->map[pos.y][pos.x] == ENEMY_CODE)
	{
		damage_hero(hero, 20);
		hero->xp += 50;
	}
	else if (map->map[pos.y][pos.x] == COLL_CODE)
		hero->xp += 20;
	else if (map->map[pos.y][pos.x] == EXIT_CODE)
		hero->status |= STATUS_WON;
	map->map[hero->pos.y][hero->pos.x] = EMPTY_CODE;
	map->map[pos.y][pos.x] = HERO_CODE;
	hero->pos = pos;
	hero->steps_done += 1;
}

void	move_hero_rel(t_hero *hero, t_map *map, t_pos pos)
{
	t_pos	abs_pos;

	abs_pos = hero->pos;
	abs_pos.x += pos.x;
	abs_pos.y += pos.y;
	move_hero(hero, map, abs_pos);
}

void	print_hero_status(t_hero *hero)
{
	if (hero->status & STATUS_DEAD)
	{
		ft_printf("Hero is dead. Nothing left from it\n");
		return ;
	}
	else if (hero->status & STATUS_DAMAGED)
		ft_printf("Your hero is very tired\n");
	else if (hero->status & STATUS_HURT)
		ft_printf("Your hero is feeling drozy\n");
	else if (hero->status & STATUS_HEALTHY)
		ft_printf("Your hero is full of energy\n");
	if (hero->status & STATUS_WON)
		ft_printf("Congratulations!\n");
	ft_printf("HP: %d\nXP: %d\n", hero->hp, hero->xp);
	ft_printf("You made %u steps\n", hero->steps_done);
}

int	damage_hero(t_hero *hero, int damage)
{
	if (damage <= 0)
		return (hero->hp);
	hero->hp -= damage;
	if (hero->hp < 0)
		hero->hp = 0;
	if (hero->hp == 0)
		hero->status = STATUS_DEAD;
	else if (hero->hp < 40)
		hero->status = STATUS_DAMAGED;
	else if (hero->hp < 80)
		hero->status = STATUS_HURT;
	return (hero->hp);
}
