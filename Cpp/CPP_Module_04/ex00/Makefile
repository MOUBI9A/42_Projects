SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp WrongDog.cpp
NAME = l7ayawnat
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

############# Color ##############
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
##################################

all: $(NAME)

print_message:
	@clear
	@echo "$(MAGENTA)    CCCCCC   $(MAGENTA)PPPPPPP   PPPPPPP$(RESET)		       4	"
	@echo "$(MAGENTA)   C         $(MAGENTA)P      P  P      P$(RESET)    000       4 4	"
	@echo "$(MAGENTA)  C          $(MAGENTA)PPPPPPP   PPPPPPP$(RESET)   00   0     4  4	"
	@echo "$(MAGENTA)  C          $(MAGENTA)P         P       $(RESET) 00     00  4   4	"
	@echo "$(MAGENTA)   C         $(MAGENTA)P         P       $(RESET) 00   00   44444444	"
	@echo "$(MAGENTA)    CCCCCC   $(MAGENTA)P         P       $(RESET)   000          4	"
	@echo "                                   $(YELLOW)eeeee   x   x$(RESET)                 "
	@echo "                                  $(YELLOW)ee   ee   x x$(RESET)                 "
	@echo "                                 $(YELLOW)eeeeeeee    x$(RESET)      000   000   "
	@echo "                                 $(YELLOW)e          x x$(RESET)    00 00 00 00  "
	@echo "                                  $(YELLOW)eeeee    x   x$(RESET)    000   000	 "


clear:
	@clear

$(NAME): $(OBJ) print_message
	@$(CC) $(FLAG) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully$(RESET)"
		@echo "$(BLUE)tape ENTER to run the program OR ESC to exit$(RESET)"
	@read -s -n 1 -p ">> " answer; \
	if [ "$$answer" = "" ]; then \
		echo "\n"; ./$(NAME); \
	else \
		echo "$(RED)Goodbye$(RESET)"; \
	fi


%.o: %.cpp
	@$(CC) $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)$(NAME) objects removed successfully$(RESET)"

fclean: clean	
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) executable removed successfully$(RESET)"
	
re: fclean all
	