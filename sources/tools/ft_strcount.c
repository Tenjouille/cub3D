#include "../../includes/cub.h"

int	ft_strcount(char *str, char *to_count)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_count[j])
			if (to_count[j++] == str[i])
				count++;
		i++;
	}
	return (count);
}
