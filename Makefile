S_SRC	:=	server.c
C_SRC	:=	client.c
U_SRCS	:=	error.c util.c ft_atoi.c outputs.c

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -vrf
US		:=	100
PD		:=	32767

all		:	server client
server	:
	@$(CC) $(CFLAGS) $(S_SRC) $(U_SRCS) -o server
client	:
	@$(CC) $(CFLAGS) $(C_SRC) $(U_SRCS) -o client

rdall	:
	@$(MAKE) rdserver rdclient
rdserver	:
	@$(CC) $(CFLAGS) $(S_SRC) $(U_SRCS) -D SLP_US=$(US) -D PID_MAX=$(PD) -o server
rdclient	:
	@$(CC) $(CFLAGS) $(C_SRC) $(U_SRCS) -D SLP_US=$(US) -D PID_MAX=$(PD) -o client

file	:
	@touch minitalk.h server.c client.c
	@touch 1.txt 2.txt
clean	:
	@$(RM) server client
#	$(RM) *.txt
#	@$(RM) *.txt
fclean	:	clean
re		:	fclean all
rdre	:	fclean rdall

.PHONY	=	all server client file clean fclean re rdall rdre