/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:58:32 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/08 23:27:05 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int				pas_pause(void)
{
	SDL_Event	event;
	int			pass;

	pass = 1;
	while (pass)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_SPACE)
				pass = 0;
			if (event.key.keysym.sym == SDLK_ESCAPE)
				return (1);
		}
	}
	return (0);
}

int				space_pause(SDL_Event *event)
{
	int			pass;

	pass = 1;
	while (pass)
	{
		SDL_WaitEvent(event);
		if (event->type == SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_o)
				pass = 0;
			if (event->key.keysym.sym == SDLK_ESCAPE)
				return (1);
		}
	}
	return (0);
}
