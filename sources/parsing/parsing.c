#include "../../includes/cub.h"

int	ft_find_not_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t' && str[i] != ',' && str[i] != '\n'
			&& (str[i] < '0' || str[i] > '9'))
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
	cub->map = ft_get_map(cub, cub->desc);
	int i = 0;
	while (cub->map[i])
		printf("%s", cub->map[i++]);
	cub->desc = ft_sort_desc(cub, cub->desc);
	if (!cub->desc || ft_scan_desc(cub->desc, cub))
		return (ft_map_error_msg(), 1);
	if (ft_scan_map(cub->map, cub))
		return (ft_map_error_msg(), 1);
	return (0);
}
