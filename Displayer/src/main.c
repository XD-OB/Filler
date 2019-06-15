/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 05:29:31 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/14 17:57:24 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void			print_usage(void)
{
	ft_printf("%{CYAN}  ---# obelouch displayer #---%{eoc}\n");
	ft_printf("  | Pause on/off : %{GREEN}SPACE%{eoc}     |\n");
	ft_printf("  | Next Turn    : %{GREEN}UP%{eoc}        |\n");
	ft_printf("  | Previous Turn: %{GREEN}DOWN%{eoc}      |\n");
	ft_printf("  | Speed +      : %{GREEN}RIGHT%{eoc}     |\n");
	ft_printf("  | Speed -      : %{GREEN}LEFT%{eoc}      |\n");
	ft_printf("  | Change Color : %{GREEN}C%{eoc}         |\n");
	ft_printf("  | Music on/off : %{GREEN}M%{eoc}         |\n");
	ft_printf("  | End Game     : %{GREEN}E%{eoc}         |\n");
	ft_printf("%{CYAN}  ----------------------------%{eoc}\n");
	ft_printf("%{CYAN}        WAIT THE LOADING...%{eoc}\n");
}

int				main(void)
{
	t_display	display;
	t_movie		*curr;

	if (!init_sdl())
		return (EXIT_FAILURE);
	if (!create_window_render(&display))
		return (EXIT_FAILURE);
	print_usage();
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
