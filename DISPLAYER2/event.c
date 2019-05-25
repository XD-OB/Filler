/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 07:43:14 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 09:02:28 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void				init_display(t_display *display)
{
	display->clr = 0;
	display->pass = 1;
	display->pause = 1;
	display->speed = 30;
	display->mute = -1;
}

static void			event_keyboard(t_display *display, SDL_Event event,
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
		speed(display, 1);
	if (event.key.keysym.sym == SDLK_LEFT)
		speed(display, -1);
	if (event.key.keysym.sym == SDLK_p)
		take_screenshot(display);
	if (event.key.keysym.sym == SDLK_m)
		off_on_music(display);
}

void			loop_game(t_display *display, t_movie *curr)
{
	int			pass;
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
			SDL_Delay(display->speed);
		}
	}
}
