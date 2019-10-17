# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celva <celva@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 13:02:08 by dkathlee          #+#    #+#              #
#    Updated: 2019/10/17 17:41:02 by celva            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	fillit.c fillit_matrix.c fillit_matrix_utils.c fillit_square.c fillit_read.c check_figure.c main.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(OBJECTS): %.o:%.c
	@gcc -c -Wall -Wextra -Werror $<

$(NAME): lib $(OBJECTS)
	@gcc -o fillit $(OBJECTS) libft/libft.a

lib:
	@make -C libft

clean:
	@/bin/rm -f $(OBJECTS)
	@make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

re:	fclean all

.PHONY: clean fclean all re
