#include "../../includes/cub.h"

int	ft_parsing(int ac, char **av, t_cub *cub)
{
	// int	i = 0;
	if (ft_argv_parsing(ac, av))
		return (1);
	cub->desc = ft_get_desc(av[1]);
	// while (cub->desc[i])
	// 	printf("%s\n", cub->desc[i++]);
	cub->map = ft_get_map(cub, cub->desc);
	cub->desc = ft_sort_desc(cub->desc);
	// i = 0;
	// while (cub->map[i])
	// 	printf("%s\n", cub->map[i++]);
	if (ft_scan_desc(cub->desc, cub))
		return (1);
	if (ft_scan_map(cub->map, cub))
		return (1);
	return (0);
}
