/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 21:09:57 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 05:25:31 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
