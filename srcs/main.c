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
		if (filler->me == 1)
		{
			if (line[i] == '.')
				segm[j] = 0;
			else if (line[i] == 'O' || line[i] == 'o')
				segm[j] = -1;
			else if (line[i] == 'X')
				segm[j] = -2;
			else
				segm[j] = -3;
		}
		else
		{
			if (line[i] == '.')
				segm[j] = 0;
			else if (line[i] == 'X' || line[i] == 'x')
				segm[j] = -1;
			else if (line[i] == 'O')
				segm[j] = -2;
			else
				segm[j] = -3;
		}
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
	while (i < (*filler)->token_y)		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{
		free((*filler)->token[i]);
		i++;
	}
	free((*filler)->token);
	free(*filler);
	filler = NULL;
}

int	main(void)
{
	t_filler	*filler;
	char		*line;
	int		fd;
	int		ret;
	int		i;
	int		k;

	filler = (t_filler*)malloc(sizeof(t_filler));
	get_next_line(0, &line);
	take_sides(filler, &line);
	init_map_size(filler, line);
		ft_dprintf(2, "rows: %d\ncols: %d\n", filler->rows, filler->cols);
	free(line);
	get_next_line(0, &line);
	free(line);
	i = 0;
	filler->map = (int**)malloc(sizeof(int*) * filler->rows);
	while (i < filler->rows)
	{
		get_next_line(0, &line);
		filler->map[i] = str_int(filler, line);
			k = -1;
			while (++k < filler->cols)
				ft_dprintf(2, "%d", filler->map[i][k]);
			ft_dprintf(2, "\n%s\n", &line[4]);
		free(line);
		i++;
	}
	init_token_size(filler);
	filler->token = get_token(filler);
	free_filler(&filler);
	return (0);
}
