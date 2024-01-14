NAME = libftprintf.a
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c ft_putnbr_base_m.c
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
CC = gcc

${NAME}: 
	@${CC} ${FLAGS} -c ${SRC}
	@ar rc ${NAME} $(OBJS)

all: ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all