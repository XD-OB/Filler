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
			ft_putstr_fd("me: ", 2);
			ft_putnbr_fd(filler->me, 2);
			ft_putstr_fd("\nvs: ", 2);
			ft_putnbr_fd(filler->vs, 2);
			ft_putchar_fd('\n', 2);
		free(*line);
		get_next_line(0, line);
	}
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
		ft_putstr_fd("rows: ", 2);
		ft_putnbr_fd(filler->rows, 2);
		ft_putstr_fd("\ncols: ", 2);
		ft_putnbr_fd(filler->cols, 2);
		ft_putchar_fd('\n', 2);
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
				ft_putnbr_fd(filler->map[i][k], 2);
			ft_putchar_fd('\n', 2);
			//ft_putstr_fd(line, 2);
			//ft_putchar_fd('\n', 2);
		free(line);
		i++;
	}
	init_token_size(filler);
		ft_putstr_fd("token_y: ", 2);
		ft_putnbr_fd(filler->token_y, 2);
		ft_putstr_fd("\ntoken_x: ", 2);
		ft_putnbr_fd(filler->token_x, 2);
		ft_putchar_fd('\n', 2);
	while (get_next_line(0, &line))
	{
	}
	return (0);
}
