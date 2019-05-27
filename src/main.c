/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 06:46:10 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/26 23:00:55 by obelouch         ###   ########.fr       */
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

int			main(void)
{
	t_filler	filler;

	init_filler(&filler);
	while (1)
	{
		if (!take_infos(&filler))
			return (EXIT_SUCCESS);
		if (!skip_line())
			return (EXIT_FAILURE);
		if (!int_map(&filler))
			return (EXIT_FAILURE);
		if (!get_token(&filler))
			return (EXIT_FAILURE);
		if (!heat_map(&filler))
			return (EXIT_FAILURE);
		output(&filler);
		free_filler(&filler);
	}
	return (EXIT_SUCCESS);
}
