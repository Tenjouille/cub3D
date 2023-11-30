#include "../../includes/cub.h"

void	free_list(t_mem *list_ptr)
{
	free(list_ptr->data);
	free(list_ptr);
	return ;
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
