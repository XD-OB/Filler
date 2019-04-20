#ifndef	FILLER_H
# define FILLER_H

# include "./libft/ft_printf.h"
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_filler
{
	int		me;
	int		vs;
	int		rows;
	int		cols;
	int		piece_y;
	int		piece_x;
	int		token_y;
	int		token_x;
	char		**token;
	int		**map;
	int		x;
	int		y;
}			t_filler;

#endif
