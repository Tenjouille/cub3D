/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:43:04 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:43:05 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	move_up(t_cub *cub)
{
	int		y;
	int		x;

	y = (int)(cub->game->p_pos_y + cub->game->p_ori_y * cub->movespeed);
	x = (int)cub->game->p_pos_x;
	if (cub->map[y][x] != '1')
		cub->game->p_pos_y += cub->game->p_ori_y * cub->movespeed;
	y = (int)cub->game->p_pos_y;
	x = (int)(cub->game->p_pos_x + cub->game->p_ori_x * cub->movespeed);
	if (cub->map[y][x] != '1')
		cub->game->p_pos_x += cub->game->p_ori_x * cub->movespeed;
}

void	move_left(t_cub *cub)
{
	int		y;
	int		x;

	y = (int)(cub->game->p_pos_y - cub->game->plane_y * 0.65 * MOVESPEED);
	x = (int)cub->game->p_pos_x;
	if (cub->map[y][x] != '1')
		cub->game->p_pos_y -= cub->game->plane_y * 0.65 * MOVESPEED;
	y = (int)cub->game->p_pos_y;
	x = (int)(cub->game->p_pos_x - cub->game->plane_x * 0.65 * MOVESPEED);
	if (cub->map[y][x] != '1')
		cub->game->p_pos_x -= cub->game->plane_x * 0.65 * MOVESPEED;
}

void	move_down(t_cub *cub)
{
	int		y;
	int		x;

	y = (int)(cub->game->p_pos_y - cub->game->p_ori_y * 0.5 * MOVESPEED);
	x = (int)cub->game->p_pos_x;
	if (cub->map[y][x] != '1')
		cub->game->p_pos_y -= cub->game->p_ori_y * 0.5 * MOVESPEED;
	y = (int)cub->game->p_pos_y;
	x = (int)(cub->game->p_pos_x - cub->game->p_ori_x * 0.5 * MOVESPEED);
	if (cub->map[y][x] != '1')
		cub->game->p_pos_x -= cub->game->p_ori_x * 0.5 * MOVESPEED;
}

void	move_right(t_cub *cub)
{
	int		y;
	int		x;

	y = (int)(cub->game->p_pos_y + cub->game->plane_y * 0.65 * MOVESPEED);
	x = (int)cub->game->p_pos_x;
	if (cub->map[y][x] != '1')
		cub->game->p_pos_y += cub->game->plane_y * 0.65 * MOVESPEED;
	y = (int)cub->game->p_pos_y;
	x = (int)(cub->game->p_pos_x + cub->game->plane_x * 0.65 * MOVESPEED);
	if (cub->map[y][x] != '1')
		cub->game->p_pos_x += cub->game->plane_x * 0.65 * MOVESPEED;
}
