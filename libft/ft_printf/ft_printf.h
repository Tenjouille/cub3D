/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gurse <Gurse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:16:32 by tgeorge           #+#    #+#             */
/*   Updated: 2023/06/26 21:58:16 by Gurse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <ctype.h>
# include <string.h>
// # include <bsd/string.h>
# include <stdint.h>
# include <limits.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putadress(unsigned long long ptr);
int		ft_putnbr(int n);
int		ft_putunsnbr(unsigned int n);
int		ft_put_hexamaj(int nbr);
int		ft_put_hexamin(int nbr);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_printf(const char *format, ...);
int		check_format(char c);
void	ft_launch(int i);
int		format_type(char c, va_list args);
char	*ft_strchr(const char *s, int c);

#endif