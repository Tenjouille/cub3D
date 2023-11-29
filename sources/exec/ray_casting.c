#include "../../includes/cub.h"

void	set_camera(t_cub *cub, t_ray *ray, int x)
{
	ray->camera = 2 * x / (double)cub->window_x - 1;
	ray->diray_x = cub->game->p_ori_x + cub->game->plane_x * ray->camera;
	ray->diray_y = cub->game->p_ori_y + cub->game->plane_y * ray->camera;
	ray->map_x = (int)cub->game->p_pos_x;
	ray->map_y = (int)cub->game->p_pos_y;
	if (ray->diray_x != 0)
		ray->delta_dist_x = fabs(1 / ray->diray_x);
	else
		ray->delta_dist_x = INT_MAX;
	if (ray->diray_y != 0)
		ray->delta_dist_y = fabs(1 / ray->diray_y);
	else
		ray->delta_dist_y = INT_MAX;
}

void	set_sidedist(t_cub *cub, t_ray *ray)
{
	if (ray->diray_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->game->p_pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - cub->game->p_pos_x)
			* ray->delta_dist_x;
	}
	if (ray->diray_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->game->p_pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - cub->game->p_pos_y)
			* ray->delta_dist_y;
	}
}

void	check_hit(t_cub *cub, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (cub->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->ray_length = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->ray_length = ray->side_dist_y - ray->delta_dist_y;
	if (ray->ray_length < 0.001)
		ray->ray_length = 0.005;
	ray->line_height = cub->window_y / (ray->ray_length);
}

void	ray_cast(t_cub *cub)
{
	int		x;

	cub->img = malloc(sizeof(t_img) * 1);
	cub->img->mlx_img = mlx_new_image(cub->mlx, cub->window_x, cub->window_y);
	cub->img->addr = mlx_get_data_addr(cub->img->mlx_img,
			&(cub->img->bpp), &(cub->img->rowlen),
			&(cub->img->end));
	cub->mini_img = malloc(sizeof(t_img) * 1);
	cub->mini_img->mlx_img = mlx_new_image(cub->mlx, cub->window_x, cub->window_y);
	cub->mini_img->addr = mlx_get_data_addr(cub->mini_img->mlx_img,
			&(cub->mini_img->bpp), &(cub->mini_img->rowlen),
			&(cub->mini_img->end));
	x = 0;
	while (x < cub->window_x)
	{
		set_camera(cub, cub->ray, x);
		set_sidedist(cub, cub->ray);
		check_hit(cub, cub->ray);
		draw_textures(cub, cub->ray, x);
		draw_mini_map(cub, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->mlx_img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img->mlx_img);
	mlx_destroy_image(cub->mlx, cub->mini_img->mlx_img);
	free(cub->img);
	free(cub->mini_img);
}
