SRC = ClapTrap.cpp main.cpp 
NAME = ClapTrap
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)
		@echo "If you want to run the program tape x if no tape n"
	@read -p ">> " answer; \
	if [ $$answer = "x" ]; then \
		./$(NAME); \
	else \
		echo "Goodbye"; \
	fi

clean:
	@rm $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all