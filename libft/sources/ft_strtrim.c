/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:21:05 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 16:00:30 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i > 0 && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

// int	main(int ac, char **av)
// {
//  	if (ac == 3)
//  		printf("%s", ft_strtrim(av[1], av[2]));
// 	// (void)ac;
// 	// (void)av;
// 	// char	*res;
// 	// res = ft_strtrim(" lorem ipsum dolor sit amet", "l ");
// 	// printf("%s", res);
// }
// int	main(void)
// {
// 	char  s[] = "   xxxtripouille   xxx";
//     char  set[] = " x";
//     char  *res;
// 	res = ft_strtrim(s, set);
// 	printf("%s\n", res);
// }