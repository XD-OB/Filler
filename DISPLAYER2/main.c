/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 05:29:31 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 02:24:38 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

int				main(int ac, char **av)
{
	t_display	display;

	if (!init_sdl())
		return (EXIT_FAILURE);
	if (!create_window_render(&display))
		return (EXIT_FAILURE);
	if (!record_game(&display))
		return (EXIT_FAILURE);
	load_music(&display);
	put_pieces(&display, ac, av);
	//print_list(display.movie);
	put_pieces(&display, ac, av);
	SDL_Delay(8000);
	free_display(&display);
	free_sdl(&display);
	return (EXIT_SUCCESS);
}
