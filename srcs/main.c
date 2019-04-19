#include "../filler.h"

void	init_map_size(t_filler *filler, char *line)
{
	int	i;

	i = 8;
	filler->rows = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	filler->cols = ft_atoi(&line[i]);
}

void	init_token_size(t_filler *filler)
{
	int	i;
	char	*line;

	i = 6;
	get_next_line(0, &line);
	filler->token_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	filler->token_x = ft_atoi(&line[i]);
		ft_dprintf(2, "Token_Y: %d\tToken_X: %d\n", filler->token_y, filler->token_x);
	free(line);
}

static void	fill_segment(int *segm, char *line, int me)
{
	if (me == 1)
	{
		if (*line == '.')
			*segm = 0;
		else if (*line == 'O' || *line == 'o')
			*segm = -1;
		else if (*line == 'X')
			*segm = -2;
		else
			*segm = -3;
	}
	else
	{
		if (*line == '.')
			*segm = 0;
		else if (*line == 'X' || *line == 'x')
			*segm = -1;
		else if (*line == 'O')
			*segm = -2;
		else
			*segm = -3;
	}
}

int	*str_int(t_filler *filler, char *line)
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
		fill_segment(&segm[j], &line[i], filler->me);
		j++;
	}
	return (segm);
}

void	take_sides(t_filler *filler, char **line)
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

int	is_allpoint(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	real_token(char ***token, t_filler *filler)
{
	int	i;
	int	j;

	i = filler->token_y;
	while (--i >= 0)
	{
		if (is_allpoint((*token)[i]))
		{
			(filler->token_y)--;
			free((*token)[i]);
		}
	}
	j = filler->token_x;
	while (--j >= 0)
	{
		i = filler->token_y - 1;
		while (i >= 0 && (*token)[i][j] == '.')
			i--;
		if (i == -1)
		{
			i = filler->token_y;
			while (--i >= 0)
				(*token)[i][j] = '\0';
			(filler->token_x)--;
		}
		else
			break ;
	}
}

char	**get_token(t_filler *filler)
{
	char	**token;
	int	i;

	i = -1;
	token = (char**)malloc(sizeof(char*) * filler->token_y);
	while (++i < filler->token_y)
		get_next_line(0, &token[i]);
	real_token(&token, filler);
	ft_dprintf(2, "*token_Y: %d\t*token_X: %d\n", filler->token_y, filler->token_x);
		i = -1;	
		while (++i < filler->token_y)
			ft_dprintf(2, "%s\n", token[i]);
	return (token);
}

void	free_filler(t_filler **filler)
{
	int	i;

	i = 0;
	while (i < (*filler)->rows)
	{
		free((*filler)->map[i]);
		i++;
	}
	i = 0;
	free((*filler)->map);
	while (i < (*filler)->token_y)
	{
		free((*filler)->token[i]);
		i++;
	}
	free((*filler)->token);
	free(*filler);
	filler = NULL;
}

int	a_zero(int **tab, int size_y, int size_x)
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

void	cercle_it(t_filler **filler, int victim)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	t = (victim < 0) ? 1 : victim + 1;
	while (i < (*filler)->rows)
	{
		j = 0;
		while (j < (*filler)->cols)
		{
			if (((*filler)->map)[i][j] == victim)
			{
				if (i > 0 && ((*filler)->map)[i - 1][j] == 0)
					((*filler)->map)[i - 1][j] = t;
				if (j > 0 && ((*filler)->map)[i][j - 1] == 0)
					((*filler)->map)[i][j - 1] = t;
				if (i < ((*filler)->rows - 1) && ((*filler)->map)[i + 1][j] == 0)
					((*filler)->map)[i + 1][j] = t;
				if (j < ((*filler)->cols - 1) && ((*filler)->map)[i][j + 1] == 0)
					((*filler)->map)[i][j + 1] = t;
				if (j < ((*filler)->cols - 1) && i > 0 && ((*filler)->map)[i - 1][j + 1] == 0)
					((*filler)->map)[i - 1][j + 1] = t;
				if (j < ((*filler)->cols - 1) && i < ((*filler)->rows - 1) && ((*filler)->map)[i + 1][j + 1] == 0)
					((*filler)->map)[i + 1][j + 1] = t;
				if (j > 0 && i < ((*filler)->rows - 1) && ((*filler)->map)[i + 1][j - 1] == 0)
					((*filler)->map)[i + 1][j - 1] = t;
				if (j > 0 && i > 0 && ((*filler)->map)[i - 1][j - 1] == 0)
					((*filler)->map)[i - 1][j - 1] = t;
			}
			j++;
		}
		i++;
	}
}

void	heat_map(t_filler **filler)
{
	int	i;
	int	j;
	int	victim;

	victim = -2;
	while (a_zero((*filler)->map, (*filler)->rows, (*filler)->cols))
	{
		cercle_it(filler, victim);
		victim = (victim < 0) ? 1 : victim + 1;
	}
}


int	main(void)
{
	t_filler	*filler;
	char		*line;
	int		fd;
	int		i;
	int		k;

	//while (get_next_line(0, &line) > 0)
	//{
		get_next_line(0, &line);
		filler = (t_filler*)malloc(sizeof(t_filler));
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
			ft_dprintf(2, "\n");
			k = -1;
			while (++k < filler->rows)
			{
				i = 0;
				while (++i < filler->cols)
				{
					if (filler->map[k][i] >= 0 && filler->map[k][i] <= 9)
						ft_dprintf(2, " %d", filler->map[k][i]);
					else
						ft_dprintf(2, "%d", filler->map[k][i]);
				}
				ft_putstr_fd("\n", 2);
			}
		free_filler(&filler);
	//}
	return (0);
}
