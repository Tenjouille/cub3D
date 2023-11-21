/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:55:45 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 16:00:11 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	max_len;

	if (!size && !dst && !src)
		return (0);
	if (!size)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	max_len = ft_strlen(src) + d_len;
	if (size < d_len)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] != '\0' && d_len + i < size - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (max_len);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 4)
// 	{
// 		size_t	size;

// 		size = strlcat(av[1], av[2], atoi(av[3]));
// 		printf("La fonction : %ld\n", size);
// 	}
// }
