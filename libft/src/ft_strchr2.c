#include "libft.h"

int	corewar_strchr(const char *s, int c)
{
	int		i;
	int		is_quote;

	i = 0;
	is_quote = 0;
	while (s[i])
	{
		if (s[i] == '"')
			is_quote = !is_quote;
		if (s[i] == c && !is_quote)
			return (i);
		i++;
	}
	return (-1);
}
