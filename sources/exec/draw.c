#include "../../includes/cub.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y > WINHEIGHT - 1 || x < 0 || x > WINWIDTH - 1)
		return ;
	dst = img->addr + (y * img->rowlen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_cub *cub, int x, int y, int texture)
{
	return (*(int *)(cub->textures[texture].addr
		+ (y * cub->textures[texture].rowlen + x
			* (cub->textures[texture].bpp / 8))));
}

void	set_textures_variables(t_cub *cub, t_ray *ray)
{
	ray->wall_x = 0;
	ray->tex_pos = 0;
	ray->draw_start = -ray->line_height / 2 + cub->window_y / 2;
	if (ray->draw_start < 0 || ray->draw_start > cub->window_y)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + cub->window_y / 2;
	if (ray->draw_end >= cub->window_y)
		ray->draw_end = cub->window_y - 1;
	if (ray->side == 0)
		ray->wall_x = cub->game->p_pos_y + ray->ray_length * ray->diray_y;
	else
		ray->wall_x = cub->game->p_pos_x + ray->ray_length * ray->diray_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEXWIDTH);
	if ((ray->side == 0 && ray->diray_x > 0)
		|| (ray->side == 1 && ray->diray_y < 0))
		ray->tex_x = TEXWIDTH - ray->tex_x - 1;
	ray->step = 1 * (double)TEXHEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - WINHEIGHT
			/ 2 + ray->line_height / 2) * ray->step;
}

void	pick_texture(t_cub *cub, t_ray *ray)
{
	if (ray->side == 0 && ray->diray_x < 0)
		cub->game->texture = EA_TEXT;
	else if (ray->side == 0 && ray->diray_x > 0)
		cub->game->texture = WE_TEXT;
	else if (ray->side == 1 && ray->diray_y < 0)
		cub->game->texture = SO_TEXT;
	else if (ray->side == 1 && ray->diray_y > 0)
		cub->game->texture = NO_TEXT;
}

void	draw_textures(t_cub *cub, t_ray *ray, int x)
{
	int		i;

	set_textures_variables(cub, cub->ray);
	pick_texture(cub, cub->ray);
	i = ray->draw_start;
	while (i >= 0)
		my_mlx_pixel_put(cub->img, x, i--, 0x00AABBFF);
	i = ray->draw_start;
	while (i <= ray->draw_end)
	{
		my_mlx_pixel_put(cub->img, x, i,
			get_color(cub, ray->tex_x, ray->tex_pos, cub->game->texture));
		ray->tex_pos += ray->step;
		i++;
	}
	while (i < cub->window_y)
		my_mlx_pixel_put(cub->img, x, i++, 0x00555455);
}

// void	draw_lines(t_cub *cub, int line_height, int side, int x)
// {
// 	int		draw_start;
// 	int		draw_end;
// 	int		color;
// 	int		i;

// 	draw_start = -line_height / 2 + cub->window_y / 2;
// 	if (draw_start < 0 || draw_start > cub->window_y)
// 		draw_start = 0;
// 	draw_end = line_height / 2 + cub->window_y / 2;
// 	if (draw_end >= cub->window_y)
// 		draw_end = cub->window_y - 1;
// 	if (side == 1)
// 		color = 0x00FF0000;
// 	else
// 		color = 0x0000FF00;
// 	// i = 0;
// 	// printf("start = %d\n", draw_start);
// 	i = draw_start;
// 	while (i >= 0)
// 	{
// 		my_mlx_pixel_put(cub->img, x, i, 0x000000FF);
// 		i--;
// 	}
// 	i = draw_start;
// 	while (i <= draw_end)
// 	{
// 		my_mlx_pixel_put(cub->img, x, i, color);
// 		i++;
// 	}
// 	while (i < cub->window_y - 1)
// 	{
// 		my_mlx_pixel_put(cub->img, x, i, 0x00FFFFFF);
// 		i++;
// 	}
// }
