/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:27:02 by tgeorge           #+#    #+#             */
/*   Updated: 2022/12/10 11:37:44 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(uintptr_t ptr)
{
	int	i;

	i = 0;
	if (ptr >= 16)
	{
		i += ft_put_ptr(ptr / 16);
		i += ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			i += ft_putchar(ptr + 48);
		else
			i += ft_putchar(ptr - 10 + 'a');
	}
	return (i);
}

int	ft_putadress(unsigned long long ptr)
{
	int	i;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = 0;
	i += write(1, "0x", 2);
	if (ptr == 0)
		i += write(1, "0", 1);
	else
		i += ft_put_ptr(ptr);
	return (i);
}
