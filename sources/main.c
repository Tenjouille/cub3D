#include "../includes/cub.h"

int	end_of_prog(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	exit (1);
}

int	keyboard_stuff(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		end_of_prog(cub);
	if (keysym == KEY_W)
		cub->game->key_w = 1;
	if (keysym == KEY_S)
		cub->game->key_s = 1;
	if (keysym == KEY_A)
		cub->game->key_a = 1;
	if (keysym == KEY_D)
		cub->game->key_d = 1;
	if (keysym == KEY_RIGHT)
		cub->game->key_right = 1;
	if (keysym == KEY_LEFT)
		cub->game->key_left = 1;
	else
		return (0);
	return (42);
}

int	keyboard_release(int keysym, t_cub *cub)
{
	if (keysym == KEY_W)
		cub->game->key_w = 0;
	if (keysym == KEY_S)
		cub->game->key_s = 0;
	if (keysym == KEY_A)
		cub->game->key_a = 0;
	if (keysym == KEY_D)
		cub->game->key_d = 0;
	if (keysym == KEY_RIGHT)
		cub->game->key_right = 0;
	if (keysym == KEY_LEFT)
		cub->game->key_left = 0;
	else
		return (0);
	return (42);
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

char	**ft_get_map(char **desc)
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
	return (map);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	cub.window_x = 1280;
	cub.window_y = 720;
	if (ft_parsing(ac, av, &cub))
		return (1);
	cub.mlx = mlx_init();
	if (!cub.mlx)
		return (1);
	cub.win = mlx_new_window(cub.mlx, cub.window_x, cub.window_y, "Cub3D");
	if (!cub.win)
		return (1);
	game_init(&cub);
	mlx_hook(cub.win, KeyPress, KeyPressMask, &keyboard_stuff, &cub);
	mlx_hook(cub.win, KeyRelease, KeyReleaseMask, &keyboard_release, &cub);
	mlx_hook(cub.win, 17, 1l << 17, &end_of_prog, &cub);
	mlx_loop_hook(cub.mlx, game_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
