#include "../minitalk.h"

int	ft_isdigit(int chr)
{
	return (chr >= '0' && chr <= '9');
}

int	ft_isprint(int chr)
{
	return (chr >= ' ' && chr <= '~');
}

int	ft_isspace(int chr)
{
	return ((chr >= '\t' && chr <= '\r') || chr == ' ');
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
	{
		if (len == SIZE_MAX)
			return (0);
		len += 1;
	}
	return (len);
}
