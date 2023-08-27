#include "../minitalk.h"

//25L
void	handle_error(int err_id)
{
	ssize_t	res;

	res = 0;
	if (err_id == EMPTY_ARGS)
		res = ft_putstr_id("{NOT ENOUGH ARGS}\n \
			Make sure you put the command-line args as follows:\n \
			./client <pid> <your message>\n", err_id);
	else if (err_id == INVALID_ARGV1)
		res = ft_putstr_id("{INVALID ARGV[1]}\n \
			Make sure you put the valid number for the 2nd arg:\n \
			./client <POSITIVE INTEGER> <your message>\n", err_id);
	else if (err_id == INVALID_ARGV2)
		res = ft_putstr_id("{INVALID ARGV[2]}\n \
			Put only printable characters or spaces for the 3rd arg:\n \
			./client <pid> <ONLY PRINTABLE (or spaces)>\n", err_id);
	else if (err_id == INVALID_PID)
		res = ft_putstr_id("{INVALID PID}\n \
			Something seems to be wrong with the pid.\n \
			Please Try again.\n", err_id);
	if (res < 0 || err_id == SYSCALL_ERROR)
		res = ft_putstr_id("{SYSTEM ERROR}\n \
			Plese try again, and if the problem persists,\n \
			please quit the program. Sorry.\n", err_id);
	if (res != 0)
		exit(EXIT_FAILURE);	
}
