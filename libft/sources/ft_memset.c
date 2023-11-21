/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:50:38 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:59:12 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (char)c;
		i++;
	}
	return (s);
}

// int     main(int ac, char **av)
// {
//         if (ac == 2)
//         {
//         	printf("Avant : %s\n", av[1]);
//                 av[1] = ft_memset(av[1], 'x', 2*sizeof(char));
//                 printf("Apres : %s\n", av[1]);
//         }
// }
