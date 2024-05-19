
NAME	:= CUB3D
FILE = map.cub
CC := gcc
CFLAGS	:= -Wextra -Wall -Werror -g -fsanitize=address
LIBMLX	:= ../MLX42/build/libmlx42.a
LIBFLAGS := -framework Cocoa -framework OpenGL -framework IOKit
GLFWPATH := /Users/hel-moue/Desktop/old/MLX42/build/libmlx42.a
SRC = *.c
OBJ = ${SRC:%.c=%.o}

$(NAME): $(OBJ)
	$(CC) ${CFLAGS} ${LIBFLAGS} $(LIBMLX) ${GLFWPATH} -o $(NAME)
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



