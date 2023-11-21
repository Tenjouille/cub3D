/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:19:31 by tgeorge           #+#    #+#             */
/*   Updated: 2023/05/03 15:58:31 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *lst;
	while (temp1)
	{
		temp2 = temp1->next;
		ft_lstdelone(temp1, del);
		temp1 = temp2;
	}
	*lst = 0;
}
