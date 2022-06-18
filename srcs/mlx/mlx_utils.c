/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:10:34 by lalex             #+#    #+#             */
/*   Updated: 2022/03/29 01:12:12 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mlx.h"
#include "so_long_map.h"

void	put_rect(t_img *img, t_pos corner, t_pos w_h, int c)
{
	t_pos	loc;

	loc.y = corner.y;
	while (loc.y < corner.y + w_h.y)
	{
		loc.x = corner.x;
		while (loc.x < corner.x + w_h.x)
		{
			put_pixel(img, loc, c);
			loc.x++;
		}
		loc.y++;
	}
}

void	put_img(t_img *canvas, t_img *img, t_pos corner)
{
	t_pos	canvas_loc;
	t_pos	img_loc;
	t_pos	scaler;
	int		pix;

	if (!img || canvas->w_h.x < img->w_h.x || canvas->w_h.y < img->w_h.y)
		return ;
	scaler = (t_pos){.x = CELL_WIDTH / img->w_h.x,
		.y = CELL_WIDTH / img->w_h.y};
	img_loc.y = 0;
	while (img_loc.y < img->w_h.y)
	{
		img_loc.x = 0;
		while (img_loc.x < img->w_h.x)
		{
			canvas_loc.x = corner.x + img_loc.x * scaler.x;
			canvas_loc.y = corner.y + img_loc.y * scaler.y;
			pix = get_pixel(img, img_loc);
			if (pix)
				put_rect(canvas, canvas_loc, scaler, pix);
			img_loc.x++;
		}
		img_loc.y++;
	}
}

void	fill_with_img(t_img *canvas, t_img *img)
{
	t_pos	loc;

	loc.y = 0;
	while (loc.y < canvas->w_h.y)
	{
		loc.x = 0;
		while (loc.x < canvas->w_h.x)
		{
			put_img(canvas, img, loc);
			loc.x += CELL_WIDTH;
		}
		loc.y += CELL_WIDTH;
	}
}
