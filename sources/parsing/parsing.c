#include "../../includes/cub.h"

int	ft_parsing(int ac, char **av, t_cub *cub)
{
	if (ft_argv_parsing(ac, av))
		return (1);
	cub->desc = ft_get_desc(av[1]);
	if (ft_scan_desc(cub->desc, cub))
		return (1);
	cub->map = ft_get_map(cub, cub->desc);
	if (ft_scan_map(cub->map, cub))
		return (1);
	cub->desc = ft_sort_desc(cub->desc);
	return (0);
}
