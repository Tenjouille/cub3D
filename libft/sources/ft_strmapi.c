/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:15:00 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 16:00:19 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	i = 0;
	if (!s || !f)
		return (0);
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (0);
	while (s[i])
	{
		res[i] = (f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// char	ft_fakeupper(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'a' && c <= 'z')
// 		c = c - 32;
// 	return (c);
// }

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		char	*res;

// 		res = ft_strmapi(av[1], &ft_fakeupper);
// 		printf("%s\n", res);
// 	}
// }