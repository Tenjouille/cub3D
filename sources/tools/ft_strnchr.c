/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:41:19 by tbourdea          #+#    #+#             */
/*   Updated: 2023/11/21 15:22:39 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*ft_strnchr(const char *s, int c, int size)
{
	int	i;

	i = 0;
	if (size == 0 && !s)
		return (NULL);
	while (s[i] && i <= size)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}