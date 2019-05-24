/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 23:45:03 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 02:04:02 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_ennemy(int a)
{
	if (a == -2 || a == -3)
		return (1);
	return (0);
}

static int	the_score(t_filler *filler, int y, int x)
{
	int		score;
	int		fine;
	int		i;
	int		j;
	int		a;

	score = 0;
	fine = 0;
	i = filler->begin_y - 1;
	while (++i < filler->token_y)
	{
		a = x;
		j = filler->begin_x - 1;
		while (++j < filler->token_x)
		{
			if (filler->token[i][j] == '*')
			{
				if (a >= filler->cols || y >= filler->rows ||
						is_ennemy(filler->heatmap[y][a]))
					return (INT_MAX);
				if (filler->heatmap[y][a] == -1)
					fine++;
				score += filler->heatmap[y][a];
			}
			a++;
		}
		y++;
	}
	if (fine == 1)
		return (score);
	else
		return (INT_MAX);
}

void		output(t_filler *filler)
{
	int		score;
	int		tmp;
	int		i;
	int		j;

	i = 0;
	score = INT_MAX;
	filler->y = 0;
	filler->x = 0;
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
	ft_printf("%d %d\n", filler->y - filler->begin_y, filler->x - filler->begin_x);
	ft_dprintf(2, "y = %d | x = %d\n", filler->y - filler->begin_y, filler->x - filler->begin_x);
}
