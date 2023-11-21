/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:36:58 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 16:00:06 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// 
// void	ft_tolouche(unsigned int i, char *s)
// {
// 	if (s[i] >= 'a' && s[i] <= 'z')
// 		s[i] = s[i] - 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(f)(i, s + i);
		i++;
	}
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		ft_striteri(av[1], &ft_tolouche);
// 		printf("%s\n", av[1]);
// 	}
// }