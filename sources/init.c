#include "../includes/cub.h"

void	init_textures(t_cub *cub)
{
	cub->textures = malloc(sizeof(t_textures) * 1);
	cub->textures->ea = malloc(sizeof(t_img) * 1);
	cub->textures->we = malloc(sizeof(t_img) * 1);
	cub->textures->no = malloc(sizeof(t_img) * 1);
	cub->textures->so = malloc(sizeof(t_img) * 1);
}

void	init_images(t_cub *cub)
{
	char	*path;
	int		x;
	int		y;

	init_textures(cub);
	x = 64;
	y = 64;
	path = "../textures/green.xpm";
	cub->textures->no->mlx_img = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	cub->textures->no->addr = mlx_get_data_addr(cub->textures->no->mlx_img,
		&cub->textures->no->bpp, &cub->textures->no->rowlen, &cub->textures->no->end);
	path = "../textures/red.xpm";
	cub->textures->so->mlx_img = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	cub->textures->so->addr = mlx_get_data_addr(cub->textures->so->mlx_img,
		&cub->textures->so->bpp, &cub->textures->so->rowlen, &cub->textures->so->end);
	path = "../textures/blue.xpm";
	cub->textures->we->mlx_img = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	cub->textures->we->addr = mlx_get_data_addr(cub->textures->we->mlx_img,
		&cub->textures->we->bpp, &cub->textures->we->rowlen, &cub->textures->we->end);
	path = "../textures/yellow.xpm";
	cub->textures->ea->mlx_img = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	cub->textures->ea->addr = mlx_get_data_addr(cub->textures->ea->mlx_img,
		&cub->textures->ea->bpp, &cub->textures->ea->rowlen, &cub->textures->ea->end);
}

void	get_first_orientation(t_cub *cub, char c)
{
	if (c == 'N')
	{
		cub->game->p_ori_x = 0;
		cub->game->p_ori_y = -1;
		cub->game->fov_length = 0.66;
		cub->game->fov_width = 0;
	}
	if (c == 'E')
	{
		cub->game->p_ori_x = 1;
		cub->game->p_ori_y = 0;
		cub->game->fov_length = 0;
		cub->game->fov_width = 0.66;
	}
	if (c == 'S')
	{
		cub->game->p_ori_x = 0;
		cub->game->p_ori_y = 1;
		cub->game->fov_length = -0.66;
		cub->game->fov_width = 0;
	}
	if (c == 'W')
	{
		cub->game->p_ori_x = -1;
		cub->game->p_ori_y = 0;
		cub->game->fov_length = 0;
		cub->game->fov_width = -0.66;
	}
}

void	init_fov_and_time(t_cub *cub)
{
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

void	init_values(t_cub * cub)
{
	cub->game->key_w = 0;
	cub->game->key_a = 0;
	cub->game->key_s = 0;
	cub->game->key_d = 0;
	cub->game->key_left = 0;
	cub->game->key_right = 0;
	cub->game->texture = 0;
	init_fov_and_time(cub);
}

void	game_init(t_cub *cub)
{
	cub->game = malloc(sizeof(t_game) * 1);
	init_values(cub);
	// init_images(cub);
	get_player_pos(cub);
}

int	game_loop(t_cub *cub)
{
	if (cub->game->key_w)
		move_up(cub);
	if (cub->game->key_a)
		move_left(cub);
	if (cub->game->key_s)
		move_down(cub);
	if (cub->game->key_d)
		move_right(cub);
	if (cub->game->key_right)
		rotate_right(cub);
	if (cub->game->key_left)
		rotate_left(cub);
	ray_cast(cub);
	return (0);
}
