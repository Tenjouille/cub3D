/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:10:14 by tgeorge           #+#    #+#             */
/*   Updated: 2023/12/08 11:14:31 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s, char const *s2)
{
	int		size1;
	int		size2;
	char	*res;

	size1 = 0;
	size2 = 0;
	if (!s || !s2)
		return (ft_strdup(""));
	res = ft_malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(s2) + 1), 0, 0, 0);
	if (!res)
		return (0);
	while (s[size1])
	{
		res[size1] = s[size1];
		size1++;
	}
	while (s2[size2])
	{
		res[size1 + size2] = s2[size2];
		size2++;
	}
	res[size1 + size2] = '\0';
	return (res);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 3)
// 	{
// 		char	*res;

// 		res = ft_strjoin(av[1], av[2]);
// 		printf("%s", res);
// 	}
// }
