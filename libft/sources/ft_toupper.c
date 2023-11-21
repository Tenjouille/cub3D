/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:04:20 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 17:53:54 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c = c - 32;
	return (c);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		char	res;
// 		char	ft_res;
// 		ft_res = ft_toupper((int)*av[1]);
// 		res = toupper((int)*av[1]);
// 		if (res != (int)*av[1])
// 			printf("VraiUpper : %c\n", res);
// 		if (ft_res != (int)*av[1])
// 			printf("MonUpper : %c", ft_res);
// 	}
// }
