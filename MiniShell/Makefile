GCCFLAG= -Wall -Wextra -Werror
NAME = minishell

OS := $(shell uname)

all: $(NAME)

$(NAME):  src/libft/*.c src/builtins/*.c src/execution/*.c src/ft/*.c src/main/*.c src/parsing/*.c src/redirections/*.c src/utils/*.c
	@echo "\033[1;35m\n\n - STARTING COMPILATION OF MINISHELL -\n\n\033[0m"
	@if [ "$(OS)" = "Linux" ]; then \
		cc -Wall -Wextra -Werror -o minishell src/libft/*.c src/builtins/*.c src/execution/*.c src/ft/*.c src/main/*.c src/parsing/*.c src/redirections/*.c src/utils/*.c -lreadline -lncurses -lhistory; \
	elif [ "$(OS)" = "Darwin" ]; then \
		cc -Wall -Wextra -Werror -o minishell src/libft/*.c src/builtins/*.c src/execution/*.c src/ft/*.c src/main/*.c src/parsing/*.c src/redirections/*.c src/utils/*.c -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include; \
	else \
		echo "Unsupported operating system: $(OS)"; \
		exit 1; \
	fi

sanitize:  src/libft/*.c src/builtins/*.c src/execution/*.c src/ft/*.c src/main/*.c src/parsing/*.c src/redirections/*.c src/utils/*.c
	@echo "\033[1;35m\n\n - STARTING COMPILATION OF MINISHELL  WITH SANITIZE -\n\n\033[0m"
	@if [ "$(OS)" = "Linux" ]; then \
		cc -Wall -Wextra -Werror -g -fsanitize=address -o minishell src/libft/*.c src/builtins/*.c src/execution/*.c src/ft/*.c src/main/*.c src/parsing/*.c src/redirections/*.c src/utils/*.c  -lreadline -lncurses -lhistory; \
	elif [ "$(OS)" = "Darwin" ]; then \
		cc -Wall -Wextra -Werror -g -fsanitize=address -o minishell src/libft/*.c src/builtins/*.c src/execution/*.c src/ft/*.c src/main/*.c src/parsing/*.c src/redirections/*.c src/utils/*.c -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include; \
	else \
		echo "Unsupported operating system: $(OS)"; \
		exit 1; \
	fi

clean:
	rm -f minishell
	rm -rf minishell.dSYM

fclean: clean
	rm -f inc/*.gch

re: fclean all
