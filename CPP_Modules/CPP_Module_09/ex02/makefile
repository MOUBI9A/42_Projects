CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp PmergeMe.cpp
NAME = PmergeMe
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[1;32mIf you want to run the program type x if no type n\033[1;32m"
	@read -p ">> " answer; \
	if [ "$$answer" = "x" ]; then \
		echo "\033[1;32mHow many random numbers do you want to generate?\033[0m"; \
		read -p ">> " ARG1; \
		echo "\033[1;32mWhat is the minimum value of the random numbers?\033[0m"; \
		read -p ">> " ARG2; \
		echo "\033[1;32mWhat is the maximum value of the random numbers?\033[0m"; \
		read -p ">> " ARG3; \
		./$(NAME) `jot -r "$$ARG1" "$$ARG2" "$$ARG3" | tr '\n' ' '` && echo "\033[1;32mThank you\033[0m"; \
	else \
		echo -e "\033[1;31mGoodbye\033[0m"; \
	fi

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all