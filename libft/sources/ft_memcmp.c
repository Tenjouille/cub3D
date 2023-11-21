/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:44:16 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:59:01 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

// int	main(int ac, char **av)
// {
// 	/*if (ac == 4)
// 	{
// 		printf("Ma fonction : %d\n", ft_memcmp(av[1], av[2], atoi(av[3])));
// 		printf("Vraie fonction : %d\n", memcmp(av[1], av[2], atoi(av[3])));
// 	}*/
// 	(void)ac;
// 	char	s1[] = "abcd\0fzh";
// 	char	s2[] = "abcdefgh";
// 	int	res1;
// 	int	res2;

// 	res1 = ft_memcmp(s1, s2, atoi(av[1]));
// 	res2 = memcmp(s1, s2, atoi(av[1]));
// 	printf("Ma fonction : %d\n", res1);
// 	printf("Vraie fonction : %d\n", res2);
// }
