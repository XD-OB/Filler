/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 23:45:03 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 05:20:09 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_ennemy(int a)
{
	if (a == -2 || a == -3)
		return (1);
	return (0);
}

/*
**	v:		0: i	1: j	2: a	3: fine		4: score
*/

static int	the_score(t_filler *filler, int y, int x)
{
	int		v[5];

	v[4] = 0;
	v[3] = 0;
	v[0] = filler->begin_y - 1;
	while (++v[0] < filler->token_y)
	{
		v[2] = x;
		v[1] = filler->begin_x - 1;
		while (++v[1] < filler->token_x)
		{
			if (filler->token[v[0]][v[1]] == '*')
			{
				if (v[2] >= filler->cols || y >= filler->rows ||
						is_ennemy(filler->heatmap[y][v[2]]))
					return (INT_MAX);
				if (filler->heatmap[y][v[2]] == -1)
					v[3]++;
				v[4] += filler->heatmap[y][v[2]];
			}
			v[2]++;
		}
		y++;
	}
	return ((v[3] == 1) ? v[4] : INT_MAX);
}

void		xy_coord(t_filler *filler)
{
	int		score;
	int		tmp;
	int		i;
	int		j;

	i = 0;
	score = INT_MAX;
	while (i < filler->rows)
	{
		j = 0;
		while (j < filler->cols)
		{
			tmp = the_score(filler, i, j);
			if (tmp < score)
			{
				filler->y = i;
				filler->x = j;
				score = tmp;
			}
			j++;
		}
		i++;
	}
}

void		output(t_filler *filler)
{
	int		y;
	int		x;

	xy_coord(filler);
	y = filler->y - filler->begin_y;
	x = filler->x - filler->begin_x;
	ft_printf("%d %d\n", y, x);
}
