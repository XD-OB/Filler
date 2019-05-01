GREEN = \033[1;32m
RED = \033[1;31m
EOC = \033[1;0m

NAME = ../ob_displayer

SRC = *.c

OBJ = *.o

all: $(NAME)

$(NAME):
	@make -C ../libft re
	@gcc -c $(SRC) 
	@gcc -o $(NAME) $(OBJ) -L ../libft/ -lft -lSDL -lSDL_image -lSDL_ttf
	@echo "$(GREEN)Displayer is made in the Root Directory!$(EOC)"

clean:
	@make -C ../libft clean
	@/bin/rm -f $(OBJ)
	@echo "$(GREEN)Cleaned Displayer$(EOC)"

fclean: clean
	@make -C ../libft fclean
	@/bin/rm -f $(NAME)
	@echo "$(RED)Remove Displayer :/$(EOC)"

re: fclean all
