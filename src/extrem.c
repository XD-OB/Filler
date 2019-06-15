/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 06:12:46 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/27 06:16:16 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**		In little map it's better to attack: further safe
**		In Big Maps it's better to attack: near safe
*/

static void		affect_yxm(t_filler *filler, int y, int x)
{
	filler->ym = y;
	filler->xm = x;
}

void			coord_max(t_filler *filler)
{
	int		diff_ymu;
	int		diff_ymd;

	diff_ymd = filler->rows - filler->p_y - 1;
	diff_ymu = filler->p_y;
	if (filler->rows > 20)
	{
		if (diff_ymd < diff_ymu)
			affect_yxm(filler, filler->rows - 1, filler->cols / 2);
		else
			affect_yxm(filler, 0, filler->cols / 2);
	}
	else
	{
		if (diff_ymd > diff_ymu)
			affect_yxm(filler, filler->rows - 1,
					filler->cols / 2);
		else
			affect_yxm(filler, 0, filler->cols / 2);
	}
}

static void		heatmap_engine_extrm(t_filler *filler,
									int y, int x, int siege)
{
	if (x + 1 < filler->cols &&
			(filler->heatmap[y][x + 1] <= 0))
		filler->heatmap[y][x + 1] = siege;
	if (x - 1 >= 0 && (filler->heatmap[y][x - 1] <= 0))
		filler->heatmap[y][x - 1] = siege;
	if (y + 1 < filler->rows &&
			(filler->heatmap[y + 1][x] <= 0))
		filler->heatmap[y + 1][x] = siege;
	if (y - 1 >= 0 && (filler->heatmap[y - 1][x] <= 0))
		filler->heatmap[y - 1][x] = siege;
	if (y - 1 >= 0 && x - 1 >= 0 &&
			(filler->heatmap[y - 1][x - 1] <= 0))
		filler->heatmap[y - 1][x - 1] = siege;
	if (y + 1 < filler->rows && x + 1 < filler->cols &&
			(filler->heatmap[y + 1][x + 1] <= 0))
		filler->heatmap[y + 1][x + 1] = siege;
	if (x - 1 >= 0 && y + 1 < filler->rows &&
			(filler->heatmap[y + 1][x - 1] <= 0))
		filler->heatmap[y + 1][x - 1] = siege;
	if (y - 1 >= 0 && x + 1 < filler->cols &&
			(filler->heatmap[y - 1][x + 1] <= 0))
		filler->heatmap[y - 1][x + 1] = siege;
}

int				heatmap_extrem(t_filler *filler)
{
	int			vic_sieg[2];
	int			wave;
	int			i;
	int			j;

	if (!(filler->heatmap =
				copy_int2(filler->map, filler->rows, filler->cols)))
		return (0);
	filler->heatmap[filler->ym][filler->xm] = 1;
	wave = -1;
	while (++wave < ft_max(filler->cols, filler->rows))
	{
		i = -1;
		vic_sieg[0] = wave + 1;
		vic_sieg[1] = wave + 2;
		while (++i < filler->rows)
		{
			j = -1;
			while (++j < filler->cols)
				if (filler->heatmap[i][j] == vic_sieg[0])
					heatmap_engine_extrm(filler, i, j, vic_sieg[1]);
		}
	}
	put_me_in(filler);
	return (1);
}
