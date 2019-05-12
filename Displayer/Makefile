# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/08 23:44:20 by obelouch          #+#    #+#              #
#    Updated: 2019/05/11 21:10:27 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[1;32m
RED = \033[1;31m
EOC = \033[1;0m

LIB_SDL = -L./SDL/ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

NAME = ../ob_displayer

DISPLAYER_SRC = event main pause score surface displayer tools

SRC = $(addprefix src/, $(addsuffix .c, $(DISPLAYER_SRC)))

OBJ = $(addsuffix .o, $(DISPLAYER_SRC))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C ../libft re
	@gcc -c -I ./ $(SRC) $(FLAGS)
	@gcc -o $(NAME) $(OBJ) -L ../libft/ -lft $(LIB_SDL) 
	@echo "$(GREEN)Displayer is made in the Root Directory!$(EOC)"
	@cp vm_exec ../vm_exec

clean:
	@make -C ../libft clean
	@/bin/rm -f $(OBJ)
	@echo "$(GREEN)Cleaned Displayer$(EOC)"

fclean: clean
	@make -C ../libft fclean
	@/bin/rm -f $(NAME)
	@echo "$(RED)Remove Displayer :/$(EOC)"
	@rm -f ../vm_exec

re: fclean all
