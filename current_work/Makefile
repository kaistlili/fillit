NAME = fillit
SRC = fillit.c ft_util.c ft_solver.c
LIB = ./libft/libft.a
FLAG = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	$(MAKE) -C libft 
	gcc -o $(NAME) $(SRC) $(LIB)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
