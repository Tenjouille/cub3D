#include "../includes/cub.h"

void	init_images(t_cub *cub)
{
	char	*path;
	int		x;
	int		y;

	cub->textures = malloc(sizeof(t_textures) * 1);
	x = 1000;
	y = 1000;
	path = "../textures/green.xpm";
	cub->textures->no = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	path = "../textures/red.xpm";
	cub->textures->so = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	path = "../textures/blue.xpm";
	cub->textures->we = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	path = "../textures/yellow.xpm";
	cub->textures->ea = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
}

void	get_first_orientation(t_cub *cub, char c)
{
	if (c == 'N')
	{
		cub->game->p_ori_x = 0;
		cub->game->p_ori_y = -1;
	}
	if (c == 'E')
	{
		cub->game->p_ori_x = 1;
		cub->game->p_ori_y = 0;
	}
	if (c == 'S')
	{
		cub->game->p_ori_x = 0;
		cub->game->p_ori_y = 1;
	}
	if (c == 'W')
	{
		cub->game->p_ori_x = -1;
		cub->game->p_ori_y = 0;
	}
}

void	init_fov_and_time(t_cub *cub)
{
	cub->game->fov_length = 1;
	cub->game->fov_width = 0.66;
	cub->game->cur_time = 0;
	cub->game->old_time = 0;
}

void	get_player_pos(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'E'
				|| cub->map[i][j] == 'S' || cub->map[i][j] == 'W')
				{
					cub->game->p_pos_x = j + 0.5;
					cub->game->p_pos_y = i + 0.5;
					get_first_orientation(cub, cub->map[i][j]);
					return ;
				}
				j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->rowlen + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
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
	printf("start = %d\n", draw_start);
	i = draw_start;
	while (i >= 0)
	{
		my_mlx_pixel_put(cub->img, x, i, 0x00FFFF00);
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

// void	draw_fov(t_cub *cub, double xray, double yray)
// {
// 	my_mlx_pixel_put(cub->img, fabs(yray * 500) + 200, fabs(xray * 500) + 200, 0x0000FF00);
// }

void	init_camera(t_cub *cub)
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
		printf("valeur de x : %d\n", x);
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
		else
			delta_dist_x = fabs(1 / pow(10, 30));
		// printf("delta_x : %f\n", delta_dist_x);
		if (diray_y != 0)
			delta_dist_y = fabs(1 / diray_y);
		else
			delta_dist_y = fabs(1 / pow(10, 30));
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
		printf("\n");
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
			if (cub->map[map_y][map_x] != 0)
				hit = 1;
			// nbhit++;
		}
		// if (nbhit > 1)
			// printf("nbhit a x : %d\n", x);
		if (side == 0)
			ray_length = side_dist_x - delta_dist_x;
		else
			ray_length = side_dist_y - delta_dist_y;
		line_height = cub->window_y / (ray_length * 3);
		// draw_fov(cub, diray_x, diray_y);
		draw_lines(cub, line_height, side, x);
		// printf("line height : %d\n", line_height);
		x++;
	}
	// (void)line_height;
	// printf("line height : %d\n", line_height);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->mlx_img, 0, 0);
}

// void	affiche_map(t_cub *cub)
// {

// }

void	game_init(t_cub *cub)
{
	cub->game = malloc(sizeof(t_game) * 1);
	init_fov_and_time(cub);
	get_player_pos(cub);
	init_camera(cub);
}

// void	draw_test(t_cub *cub)
// {
// 	int		color;
// 	int		side;
// 	int		y;
// 	int		x;
// 	// t_img	img;

// 	cub->img = malloc(sizeof(t_img) * 1);
// 	cub->img->mlx_img = mlx_new_image(cub->mlx, 500, 600);
// 	cub->img->addr = mlx_get_data_addr(cub->img->mlx_img, &cub->img->bpp, &cub->img->rowlen,
// 								&cub->img->end);
// 	side = 1;
// 	if (side == 1)
// 		color = 0x0000FF00;
// 	else
// 		color = 0x00FF0000;
// 	x = 100;
// 	while (x <= 400)
// 	{
// 		y = 100;
// 		while (y <= 200)
// 		{
// 			my_mlx_pixel_put(cub->img, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->mlx_img, 0, 0);
// }

// void	draw_test(t_cub *cub)
// {
// 	int		color;
// 	int		side;
// 	int		y;
// 	int		x;
// 	t_img	img;

// 	// cub->img = malloc(sizeof(t_img) * 1);
// 	img.mlx_img = mlx_new_image(cub->mlx, 500, 600);
// 	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.rowlen,
// 								&img.end);
// 	side = 1;
// 	if (side == 1)
// 		color = 0x0000FF00;
// 	else
// 		color = 0x00FF0000;
// 	x = 100;
// 	while (x <= 400)
// 	{
// 		y = 100;
// 		while (y <= 200)
// 		{
// 			my_mlx_pixel_put(&img, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(cub->mlx, cub->win, img.mlx_img, 0, 0);
// }