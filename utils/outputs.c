#include "../minitalk.h"

ssize_t	ft_putchar_fd(char c, int fd)
{
	int	res;

	res = write(fd, &c, 1);
	return (res);
}

ssize_t	ft_putstr_id(char *str, int id)
{
	ssize_t	ret;

	ret = 0;
	if (id == OK)
		ret = write(STDOUT_FILENO, str, ft_strlen(str));
	else
		ret = write(STDERR_FILENO, str, ft_strlen(str));
	return (ret);
}
