NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c stack.c sorter.c utils.c utils_2.c instructions_a.c instructions_b.c sorter_small.c norm.c
OBJS=$(SRCS:%.c=%.o)
LIBFT=./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT)

%.o: %.c 
	@$(CC) $(FLAGS) $(SRCS) -c $^

$(LIBFT): $(SRCSLIBFT)
	@make -C ./libft

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
