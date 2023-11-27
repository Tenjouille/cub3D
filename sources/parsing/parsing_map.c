#include "../../includes/cub.h"

// int	ft_fill_map(char **res, char **map, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	i = x;
// 	j = y;
// 	while (map[y][x] == ' ')
// 	{
// 		if ((!map[y - 1][x] || !ft_is_char(map[y - 1][x], " F1\n"))
// 			&& (!map[y + 1][x] || !ft_is_char(map[y + 1][x], " F1\n"))
// 			&& (!map[y][x - 1] || !ft_is_char(map[y][x - 1], " F1\n"))
// 			&& (!map[y][x + 1] || !ft_is_char(map[y][x + 1], " F1\n")))
// 			return (ft_map_error_msg(), 1);
// 		else
// 			res[y - j][x - i] = 'F';
		
// 	}
// }

// int	ft_map_parsing(char **map)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (map[y])
// 	{
// 		while (map[y][x] && map[y][x] != ' ')
// 			x++;
// 		if (!map[y][x])
// 		{
// 			x = 0;
// 			y++;
// 		}
// 		else
// 			if (ft_fill_space(&map[x][y], map, x, y))
// 				return (1);
		
// 	}
// }

int	ft_scan_map(char **map, t_cub *cub)
{
	int	x;
	int	y;
	int	count;

	(void) cub;
	count = 0;
	y = 0;
	x = 0;
	while (map[y])
	{
		while (ft_is_char(map[y][x], " 10NSEW"))
			if (ft_is_char(map[y][x++], "NSEW"))
				count++;
		if (count > 1 || (!ft_is_char(map[y][x], "\n") && map[y][x]))
			return (ft_map_error_msg(), 1);
		y++;
		x = 0;
	}
	// if (ft_map_parsing(map))
	// 	return (1);
	return (0);
}
