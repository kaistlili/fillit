#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eneto <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 19:05:57 by eneto             #+#    #+#              #
#    Updated: 2018/04/20 19:20:41 by ktlili           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

LIB = ./libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror 

SRCS = 	fillit.c		\
		util1.c 		\
		util2.c 		\
		output.c 		\
		solver.c 		\
		read.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

clean:
	@/bin/rm -f $(OBJ)
	$(MAKE) -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME) $(LIB)
	$(MAKE) -C ./libft clean

re: fclean all
