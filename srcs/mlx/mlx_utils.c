#include "so_long_mlx.h"

int	to_trgb(unsigned char t,
		unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_pixel(t_img *img, t_pos pos, int c)
{
	char	*dst;

	if (pos.x < 0 || pos.y < 0 || pos.x > img->w_h.x || pos.y > img->w_h.y)
		return ;
	dst = img->addr + (pos.y * img->line_len + pos.x * (img->bpp / 8));
	((unsigned int *)dst)[0] = c;
}

int	get_pixel(t_img *img, t_pos pos)
{
	char	*dst;

	if (pos.x < 0 || pos.y < 0 || pos.x > img->w_h.x || pos.y > img->w_h.y)
		return (0);
	dst = img->addr + (pos.y * img->line_len + pos.x * (img->bpp / 8));
	return (((unsigned int *)dst)[0]);
}

void	put_rect(t_img *img, t_pos corner, t_pos w_h, int c)
{
	t_pos	till;

	till = (t_pos){.x = corner.x + w_h.x, .y = corner.y + w_h.y};
	while (corner.y < till.y)
	{
		while (corner.x < till.x)
		{
			put_pixel(img, corner, c);
			corner.x++;
		}
		corner.x -= w_h.x;
		corner.y++;
	}
}

void	fill_color(t_img *img, int c)
{
	put_rect(img, (t_pos){.x = 0, .y = 0}, img->w_h, c);
}

void	clear_mlx(t_mlx *mlx)
{
	t_list	*el;
	t_list	*next;

	if (mlx == NULL)
		return ;
	el = mlx->images;
	while (el)
	{
		next = el->next;
		mlx_destroy_image(mlx->mlx, ((t_img *)(el->content))->img);
		free(el->content);
		free(el);
		el = next;
	}
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	free(mlx);
}
