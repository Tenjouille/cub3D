#include "../../includes/cub.h"

char	*ft_strdup_better(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else if (str[i++])
			len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			res[len++] = str[i++];
	}
	res[len] = '\0';
	return (res);
}

char	**ft_sorting_tab(char **unsort, char **res)
{
	int	i;
	int	j;

	i = 0;
	while (unsort[i])
	{
		j = 0;	
		while (unsort[i][j] == ' ' || unsort[i][j] == '\t')
			j++;
		if (unsort[i][j] == 'N')
			res[0] = ft_strdup_better(&unsort[i][j]);
		if (unsort[i][j] == 'S')
			res[1] = ft_strdup_better(&unsort[i][j]);
		if (unsort[i][j] == 'E')
			res[2] = ft_strdup_better(&unsort[i][j]);
		if (unsort[i][j] == 'W')
			res[3] = ft_strdup_better(&unsort[i][j]);
		if (unsort[i][j] == 'F')
			res[4] = ft_strdup_better(&unsort[i][j]);
		if (unsort[i][j] == 'C')
			res[5] = ft_strdup_better(&unsort[i][j]);
		i++;
	}
	res[6] = 0;
	return (res);
}

char	**ft_sort_desc(char	**unsort)
{
	char	**desc;
	int		i;
	int		j;
	int		len;

	i = 0;
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
		if (!desc[i])
			return (ft_putstr_fd("CALLOC FAILURE\n", 2), NULL);
		i++;
	}
	return (ft_sorting_tab(unsort, desc));
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

