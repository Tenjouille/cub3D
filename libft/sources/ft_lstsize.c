/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:32:49 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:51 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
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
// 	printf("Size : %d\n", ft_lstsize(elem1));
// }