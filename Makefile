# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pluu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 16:43:44 by pluu              #+#    #+#              #
#    Updated: 2017/02/08 16:54:02 by pluu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = fillit

C_FILES  = libft_func1.c \
		   libft_func2.c \
		   first_read.c \
		   first_read_helper.c \
		   second_read.c \
		   map_funcs.c \
		   map_helper.c \
		   solve.c \
		   solve_helper.c \
		   fillit.c
 
O_FILES  = $(C_FILES:.c=.o)

CC       = gcc

C_FLAGS  = -Wall -Wextra -Werror

SRCS     = $(addprefix ./, $(C_FILES))
OBJS     = $(addprefix ./, $(O_FILES))

all: $(NAME)

$(NAME):
	$(CC) $(C_FLAGS) -c $(SRCS)
	$(CC) $(C_FLAGS) $(OBJS) -o $(NAME) -I./fillit.h

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
