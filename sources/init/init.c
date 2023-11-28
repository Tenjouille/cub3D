#include "../../includes/cub.h"

void	init_images(t_cub *cub)
{
	char	*path;
	int		x;
	int		y;

	path = NULL;
	x = 64;
	y = 64;
	path = "textures/my_wall.xpm";
	cub->textures[NO_TEXT].mlx_img = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	cub->textures[NO_TEXT].addr = mlx_get_data_addr(cub->textures[NO_TEXT].mlx_img,
		&cub->textures[NO_TEXT].bpp, &cub->textures[NO_TEXT].rowlen, &cub->textures[NO_TEXT].end);
	path = "textures/colorstone.xpm";
	cub->textures[SO_TEXT].mlx_img = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	cub->textures[SO_TEXT].addr = mlx_get_data_addr(cub->textures[SO_TEXT].mlx_img,
		&cub->textures[SO_TEXT].bpp, &cub->textures[SO_TEXT].rowlen, &cub->textures[SO_TEXT].end);
	path = "textures/eagle.xpm";
	cub->textures[WE_TEXT].mlx_img = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	cub->textures[WE_TEXT].addr = mlx_get_data_addr(cub->textures[WE_TEXT].mlx_img,
		&cub->textures[WE_TEXT].bpp, &cub->textures[WE_TEXT].rowlen, &cub->textures[WE_TEXT].end);
	path = "textures/mossy.xpm";
	cub->textures[EA_TEXT].mlx_img = mlx_xpm_file_to_image(cub->mlx, path, &x, &y);
	cub->textures[EA_TEXT].addr = mlx_get_data_addr(cub->textures[EA_TEXT].mlx_img,
		&cub->textures[EA_TEXT].bpp, &cub->textures[EA_TEXT].rowlen, &cub->textures[EA_TEXT].end);
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

void	game_init(t_cub *cub)
{
	cub->game = malloc(sizeof(t_game) * 1);
	cub->ray = malloc(sizeof(t_ray) * 1);
	init_values(cub);
	init_images(cub);
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
