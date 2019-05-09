/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:55:05 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/09 01:16:14 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void			wait_close(void)
{
	SDL_Event	event;
	int			pass;

	pass = 1;
	while (pass)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			pass = 0;
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				pass = 0;
		}
	}
}

int				event_trigger(SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		return (1);
	if (event->type == SDL_KEYDOWN)
	{
		if (event->key.keysym.sym == SDLK_ESCAPE)
			return (1);
		if (event->key.keysym.sym == SDLK_p)
		{
			if (space_pause(event))
				return (1);
			else
				return (0);
		}
		if (event->key.keysym.sym == SDLK_SPACE)
		{
			if (pas_pause())
				return (1);
			else
				return (0);
		}
	}
	return (0);
}
