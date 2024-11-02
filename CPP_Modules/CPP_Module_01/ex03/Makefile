CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = l7arb
SRC = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "If you want to test the program, type ./l7arb or Y if not type N"
	@read line; if [ $$line = "Y" ] || [ $$line = "y" ]; then ./l7arb; fi
	@echo "Thank you for testing the program"


clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all