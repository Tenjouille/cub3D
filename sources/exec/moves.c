#include "../../includes/cub.h"

void	move_up(t_cub *cub)
{
	int		y;
	int		x;

	y = (int)(cub->game->p_pos_y + cub->game->p_ori_y * MOVESPEED);
	x = (int)cub->game->p_pos_x;
	if (cub->map[y][x] != '1')
		cub->game->p_pos_y += cub->game->p_ori_y * MOVESPEED;
	y = (int)cub->game->p_pos_y;
	x = (int)(cub->game->p_pos_x + cub->game->p_ori_x * MOVESPEED);
	if (cub->map[y][x] != '1')
		cub->game->p_pos_x += cub->game->p_ori_x * MOVESPEED;
}

void	move_left(t_cub *cub)
{
	int		y;
	int		x;

	y = (int)(cub->game->p_pos_y - cub->game->plane_y * MOVESPEED);
	x = (int)cub->game->p_pos_x;
	if (cub->map[y][x] != '1')
		cub->game->p_pos_y -= cub->game->plane_y * MOVESPEED;
	y = (int)cub->game->p_pos_y;
	x = (int)(cub->game->p_pos_x - cub->game->plane_x * MOVESPEED);
	if (cub->map[y][x] != '1')
		cub->game->p_pos_x -= cub->game->plane_x * MOVESPEED;
}

void	move_down(t_cub *cub)
{
	int		y;
	int		x;

	y = (int)(cub->game->p_pos_y - cub->game->p_ori_y * MOVESPEED);
	x = (int)cub->game->p_pos_x;
	if (cub->map[y][x] != '1')
		cub->game->p_pos_y -= cub->game->p_ori_y * MOVESPEED;
	y = (int)cub->game->p_pos_y;
	x = (int)(cub->game->p_pos_x - cub->game->p_ori_x * MOVESPEED);
	if (cub->map[y][x] != '1')
		cub->game->p_pos_x -= cub->game->p_ori_x * MOVESPEED;
}

void	move_right(t_cub *cub)
{
	int		y;
	int		x;

	y = (int)(cub->game->p_pos_y + cub->game->plane_y * MOVESPEED);
	x = (int)cub->game->p_pos_x;
	if (cub->map[y][x] != '1')
		cub->game->p_pos_y += cub->game->plane_y * MOVESPEED;
	y = (int)cub->game->p_pos_y;
	x = (int)(cub->game->p_pos_x + cub->game->plane_x * MOVESPEED);
	if (cub->map[y][x] != '1')
		cub->game->p_pos_x += cub->game->plane_x * MOVESPEED;
}

void	get_rotate_speed(t_cub *cub)
{
	cub->rotation_speed = (double)ROTSPEED * (double)((double)1 + 20 * (double)((double)((int)fabs((double)cub->mouse_x - (double)(WINWIDTH / 2)) / (double)(WINWIDTH / 2))));
}

void	rotate_right(t_cub *cub)
{
	double		old_dir_x;
	double		old_plane_x;

	get_rotate_speed(cub);
	old_dir_x = cub->game->p_ori_x;
	cub->game->p_ori_x = cub->game->p_ori_x * cos(cub->rotation_speed) - cub->game->p_ori_y * sin(cub->rotation_speed);
	cub->game->p_ori_y = old_dir_x * sin(cub->rotation_speed) + cub->game->p_ori_y * cos(cub->rotation_speed);
	old_plane_x = cub->game->plane_x;
	cub->game->plane_x = cub->game->plane_x * cos(cub->rotation_speed) - \
		cub->game->plane_y * sin(cub->rotation_speed);
	cub->game->plane_y = old_plane_x * sin(cub->rotation_speed) +\
		cub->game->plane_y * cos(cub->rotation_speed);
}

void	rotate_left(t_cub *cub)
{
	double		old_dir_x;
	double		old_plane_x;

	get_rotate_speed(cub);
	old_dir_x = cub->game->p_ori_x;
	cub->game->p_ori_x = cub->game->p_ori_x * cos(-cub->rotation_speed) -\
		cub->game->p_ori_y * sin(-cub->rotation_speed);
	cub->game->p_ori_y = old_dir_x * sin(-cub->rotation_speed) +\
		cub->game->p_ori_y * cos(-cub->rotation_speed);
	old_plane_x = cub->game->plane_x;
	cub->game->plane_x = cub->game->plane_x * cos(-cub->rotation_speed) -\
		cub->game->plane_y * sin(-cub->rotation_speed);
	cub->game->plane_y = old_plane_x * sin(-cub->rotation_speed) +\
		cub->game->plane_y * cos(-cub->rotation_speed);
}
