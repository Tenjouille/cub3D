/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:44:30 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:42 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	while (i < ft_lstsize(lst) - 1)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

// int	main(void)
// {
// 	t_list	*elem1;
// 	t_list	*elem2;
// 	t_list	*elem3;
// 	t_list	*elem4;
// 	char	s123[] = "Bonjour";
// 	char	s4[] = "Bye";

// 	elem1 = ft_lstnew(s123);
// 	elem2 = ft_lstnew(s123);
// 	elem3 = ft_lstnew(s123);
// 	elem4 = ft_lstnew(s4);
// 	elem1->next = elem2;
// 	elem2->next = elem3;
// 	elem3->next = elem4;

// 	printf("%s\n", (char *)ft_lstlast(elem1)->content);
// }
