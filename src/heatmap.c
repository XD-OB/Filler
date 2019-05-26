/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:52:34 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/26 10:11:59 by obelouch         ###   ########.fr       */
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
			if (filler->map[i][j] == -1)
				filler->heatmap[i][j] = -1;
			if (filler->map[i][j] == -2)
				filler->heatmap[i][j] = -2;
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

int			is_touch(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->rows)
	{
		j = 0;
		while (j < filler->cols)
		{
			if ((i == 0 || i == filler->rows - 1 ||
				j == 0 || j == filler->cols - 1) &&
				filler->map[i][j] == -1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			is_smaller(int min, int a, int b, int c)
{
	if (min > a && (min < c || min < b))
			return (1);
	if (min > b && (min < c || min < a))
		return (1);
	if (min > c && (min < b || min < a))
		return (1);
	return (0);
}

void		coord_max(t_filler *filler, int *ym, int *xm)
{
	int		diff_xmr;
	int		diff_xml;
	int		diff_ymu;
	int		diff_ymd;

	diff_xmr = filler->cols - filler->p_x - 1;
	diff_ymd = filler->rows - filler->p_y - 1;
	diff_xml = filler->p_x;
	diff_ymu = filler->p_y;
	if (is_smaller(diff_xmr, diff_ymd, diff_xml, diff_ymu))
	{
		//*ym = filler->p_y;
		//*ym = filler->p_y;
		*xm = filler->cols - 1;
	}
	if (is_smaller(diff_ymd, diff_xmr, diff_xml, diff_ymu))
	{
		*ym = filler->rows - 1;
		//*xm = filler->p_x;
		*xm = filler->cols / 2;
	}
	if (is_smaller(diff_xml, diff_ymd, diff_xmr, diff_ymu))
	{
		//*ym = filler->p_y;
		*ym = filler->rows / 2;
		*xm = 0;
	}
	if (is_smaller(diff_ymu, diff_ymd, diff_xml, diff_xmr))
	{
		*ym = 0;
		//*xm = filler->p_x;
		*xm = filler->cols / 2;
	}
}

static int	isok(int coord)
{
	if (coord == 0 || coord == -1 || coord == -2)
		return (1);
	return (0);
}

static void	heatmap_engine_extrm(t_filler *filler, int y, int x, int siege)
{
	if (x + 1 < filler->cols &&
			isok(filler->heatmap[y][x + 1]))
		filler->heatmap[y][x + 1] = siege;
	if (x - 1 >= 0 &&
			isok(filler->heatmap[y][x - 1]))
		filler->heatmap[y][x - 1] = siege;
	if (y + 1 < filler->rows &&
			isok(filler->heatmap[y + 1][x]))
		filler->heatmap[y + 1][x] = siege;
	if (y - 1 >= 0 &&
			isok(filler->heatmap[y - 1][x]))
		filler->heatmap[y - 1][x] = siege;
	if (y - 1 >= 0 && x - 1 >= 0 &&
			isok(filler->heatmap[y - 1][x - 1]))
		filler->heatmap[y - 1][x - 1] = siege;
	if (y + 1 < filler->rows && x + 1 < filler->cols &&
			isok(filler->heatmap[y + 1][x + 1]))
		filler->heatmap[y + 1][x + 1] = siege;
	if (x - 1 >= 0 && y + 1 < filler->rows &&
			isok(filler->heatmap[y + 1][x - 1]))
		filler->heatmap[y + 1][x - 1] = siege;
	if (y - 1 >= 0 && x + 1 < filler->cols &&
			isok(filler->heatmap[y - 1][x + 1]))
		filler->heatmap[y - 1][x + 1] = siege;
}

int			heat_map_extrm(t_filler *filler, int ym, int xm)
{
	int		vic_sieg[3];
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
		vic_sieg[1] = wave + 1;
		vic_sieg[2] = wave + 2;
		while (++i < filler->rows)
		{
			j = -1;
			while (++j < filler->cols)
				if (filler->heatmap[i][j] == vic_sieg[0] ||
						filler->heatmap[i][j] == vic_sieg[1])
					heatmap_engine_extrm(filler, i, j, vic_sieg[2]);
		}
	}
	put_me_in(filler);
/*	i = 0;
	while (i < filler->rows)
	{
		j = 0;
		while (j < filler->cols)
		{
			if (filler->heatmap[i][j] < 10 && filler->heatmap[i][j] >= 0)
				ft_putchar_fd(' ', 2);
			ft_dprintf(2, "%d ", filler->heatmap[i][j]);
			j++;
		}
		i++;
	}*/
	return (1);
}



int			heat_map(t_filler *filler)
{
	int		xm;
	int		ym;

	coord_max(filler, &ym, &xm);
	if (filler->map[ym][xm] == 0)
	{
		//ft_putstr_fd("ana f extrem\n", 2);
		return (heat_map_extrm(filler, ym, xm));
	}
	//ft_dprintf(2, "\n---ym: [%d] --- xm: [%d]-----\n", ym, xm);
	return (heat_map_final(filler));
	return (1);
}
