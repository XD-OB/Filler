NAME = battle_begin

SRC = *.c

OBJ = *.o

all: $(NAME)

$(NAME):
	gcc -c $(SRC) -Wall -Wextra -Werror
	gcc -o $(NAME) $(OBJ) -L ../../libft -lft -lSDL -lSDL_image


clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
