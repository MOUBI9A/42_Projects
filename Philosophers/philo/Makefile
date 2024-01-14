# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:45:11 by hel-moue          #+#    #+#              #
#    Updated: 2023/11/07 21:37:11 by hel-moue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror
CFLAGSADD = -Wall -Wextra -Werror -fsanitize=address
CFLAGSTHREAD = -Wall -Wextra -Werror -fsanitize=thread
 
RM = rm -rf

SRCS = 	init.c act.c philo.c utils.c set.c get.c 
			

$(NAME) :
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

norm :
	norminette $(SRCS)

add : fclean
	gcc $(CFLAGSADD) $(SRCS) -o $(NAME)

thread : fclean
	gcc $(CFLAGSTHREAD) $(SRCS) -o $(NAME)

run : re
	@./philo $$VAR
eat : re
	@./philo $$VAR | grep "$$PHILO is eating"
	@echo "----philo $$PHILO is eating-----"
	@./philo $$VAR | grep "$$PHILO is eating" | wc -l
	
	
re : fclean all