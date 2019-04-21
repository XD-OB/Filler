#include "filler.h"

void		init_map_size(t_filler *filler, char *line)
{
	int	i;

	i = 8;
	filler->rows = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	filler->cols = ft_atoi(&line[i]);
}

int		*str_int(t_filler *filler)
{
	int	*segm;
	char	*line;
	int	i;
	int	j;

	i = 0;
	get_next_line(0, &line);
	while (line[i] != ' ')
		i++;
	j = 0;
	segm = (int*)malloc(sizeof(int) * filler->cols);
	while (line[++i])
	{
		if (line[i] == '.')
			segm[j] = 0;
		else if (line[i] == 'O' || line[i] == 'o')
			segm[j] = (filler->me == 1) ? -1 : -2;
		else if (line[i] == 'X' || line[i] == 'x')
			segm[j] = (filler->me == 1) ? -2 : -1;
		j++;
	}
	free(line);
	return (segm);
}

void		take_sides(t_filler *filler, char **line)
{
	if (!ft_strncmp(*line, "$$$", 3))
	{
		filler->me = ft_atoi(&(*line)[10]);
		filler->vs = (filler->me == 1) ? 2 : 1;
		//	ft_dprintf(2, "me: %d\tvs: %d\n", filler->me, filler->vs);
		free(*line);
		get_next_line(0, line);
	}
}

int		a_zero(int **tab, int size_y, int size_x)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			if (tab[i][j] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
