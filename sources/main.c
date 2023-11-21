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

int	ft_parsing(int ac, char **av, t_cub *cub)
{
	(void) cub;
	if (ft_argv_parsing(ac, av))
		return (1);
	// if (ft_file_parsing(av[1]))
	// 	return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ft_parsing(ac, av, &cub))
		return (1);
	cub.mlx = mlx_init();
	if (!cub.mlx)
		return (1);
	cub.win = mlx_new_window(cub.mlx, 1280, 720, "Cub3D");
	if (!cub.win)
		return (1);
	mlx_hook(cub.win, KeyPress, KeyPressMask, &keyboard_stuff, &cub);
	mlx_hook(cub.win, 17, 1l << 17, &end_of_prog, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
