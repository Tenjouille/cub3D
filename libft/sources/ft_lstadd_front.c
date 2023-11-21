/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:10:09 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:28 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	*lst = new;
	new->next = temp;
}

// int	main(void)
// {
// 	t_list	*elem1;
// 	t_list	*elem2;
// 	char	s1[] = "Bonjour";
// 	char	s2[] = "Bye";

// 	elem1 = ft_lstnew(s1);
// 	elem2 = ft_lstnew(s2);
// 	ft_lstadd_front(&elem1, elem2);
// 	printf("%s\n", (char *)elem2->next->content);
// }
