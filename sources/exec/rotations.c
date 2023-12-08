/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:43:12 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:43:13 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	get_rotate_speed(t_cub *cub)
{
	if (cub->mouse_active)
		cub->rotation_speed = (double)ROTSPEED
			* (double)((double)1 + MOUSE_RATIO
				* (double)((double)((int)fabs((double)cub->mouse_x
							- (double)(WINWIDTH / 2))
						/ (double)(WINWIDTH / 2))));
	else
		cub->rotation_speed = ROTSPEED;
}

void	rotate_right(t_cub *cub)
{
	double		old_dir_x;
	double		old_plane_x;

	get_rotate_speed(cub);
	old_dir_x = cub->game->p_ori_x;
	cub->game->p_ori_x = cub->game->p_ori_x * cos(cub->rotation_speed)
		- cub->game->p_ori_y * sin(cub->rotation_speed);
	cub->game->p_ori_y = old_dir_x * sin(cub->rotation_speed)
		+ cub->game->p_ori_y * cos(cub->rotation_speed);
	old_plane_x = cub->game->plane_x;
	cub->game->plane_x = cub->game->plane_x * cos(cub->rotation_speed) - \
		cub->game->plane_y * sin(cub->rotation_speed);
	cub->game->plane_y = old_plane_x * sin(cub->rotation_speed)
		+ cub->game->plane_y * cos(cub->rotation_speed);
}

void	rotate_left(t_cub *cub)
{
	double		old_dir_x;
	double		old_plane_x;

	get_rotate_speed(cub);
	old_dir_x = cub->game->p_ori_x;
	cub->game->p_ori_x = cub->game->p_ori_x * cos(-cub->rotation_speed)
		- cub->game->p_ori_y * sin(-cub->rotation_speed);
	cub->game->p_ori_y = old_dir_x * sin(-cub->rotation_speed)
		+ cub->game->p_ori_y * cos(-cub->rotation_speed);
	old_plane_x = cub->game->plane_x;
	cub->game->plane_x = cub->game->plane_x * cos(-cub->rotation_speed)
		- cub->game->plane_y * sin(-cub->rotation_speed);
	cub->game->plane_y = old_plane_x * sin(-cub->rotation_speed)
		+ cub->game->plane_y * cos(-cub->rotation_speed);
}
