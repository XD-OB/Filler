#ifndef	FILLER_H
# define FILLER_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_filler
{
	int		me;
	int		vs;
	int		rows;
	int		cols;
	int		token_y;
	int		token_x;
	int		diff_y;
	int		diff_x;
	char		*token;
	int		**map;
}			t_filler;

#endif
