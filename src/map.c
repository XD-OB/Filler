/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:56:15 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 00:23:37 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			take_infos(t_filler *filler)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	if (!ft_strncmp(line, "$$$ exec p", 10))
	{
		filler->me = ft_atoi(&line[10]);
		free(line);
		get_next_line(0, &line);
	}
	if (ft_strncmp(line, "Plateau ", 8))
	{
		free(line);
		return (0);
	}
	filler->rows = ft_atoi(&line[8]);
	i = 8;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	filler->cols = ft_atoi(&line[i]);
	free(line);
	return (1);
}

static void	fill_segm_case(t_filler *filler, int *segm, char c)
{
	if (filler->me == 1)
	{
		if (c == 'o' || c == 'O')
			*segm = -1;
		else if (c == 'X')
			*segm = -3;
		else if (c == 'x')
			*segm = -2;
		else
			*segm = 0;
	}
	else
	{
		if (c == 'x' || c == 'X')
			*segm = -1;
		else if (c == 'O')
			*segm = -3;
		else if (c == 'o')
			*segm = -2;
		else
			*segm = 0;
	}
}

static void	fill_map_segm(t_filler *filler, int **segm, int p)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	get_next_line(0, &line);
	while (line[j] && line[j] != ' ')
		j++;
	i = 0;
	while (line[++j] && filler)
	{
		fill_segm_case(filler, &(*segm)[i], line[j]);
		if ((*segm)[i] == -1)
		{
			filler->p_y = p;
			filler->p_x = i;
		}
		i++;
	}
	free(line);
}

int			int_map(t_filler *filler)
{
	int		i;

	if (!(filler->map = (int**)malloc(sizeof(int*) * (filler->rows + 1))))
		return (0);
	filler->map[filler->rows] = NULL;
	i = 0;
	while (i < filler->rows)
	{
		filler->map[i] = (int*)malloc(sizeof(int) * (filler->cols));
		fill_map_segm(filler, &filler->map[i], i);
		i++;
	}
	return (1);
}
