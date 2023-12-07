/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:32:18 by tgeorge           #+#    #+#             */
/*   Updated: 2023/12/07 21:23:45 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	count;

	i = 0;
	res = 0;
	count = 0;
	if (!str || !str[0])
		return (-1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	count = i;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - 48);
	while (str[i] == ' ' || str[i] == '\t')
	{
		count++;
		i++;
	}
	if (str[i] || i - count > 3)
		return (-1);
	return (res);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("Mon atoi = %d\n", ft_atoi(av[1]));
// 		printf("Vrai atoi : %d", atoi(av[1]));
// 	}
// }
