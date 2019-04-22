#include "visual.h"

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

	bk_img = IMG_Load("./Visualizer/img/arena.jpg");
	bk_img_pos.x = 0;
	bk_img_pos.y = 100;
	SDL_BlitSurface(bk_img, NULL, screen, &bk_img_pos);
	return (bk_img);
}
