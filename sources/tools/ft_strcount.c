/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:44:37 by tbourdea          #+#    #+#             */
/*   Updated: 2023/12/08 11:44:38 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_strcount(char *str, char *to_count)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_count[j])
			if (to_count[j++] == str[i])
				count++;
		i++;
	}
	return (count);
}
