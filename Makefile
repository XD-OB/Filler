# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 13:15:54 by obelouch          #+#    #+#              #
#    Updated: 2019/05/25 22:54:49 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[1;33m
CYAN = \033[1;36m
RED = \033[1;31m
GREEN = \033[1;32m
EOC = \033[1;0m

NAME = obelouch.filler

FILLER = main tools heatmap token map output

SRC = $(addprefix src/, $(addsuffix .c, $(FILLER)))

OBJ = $(addsuffix .o, $(FILLER))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@make -C ./Displayer
	@make -C ./libft
	@gcc -c $(SRC) $(FLAGS) -I ./
	@gcc -o $(NAME) $(OBJ) -L ./libft -lft
	@echo "\n"
	@echo "$(CYAN)  ███████╗██╗██╗     ██╗     ███████╗██████╗"
	@echo "$(CYAN)  ██╔════╝██║██║     ██║     ██╔════╝██╔══██"
	@echo "$(CYAN)  █████╗  ██║██║     ██║     █████╗  ██████╔"
	@echo "$(CYAN)  ██╔══╝  ██║██║     ██║     ██╔══╝  ██╔══██"
	@echo "$(CYAN)  ██║     ██║███████╗███████╗███████╗██║  ██║"
	@echo "$(CYAN)  ╚═╝     ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝$(EOC)"
	@echo "   Defeat me if you can!    by:$(GREEN) obelouch\n$(EOC)"

visualizer :
	@make -C ./Displayer
	@echo "\n"
	@echo "$(GREEN)      ____  _         _                 "
	@echo "$(GREEN)     |    \|_|___ ___| |___ _ _ ___ ___ "
	@echo "$(GREEN)     |  |  | |_ -| . | | .'| | | -_|  _|"
	@echo "$(GREEN)     |____/|_|___|  _|_|__,|_  |___|_|  "
	@echo "$(GREEN)                 |_|       |___|        $(EOC)"
	@echo "      by:$(GREEN) obelouch\n$(EOC)"

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

.SILENT: all re clean fclean
