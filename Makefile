# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 13:02:08 by dkathlee          #+#    #+#              #
#    Updated: 2019/10/17 13:38:41 by dkathlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

SRCS =	fillit.c fillit_matrix.c fillit_matrix_utils.c fillit_square.c fillit_read.c check_figure.c main.c

OBJECTS = fillit.o fillit_matrix.o fillit_matrix_utils.o fillit_square.o fillit_read.o check_figure.o main.o

all: $(NAME)

$(OBJECTS): %.o:%.c
	gcc -c $<

$(NAME): $(OBJECTS)
	gcc -o fillit $(OBJECTS) libft/libft.a

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
