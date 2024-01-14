NAME		= server
NAMI		= client

SRVB		= server_bonus
CLTB		= client_bonus

FLAGS	= -Wall -Wextra -Werror

all: ${NAME} ${NAMI}

bonus: ${SRVB} ${CLTB}

${SRVB}: server_bonus.c
	@cc ${FLAGS} server_bonus.c -o server_bonus

${CLTB}: client_bonus.c
	@cc ${FLAGS} client_bonus.c -o client_bonus

${NAME}: server.c
	@cc ${FLAGS} server.c -o server

${NAMI}: client.c
	@cc ${FLAGS} client.c -o client


clean:
	@rm -f server 
	@rm -f client
	@rm -f server_bonus
	@rm -f client_bonus
fclean: clean

re: fclean all
