#include "../includes/cub.h"

void	ray_cast(t_cub *cub)
{
	int		x;
	double	camera;

	double	diray_x;
	double	diray_y;

	int		map_x;
	int		map_y;

	double	side_dist_x;
	double	side_dist_y;

	double	delta_dist_x;
	double	delta_dist_y;

	double	ray_length;
	int		step_x;
	int		step_y;
	int		hit;
	// int		nbhit;
	int		side;

	int		line_height;

	cub->img = malloc(sizeof(t_img) * 1);
	cub->img->mlx_img = mlx_new_image(cub->mlx, cub->window_x, cub->window_y);
	cub->img->addr = mlx_get_data_addr(cub->img->mlx_img, &(cub->img->bpp), &(cub->img->rowlen),
								&(cub->img->end));
	x = 0;
	while (x < cub->window_x)
	{
		// printf("valeur de x : %d\n", x);
		camera = 2 * x / (double)cub->window_x - 1;
		// printf("camera : %f\n", camera);
		diray_x = cub->game->p_ori_x + cub->game->fov_length * camera;
      	diray_y = cub->game->p_ori_y + cub->game->fov_width * camera;
		// printf("ray x : %f\n", diray_x);
		// printf("ray y : %f\n", diray_y);
		map_x = (int)cub->game->p_pos_x;
		map_y = (int)cub->game->p_pos_y;
		// printf("map x : %d\n", map_x);
		// printf("map y : %d\n", map_y);
		if (diray_x != 0)
			delta_dist_x = fabs(1 / diray_x);
		// else
		// 	delta_dist_x = fabs(1 / pow(10, 30));
		// printf("delta_x : %f\n", delta_dist_x);
		if (diray_y != 0)
			delta_dist_y = fabs(1 / diray_y);
		// else
		// 	delta_dist_y = fabs(1 / pow(10, 30));
		// printf("delta_y : %f\n", delta_dist_y);
		// printf("\n");
		if (diray_x < 0)
		{
			step_x = -1;
			side_dist_x = (cub->game->p_pos_x - (double)map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = ((double)map_x + 1 - cub->game->p_pos_x) * delta_dist_x;
		}
		if (diray_y < 0)
		{
			step_y = -1;
			side_dist_y = (cub->game->p_pos_y - (double)map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = ((double)map_y + 1 - cub->game->p_pos_y) * delta_dist_y;
		}
		hit = 0;
		// nbhit = 0;
		// printf("sidedist x : %f\n", side_dist_x);
		// printf("sidedist y : %f\n", side_dist_y);
		// printf("\n");
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			// printf("map x : %d\n", map_x);
			// printf("map y : %d\n", map_y);
			// printf("\n");
			// printf("\n");
			if (cub->map[map_y][map_x] == '1')
				hit = 1;
			// nbhit++;
		}
		if (side == 0)
			ray_length = side_dist_x - delta_dist_x;
		else
			ray_length = side_dist_y - delta_dist_y;
		line_height = cub->window_y / (ray_length);
		// draw_fov(cub, diray_x, diray_y);
		draw_lines(cub, line_height, side, x);
		// draw_textures(cub, line_height, side, x, ray_length, diray_x, diray_y); 
		// printf("line height : %d\n", line_height);
		x++;
	}
	// (void)line_height;
	// printf("line height : %d\n", line_height);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->mlx_img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img->mlx_img);
	free(cub->img);
}