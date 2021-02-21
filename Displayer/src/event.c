/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 07:43:14 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/27 00:19:31 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void			init_display(t_display *display)
{
	display->clr = 1;
	display->pass = 1;
	display->pause = 1;
	display->mute = -1;
	display->frm = 2;
	display->frame[0] = 5;
	display->frame[1] = 10;
	display->frame[2] = 24;
	display->frame[3] = 50;
	display->frame[4] = 250;
	display->frame[5] = 200000;
}

static void		event_keyboard(t_display *display, SDL_Event event,
						t_movie **curr)
{
	if (event.key.keysym.sym == SDLK_ESCAPE)
		display->pass = 0;
	if (event.key.keysym.sym == SDLK_UP)
		draw_next(display, curr);
	if (event.key.keysym.sym == SDLK_DOWN)
		draw_prev(display, curr);
	if (event.key.keysym.sym == SDLK_SPACE)
		display->pause = (display->pause) ? 0 : 1;
	if (event.key.keysym.sym == SDLK_r)
		reset_game(display, curr);
	if (event.key.keysym.sym == SDLK_c)
		change_color(display, *curr);
	if (event.key.keysym.sym == SDLK_RIGHT)
		(display->frm < 5) ? display->frm++ : 0;
	if (event.key.keysym.sym == SDLK_LEFT)
		(display->frm > 0) ? display->frm-- : 0;
	if (event.key.keysym.sym == SDLK_p)
		take_screenshot(display);
	if (event.key.keysym.sym == SDLK_m)
		off_on_music(display);
	if (event.key.keysym.sym == SDLK_e)
		end_game(display, curr);
}

void			loop_game(t_display *display, t_movie *curr)
{
	SDL_Event	event;

	while (display->pass)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				display->pass = 0;
			if (event.type == SDL_KEYDOWN)
				event_keyboard(display, event, &curr);
		}
		if (!display->pause)
		{
			draw_next(display, &curr);
			SDL_Delay(2000 / display->frame[display->frm]);
		}
	}
}
