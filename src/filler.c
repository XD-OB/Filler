#include "filler.h"

void		output(t_filler *filler)
{
	int		y;
	int		x;

	xy_coord(&filler);
	y = filler->y - filler->begin_y;
	x = filler->x - filler->begin_x;
	ft_dprintf(1, "%d %d\n", y, x);
	//	ft_dprintf(2, "X: %d\tY: %d\n", x, y);
}

int		main(void)
{
	t_filler	*filler;
	char		*line;
	int		i;
	//	int		j;

	filler = (t_filler*)malloc(sizeof(t_filler));
	while (get_next_line(0, &line) > -1)
	{
		take_sides(filler, &line);
		init_map_size(filler, line);
		//	ft_dprintf(2, "rows: %d\ncols: %d\n", filler->rows, filler->cols);
		free(line);
		get_next_line(0, &line);
		free(line);
		i = -1;
		if (!(filler->map = (int**)malloc(sizeof(int*) * filler->rows)))
			return (EXIT_FAILURE);
		while (++i < filler->rows)
		//	{
			//get_next_line(0, &line);
			filler->map[i] = str_int(filler);
			//	j = -1;
			//	while (++j < filler->cols)
			//		ft_dprintf(2, "%d", filler->map[i][j]);
			//	ft_dprintf(2, "\n%s\n", &line[4]);
			//free(line);
		//	}
		heat_map(&filler);
		filler->token = get_token(filler);
		//	ft_putchar_fd('\n', 2);
		//	j = -1;
		//	while (++j < filler->rows)
		//	{
		//		j = -1;
		//		while (++i < filler->cols)
		//		{
		//			if (filler->map[j][i] >= 0 && filler->map[j][i] <= 9)
		//				ft_dprintf(2, " %d", filler->map[j][i]);
		//			else
		//				ft_dprintf(2, "%d", filler->map[j][i]);
		//		}
		//		ft_putchar_fd('\n', 2);
		//	}
		output(filler);
		free_filler(filler);
	}
	ultime_free_filler(&filler);
	return (EXIT_SUCCESS);
}
