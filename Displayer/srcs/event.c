#include "display.h"

void	wait_close(void)
{
	SDL_Event event;
	int	pass;

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

void	event_trigger(SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		exit(1) ;
	if (event->type == SDL_KEYDOWN)
	{
		if (event->key.keysym.sym == SDLK_ESCAPE)
			exit(1);
		if (event->key.keysym.sym == SDLK_p)
			space_pause(event);
		if (event->key.keysym.sym == SDLK_SPACE)
			pas_pause();
	}
}
