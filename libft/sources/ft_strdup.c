/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:33:18 by tgeorge           #+#    #+#             */
/*   Updated: 2023/11/23 17:02:02 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	len = 0;
	while (s[len])
	{
		dup[len] = s[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		char	*p1;
// 		char	*p2;
// 		p1 = ft_strdup(av[1]);
// 		p2 = strdup(av[1]);
// 		printf("Mon dup : %s\n", p1);
// 		printf("Adresse : %p\n", p1);
// 		printf("Vrai dup : %s\n", p2);
// 		printf("Adresse : %p\n", p2);
// 		free(p1);
// 		free(p2);
// 	}
// }
