#include "../includes/cub.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->rowlen + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	get_color(t_cub *cub, int x, int y, int texture)
{
	if (texture == EA_TEXT)
		return (*(int *)(cub->textures->ea->addr + (y * cub->textures->ea->rowlen + x
				* (cub->textures->ea->bpp / 8))));
	if (texture == WE_TEXT)
		return (*(int *)(cub->textures->we->addr + (y * cub->textures->we->rowlen + x
				* (cub->textures->we->bpp / 8))));
	if (texture == NO_TEXT)
		return (*(int *)(cub->textures->no->addr + (y * cub->textures->no->rowlen + x
				* (cub->textures->no->bpp / 8))));
	if (texture == SO_TEXT)
		return (*(int *)(cub->textures->so->addr + (y * cub->textures->so->rowlen + x
				* (cub->textures->so->bpp / 8))));
	return (0);
}

void	draw_textures(t_cub *cub, int line_height, int side, int x, double ray_length, double diray_x, double diray_y)
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		draw_start;
	int		draw_end;
	int		i;
	int		color;

	draw_start = -line_height / 2 + cub->window_y / 2;
	if (draw_start < 0 || draw_start > cub->window_y)
		draw_start = 0;
	draw_end = line_height / 2 + cub->window_y / 2;
	if (draw_end >= cub->window_y)
		draw_end = cub->window_y - 1;
	if (side == 0)
		wall_x = cub->game->p_pos_y + ray_length * diray_y;
	else
		wall_x = cub->game->p_pos_x + ray_length * diray_x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * TEXWIDTH;
	if (side == 0 && diray_x > 0)
		tex_x = TEXWIDTH - tex_x - 1;
	if (side == 1 && diray_y < 0)
		tex_x = TEXWIDTH - tex_x - 1;
	step = 1 * TEXHEIGHT / line_height;
	tex_pos = (draw_start - cub->window_y / 2 + line_height / 2) * step;
	if (side == 0 && diray_x < 0)
		cub->game->texture = EA_TEXT;
	else if (side == 0 && diray_x > 0)
		cub->game->texture = WE_TEXT;
	else if (side == 1 && diray_y < 0)
		cub->game->texture = SO_TEXT;
	else if (side == 1 && diray_y > 0)
		cub->game->texture = NO_TEXT;
	i = draw_start;
	while (i <= draw_end)
	{
		tex_pos += step;
		color = get_color(cub, tex_x, tex_pos, cub->game->texture);
		my_mlx_pixel_put(cub->img, x, i, color);
		i++;
	}
}

void	draw_lines(t_cub *cub, int line_height, int side, int x)
{
	int		draw_start;
	int		draw_end;
	int		color;
	int		i;

	draw_start = -line_height / 2 + cub->window_y / 2;
	if (draw_start < 0 || draw_start > cub->window_y)
		draw_start = 0;
	draw_end = line_height / 2 + cub->window_y / 2;
	if (draw_end >= cub->window_y)
		draw_end = cub->window_y - 1;
	if (side == 1)
		color = 0x00FF0000;
	else
		color = 0x0000FF00;
	// i = 0;
	// printf("start = %d\n", draw_start);
	i = draw_start;
	while (i >= 0)
	{
		my_mlx_pixel_put(cub->img, x, i, 0x000000FF);
		i--;
	}
	i = draw_start;
	while (i <= draw_end)
	{
		my_mlx_pixel_put(cub->img, x, i, color);
		i++;
	}
	while (i < cub->window_y - 1)
	{
		my_mlx_pixel_put(cub->img, x, i, 0x00FFFFFF);
		i++;
	}
}
