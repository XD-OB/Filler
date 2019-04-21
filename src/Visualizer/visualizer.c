#include "../../filler.h"
#include <SDL/SDL.h>

int	main(void)
{
	SDL_Surface	*screen;
	SDL_Event	event;
	int		pass;

	pass = 1;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
	{
		fprintf(2, "Initializing Error!:\n%s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	SDL_SetVideoMode(800, 500, 32, SDL_HWSURFACE
			| SDL_RESIZABLE | SDL_DOUBLEBUF);
	while(1);

	SDL_Quit();
	return (EXIT_SUCCESS);
}
