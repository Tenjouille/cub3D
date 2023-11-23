/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:59:47 by tgeorge           #+#    #+#             */
/*   Updated: 2023/11/23 16:15:11 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size && (nmemb * size / size) != nmemb)
		return (0);
	ptr = ft_malloc(nmemb * size, 0, 0, 0);
	if (!ptr)
		return (0);
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return ((unsigned char *)ptr);
}

// int	main(void)
// {
// 	char	*ptr;
// 	size_t	i;
// 	size_t	nmemb;

// 	nmemb = SIZE_MAX;
// 	i = 0;
// 	ptr = ft_calloc(nmemb, SIZE_MAX - 1);
// 	if (ptr == NULL)
// 	{
// 		printf("ptr NULL");
// 	}
// 	else
// 	{
// 		while (i < nmemb)
// 		{
// 			write(1, &ptr[i], 1);
// 			i++;
// 		}
// 	}
// }
