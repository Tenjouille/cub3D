/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:37:29 by tgeorge           #+#    #+#             */
/*   Updated: 2023/06/14 16:12:56 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("Ma fonction : %ld\n", ft_strlen(av[1]));
// 		printf("Vraie fonction : %ld", strlen(av[1]));
// 	}
// }
