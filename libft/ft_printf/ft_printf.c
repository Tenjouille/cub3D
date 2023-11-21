/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:09:40 by tgeorge           #+#    #+#             */
/*   Updated: 2022/12/10 11:37:10 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_type(char c, va_list args)
{
	size_t	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		i += ft_putadress(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_putunsnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_put_hexamin(va_arg(args, int));
	else if (c == 'X')
		i += ft_put_hexamaj(va_arg(args, int));
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	check_format(char c)
{
	if (ft_strchr("cspdiuxX", c) || c == '%')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	size_t	nbcarac;

	va_start(args, format);
	nbcarac = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			nbcarac += format_type(format[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			nbcarac++;
		}
	}
	va_end(args);
	return (nbcarac);
}
