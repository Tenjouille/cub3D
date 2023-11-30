/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_machine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleger <rleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:07:02 by rleger            #+#    #+#             */
/*   Updated: 2023/02/28 20:34:5 by rleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_memclear(t_mem **lst, int stop)
{
	t_mem	*curr;
	t_mem	*tmp;

	if (!lst)
		return ;
	curr = *lst;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		if (tmp->data)
			free(tmp->data);
		free(tmp);
	}
	(*lst) = NULL;
	if (stop)
		exit(1);
	return ;
}

void	exit_failure_malloc(void *data)
{
	free(data);
	exit(1);
}

t_mem	*ft_create_elem(void *data)
{
	t_mem	*ptr;

	ptr = malloc(sizeof(*ptr));
	if (!ptr)
		return (0);
	ptr->next = 0;
	ptr->data = data;
	return (ptr);
}

void	ft_list_push_back(t_mem **begin_list, void *data)
{
	t_mem	*ptr;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data);
		if (!(*begin_list))
			exit_failure_malloc(data);
		return ;
	}
	ptr = *begin_list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = ft_create_elem(data);
	if (!ptr->next)
	{
		free(data);
		ft_memclear(begin_list, 1);
	}
}

void	*ft_malloc(size_t size, int clear, int clear_one, void *data)
{
	static t_mem	*memory;
	void			*mem_ptr;

	if (clear)
	{
		ft_memclear(&memory, 0);
		return (NULL);
	}
	if (clear_one)
	{
		ft_free(&memory, data);
		return (NULL);
	}
	mem_ptr = malloc(size);
	if (!mem_ptr)
		ft_memclear(&memory, 1);
	ft_list_push_back(&memory, mem_ptr);
	return (mem_ptr);
}
