/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:06:53 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:17 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (16384);
	else
		return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("Ma fonction : %d\n", ft_isprint(atoi(av[1])));
// 		printf("Vraie fonction : %d", isprint(atoi(av[1])));
// 	}
// }
