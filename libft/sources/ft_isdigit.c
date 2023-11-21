/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:06:04 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:14 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (2048);
	else
		return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("Ma fonction : %d\n", ft_isdigit(atoi(av[1])));
// 		printf("Vraie fonction : %d", isdigit(atoi(av[1])));
// 	}
// }
