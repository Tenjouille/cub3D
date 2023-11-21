/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:58:14 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:56 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 4)
// 	{
// 		char	*ptr;	
// 		ptr = ft_memchr(av[1], (int)*av[2], atoi(av[3]));
// 		if (ptr == 0)
// 			printf("Pointeur nul (caractere non trouve)");
// 		else
// 			printf("Trouve : %s", ptr);
// 	}
// }
