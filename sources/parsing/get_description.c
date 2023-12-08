/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_description.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:43:49 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:43:50 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	j_passing_whitespaces(int i, int j, char **unsort)
{
	j = 0;
	while (unsort[i][j] == ' ' || unsort[i][j] == '\t')
		j++;
	return (j);
}

char	**ft_sorting_tab(t_cub *cub, char **unsort, char **res)
{
	int	i;
	int	j;

	i = 0;
	if (ft_bigstrlen(unsort) - ft_bigstrlen(cub->map) > 6)
		return (NULL);
	while (unsort[i])
	{
		j = j_passing_whitespaces(i, j, unsort);
		if (unsort[i][j] == 'N')
			res[0] = ft_strdup_better(&unsort[i][j], 2);
		else if (unsort[i][j] == 'S')
			res[1] = ft_strdup_better(&unsort[i][j], 2);
		else if (unsort[i][j] == 'E')
			res[2] = ft_strdup_better(&unsort[i][j], 2);
		else if (unsort[i][j] == 'W')
			res[3] = ft_strdup_better(&unsort[i][j], 2);
		else if (unsort[i][j] == 'F')
			res[4] = ft_strdup_better(&unsort[i][j], 1);
		else if (unsort[i][j] == 'C')
			res[5] = ft_strdup_better(&unsort[i][j], 1);
		i++;
	}
	res[6] = 0;
	return (res);
}

char	**ft_sort_desc(t_cub *cub, char	**unsort)
{
	char	**desc;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	if (ft_bigstrlen(unsort) < 9)
		return (NULL);
	desc = ft_calloc(sizeof(char *), 7);
	while (i < 7)
	{
		j = 0;
		len = 0;
		while (unsort[i][j])
		{
			if (unsort[i][j] == ' ' || unsort[i][j] == '\t')
				j++;
			else if (unsort[i][j++])
				len++;
		}
		desc[i] = ft_calloc(sizeof(char), len + 1);
		i++;
	}
	return (ft_sorting_tab(cub, unsort, desc));
}

int	ft_desclen(char *desc)
{
	int		fd;
	int		i;
	int		map;
	char	*buf;

	map = 0;
	i = 0;
	fd = init_fd(desc);
	buf = get_next_line(fd);
	while (buf)
	{
		if (!ft_empty_line(buf) && !ft_strchr(desc, ',')
			&& !ft_strchr(desc, '.'))
			map = 1;
		if (ft_empty_line(desc) && !map)
		{
			ft_malloc(0, 0, 1, buf);
			buf = get_next_line(fd);
			continue ;
		}
		ft_malloc(0, 0, 1, buf);
		i++;
		buf = get_next_line(fd);
	}
	return (close(fd), i);
}

char	**ft_get_desc(char *file)
{
	int		fd;
	int		i;
	int		len;
	char	**desc;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("OPEN FAILURE\n", 2), NULL);
	len = ft_desclen(file);
	desc = ft_calloc(sizeof(char *), len + 1);
	desc[i] = get_next_line(fd);
	while (desc[i])
	{
		if (!ft_empty_line(desc[i]) && !ft_strchr(desc[i], ',')
			&& !ft_strchr(desc[i], '.'))
			len = 0;
		if (ft_empty_line(desc[i]) && len)
			ft_malloc(0, 0, 1, desc[i]);
		else
			i++;
		desc[i] = get_next_line(fd);
	}
	desc[i] = NULL;
	return (desc);
}
