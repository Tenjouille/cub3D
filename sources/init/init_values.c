#include "../../includes/cub.h"

void	init_values(t_cub *cub)
{
	cub->game->key_w = 0;
	cub->game->key_a = 0;
	cub->game->key_s = 0;
	cub->game->key_d = 0;
	cub->game->key_left = 0;
	cub->game->key_right = 0;
	cub->game->texture = 0;
	cub->game->cur_time = 0;
	cub->game->old_time = 0;
}

void	get_first_orientation(t_cub *cub, char c)
{
	if (c == 'N')
	{
		cub->game->p_ori_x = 0;
		cub->game->p_ori_y = -1;
		cub->game->plane_x = 0.66;
		cub->game->plane_y = 0;
	}
	if (c == 'E')
	{
		cub->game->p_ori_x = 1;
		cub->game->p_ori_y = 0;
		cub->game->plane_x = 0;
		cub->game->plane_y = 0.66;
	}
	if (c == 'S')
	{
		cub->game->p_ori_x = 0;
		cub->game->p_ori_y = 1;
		cub->game->plane_x = -0.66;
		cub->game->plane_y = 0;
	}
	if (c == 'W')
	{
		cub->game->p_ori_x = -1;
		cub->game->p_ori_y = 0;
		cub->game->plane_x = 0;
		cub->game->plane_y = -0.66;
	}
}
