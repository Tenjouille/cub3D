#include "../../includes/cub.h"

void	draw_char(t_cub *cub, int x)
{
	int		i;

	i = cub->mini->size_y / 2 + 5;
	while (i <= cub->mini->size_y / 2 + 15)
	{
		if ((x >= cub->window_x - 15 - (cub->mini->size_x / 2)) && (x <= cub->window_x - (cub->mini->size_x / 2) - 5))
			my_mlx_pixel_put(cub->img, x, i, 0x00FF0000);
		i++;
	}
}

int	get_coords(t_cub *cub, int x, int y)
{
	int		dist_x;
	int		dist_y;
	int		coord_x;
	int		coord_y;

	dist_x = cub->mini->mini_map_x + cub->mini->size_x / 2 - x;
	dist_y = 10 + cub->mini->size_y / 2 - y;
	coord_x = cub->mini->map_x - dist_x / cub->mini->wall_size;
	coord_y = cub->mini->map_y - dist_y / cub->mini->wall_size;
	if (x == cub->mini->mini_map_x + 154 && y == 100)
	{
		printf("map_height : %d\n", cub->map_height);
		printf("len de la ligne : %d\n", (int)strlen(cub->map[coord_y]));
		printf("wall_size : %d\n", cub->mini->wall_size);
		printf("dist_x : %d\ncoord_x : %d\n", dist_x, coord_x);
		printf("dist_y : %d\ncoord_y : %d\n\n", dist_y, coord_y);
	}
	if (coord_y >= 0 && coord_y <= cub->map_height)
	{
		if (coord_x >= 0 && coord_x <= (int)strlen(cub->map[coord_y]))
		{
			if (cub->map[coord_y][coord_x] == '1')
				return (1);
			if (cub->map[coord_y][coord_x] == '0')
				return (2);
		}
	}
	return (0);
}

void	draw_mini_map(t_cub *cub, int x)
{
	int		y;

	y = 10;
	cub->mini->size_y = cub->mini->mini_map_y - 10;
	cub->mini->size_x = cub->window_x - 10 - cub->mini->mini_map_x;
	cub->mini->wall_size = cub->mini->size_x / 10;
	cub->mini->map_x = (int)cub->game->p_pos_x;
	cub->mini->map_y = (int)cub->game->p_pos_y;
	while (y <= cub->mini->mini_map_y && x >= cub->mini->mini_map_x && x <= cub->window_x - 10)
	{
		if (get_coords(cub, x, y) == 1)
			my_mlx_pixel_put(cub->img, x, y, 0x0000FF00);
		// else if (get_coords(cub, x, y) == 2)
			// my_mlx_pixel_put(cub->img, x, y, 0x000000FF);
		else
			my_mlx_pixel_put(cub->img, x, y, 0x000000FF);
		y++;
	}
	draw_char(cub, x);
}