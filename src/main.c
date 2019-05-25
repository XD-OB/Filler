/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 06:46:10 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 04:46:03 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_filler	filler;

	filler.x = 0;
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
