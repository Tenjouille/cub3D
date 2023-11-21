/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:48:57 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:45 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new1;
	t_list	*new2;

	if (!lst || !f || !del)
		return (0);
	new1 = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		new2 = ft_lstnew(f(lst->content));
		if (!new2)
		{
			ft_lstclear(&new1, del);
			return (new1);
		}
		ft_lstadd_back(&new1, new2);
		lst = lst->next;
	}
	return (new1);
}
