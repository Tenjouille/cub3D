/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:06:17 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:48 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

// int	main(void)
// {
// 	t_list	*elem1;
// 	t_list	*elem2;
// 	char	*c;
// 	char	*d;

// 	c = "Hello";
// 	d = "You";
// 	elem1 = ft_lstnew(c);
// 	elem2 = ft_lstnew(d);
// 	elem1->next = elem2;
// 	printf("%s\n", (char *)elem1->content);
// 	printf("%s\n", (char *)elem2->content);
// }
