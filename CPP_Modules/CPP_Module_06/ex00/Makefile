SRC = main.cpp ScalarConverte.cpp
NAME = SclarConverte
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "Enter a value to convert"
	@read -p ">> " answer; \
	if [ -n "$$answer" ]; then \
		./$(NAME) $$answer; \
	else \
		echo "Goodbye"; \
	fi	
	


clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) *_shrubbery

re: fclean all
