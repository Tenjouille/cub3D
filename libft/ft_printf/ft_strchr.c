/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:45:33 by tgeorge           #+#    #+#             */
/*   Updated: 2022/12/08 17:15:06 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while ((unsigned char)*ptr != '\0'
		&& (unsigned char)*ptr != (unsigned char)c)
		ptr++;
	if ((unsigned char)*ptr == (unsigned char)c)
		return ((char *)ptr);
	return (0);
}
