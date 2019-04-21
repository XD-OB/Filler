#include "../filler.h"

void		init_map_size(t_filler *filler, char *line)
{
	int	i;

	i = 8;
	filler->rows = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	filler->cols = ft_atoi(&line[i]);
}

int		*str_int(t_filler *filler, char *line)
{
	int	*segm;
	int	i;
	int	j;

	segm = (int*)malloc(sizeof(int) * filler->cols);
	i = 0;
	while (line[i] != ' ')
		i++;
	j = 0;
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
	return (segm);
}

static void	take_sides(t_filler *filler, char **line)
{
	if (!ft_strncmp(*line, "$$$", 3))
	{
		filler->me = ft_atoi(&(*line)[10]);
		filler->vs = (filler->me == 1) ? 2 : 1;
			ft_dprintf(2, "me: %d\tvs: %d\n", filler->me, filler->vs);
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

void		output(t_filler *filler)
{
	int		y;
	int		x;

	xy_coord(&filler);
	y = filler->y - filler->begin_y;
	x = filler->x - filler->begin_x;
	ft_dprintf(1, "%d %d\n", y, x);
	ft_dprintf(2, "X: %d\tY: %d\n", x, y);
}

int		main(void)
{
	t_filler	*filler;
	char		*line;
	int		i;
		int		k;

	filler = (t_filler*)malloc(sizeof(t_filler));
	while (get_next_line(0, &line) > -1)
	{
		take_sides(filler, &line);
		init_map_size(filler, line);
			ft_dprintf(2, "rows: %d\ncols: %d\n", filler->rows, filler->cols);
		free(line);
		get_next_line(0, &line);
		free(line);
		i = -1;
		filler->map = (int**)malloc(sizeof(int*) * filler->rows);
		while (++i < filler->rows)
		{
			get_next_line(0, &line);
			filler->map[i] = str_int(filler, line);
				k = -1;
				while (++k < filler->cols)
					ft_dprintf(2, "%d", filler->map[i][k]);
				ft_dprintf(2, "\n%s\n", &line[4]);
			free(line);
		}
		heat_map(&filler);
		init_token_size(filler);
		filler->token = get_token(filler);
			ft_putchar_fd('\n', 2);
			k = -1;
			while (++k < filler->rows)
			{
				i = -1;
				while (++i < filler->cols)
				{
					if (filler->map[k][i] >= 0 && filler->map[k][i] <= 9)
						ft_dprintf(2, " %d", filler->map[k][i]);
					else
						ft_dprintf(2, "%d", filler->map[k][i]);
				}
				ft_putchar_fd('\n', 2);
			}
		output(filler);
		free_filler(filler);
	}
	ultime_free_filler(&filler);
	return (0);
}
