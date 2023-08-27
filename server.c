#include "minitalk.h"

static void		handle_signal(int sig_num);
static ssize_t	announce_pid(pid_t n);
static ssize_t	ft_putpid_fd(pid_t n, int fd);

//12L
int	main(void)
{
	int		ret;

	ret = announce_pid(getpid());
	if (ret < 0)
		handle_error(SYSCALL_ERROR);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
	// printf("PID: %d\n", server_pid);
	// printf("SLP: %d\n", SLP_US);

//12L
static ssize_t	announce_pid(pid_t n)
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

//6L
static ssize_t	ft_putpid_fd(pid_t n, int fd)
{
	ssize_t ret;

	if (n > 9)
		ft_putpid_fd(n / 10, fd);
	ret = ft_putchar_fd(n % 10 + '0', fd);
	return (ret);
}

	// static char		chr;
	// static size_t	bit_n;
//17L
static void	handle_signal(int sig_num)
{
	static t_sig	msg;
	ssize_t			ret;

	if (sig_num == SIGUSR1)
		msg.chr |= (0x01 << msg.bit_n);
	msg.bit_n++;
	if (msg.bit_n == 8)
	{
		ret = ft_putchar_fd(msg.chr, STDOUT_FILENO);
		if (ret < 0)
			handle_error(SYSCALL_ERROR);
		msg.bit_n = 0;
		msg.chr = 0;
		return ;
	}
}

// t_sig	g_msg;
	// g_msg.bit_n = 0;
	// g_msg.chr = 0;

//10L
// static void	handle_signal(int sig_num)
// {
// 	if (sig_num == SIGUSR1)
// 		g_msg.chr |= (0x01 << g_msg.bit_n);
// 	g_msg.bit_n++;
// 	if (g_msg.bit_n == 8)
// 	{
// 		write(STDOUT_FILENO, (const char*)&g_msg.chr, 1);
// 		g_msg.bit_n = 0;
// 		g_msg.chr = 0;
// 		return ;
// 	}
// }
