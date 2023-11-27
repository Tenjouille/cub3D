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

// int	ft_manage_quote(char *path, char quote, int i)
// {
// 	int	j;

// 	j = 0;
// 	if (!path)
// 		return (ft_putstr_fd("Texture path not found\n", 2), -1);
// 	if (!quote)
// 	{
// 		while (path[i + j])
// 			i++;
// 	}
// 	if (!path[1])
// 		return (ft_putstr_fd("Invalid path to texture", 2), -1);
// 	while (path[i + j] && path[i + j] != quote)
// 		j++;
// 	if (path[i + j] != quote)
// 		return (ft_putstr_fd("Invalid path to texture", 2), -1);
// 	return (i + j);
// }

// int	ft_texture(char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (str[i] == 'N')
// 	{
// 		while (str[++i] == ' ' || str[++i] == '\t')
// 			continue ;
// 		if (str[i] == 'O')
// 		{
// 			i++;
// 			while (str[i] == ' ' || str[i] == '\t')
// 				i++;
// 			while (str[i + j] && str [i + j] != ' ')
// 				j++;
// 			if (!ft_strnchr(&str[i], '\"', j) || !ft_strnchr(&str[i], '\'', j))
// 				return (ft_putstr_fd("Too many arguments to run cub\n", 2), 1);
// 			if ((ft_strnchr(&str[i], '\"', j)
// 				&& !ft_strnchr(&str[i + j], '\"', ft_strlen(&str[i + j])))
// 				|| (ft_strnchr(&str[i], '\'', j)
// 				&& !ft_strnchr(&str[i + j], '\'', ft_strlen(&str[i + j]))))
// 		}
// 	}
// }

// int	ft_file_parsing(char *map)
// {
// 	int		fd;
// 	char	*buf;
// 	int		i;

// 	i = 0;
// 	fd = open(map, O_RDONLY);
// 	if (fd < 0)
// 		return (ft_putstr_fd("OPEN FAILURE\n", 2), 1);
// 	buf = get_next_line(fd);
// 	while (buf)
// 	{
// 		while (buf[i] == ' ' | buf[i] == '\t')
// 			i++;
// 		if (buf[i] == '\n')
// 		{
// 			free(buf);
// 			buf = get_next_line(fd);
// 			continue ;
// 		}
// 		if (ft_texture(&buf[i]))
// 		{
// 			if (ft_texture_parsing(&buf[i]))
// 				return (free(buf), 1);
// 			else
// 			{
// 				free(buf);
// 				buf = get_next_line(fd);
// 				continue ;
// 			}
// 		}
// 		else
// 			return (free(buf), ft_putstr_fd("Invalid texture syntaxe", 2), 1);
// 	}
	
// 	return (0);
// }

int	ft_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (1);
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
	while (!ft_strchr(desc[j], '.'))
		j--;
	j++;
	map = malloc(sizeof(char*) * (i - j + 1));
	if (!map)
		return (ft_putstr_fd("MALLOC FAILURE\n", 2), NULL);
	while (desc[j] && j < i)
		map[k++] = ft_strdup(desc[j++]);
	map[k] = 0;
	return (map);
}

int	ft_desclen(char *desc)
{
	int		fd;
	int		i;
	char	*buf;

	i = 0;
	fd = open(desc, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("OPEN FAILURE\n", 2), 1);
	buf = get_next_line(fd);
	while (buf)
	{
		if (ft_empty_line(buf))
		{
			free(buf);
			buf = get_next_line(fd);
			continue ;
		}
		free(buf);
		i++;
		buf = get_next_line(fd);
	}
	// printf("%d\n", i);
	return (close(fd), free(buf), i);
}

char	**ft_get_desc(char *file)
{
	int		fd;
	int		i;
	char	**desc;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("OPEN FAILURE\n", 2), NULL);
	desc = ft_calloc(sizeof(char*), ft_desclen(file) + 1);
	if (!desc)
		return (ft_putstr_fd("CALLOC FAILURE\n", 2), NULL);
	desc[i] = get_next_line(fd);
	while (desc[i])
	{
		if (ft_empty_line(desc[i]))
			free(desc[i]);
		else
			i++;
		desc[i] = get_next_line(fd);
	}
	return (desc);
}

int	ft_check_texture_path(char *path)
{
	(void) path;
	return (0);
}

// int	ft_check_NSEW(char **desc, char *dir)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = 0;
// 	while (desc[i][j] == ' ' || desc[i][j] == '/t')
// 		j++;
// 	while (desc[i] && desc[i][j] != dir[0] && desc[i][j + 1] != dir[1])
// 	{
// 		j = 0;
// 		i++;
// 		while (desc[i][j] == ' ' || desc[i][j] == '/t')
// 			j++;
// 	}
// 	if (!desc[i])
// 		return (1);
// 	while (desc[i][j] == ' ' || desc[i][j] == '\t')
// 		j++;
// 	if (ft_check_texture_path(&desc[i][j]))
// 		return (1);
// 	return (0);
// }

// int	ft_check_color(char *color)
// {
// 	int		i;
// 	int		len;
// 	char	*buf;

// 	i = 0;
// 	while (color[i] != '.')
// 	{
// 		if (color[i] == ' ' || color[i] == '\t')
// 			i++;
		
// 	}
// 	buf = ft_calloc(sizeof(char), len + 1)
// }

// int	ft_check_FC(char **desc, char FC)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = 0;
// 	while (desc[i][j] == ' ' || desc[i][j] == '/t')
// 		j++;
// 	while (desc[i] && desc[i][j] != FC)
// 	{
// 		j = 0;
// 		i++;
// 		while (desc[i][j] == ' ' || desc[i][j] == '/t')
// 			j++;
// 	}
// 	if (!desc[i])
// 		return (1);
// 	while (desc[i][j] == ' ' || desc[i][j] == '\t')
// 		j++;
// 	// if (ft_check_color(&desc[i][j]))
// 	// 	return (1);
// 	return (0);
// }

// int	ft_check_all_dir(char **desc)
// {
// 	int	check;

// 	check = 0;
// 	check += ft_check_NSEW(desc, "NO");
// 	check += ft_check_NSEW(desc, "SO");
// 	check += ft_check_NSEW(desc, "WE");
// 	check += ft_check_NSEW(desc, "EA");
// 	check += ft_check_FC(desc, 'F');
// 	check += ft_check_FC(desc, 'C');
// 	return (check);
// }

int	ft_scan_desc(char **desc)
{
	int	i;

	i = 0;
	while (ft_strchr(desc[i], '.'))
		i++;
	if (i != 6)
		return (ft_map_error_msg(), 1);
	// if (ft_check_all_dir(desc))
	// 	return (ft_map_error_msg(), 1);
	return (0);
}

int	ft_parsing(int ac, char **av, t_cub *cub)
{
	// int		i;

	// i = 0;
	if (ft_argv_parsing(ac, av))
		return (1);
	cub->desc = ft_get_desc(av[1]);
	if (ft_scan_desc(cub->desc))
		return (1);
	cub->map = ft_get_map(cub->desc);
	// while (cub->desc[i])
	// 	printf("%s", cub->desc[i++]);
	// printf("\n");
	// i = 0;
	// while (cub->map[i])
	// 	printf("%s", cub->map[i++]);
	// if (ft_file_parsing(av[1]))
	// 	return (1);
	// cub->map = ft_map_scanning(av[1]);
	return (0);
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
