NAME = fillit
SRC = fillit.c ft_util.c libft.a 

FLAG = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
