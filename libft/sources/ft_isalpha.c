/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:37:01 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:08 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1024);
	else
		return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("Ma fonction : %d\n", ft_isalpha(atoi(av[1])));
// 		printf("Vraie fonction : %d", isalpha(atoi(av[1])));
// 	}
// }
