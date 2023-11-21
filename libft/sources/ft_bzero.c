/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:57:03 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:57:57 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

// int	main(int ac, char **av)
// {
// 	if (ac == 3)
// 	{
// 		int	i;

// 		i = 0;
// 		ft_bzero(av[1], atoi(av[2]));
// 		while (i < 2 * atoi(av[2]))
// 		{
// 			printf("%c", av[1][i]);
// 			i++;
// 		}
// 	}
// }
