#include "minitalk.h"

static ssize_t	ft_putpid_fd(pid_t n, int fd);

ssize_t	ft_putchar_fd(char c, int fd)
{
	int	res;

	res = write(fd, &c, 1);
	return (res);
}

ssize_t	announce_pid(pid_t n)
{
	ssize_t	ret;

	if (n < 0 || n > PID_MAX || kill(n, 0) != 0)
		return (INVALID_PID);
	ret = ft_putstr_id("PID: ", OK);
	if (ret < 0)
		return (SYSCALL_ERROR);
	ret = ft_putpid_fd(n, STDOUT_FILENO);
	if (ret < 0)
		return (SYSCALL_ERROR);
	ret = ft_putchar_fd('\n', STDOUT_FILENO);
	return (ret);
}

static ssize_t	ft_putpid_fd(pid_t n, int fd)
{
	ssize_t ret;

	if (n > 9)
		ft_putpid_fd(n / 10, fd);
	ret = ft_putchar_fd(n % 10 + '0', fd);
	return (ret);
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

// static void	ft_putpid_fd(pid_t n, int fd);

// static void	ft_putui_fd(pid_t n, int fd)
// {
// 	if (n > 9)
// 		ft_putui_fd(n / 10, fd);
// 	ft_putchar_fd(n % 10 + '0', fd);
// }

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

	// if (n == INT_MIN)
	// 	ft_putstr_fd("-2147483648", fd);
	// else if (n < 0)
	// {
	// 	ft_putchar_fd('-', fd);
	// 	ft_putnbr_fd(-n, fd);
	// }
	// else
	// {
	// }
	// ft_putui_fd(n, STDOUT_FILENO);

// int	main(void)
// {
// 	int	res;
// 	pid_t	pid = getpid();

// 	res = announce_pid(pid);
// 	if (res < 0)
// 		handle_error(SYSCALL_ERROR);
// 	if (res > 0)
// 		res = 0;
// 	return res;
// }
