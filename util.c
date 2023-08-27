#include "minitalk.h"

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

//3
// static void	check_args(int argc, char **argv)
// {
// 	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
// 		exit(1);
// 	if (*argv[1] == '\0' || *argv[2] == '\0')
// 		exit(1);
// 	while (*argv[1] != '\0')
// 	{
// 		if (!ft_isdigit(*argv[1]))
// 			exit(1);
// 		argv[1]++;
// 	}
// 	while (*argv[2] != '\0')
// 	{
// 		if (!ft_isspace(*argv[2]) && !ft_isprint(*argv[2]))
// 			exit(1);
// 		argv[2]++;
// 	}
// }

//2
// static int	check_args(int argc, char **argv)
// {
// 	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
// 		return (1);
// 	if (*argv[1] == '\0' || *argv[2] == '\0')
// 		return (1);
// 	while (*argv[1] != '\0')
// 	{
// 		if (!ft_isdigit(*argv[1]))
// 			return (1);
// 		argv[1]++;
// 	}
// 	while (*argv[2] != '\0')
// 	{
// 		if (!ft_isprint(*argv[2]) && !ft_isspace(*argv[2]))
// 			return (1);
// 		argv[2]++;
// 	}
// 	return (0);
// }
