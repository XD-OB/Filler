NAME = ../ob_displayer

SRC = *.c

OBJ = *.o

all: $(NAME)

$(NAME):
	@make -C ../libft re
	@gcc -c $(SRC) 
	@gcc -o $(NAME) $(OBJ) -L ../libft/ -lft -lSDL -lSDL_image -lSDL_ttf


clean:
	@make -C ../libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C ../libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

.SILENT: all fclean clean
