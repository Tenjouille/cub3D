/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:13:22 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:25 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == 0)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

// int	main(void)
// {
// 	t_list	*elem1;
// 	t_list	*elem2;
// 	t_list	*elem3;
// 	char	s12[] = "Bonjour";
// 	char	s3[] = "Bye";

// 	elem1 = ft_lstnew(s12);
// 	elem2 = ft_lstnew(s12);
// 	elem3 = ft_lstnew(s3);
// 	elem1->next = elem2;
// 	ft_lstadd_back(&elem1, elem3);
// 	printf("%s\n", (char *)elem1->next->next->content);
// }
