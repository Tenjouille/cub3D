/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:43:21 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:43:22 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	init_values(t_cub *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->game->key_w = 0;
	cub->game->key_a = 0;
	cub->game->key_s = 0;
	cub->game->key_d = 0;
	cub->game->key_left = 0;
	cub->game->key_right = 0;
	cub->game->texture = 0;
	cub->game->cur_time = 0;
	cub->game->old_time = 0;
	cub->mini->mini_map_x = cub->window_x - 10 - (cub->window_x / 5);
	cub->mini->mini_map_y = 10 + (cub->window_y / 5);
	cub->mini->display = 0;
	cub->mouse_x = 0;
	cub->rotation_speed = ROTSPEED;
	cub->textures[NO_TEXT].mlx_img = NULL;
	cub->textures[SO_TEXT].mlx_img = NULL;
	cub->textures[EA_TEXT].mlx_img = NULL;
	cub->textures[WE_TEXT].mlx_img = NULL;
	cub->mouse_active = 0;
	cub->run = 0;
	cub->movespeed = MOVESPEED;
}

void	get_first_orientation_two(t_cub *cub, char c)
{
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
	get_first_orientation_two(cub, c);
}
