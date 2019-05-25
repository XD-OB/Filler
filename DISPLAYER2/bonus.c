/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 07:21:34 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 08:50:38 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void		reset_game(t_display *display, t_movie **curr)
{
	*curr = display->movie;
	display->pause = 1;
	draw_current(display, *curr);
}


void		change_color(t_display *display, t_movie *curr)
{
	display->clr++;
	if (display->clr == 3)
		display->clr = 0;
	draw_current(display, curr);
}

void		speed(t_display *display, int way)
{
	if (way == 1)
	{
		if (way > 2)
			display->speed /= 2;
	}
	else if (way == -1)
			display->speed *= 1.2;
}

void		off_on_music(t_display *display)
{
	if (display->mute == -1)
	{
		display->mute = 0;
		Mix_PauseMusic();
	}
	else
	{
		display->mute = -1;
		Mix_PlayMusic(display->music, display->mute);
	}
}

void		take_screenshot(t_display *display)
{
	SDL_Surface	*tmp;

	tmp = SDL_CreateRGBSurfaceWithFormat(0, WIDTH, HEIGHT,
			32, SDL_PIXELFORMAT_RGBA32);
	SDL_RenderReadPixels(display->render, NULL,
			SDL_PIXELFORMAT_RGBA32,
			tmp->pixels, tmp->pitch);
	IMG_SavePNG(tmp, "screenshot.png");
	SDL_FreeSurface(tmp);
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
			"Obelouch Displayer:",
			"Nice Picture!\n Your Picture is made successfuly ;)",
			display->window);
}
