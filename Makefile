# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 13:15:54 by obelouch          #+#    #+#              #
#    Updated: 2019/05/09 15:08:15 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[1;33m
CYAN = \033[1;36m
RED = \033[1;31m
GREEN = \033[1;32m
EOC = \033[1;0m

NAME = obelouch.filler

FILLER = filler tools heatmap tokens map

SRC = $(addprefix src/, $(addsuffix .c, $(FILLER)))

OBJ = $(addsuffix .o, $(FILLER))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@make -C ./Displayer re
	@make -C ./libft re
	@gcc -c $(SRC) $(FLAGS) -I ./
	@gcc -o $(NAME) $(OBJ) -L ./libft -lft
	@echo "$(CYAN)obelouch.filler is Ready :)$(EOC)"

clean :
	@make -C ./Displayer clean
	@/bin/rm -f $(OBJ)
	@/bin/rm -f libft/$(OBJ)
	@echo "$(YELLOW)Clean Filler$(EOC)"

fclean : clean
	@make -C ./Displayer fclean
	@/bin/rm -f $(NAME) ./libft/libft.a
	@echo "$(RED)Totaly Cleaned Filler$(EOC)"

re: fclean all
