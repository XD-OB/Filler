/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:30:06 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/02 22:30:36 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		init_map_size(t_filler *filler, char *line)
{
	int		i;

	i = 8;
	filler->rows = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	filler->cols = ft_atoi(&line[i]);
}

/*
**	always!		me: -1		opponent: -2
*/

int			*str_int(t_filler *filler)
{
	int		*segm;
	char	*line;
	int		i;
	int		j;

	i = 0;
	get_next_line(0, &line);
	while (line[i] != ' ')
		i++;
	j = 0;
	segm = (int*)malloc(sizeof(int) * filler->cols);
	while (line[++i])
	{
		if (line[i] == '.')
			segm[j] = 0;
		else if (line[i] == 'O' || line[i] == 'o')
			segm[j] = (filler->me == 1) ? -1 : -2;
		else if (line[i] == 'X' || line[i] == 'x')
			segm[j] = (filler->me == 1) ? -2 : -1;
		j++;
	}
	free(line);
	return (segm);
}

void		take_sides(t_filler *filler, char **line)
{
	if (!ft_strncmp(*line, "$$$", 3))
	{
		filler->me = ft_atoi(&(*line)[10]);
		free(*line);
		get_next_line(0, line);
	}
}
