#ifndef	FILLER_H
# define FILLER_H

# include "./libft/ft_printf.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct		s_filler
{
	int		me;
	int		vs;
	int		rows;
	int		cols;
	int		begin_y;
	int		begin_x;
	int		token_y;
	int		token_x;
	char		**token;
	int		**map;
	int		x;
	int		y;
}			t_filler;

void			take_sides(t_filler *filler, char **line);
void			xy_coord(t_filler **filler);
void			heat_map(t_filler **filler);
int			is_allpoint(char *str);
int			*str_int(t_filler *filler);
void			ultime_free_filler(t_filler **filler);
void			free_filler(t_filler *filler);
void			free_tab(char ***tab, int size_y);
char			**get_token(t_filler *filler);
void			init_map_size(t_filler *filler, char *line);

#endif
