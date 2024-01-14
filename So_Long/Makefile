# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 19:46:28 by hel-moue          #+#    #+#              #
#    Updated: 2023/05/15 19:55:07 by hel-moue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
FLAGS=-Wall -Werror -Wextra
SRCS= ft_err.c ft_read_map.c key_hook.c so_long.c ft_gv_line.c ft_top_bottom.c ft_check_length_width.c ft_left_right.c ft_valid_maps.c ft_check_player.c ft_player.c path.c
SRCSLIBFT = $(addprefix libft/,ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_strtrim.c ft_striteri.c) 
OBJS=$(SRCS:%.c=%.o)
NAME=so_long
LIBFT=./libft/libft.a

all: $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) -I minilibx libft/libft.a -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)


$(LIBFT): $(SRCSLIBFT)
	make -C ./libft

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all





