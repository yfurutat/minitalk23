#include "minitalk.h"

// t_sig	g_msg;
	// g_msg.bit_n = 0;
	// g_msg.chr = 0;

//11L
static void	handle_signal(int sig_num);

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

static void	handle_signal(int sig_num)
{
	static t_sig	msg;
	ssize_t			ret;
	// static char		chr;
	// static size_t	bit_n;

	if (sig_num == SIGUSR1)
		msg.chr |= (0x01 << msg.bit_n);
	msg.bit_n++;
	if (msg.bit_n == 8)
	{
		// ret = write(STDOUT_FILENO, &msg.chr, 1);
		ret = ft_putchar_fd(msg.chr, STDOUT_FILENO);
		if (ret < 0)
			handle_error(SYSCALL_ERROR);
		msg.bit_n = 0;
		msg.chr = 0;
		return ;
	}
}

	// ssize_t	res;
		// res = 0;

	// g_msg.chr <<= 1;
	// g_msg.bit_n++;
	// chr <<= 1;
		// chr += 0x01;
		// chr = (chr << 1) + 0x01;
		// g_msg.chr = (g_msg.chr << 0x01) + 0x01;
		// g_msg.chr += (0x01 << g_msg.bit_n);
	// else if (sig_num == SIGUSR2)
		// chr += 0x00;
	// else
	// 	chr = (chr << 1) + 0x00;
	// 	g_msg.chr = (g_msg.chr << 0x01) + 0x00;
	// else if (sig_num == SIGUSR2)
	// 	g_msg.chr += 0x00;
	// if (g_msg.bit_n == 8)
		// write(STDOUT_FILENO, &g_msg.chr, 1);
		// res = write(STDOUT_FILENO, &g_msg.chr, 1);
		// if (res < 0)
		// 	handle_error(SYSCALL_ERROR);
		// g_msg.bit_n = 0;
		// g_msg.chr = 0;