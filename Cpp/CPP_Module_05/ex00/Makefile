SRC = main.cpp Bureaucrat.cpp 
NAME = Bureaucrat
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "If you want to run the program tape x if no tape n"
	@read -p ">> " answer; \
	if [ $$answer = "x" ]; then \
		./$(NAME); \
	else \
		echo "Goodbye"; \
	fi


clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all