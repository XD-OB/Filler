# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 13:15:54 by obelouch          #+#    #+#              #
#    Updated: 2019/04/20 14:30:27 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[1;31m
GREEN = \033[1;32m
EOC = \033[1;0m

NAME = obelouch.filler

FILLER = filler tools heatmap tokens map

OBJ = *.o

FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix src/, $(addsuffix .c, $(FILLER)))

all : $(NAME)

$(NAME) :
	@make -C ./libft re
	@gcc -c $(SRC) $(FLAGS) -I ./
	@gcc -o $(NAME) $(OBJ) -L ./libft -lft
	@mv $(OBJ) src/.
	@echo "$(GREEN)obelouch.filler is Ready :)$(EOC)"

clean :
	@/bin/rm -f src/$(OBJ)
	@/bin/rm -f libft/$(OBJ)
	@echo "$(GREEN)Cleaned Successfuly Filler$(EOC)"

fclean : clean
	@/bin/rm -f $(NAME) ./libft/libft.a
	@echo "$(RED)Totaly Cleaned Filler$(EOC)"

re: fclean all
