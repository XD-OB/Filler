NAME = battle_begin

SRC = *.c

OBJ = *.o

all: $(NAME)

$(NAME):
	@make -C ../../libft re
	@gcc -c $(SRC) 
	@gcc -o $(NAME) $(OBJ) -L ../../libft/ -lft -lSDL -lSDL_image


clean:
	@make -C ../../libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C ../../libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

.SILENT: all fclean clean
