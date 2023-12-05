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
		return (ft_map_error_msg(), 1);
	return (0);
}

int	ft_check_nsew(char **desc, char *dir)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (desc[i] && (desc[i][j] == ' ' || desc[i][j] == '\t'))
		j++;
	while (desc[i] && ft_strncmp(&desc[i][j], dir, 2))
	{
		j = 0;
		i++;
		while (desc[i] && (desc[i][j] == ' ' || desc[i][j] == '\t'))
			j++;
	}
	if (!desc[i])
		return (ft_map_error_msg(), 1);
	j += 2;
	while (desc[i][j] == ' ' || desc[i][j] == '\t')
		j++;
	if (ft_check_texture_path(&desc[i][j]))
		return (1);
	return (0);
}

int	ft_check_color(char *color, char FC, t_cub *cub)
{
	int		i;
	int		tmp;
	int		len;
	int		rgb;
	char	*buf;

	rgb = 0;
	i = 0;
	while (color[i] == FC || color[i] == ' ' || color[i] == '\t')
		i++;
	if (ft_find_not_digit(&color[i]))
		return (ft_map_error_msg(), 1);
	while (color[i] && rgb < 3)
	{
		len = 0;
		tmp = i;
		while (color[i] && color[i] != ',' && color[i] != '\n')
		{
			i++;
			len++;
		}
		buf = ft_calloc(sizeof(char), len + 1);
		i = tmp;
		len = 0;
		while (color[i] && color[i] != ',' && color[i] != '\n')
			buf[len++] = color[i++];
		buf[len] = '\0';
		printf("%d \n", ft_atoi(buf));
		if (ft_atoi(buf) < 0 || ft_atoi(buf) > 255)
			return (ft_map_error_msg(), 1);
		if (FC == 'F')
			cub->floor[rgb] = ft_atoi(buf);
		else
			cub->ceiling[rgb] = ft_atoi(buf);
		ft_malloc(0, 0, 1, buf);
		rgb++;
		i++;
	}
	if (rgb != 3)
		return (ft_map_error_msg(), 1);
	cub->floor[3] = -1;
	cub->ceiling[3] = -1;
	i = 0;
	return (0);
}

int	ft_check_fc(char **desc, char FC, t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (desc[i][j] == ' ' || desc[i][j] == '\t')
		j++;
	while (desc[i] && desc[i][j] != FC)
	{
		j = 0;
		i++;
		while (desc[i][j] == ' ' || desc[i][j] == '\t')
			j++;
	}
	if (!desc[i])
		return (1);
	j++;
	if (ft_strcount(desc[i], ",") != 2 || ft_check_color(&desc[i][j], FC, cub))
		return (1);
	return (0);
}

int	ft_scan_desc(char **desc, t_cub *cub)
{
	int	i;

	i = 0;
	if (!desc || !desc[i])
		return(ft_map_error_msg(), 1);
	while (desc[i] && (ft_strchr(desc[i], '.') || ft_strchr(desc[i], ',')))
		i++;
	if (i != 6)
		return (ft_map_error_msg(), 1);
	if (ft_check_nsew(desc, "NO"))
		return (1);
	if (ft_check_nsew(desc, "SO"))
		return (1);
	if (ft_check_nsew(desc, "WE"))
		return (1);
	if (ft_check_nsew(desc, "EA"))
		return (1);
	if (ft_check_fc(desc, 'F', cub))
		return (1);
	if (ft_check_fc(desc, 'C', cub))
		return (1);
	return (0);
}
