/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:02:31 by rleger            #+#    #+#             */
/*   Updated: 2023/11/23 16:08:27 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	free_list(t_mem *list_ptr)
{
	free(list_ptr->data);
	free(list_ptr);
}

void	ft_list_remove_if(t_mem **begin_list, void *data_ref)
{
	t_mem	*list_ptr;
	t_mem	*prev;

	list_ptr = *begin_list;
	while (list_ptr && list_ptr->data == data_ref)
	{
		*begin_list = list_ptr->next;
		free_list(list_ptr);
		list_ptr = *begin_list;
	}
	prev = 0;
	while (list_ptr)
	{
		if (list_ptr->data == data_ref)
		{
			prev->next = list_ptr->next;
			free_list(list_ptr);
			list_ptr = prev->next;
		}
		else
		{
			prev = list_ptr;
			list_ptr = list_ptr->next;
		}
	}
}

void	ft_free(t_mem **memory, void *data)
{
	ft_list_remove_if(memory, data);
}
