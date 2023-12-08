/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:43:25 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:43:26 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

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

void	cub_init(t_cub *cub)
{
	cub->game = ft_malloc(sizeof(t_game) * 1, 0, 0, 0);
	cub->ray = ft_malloc(sizeof(t_ray) * 1, 0, 0, 0);
	cub->mini = ft_malloc(sizeof(t_mini) * 1, 0, 0, 0);
	init_values(cub);
	init_mlx(cub);
}

int	game_init(t_cub *cub)
{
	init_images(cub);
	cub->win = mlx_new_window(cub->mlx, cub->window_x, cub->window_y, "Cub3D");
	if (!cub->win)
	{
		mlx_do_key_autorepeaton(cub->mlx);
		ft_malloc(0, 1, 0, 0);
		exit (1);
	}
	get_player_pos(cub);
	return (0);
}

void	get_movespeed(t_cub *cub)
{
	if (cub->run == 1)
		cub->movespeed = 2 * MOVESPEED;
	else
		cub->movespeed = MOVESPEED;
}

int	game_loop(t_cub *cub)
{
	int	y;

	get_movespeed(cub);
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
	if (cub->mouse_active == 1)
	{
		mlx_mouse_get_pos(cub->mlx, cub->win, &cub->mouse_x, &y);
		if (cub->mouse_x > WINWIDTH / 2)
			rotate_right(cub);
		else if (cub->mouse_x < WINWIDTH / 2)
			rotate_left(cub);
		mlx_mouse_move(cub->mlx, cub->win, WINWIDTH / 2, WINHEIGHT / 2);
	}
	return (ray_cast(cub), 0);
}
