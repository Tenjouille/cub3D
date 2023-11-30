#include "../includes/cub.h"

int	end_of_prog(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	ft_malloc(0, 1, 0, 0);
	exit (1);
}

int	ft_argv_parsing(int ac, char **av)
{
	int	i;

	if (ac == 1)
		return (ft_putstr_fd("Please, enter a map to play with\n", 2), 1);
	if (ac != 2)
		return (ft_putstr_fd("Too many arguments to run cub\n", 2), 1);
	i = ft_strlen(av[1]) - 1;
	if (i < 0)
		return (ft_putstr_fd("The map needs to be in a .cub file\n", 2), 1);
	while (av[1][i] != '.' && i != 0)
		i--;
	if (av[1][i] != '.')
		return (ft_putstr_fd("The map needs to be in a .cub file\n", 2), 1);
	if (ft_strncmp(&av[1][i], ".cub", ft_strlen(&av[1][i])))
		return (ft_putstr_fd("The map needs to be in a .cub file\n", 2), 1);
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
	while (!ft_strchr(desc[j], '.') && !ft_strchr(desc[j], ','))
		j--;
	j++;
	map = malloc(sizeof(char*) * (i - j + 1));
	if (!map)
		return (ft_putstr_fd("malloc FAILURE\n", 2), NULL);
	while (desc[j] && j < i)
		map[k++] = ft_strdup(desc[j++]);
	map[k] = 0;
	cub->map_height = k - 1;
	return (map);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	cub.window_x = 1920;
	cub.window_y = 1080;
	if (ft_parsing(ac, av, &cub))
		return (ft_malloc(0, 1, 0, 0), 1);
	cub.mlx = mlx_init();
	if (!cub.mlx)
		return (ft_malloc(0, 1, 0, 0), 1);
	cub.win = mlx_new_window(cub.mlx, cub.window_x, cub.window_y, "Cub3D");
	if (!cub.win)
		return (ft_malloc(0, 1, 0, 0), 1);
	game_init(&cub);
	mlx_hook(cub.win, KeyPress, KeyPressMask, &keyboard_stuff, &cub);
	mlx_hook(cub.win, KeyRelease, KeyReleaseMask, &keyboard_release, &cub);
	mlx_hook(cub.win, 17, 1l << 17, &end_of_prog, &cub);
	mlx_loop_hook(cub.mlx, game_loop, &cub);
	mlx_loop(cub.mlx);
	ft_malloc(0, 1, 0, 0);
	return (0);
}
