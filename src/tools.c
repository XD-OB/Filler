/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 21:09:57 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/27 06:17:57 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		init_filler(t_filler *filler)
{
	filler->x = 0;
	filler->y = 0;
	filler->p_y = -1;
	filler->p_x = -1;
	filler->xm = -1;
	filler->ym = -1;
}

void		put_me_in(t_filler *filler)
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

int			skip_line(void)
{
	char	*line;
	int		ret;

	if ((ret = get_next_line(0, &line)) == -1)
		return (0);
	if (ret == 0)
	{
		free(line);
		line = NULL;
		return (0);
	}
	free(line);
	line = NULL;
	return (1);
}

void		free_filler(t_filler *filler)
{
	int		i;

	i = 0;
	while (filler->map[i])
	{
		free(filler->map[i]);
		i++;
	}
	free(filler->map);
	i = 0;
	while (filler->heatmap[i])
	{
		free(filler->heatmap[i]);
		i++;
	}
	free(filler->heatmap);
	free_tabstr(&filler->token);
}

int			is_allpoint(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
