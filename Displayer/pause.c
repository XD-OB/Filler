#include "display.h"

void	pas_pause(void)
{
	SDL_Event 	event;
	int		pass;

	pass = 1;
	while (pass)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_SPACE)
				pass = 0;
			if (event.key.keysym.sym == SDLK_ESCAPE)
				exit(1);
		}
	}
}

void	space_pause(SDL_Event *event)
{
	int		pass;

	pass = 1;
	while (pass)
	{
		SDL_WaitEvent(event);
		if (event->type == SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_o)
				pass = 0;
			if (event->key.keysym.sym == SDLK_ESCAPE)
				exit(1);
		}
	}
}
