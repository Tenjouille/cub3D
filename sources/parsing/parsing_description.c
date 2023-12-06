#include "../../includes/cub.h"

int	ft_check_nsew(char *desc, char *dir)
{
	int	i;

	i = 0;
	while (desc && (desc[i] == ' ' || desc[i] == '\t'))
		i++;
	if (ft_strncmp(desc, dir, 2))
		return (ft_map_error_msg(), 1);
	i += 2;
	while (desc[i] == ' ' || desc[i] == '\t')
		i++;
	if (ft_check_texture_path(&desc[i]))
		return (1);
	return (0);
}

char	*ft_check_color_loop(t_cub *cub, char *color, int *i, int rgb)
{
	int		len;
	int		tmp;
	char	*buf;

	len = 0;
	tmp = *i;
	while (color[*i + len] && color[*i + len] != ',' && color[*i + len] != '\n')
		len++;
	buf = ft_calloc(sizeof(char), len + 1);
	len = 0;
	while (color[*i + len] && color[*i + len] != ',' && color[*i + len] != '\n')
	{
		buf[len] = color[*i + len];
		len++;
	}
	*i = tmp + len;
	buf[len] = '\0';
	if (ft_atoi(buf) < 0 || ft_atoi(buf) > 255)
		return (ft_map_error_msg(), NULL);
	if ((char)cub->FC == 'F')
		cub->floor[rgb] = ft_atoi(buf);
	else
		cub->ceiling[rgb] = ft_atoi(buf);
	return (buf);
}

int	ft_check_color(char *color, char FC, t_cub *cub)
{
	int		i;
	int		rgb;
	char	*buf;

	rgb = 0;
	i = 0;
	while (color[i] == FC || color[i] == ' ' || color[i] == '\t')
		i++;
	if (ft_find_not_digit(&color[i]))
		return (ft_map_error_msg(), 1);
	while (rgb < 3 && color[i])
	{
		buf = ft_check_color_loop(cub, color, &i, rgb);
		if (!buf)
			return (1);
		ft_malloc(0, 0, 1, buf);
		rgb++;
		i++;
	}
	if (rgb != 3)
		return (ft_map_error_msg(), 1);
	cub->floor[3] = -1;
	cub->ceiling[3] = -1;
	return (0);
}

int	ft_check_fc(char *desc, char FC, t_cub *cub)
{
	int	i;

	i = 0;
	cub->FC = (int)FC;
	while (desc[i] == ' ' || desc[i] == '\t')
		i++;
	if (desc[i] != FC)
		return (1);
	i++;
	if (ft_strcount(desc, ",") != 2 || ft_check_color(&desc[i], FC, cub))
		return (1);
	return (0);
}

int	ft_scan_desc(char **desc, t_cub *cub)
{
	int	i;

	i = 0;
	if (!desc || !desc[i])
		return (ft_map_error_msg(), 1);
	while (desc[i] && (ft_strchr(desc[i], '.') || ft_strchr(desc[i], ',')))
		i++;
	if (i != 6)
		return (ft_map_error_msg(), 1);
	if (ft_check_nsew(desc[0], "NO"))
		return (1);
	if (ft_check_nsew(desc[1], "SO"))
		return (1);
	if (ft_check_nsew(desc[3], "WE"))
		return (1);
	if (ft_check_nsew(desc[2], "EA"))
		return (1);
	if (ft_check_fc(desc[4], 'F', cub))
		return (1);
	if (ft_check_fc(desc[5], 'C', cub))
		return (1);
	return (0);
}
