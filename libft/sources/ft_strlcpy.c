/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:30:50 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 16:00:13 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!src)
		return (0);
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 4)
// 	{
// 		size_t	n1;
// 		size_t	n2;

// 		n1 = ft_strlcpy(av[1], av[2], atoi(av[3]));
// 		n2 = strlcpy(av[1], av[2], atoi(av[3]));
// 		printf("Ma fonction : %ld\n", n1);
// 		printf("Vraie fonction : %ld", n2);
// 	}
// }
