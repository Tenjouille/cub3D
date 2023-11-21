/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:15:51 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:04 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalnum(int c)
{
	if (c > 47 && c < 58)
		return (8);
	else if (c > 64 && c < 91)
		return (8);
	else if (c > 96 && c < 123)
		return (8);
	else
		return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("Ma fonction : %d\n", ft_isalnum(atoi(av[1])));
// 		printf("Vraie fonction : %d", isalnum(atoi(av[1])));
// 	}
// }
