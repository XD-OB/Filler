GREEN = \033[1;32m
RED = \033[1;31m
EOC = \033[1;0m

NAME = ../ob_displayer

DISPLAYER_SRC = event main pause score surface displayer tools

SRC = $(addprefix srcs/, $(addsuffix .c, $(DISPLAYER_SRC)))

OBJ = *.o

all: $(NAME)

$(NAME):
	@make -C ../libft re
	@gcc -c -I ./ $(SRC)
	@gcc -o $(NAME) $(OBJ) -L ../libft/ -lft -L./SDL/ -lSDL2 -lSDL2_image -lSDL2_ttf
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
