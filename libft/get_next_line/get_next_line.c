/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:46:24 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/09 13:51:41 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *remember)
{
	char	*buff;
	int		size;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	size = 1;
	while (!ft_strchr_gnl(remember, '\n') && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(buff);
			return (0);
		}
		buff[size] = '\0';
		remember = ft_strjoin_gnl(remember, buff);
	}
	free(buff);
	return (remember);
}

char	*current_line(char	*remember)
{
	char	*curr_line;
	int		len;

	len = 0;
	if (!remember[len])
		return (0);
	while (remember[len] && remember[len] != '\n')
		len++;
	curr_line = malloc((len + 2) * sizeof(char));
	if (!curr_line)
		return (0);
	len = 0;
	while (remember[len] && remember[len] != '\n')
	{
		curr_line[len] = remember[len];
		len++;
	}
	if (remember[len] == '\n')
	{
		curr_line[len] = '\n';
		len++;
	}
	curr_line[len] = '\0';
	return (curr_line);
}

char	*next_line(char *remember)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remember[i] && remember[i] != '\n')
		i++;
	if (!remember[i])
	{
		free(remember);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(remember) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remember[i])
		str[j++] = remember[i++];
	str[j] = '\0';
	free(remember);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*remember[1024];
	char		*curr_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remember[fd] = read_line(fd, remember[fd]);
	if (!remember[fd])
		return (0);
	curr_line = current_line(remember[fd]);
	remember[fd] = next_line(remember[fd]);
	return (curr_line);
}

// int	main(void)
// {
// 	int	fd;
// 	char	*line;
// 	int	boucle;

// 	boucle = 1;
// 	fd = open("test.txt", O_RDONLY);
// 	while (boucle <= 15)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		boucle++;
// 	}
// 	close(fd);
// }