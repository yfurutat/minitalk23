#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <string.h>

//DELETE before committing
# include <stdio.h>

// #  define PID_MAX (32767)
# ifndef PID_MAX
#  define PID_MAX (99999)
# endif
# ifndef SLP_US
#  define SLP_US (300)
# endif
# define NO (0)
# define EMPTY (0)

typedef struct s_signal {
	char	chr;
	size_t	bit_n;
}	t_sig;

typedef enum e_result {
	OK = 0,
	SYSCALL_ERROR = -1,
	EMPTY_ARGS = -2,
	INVALID_ARGV1 = 1,
	INVALID_ARGV2 = 2,
	INVALID_PID = 3
}	t_res;

void	handle_error(int err_id);
int		ft_atoi(const char *from_ascii);
// void	ft_putchar_fd(char c, int fd);
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	announce_pid(pid_t pid);
// void	ft_putpid(pid_t n, int fd);
ssize_t	ft_putstr_id(char *str, int id);
size_t	ft_strlen(char *str);
int		ft_isspace(int chr);
int		ft_isprint(int chr);
int		ft_isdigit(int chr);

#endif