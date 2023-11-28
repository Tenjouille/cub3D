#include "../../includes/cub.h"

int	ft_is_char(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (charset[i++] == c)
			return (1);
	return (0);
}
