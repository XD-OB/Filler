#include "../../filler.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void	wait_close(void)
{
	SDL_Event	event;
	int		pass;

	pass = 1;
	while (pass)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			pass = 0;
	}
}

void	error(void)
{
	ft_dprintf(2, "Initializing Error!:\n%s\n", SDL_GetError());
	exit(EXIT_FAILURE);
}

SDL_Surface	*put_header(SDL_Surface *screen)
{
	SDL_Surface	*header;
	SDL_Rect	header_pos;

	header = SDL_CreateRGBSurface(SDL_HWSURFACE, 1400, 100, 32, 0, 0, 0, 0);
	header_pos.x = 0;
	header_pos.y = 0;
	SDL_FillRect(header, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	SDL_BlitSurface(header, NULL, screen, &header_pos);
	return (header);
}

SDL_Surface	*put_arena(SDL_Surface *screen)
{
	SDL_Surface	*arena;
	SDL_Rect	arena_pos;

	arena = SDL_CreateRGBSurface(SDL_HWSURFACE, 600, 600, 32, 0, 0, 0, 0);
	arena_pos.x = (1400 / 2) - (600 / 2);
	arena_pos.y = (1000 / 2) - (600 / 2);
	SDL_FillRect(arena, NULL, SDL_MapRGB(screen->format, 200, 200, 200));
	SDL_BlitSurface(arena, NULL, screen, &arena_pos);
	return (arena);
}

SDL_Surface	*put_background(SDL_Surface *screen)
{
	SDL_Surface	*bk_img;
	SDL_Rect	bk_img_pos;

	bk_img = IMG_Load("img/arena.jpg");
	bk_img_pos.x = 0;
	bk_img_pos.y = 100;
	SDL_BlitSurface(bk_img, NULL, screen, &bk_img_pos);
	return (bk_img);
}

void	free_quit(SDL_Surface *a, SDL_Surface *b, SDL_Surface *c)
{
	SDL_FreeSurface(a);
	SDL_FreeSurface(b);
	SDL_FreeSurface(c);
	SDL_Quit();
}

int	main(void)
{
	SDL_Surface	*screen;
	SDL_Surface	*header;
	SDL_Surface	*bk_img;
	SDL_Surface	*arena;
	//SDL_Event	event;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
		error();
	if (!(screen = SDL_SetVideoMode(1400, 1000, 32, SDL_SWSURFACE)))
		error();
	SDL_WM_SetIcon(IMG_Load("img/icon.png"), NULL);
	SDL_WM_SetCaption("Bring Your Filler And Let's Fight!", "Filler Fights");
	bk_img = put_background(screen);
	header = put_header(screen);
	arena = put_arena(screen);

	SDL_Flip(screen);

	wait_close();

	free_quit(bk_img, header, arena);
	return (EXIT_SUCCESS);
}
