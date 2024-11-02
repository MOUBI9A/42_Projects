SRC = Harl.cpp main.cpp
NAME = harl_2_0
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32mHarl 2.0 is ready to use! type 1 to test \033[31mDEBUG\033[0m \033[32mor 2 to test \033[31mINFO\033[0m \033[32mor 3 to test \033[31mWARNING\033[0m \033[32mor 4 to test \033[31mERROR\033[0m\033[0m"
	@read line; if [ $$line = "1" ]; then ./harl_2_0 DEBUG; elif [ $$line = "2" ]; then ./harl_2_0 INFO; elif [ $$line = "3" ]; then ./harl_2_0 WARNING; elif [ $$line = "4" ]; then ./harl_2_0 ERROR; fi


clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all