/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:43:54 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:43:55 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_check_around(char **map, int x, int y)
{
	if (y <= 0 || x > (int)ft_strlen(map[y - 1])
		|| !ft_is_char(map[y - 1][x], "0F1NSEW")
		|| !map[y + 1] || x > (int)ft_strlen(map[y + 1])
		|| !ft_is_char(map[y + 1][x], "0F1NSEW")
		|| x <= 0 || !ft_is_char(map[y][x - 1], "01FNSEW")
		|| !map[y][x + 1] || !ft_is_char(map[y][x + 1], "01FNSEW"))
		return (1);
	return (0);
}

int	ft_fill_map(char **map, int x, int y)
{
	char	c;

	if (ft_check_around(map, x, y))
		return (1);
	c = map[y][x];
	map[y][x] = 'F';
	if (y > 0 && map[y - 1][x] == c)
		if (ft_fill_map(map, x, y - 1))
			return (1);
	if (map[y + 1] && map[y + 1][x] == c)
		if (ft_fill_map(map, x, y + 1))
			return (1);
	if (map[y][x + 1] && map[y][x + 1] == c)
		if (ft_fill_map(map, x + 1, y))
			return (1);
	if (x > 0 && map[y][x - 1] == c)
		if (ft_fill_map(map, x - 1, y))
			return (1);
	return (0);
}

int	ft_map_parsing(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x] && !ft_is_char(map[y][x], "NSEW0"))
			x++;
		if (!map[y][x])
		{
			x = 0;
			y++;
		}
		else if (map[y][x] == '0')
		{
			if (ft_fill_map(map, x++, y))
				return (1);
		}
		else
			if (ft_check_around(map, x++, y))
				return (1);
	}
	return (0);
}

int	ft_scan_map(char **map, t_cub *cub)
{
	int	x;
	int	y;
	int	count;

	(void) cub;
	count = 0;
	y = 0;
	x = -1;
	while (map[y])
	{
		while (ft_is_char(map[y][++x], " 10NSEW"))
			if (ft_is_char(map[y][x], "NSEW"))
				count++;
		if (!ft_is_char(map[y][x], "\n") && map[y][x])
			return (1);
		y++;
		x = -1;
	}
	if (count != 1 || ft_map_parsing(map))
		return (1);
	return (0);
}

char	**ft_get_map(t_cub *cub, char **desc)
{
	char	**map;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (desc[i])
		i++;
	j = i - 1;
	while (j >= 0 && !ft_strchr(desc[j], '.') && !ft_strchr(desc[j], ','))
		j--;
	j++;
	map = ft_malloc(sizeof(char *) * (i - j + 1), 0, 0, 0);
	while (desc[j] && j < i)
		map[k++] = ft_strdup(desc[j++]);
	map[k] = 0;
	cub->map_height = k - 1;
	return (map);
}
