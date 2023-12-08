/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:43:01 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:43:02 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw_char(t_cub *cub, int x)
{
	int		i;

	i = cub->mini->size_y / 2 + 5;
	while (i <= cub->mini->size_y / 2 + 15)
	{
		if ((x >= cub->window_x - 15 - (cub->mini->size_x / 2))
			&& (x <= cub->window_x - (cub->mini->size_x / 2) - 5))
			my_mlx_pixel_put(cub->img, x, i, 0x00FF0000);
		i++;
	}
}

void	get_coords_values(t_cub *cub, int x, int y)
{
	t_mini	*mini;

	mini = cub->mini;
	mini->dist_x = mini->mini_map_x + mini->size_x / 2 - x;
	mini->dist_y = 10 + mini->size_y / 2 - y;
	mini->coord_x = cub->game->p_pos_x - mini->dist_x / mini->wall_size
		- (double)(mini->dist_x % mini->wall_size) / mini->wall_size;
	mini->coord_y = cub->game->p_pos_y - mini->dist_y / mini->wall_size
		- (double)(mini->dist_y % mini->wall_size) / mini->wall_size;
	mini->real_coord_x = (int)mini->coord_x;
	mini->real_coord_y = (int)mini->coord_y;
}

int	get_coords(t_cub *cub, int x, int y)
{
	t_mini	*mini;

	mini = cub->mini;
	get_coords_values(cub, x, y);
	if (mini->coord_y >= 0 && mini->real_coord_y <= (double)cub->map_height)
	{
		if (mini->coord_x >= 0 && mini->coord_x
			<= (double)ft_strlen(cub->map[mini->real_coord_y]))
		{
			if (cub->map[mini->real_coord_y][mini->real_coord_x] == '1')
				return (1);
			if (cub->map[mini->real_coord_y][mini->real_coord_x] == 'F'
				|| cub->map[mini->real_coord_y][mini->real_coord_x] == 'N'
				|| cub->map[mini->real_coord_y][mini->real_coord_x] == 'S'
				|| cub->map[mini->real_coord_y][mini->real_coord_x] == 'E'
				|| cub->map[mini->real_coord_y][mini->real_coord_x] == 'W')
				return (2);
		}
	}
	return (0);
}

void	draw_mini_map(t_cub *cub, int x)
{
	int		y;
	int		coords;

	y = 10;
	coords = 0;
	cub->mini->size_y = cub->mini->mini_map_y - 10;
	cub->mini->size_x = cub->window_x - 10 - cub->mini->mini_map_x;
	cub->mini->wall_size = cub->mini->size_x / MINIRATIO;
	cub->mini->map_x = (int)cub->game->p_pos_x;
	cub->mini->map_y = (int)cub->game->p_pos_y;
	while (y <= cub->mini->mini_map_y && x >= cub->mini->mini_map_x
		&& x <= cub->window_x - 10)
	{
		coords = get_coords(cub, x, y);
		if (coords == 1)
			my_mlx_pixel_put(cub->img, x, y, 0x0000FF00);
		else if (coords == 2)
			my_mlx_pixel_put(cub->img, x, y, get_rgb(cub->floor));
		else
			my_mlx_pixel_put(cub->img, x, y, get_rgb(cub->ceiling));
		y++;
	}
	draw_char(cub, x);
}
