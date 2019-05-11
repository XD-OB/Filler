/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:16:36 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/11 00:33:19 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			output(t_filler *filler)
{
	int			x;
	int			y;

	xy_coord(&filler);
	y = filler->y - filler->begin_y;
	x = filler->x - filler->begin_x;
	ft_dprintf(1, "%d %d\n", y, x);
}

int				main(void)
{
	t_filler	*filler;
	char		*line;
	int			i;

	filler = (t_filler*)malloc(sizeof(t_filler));
	while (get_next_line(0, &line) > 0)
	{
		take_sides(filler, &line);
		init_map_size(filler, line);
		free(line);
		get_next_line(0, &line);
		free(line);
		i = -1;
		if (!(filler->map = (int**)malloc(sizeof(int*) * filler->rows)))
			return (EXIT_FAILURE);
		while (++i < filler->rows)
			filler->map[i] = str_int(filler);
		heat_map(&filler);
		filler->token = get_token(filler);
		output(filler);
		free_filler(filler);
	}
	free(line);
	free(filler);
	return (EXIT_SUCCESS);
}
