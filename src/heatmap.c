/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:52:34 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 02:22:47 by obelouch         ###   ########.fr       */
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
	if (x + 1 < filler->cols && is_ok(filler->heatmap[y][x + 1]))
		filler->heatmap[y][x + 1] = siege;
	if (x - 1 >= 0 && is_ok(filler->heatmap[y][x - 1]))
		filler->heatmap[y][x - 1] = siege;
	if (y + 1 < filler->rows && is_ok(filler->heatmap[y + 1][x]))
		filler->heatmap[y + 1][x] = siege;
	if (y - 1 >= 0 && is_ok(filler->heatmap[y - 1][x]))
		filler->heatmap[y - 1][x] = siege;
	if (y - 1 >= 0 && x - 1 >= 0 && is_ok(filler->heatmap[y - 1][x - 1]))
		filler->heatmap[y - 1][x - 1] = siege;
	if (y + 1 < filler->rows && x + 1 < filler->cols && is_ok(filler->heatmap[y + 1][x + 1]))
		filler->heatmap[y + 1][x + 1] = siege;
	if (x - 1 >= 0 && y + 1 < filler->rows && is_ok(filler->heatmap[y + 1][x - 1]))
		filler->heatmap[y + 1][x - 1] = siege;
	if (y - 1 >= 0 && x + 1 < filler->cols && is_ok(filler->heatmap[y - 1][x + 1]))
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
			j++;
		}
		i++;
	}
}

int			heat_map(t_filler *filler)
{
	int		vic_sieg[3];
	int		wave;
	int		i;
	int		j;

	if (!(filler->heatmap = copy_int2(filler->map, filler->rows, filler->cols)))
		return (0);
	wave = -1;
	while (++wave < ft_max(filler->cols, filler->rows))
	{
		i = -1;
		affect_victim_siege(vic_sieg, wave);
		while (++i < filler->rows)
		{
			j= -1;
			while (++j < filler->cols)
				if (filler->heatmap[i][j] == vic_sieg[0] ||
						filler->heatmap[i][j] == vic_sieg[1])
					heatmap_engine(filler, i, j, vic_sieg[2]);
		}
	}
	put_me_in(filler);
	//ft_putstr_fd("--------HEATMAP---------\n", 2);
	//print_matrice(filler->heatmap, filler->rows, filler->cols);
	return (1);
}
