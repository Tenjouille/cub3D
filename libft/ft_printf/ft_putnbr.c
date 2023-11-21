/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:27:50 by tgeorge           #+#    #+#             */
/*   Updated: 2022/12/08 19:02:55 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + 48);
	}
	else
	{
		i += ft_putchar(n + 48);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		i++;
		n = -n;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + 48);
	}
	else
	{
		i += ft_putchar(n + 48);
	}
	return (i);
}

// int	main(int ac, char **av)
// {
// 	int	i;

// 	i = 0;
// 	if (ac == 2)
// 		i = ft_putnbr(atoi(av[1]));
// 	printf("\ni = %d\n", i);
// }