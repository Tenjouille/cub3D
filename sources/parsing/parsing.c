/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:43:57 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:44:19 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	init_fd(char *desc)
{
	int	fd;

	fd = open(desc, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("OPEN FAILURE\n", 2), 1);
	return (fd);
}

char	*ft_strdup_better(char *str, int type)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t') && type == 2)
			i++;
		else if (str[i++])
			len++;
	}
	res = ft_malloc(sizeof(char) * (len), 0, 0, 0);
	i = 0;
	len = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t') && type == 2)
			i++;
		else
			res[len++] = str[i++];
	}
	res[len - 1] = '\0';
	return (res);
}

int	ft_find_not_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t' && str[i] != ',' && str[i] != '\n'
			&& str[i] != '+' && (str[i] < '0' || str[i] > '9'))
			return (1);
	return (0);
}

int	ft_check_texture_path(char *path)
{
	int	i;

	i = ft_strlen(path);
	while (path[i] != '.')
		i--;
	if (ft_strncmp(&path[i], ".xpm", 4))
		return (1);
	return (0);
}

int	ft_parsing(int ac, char **av, t_cub *cub)
{
	if (ft_argv_parsing(ac, av))
		return (1);
	cub->desc = ft_get_desc(av[1]);
	if (!cub->desc)
		return (1);
	cub->map = ft_get_map(cub, cub->desc);
	cub->desc = ft_sort_desc(cub, cub->desc);
	if (!cub->desc || ft_scan_desc(cub->desc, cub))
		return (ft_map_error_msg(), 1);
	if (ft_scan_map(cub->map, cub))
		return (ft_map_error_msg(), 1);
	return (0);
}
