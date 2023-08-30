S_SRC	:=	srcs/server.c
C_SRC	:=	srcs/client.c
U_SRCS	:=	error.c util.c ft_atoi.c outputs.c
UTL		:=	$(addprefix utils/, $(U_SRCS))

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -rfv
US		:=	300
PD		:=	32767

all		:	server client
server	:
	@$(CC) $(CFLAGS) $(S_SRC) $(UTL) -o server
client	:
	@$(CC) $(CFLAGS) $(C_SRC) $(UTL) -o client

clean	:
	@$(RM) server client
fclean	:	clean
re		:	fclean all

rdall	:
	@$(MAKE) rdserver rdclient
rdserver	:
	@$(CC) $(CFLAGS) $(S_SRC) $(UTL) -D SLP_US=$(US) -D PID_MAX=$(PD) -o server
rdclient	:
	@$(CC) $(CFLAGS) $(C_SRC) $(UTL) -D SLP_US=$(US) -D PID_MAX=$(PD) -o client
rdre	:	fclean rdall

files	:
	@mkdir utils srcs
	@touch minitalk.h server.c client.c $(U_SRCS)
	@mv server.c client.c srcs
	@mv $(U_SRCS) utils

commit	:
	git status
	git add $(S_SRC) $(C_SRC) utils $(UTL) Makefile
	git commit -m "commit through Makefile"
	git status
	echo "\n'git push' to complete\n"

.PHONY	=	all server client clean fclean re \
	files commit rdall rdre rdserver rdclient 

#	git add .
#	@touch error.c util.c outputs.c ft_atoi.c 
#	@mkdir utils
#	@mv * utils
#	@touch minitalk.h server.c client.c