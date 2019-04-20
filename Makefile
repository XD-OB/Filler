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

NAME = obelouch.filler

FILLER = main

OBJ = *.o

HEADER = filler.h

FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix src/, $(addsuffix .c, $(FILLER)))

all : $(NAME)

$(NAME) :
	@make -C ./libft re
	@gcc -c $(SRC) $(FLAGS) -I ./$(HEADER)
	@gcc -o $(NAME) $(OBJ) -L ./libft -lft
	@mv $(OBJ) src/.

clean :
	@/bin/rm -f src/$(OBJ)
	@/bin/rm -f libft/$(OBJ)

fclean : clean
	@/bin/rm -f $(NAME) ./libft/libft.a

re: fclean all

.SILENT : all clean fclean re
