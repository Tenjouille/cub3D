#include "../../includes/cub.h"

int	ft_parsing(int ac, char **av, t_cub *cub)
{
	// int		i;

	// i = 0;
	if (ft_argv_parsing(ac, av))
		return (1);
	cub->desc = ft_get_desc(av[1]);
	if (ft_scan_desc(cub->desc, cub))
		return (1);
	cub->map = ft_get_map(cub->desc);
	if (ft_scan_map(cub->map, cub))
		return (1);
	cub->desc = ft_sort_desc(cub->desc);
	// while (cub->desc[i])
	// 	printf("%s", cub->desc[i++]);
	// printf("\n\n");
	// i = 0;
	// while (cub->map[i])
	// 	printf("%s", cub->map[i++]);
	// if (ft_file_parsing(av[1]))
	// 	return (1);
	// cub->map = ft_map_scanning(av[1]);
	return (0);
}
