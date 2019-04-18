# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 14:55:40 by obelouch          #+#    #+#              #
#    Updated: 2018/10/10 08:14:23 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_*.c

HEAD = libft.h

OUTO = *.o

OPT = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(HEAD)
	gcc -c $(SRCS) $(OPT)
	ar rc $(NAME) $(OUTO)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OUTO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
