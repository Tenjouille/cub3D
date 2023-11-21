/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:34:30 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:59:33 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while ((unsigned char)*ptr != '\0'
		&& (unsigned char)*ptr != (unsigned char)c)
		ptr++;
	if ((unsigned char)*ptr == (unsigned char)c)
		return ((char *)ptr);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 3)
// 	{
// 		char *p1;
// 		char *p2;

// 		p1 = strchr(av[1], atoi(av[2]));
// 		p2 = ft_strchr(av[1], atoi(av[2]));
// 		printf("Ma fonction : %s\n", p1);
// 		printf("Vraie fonction : %s\n", p2);
// 	}
// }
