/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:52:34 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/27 05:26:43 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	affect_victim_siege(int *vic_sieg, int wave)
{
	if (wave == 0)
	{
		vic_sieg[0] = -3;
		vic_sieg[1] = -2;
		vic_sieg[2] = 1;
	}
	else
	{
		vic_sieg[0] = wave;
		vic_sieg[1] = wave;
		vic_sieg[2] = wave + 1;
	}
}

static int	is_ok(int coord)
{
	if (coord == 0 || coord == -1)
		return (1);
	return (0);
}

static void	heatmap_engine(t_filler *filler, int y, int x, int siege)
{
	if (x + 1 < filler->cols &&
			is_ok(filler->heatmap[y][x + 1]))
		filler->heatmap[y][x + 1] = siege;
	if (x - 1 >= 0 &&
			is_ok(filler->heatmap[y][x - 1]))
		filler->heatmap[y][x - 1] = siege;
	if (y + 1 < filler->rows &&
			is_ok(filler->heatmap[y + 1][x]))
		filler->heatmap[y + 1][x] = siege;
	if (y - 1 >= 0 &&
			is_ok(filler->heatmap[y - 1][x]))
		filler->heatmap[y - 1][x] = siege;
	if (y - 1 >= 0 && x - 1 >= 0 &&
			is_ok(filler->heatmap[y - 1][x - 1]))
		filler->heatmap[y - 1][x - 1] = siege;
	if (y + 1 < filler->rows && x + 1 < filler->cols &&
			is_ok(filler->heatmap[y + 1][x + 1]))
		filler->heatmap[y + 1][x + 1] = siege;
	if (x - 1 >= 0 && y + 1 < filler->rows &&
			is_ok(filler->heatmap[y + 1][x - 1]))
		filler->heatmap[y + 1][x - 1] = siege;
	if (y - 1 >= 0 && x + 1 < filler->cols &&
			is_ok(filler->heatmap[y - 1][x + 1]))
		filler->heatmap[y - 1][x + 1] = siege;
}

static void	put_me_in(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->rows)
	{
		j = 0;
		while (j < filler->cols)
		{
			if (filler->map[i][j] < 0)
				filler->heatmap[i][j] = filler->map[i][j];
			j++;
		}
		i++;
	}
}

int			heat_map_final(t_filler *filler)
{
	int		vic_sieg[3];
	int		wave;
	int		i;
	int		j;

	if (!(filler->heatmap =
			copy_int2(filler->map, filler->rows, filler->cols)))
		return (0);
	wave = -1;
	while (++wave < ft_max(filler->cols, filler->rows))
	{
		i = -1;
		affect_victim_siege(vic_sieg, wave);
		while (++i < filler->rows)
		{
			j = -1;
			while (++j < filler->cols)
				if (filler->heatmap[i][j] == vic_sieg[0] ||
						filler->heatmap[i][j] == vic_sieg[1])
					heatmap_engine(filler, i, j, vic_sieg[2]);
		}
	}
	put_me_in(filler);
	return (1);
}

/*
**		In little map it's better to attack: further safe :<
**		In Big Maps it's better to attack: near safe XD
*/

void		affect_yxm(t_filler *filler, int y, int x)
{
	filler->ym = y;
	filler->xm = x;
}

void		coord_max(t_filler *filler)
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

static void	heatmap_engine_extrm(t_filler *filler, int y, int x, int siege)
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

int			heat_map_extrm(t_filler *filler, int ym, int xm)
{
	int		vic_sieg[2];
	int		wave;
	int		i;
	int		j;

	if (!(filler->heatmap =
			copy_int2(filler->map, filler->rows, filler->cols)))
		return (0);
	filler->heatmap[ym][xm] = 1;
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

int			heat_map(t_filler *filler)
{
	if (filler->ym == -1 && filler->xm == -1)
		coord_max(filler);
	if (filler->map[filler->ym][filler->xm] == 0)
		return (heat_map_extrm(filler, filler->ym, filler->xm));
	return (heat_map_final(filler));
}
