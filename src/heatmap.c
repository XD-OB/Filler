#include "../filler.h"

static void	heatmap_engine(t_filler **filler, int y, int x, int victim)
{
	int	siege;

	siege = (victim == -2) ? 1 : victim + 1;
	if (x < (*filler)->cols - 1 && (*filler)->map[y][x + 1] == victim)
		(*filler)->map[y][x] = siege;
	if (x > 0 && (*filler)->map[y][x - 1] == victim)
		(*filler)->map[y][x] = siege;
	if (y < (*filler)->rows - 1 && (*filler)->map[y + 1][x] == victim)
		(*filler)->map[y][x] = siege;
	if (y > 0 && (*filler)->map[y - 1][x] == victim)
		(*filler)->map[y][x] = siege;
	if (y > 0 && x > 0 && (*filler)->map[y - 1][x - 1] == victim)
		(*filler)->map[y][x] = siege;
	if (y < (*filler)->rows - 1 && x < (*filler)->cols - 1
			&& (*filler)->map[y + 1][x + 1] == victim)
		(*filler)->map[y][x] = siege;
	if (y < (*filler)->rows - 1 && x > 0 && (*filler)->map[y + 1][x - 1] == victim)
		(*filler)->map[y][x] = siege;
	if (y > 0 && x < (*filler)->cols - 1 && (*filler)->map[y - 1][x + 1] == victim)
		(*filler)->map[y][x] = siege;
}

void		heat_map(t_filler **filler)
{
	int	victim;
	int	wave;
	int	i;
	int	j;

	wave = -1;
	while (++wave < (*filler)->cols)
	{
		i = -1;
		victim = (wave == 0) ? -2 : wave;
		while (++i < (*filler)->rows)
		{
			j = -1;
			while (++j < (*filler)->cols)
				if ((*filler)->map[i][j] == 0)
					heatmap_engine(filler, i, j, victim);
		}
	}
}

static int	the_score(t_filler *filler, int y, int x)
{
	int	score;
	int	fine;
	int	a;
	int	i;
	int	j;

	score = 0;
	fine = 0;
	i = filler->begin_y - 1;
	while (++i < filler->token_y)
	{
		a = x;
		j = filler->begin_x - 1;
		while (++j < filler->token_x)
		{
			if (a >= filler->cols || y >= filler->rows || filler->map[y][a] == -2)
				return (INT_MAX);
			if (filler->map[y][a] == -1 && filler->token[i][j] == '*')
				fine++;
			score += filler->map[y][a];
			a++;		
		}
		y++;
	}
	return ((fine == 1) ? score : INT_MAX);
}

void		xy_coord(t_filler **filler)
{
	int	score;
	int	i;
	int	j;

	i = -1;
	score = INT_MAX - 1;
	(*filler)->x = -5;
	(*filler)->y = -5;
	while (++i < (*filler)->rows)
	{
		j = -1;
		while (++j < (*filler)->cols)
		{
			if (the_score(*filler, i, j) <= score)
			{
				(*filler)->x = j;
				(*filler)->y = i;
				score = the_score(*filler, i, j);
			}
		}
	}
}

