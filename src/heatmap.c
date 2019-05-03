/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:17:11 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/02 22:29:56 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	heatmap_engine(t_filler **filler, int y, int x, int victim)
{
	int	siege;

	if (victim == -2)
		siege = -5;
	else
		siege = (victim == -5) ? 1 : victim + 1;
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
	if (y < (*filler)->rows - 1 && x > 0 &&
			(*filler)->map[y + 1][x - 1] == victim)
		(*filler)->map[y][x] = siege;
	if (y > 0 && x < (*filler)->cols - 1 &&
			(*filler)->map[y - 1][x + 1] == victim)
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
		if (wave == 0)
			victim = -2;
		else
			victim = (wave == 1) ? -5 : wave - 1;
		while (++i < (*filler)->rows)
		{
			j = -1;
			while (++j < (*filler)->cols)
				if ((*filler)->map[i][j] == 0)
					heatmap_engine(filler, i, j, victim);
		}
	}
}

static void	score_point(t_filler *filler, int *score, int y, int x)
{
	*score += filler->map[y][x];
	if (y > 0 && filler->map[y - 1][x] == -5)
		*score -= 2;
	if (x > 0 && filler->map[y][x - 1] == -5)
		*score -= 2;
	if (y < filler->rows - 1 && filler->map[y + 1][x] == -5)
		*score -= 2;
	if (x < filler->cols - 1 && filler->map[y][x + 1] == -5)
		*score -= 2;
	if (y > 0 && x > 0 && filler->map[y - 1][x - 1] == -5)
		*score -= 2;
	if (y > 0 && x < filler->cols - 1 && filler->map[y - 1][x + 1] == -5)
		*score -= 2;
	if (y < filler->rows - 1 && x > 0 && filler->map[y + 1][x - 1] == -5)
		*score -= 2;
	if (y < filler->rows - 1 && x < filler->cols - 1
			&& filler->map[y + 1][x + 1] == -5)
		*score -= 2;
}

/*
**	v:	0:i	1:j	2:a	3:fine
*/

static int	the_score(t_filler *filler, int y, int x)
{
	int	score;
	int	v[4];

	score = 0;
	v[3] = 0;
	v[0] = filler->begin_y - 1;
	while (++v[0] < filler->token_y)
	{
		v[2] = x;
		v[1] = filler->begin_x - 1;
		while (++v[1] < filler->token_x)
		{
			if (v[2] >= filler->cols || y >= filler->rows
					|| filler->map[y][v[2]] == -2)
				return (INT_MAX);
			if (filler->map[y][v[2]] == -1
				&& filler->token[v[0]][v[1]] == '*')
				v[3]++;
			else
				score_point(filler, &score, y, v[2]);
			v[2]++;
		}
		y++;
	}
	return ((v[3] == 1) ? score : INT_MAX);
}

void		xy_coord(t_filler **filler)
{
	int	score;
	int	tmp;
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
			if ((tmp = the_score(*filler, i, j)) <= score)
			{
				(*filler)->x = j;
				(*filler)->y = i;
				score = tmp;
			}
		}
	}
}
