/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:32:18 by tgeorge           #+#    #+#             */
/*   Updated: 2023/12/08 11:18:21 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_norm(int *i, int *count)
{
	*i += 1;
	*count += 1;
}

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
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (-1);
	while (str[i] == '0')
		i++;
	count = i;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - 48);
	while (str[i] == ' ' || str[i] == '\t')
		ft_norm(&i, &count);
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
