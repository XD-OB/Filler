/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 02:17:53 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 02:18:33 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static void		color_mode1(SDL_Color *color_p1, SDL_Color *color_p2)
{
	color_p1->r = 213;
	color_p1->g = 174;
	color_p1->b = 65;
	color_p2->r = 97;
	color_p2->g = 85;
	color_p2->b = 80;
}

static void		color_mode2(SDL_Color *color_p1, SDL_Color *color_p2)
{
	color_p1->r = 233;
	color_p1->g = 75;
	color_p1->b = 60;
	color_p2->r = 0;
	color_p2->g = 165;
	color_p2->b = 145;
}

static void		color_mode3(SDL_Color *color_p1, SDL_Color *color_p2)
{
	color_p1->r = 254;
	color_p1->g = 132;
	color_p1->b = 14;
	color_p2->r = 0;
	color_p2->g = 110;
	color_p2->b = 109;
}

void			put_pieces(t_display *display, int ac, char **av)
{
	if (ac > 1 && !ft_strcmp(av[1], "mode1"))
		color_mode1(&(display->color_p1), &(display->color_p2));
	else if (ac > 1 && !ft_strcmp(av[1], "mode2"))
		color_mode2(&(display->color_p1), &(display->color_p2));
	else
		color_mode3(&(display->color_p1), &(display->color_p2));
	put_scene(display);
	display_players(display);
	SDL_RenderPresent(display->render);
}
