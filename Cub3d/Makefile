
NAME := CUB3D
CC := gcc
CFLAGS := -Wextra -Wall -Werror -g -fsanitize=address
LIBMLX := ~/Desktop/tst/MLX42/build/libmlx42.a
LIBFLAGS := -framework Cocoa -framework OpenGL -framework IOKit
GLFWPATH := ~/.brew/Cellar/glfw/3.4/lib/libglfw3.a
SRC := check_n_w_e_s.c get_next_line.c libft.c norm.c file_to_data.c get_next_line_utils.c main.c ft_split.c init_data.c map_checks.c 
OBJ = ${SRC:%.c=%.o}

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFLAGS) $(LIBMLX) $(GLFWPATH) $(OBJ) -o $(NAME)
	@echo "If you want to run the program tape x if no tape n"
	@read -p ">> " answer; \
	if [ $$answer = "x" ]; then \
		./$(TARGET) $(FILE); \
	else \
		echo "Goodbye"; \
	fi

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re



