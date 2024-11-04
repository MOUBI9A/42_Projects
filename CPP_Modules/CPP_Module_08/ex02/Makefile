SRC = main.cpp 
NAME = MutantStack
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
		@echo "\033[1;32mIf you want to run the program tape x if no tape n\033[1;32m"
	@read -p ">> " answer; \
	if [ $$answer = "x" ]; then \
		echo "\033[1;32mRunning the program...\033[0m"; \
		./$(NAME) && echo "\033[1;32mThank you\033[0m"; \
	else \
		echo -e "\033[1;31mGoodbye\033[0m"; \
	fi

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
