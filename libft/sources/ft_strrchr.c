/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:28:19 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 16:00:28 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ptr;

	i = 0;
	while (s[i])
		i++;
	ptr = s + i;
	while ((unsigned char)*ptr != (unsigned char)c && ptr != s)
		ptr --;
	if ((unsigned char)*ptr == (unsigned char)c)
		return ((char *)ptr);
	return (0);
}

// int     main(int ac, char **av)
// {
//         if (ac == 3)
//         {
//                 char *p1;
//                 char *p2;
//                 p1 = strrchr(av[1], (int)*av[2]);
//                 p2 = ft_strrchr(av[1], (int)*av[2]);
//                 printf("Adresse de av[1] : %p\n", av[1]);
// 		if (p1 == 0)
// 			printf("Adresse invalide\n");
// 		else
//                 	printf("*p1 : %c\n", *p1);
//                 printf("Adresse de p1 : %p\n", p1);
// 		if (p2 == 0)
// 			printf("Adresse invalide\n");
// 		else
//                 	printf("*p2 : %c\n", *p2);
//                 printf("Adresse de p2 : %p", p2);
//         }
// }
