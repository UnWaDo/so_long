/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:24:44 by lalex             #+#    #+#             */
/*   Updated: 2022/03/29 01:18:19 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MLX_H
# define SO_LONG_MLX_H

# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include "so_long_utils.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_list	*images;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		code;
	t_pos	w_h;
}	t_img;

enum	e_IMG_CODES
{
	I_MAP_CODE,
	I_HERO_CODE,
	I_WALL_CODE,
	I_EMPTY_CODE,
	I_COLL_CODE,
	I_ENEMY_CODE,
	I_EXIT_CODE,
	I_BACKG_CODE
};

# define MLX_ALLOC_ERR	"MLX allocation failed"
# define MLX_INIT_ERR	"MLX didn't start"
# define MLX_WIN_ERR	"Window didn't open"
# define MLX_IMG_ERR	"Image loading failed"

# define HERO_IMG		"imgs/human.xpm"
# define EMPTY_IMG		"imgs/floor.xpm"
# define WALL_IMG		"imgs/wall.xpm"
# define COLL_IMG		"imgs/bag_coins.xpm"
# define ENEMY_IMG		"imgs/goblin.xpm"
# define EXIT_IMG		"imgs/flag_red.xpm"
# define BACKG_IMG		"imgs/terrain.xpm"

int		to_trgb(unsigned char t,
			unsigned char r, unsigned char g, unsigned char b);
void	put_pixel(t_img *img, t_pos pos, int c);
int		get_pixel(t_img *img, t_pos pos);
void	put_rect(t_img *img, t_pos corner, t_pos w_h, int c);
void	put_img(t_img *canvas, t_img *img, t_pos corner);
void	fill_with_img(t_img *canvas, t_img *img);
t_mlx	*start_mlx_win(int w, int h, char *title);
t_img	*create_new_image(t_mlx *mlx, t_pos w_h, int code);
t_img	*load_xpm_image(t_mlx *mlx, char *path, int code);
t_img	*get_loaded_img(t_list *lst, int code);
void	clear_mlx(t_mlx *mlx);

#endif