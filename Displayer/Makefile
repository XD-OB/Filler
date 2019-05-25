# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/08 23:44:20 by obelouch          #+#    #+#              #
#    Updated: 2019/05/25 10:24:39 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[1;32m
RED = \033[1;31m
EOC = \033[1;0m

LIB_SDL = -L /Users/obelouch/.brew/lib/ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer\

NAME = ob_displayer

DISPLAYER_SRC = main bonus draw draw_rect draw_result event\
				infos_game movie_tools put_pieces put_scene\
				record_game sdl_general tools\

SRC = $(addprefix src/, $(addsuffix .c, $(DISPLAYER_SRC)))

OBJ = $(addsuffix .o, $(DISPLAYER_SRC))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C ../libft re
	@gcc -c -I ./ $(SRC) $(FLAGS)
	@gcc -o $(NAME) $(OBJ) -L ../libft/ -lft $(LIB_SDL) 
	@echo "$(GREEN) Displayer is Created Enjoy :-)$(EOC)"
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
