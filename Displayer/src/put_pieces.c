/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 02:17:53 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 09:18:23 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static void		color_mode1(SDL_Color *color_p1, SDL_Color *color_p2,
							SDL_Color *color_p11, SDL_Color *color_p22)
{
	color_p1->r = 213;
	color_p1->g = 174;
	color_p1->b = 65;
	color_p11->r = 233;
	color_p11->g = 204;
	color_p11->b = 95;
	color_p2->r = 97;
	color_p2->g = 85;
	color_p2->b = 80;
	color_p22->r = 127;
	color_p22->g = 115;
	color_p22->b = 110;
}

static void		color_mode2(SDL_Color *color_p1, SDL_Color *color_p2,
							SDL_Color *color_p11, SDL_Color *color_p22)
{
	color_p1->r = 233;
	color_p1->g = 75;
	color_p1->b = 60;
	color_p11->r = 255;
	color_p11->g = 105;
	color_p11->b = 90;
	color_p2->r = 0;
	color_p2->g = 165;
	color_p2->b = 145;
	color_p22->r = 30;
	color_p22->g = 195;
	color_p22->b = 175;
}

static void		color_mode3(SDL_Color *color_p1, SDL_Color *color_p2,
							SDL_Color *color_p11, SDL_Color *color_p22)
{
	color_p1->r = 254;
	color_p1->g = 132;
	color_p1->b = 14;
	color_p11->r = 255;
	color_p11->g = 162;
	color_p11->b = 44;
	color_p2->r = 0;
	color_p2->g = 110;
	color_p2->b = 109;
	color_p22->r = 30;
	color_p22->g = 140;
	color_p22->b = 139;
}

void			put_pieces(t_display *display)
{
	color_mode1(&(display->color_p1[0]), &(display->color_p2[0]),
			&(display->color_p11[0]), &(display->color_p22[0]));
	color_mode2(&(display->color_p1[1]), &(display->color_p2[1]),
			&(display->color_p11[1]), &(display->color_p22[1]));
	color_mode3(&(display->color_p1[2]), &(display->color_p2[2]),
			&(display->color_p11[2]), &(display->color_p22[2]));
	put_scene(display);
	display_players(display);
}
