#include "so_long_mlx.h"
#include "so_long_map.h"

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
