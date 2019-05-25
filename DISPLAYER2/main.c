/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 05:29:31 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 07:45:32 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

int				main(int ac, char **av)
{
	t_display	display;
	t_movie		*curr;

	(void)ac;
	(void)av;
	if (!init_sdl())
		return (EXIT_FAILURE);
	if (!create_window_render(&display))
		return (EXIT_FAILURE);
	if (!record_game(&display))
		return (EXIT_FAILURE);
	init_display(&display);
	load_music(&display);
	curr = display.movie;
	draw_current(&display, curr);
	loop_game(&display, curr);
	free_display(&display);
	free_sdl(&display);
	return (EXIT_SUCCESS);
}
