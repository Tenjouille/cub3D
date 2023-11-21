/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:43 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:11 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("Ma fonction : %d\n", ft_isascii(atoi(av[1])));
// 		printf("Vraie fonction : %d", isascii(atoi(av[1])));
// 	}
// }
