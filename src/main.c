/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 06:46:10 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/27 06:19:06 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				main(int ac, char **av)
{
	t_filler	filler;

	(void)ac;
	(void)av;
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
