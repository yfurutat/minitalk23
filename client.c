#include "minitalk.h"

pid_t	g_pid;

static int	check_args(int argc, char **argv);
static int	send_signal(char msg_chr, size_t bit_n);

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
