NAME = fillit
SRC = fillit.c util1.c util2.c output.c solver.c read.c
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	$(MAKE) -C libft 
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
