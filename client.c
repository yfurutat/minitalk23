#include "minitalk.h"

pid_t	g_pid;

static int	check_args(int argc, char **argv);
static int	send_signal(char msg_chr, size_t bit_n);
// static void	send_signal(pid_t pid, char msg_chr);
// static int	send_signal(pid_t pid, char msg_chr, size_t bit_n);
	// pid_t	pid;
	// pid = atoi(argv[1]);
	// if (pid < 0 || pid > PID_MAX || kill(pid, 0) != 0)

//18L
int	main(int argc, char **argv)
{
	size_t	i;
	int		res;

	res = check_args(argc, argv);
	if (res != OK)
		handle_error(res);
	g_pid = ft_atoi(argv[1]);
	if (g_pid < 0 || g_pid > PID_MAX || kill(g_pid, 0) != 0)
		handle_error(INVALID_PID);
	i = 0;
	while (argv[2][i] != '\0')
	{
		res = send_signal(argv[2][i], 1);
		if (res != OK)
			handle_error(SYSCALL_ERROR);
		i++;
	}
	return (res);
}
		// res = send_signal(pid, argv[2][i], 0);
		// send_signal(pid, argv[2][i]);

	// int		mask;

	// bit_n = 0;
	// res = 0;
//11L
static int	send_signal(char msg_chr, size_t bit_n)
{
	int		res;

	if (msg_chr & 1)
		res = kill(g_pid, SIGUSR1);
	else
		res = kill(g_pid, SIGUSR2);
	usleep(SLP_US);
	if (res != OK || bit_n == 8)
		return (res);
	else
		return (send_signal(msg_chr >> 1, bit_n + 1));
}
	// bit_n++;

// static int	send_signal(pid_t pid, char msg_chr, size_t bit_n)
// {
// 	int		res;

// 	if (msg_chr & 1)
// 		res = kill(pid, SIGUSR1);
// 	else
// 		res = kill(pid, SIGUSR2);
// 	if (res != OK)
// 		return (SYSCALL_ERROR);
// 	usleep(300);
// 	bit_n++;
// 	if (bit_n == 8)
// 		return (res);
// 	else
// 		return (send_signal(pid, msg_chr >> 1, bit_n));
// }

// static void	send_signal(pid_t pid, char msg_chr)
// {
// 	int		res;
// 	size_t	bit_n;
// 	// int		mask;

// 	bit_n = 0;
// 	res = 0;
// 	while (bit_n < 8)
// 	{
// 		if (msg_chr & 1)
// 			res = kill(pid, SIGUSR1);
// 		else
// 			res = kill(pid, SIGUSR2);
// 		if (res != OK)
// 			exit(SYSCALL_ERROR);
// 		msg_chr >>= 1;
// 		bit_n++;
// 		usleep(300);
// 	}
// }

// static void	send_signal(pid_t pid, char msg_chr)
// {
// 	int		res;
// 	size_t	bit_n;
// 	int		mask;

// 	bit_n = 0;
// 	res = 0;
// 	while (bit_n < 8)
// 	{
// 		mask = 0x01 << bit_n;
// 		if (msg_chr & mask)
// 			res = kill(pid, SIGUSR1);
// 		else
// 			res = kill(pid, SIGUSR2);
// 		if (res != OK)
// 			exit(SYSCALL_ERROR);
// 		bit_n++;
// 		usleep(300);
// 	}
// }
	// mask = 0x01;
		// msg_chr >>= 1;
		// if (msg_chr & 0x01)
			// return (SYSCALL_ERROR);
// 	// return (res);

		// if (((msg_chr >> (7 - bit_n)) & 1) != 0)
		// else if (((msg_chr >> (7 - bit_n)) & 1) == 0)
// static void send_signal(pid_t pid, char msg_chr)
// {
// 	int		res;
// 	size_t	bit_n;

// 	bit_n = 0;
// 	res = 0;
// 	while (bit_n < 8)
// 	{
// 		if ((msg_chr & (0x01 << bit_n)) != 0)
// 			res = kill(pid, SIGUSR1);
// 		else if ((msg_chr & (0x01 << bit_n)) == 0)
// 			res = kill(pid, SIGUSR2);
// 		if (res == -1)
// 			exit(SYSCALL_ERROR);
// 		bit_n++;
// 		usleep(300);
// 	}
// }

//21L
static int	check_args(int argc, char **argv)
{
	size_t	i;

	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
		return (EMPTY_ARGS);
	if (argv[1][0] == '\0' || argv[2][0] == '\0')
		return (EMPTY_ARGS);
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i]) == NO)
			return (INVALID_ARGV1);
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (ft_isprint(argv[2][i]) == NO && ft_isspace(argv[2][i]) == NO)
			return (INVALID_ARGV2);
		i++;
	}
	return (OK);
}
