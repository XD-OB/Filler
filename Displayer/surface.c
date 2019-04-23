#include "display.h"

static SDL_Surface	*put_header(SDL_Surface *screen)
{
	SDL_Surface	*header;
	SDL_Rect	header_pos;

	header = SDL_CreateRGBSurface(SDL_HWSURFACE, WIN_WIDTH, 100, 32, 0, 0, 0, 0);
	header_pos.x = 0;
	header_pos.y = 0;
	SDL_FillRect(header, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	SDL_BlitSurface(header, NULL, screen, &header_pos);
	return (header);
}

static SDL_Surface	*put_arena(SDL_Surface *screen)
{
	SDL_Surface	*arena;
	SDL_Rect	arena_pos;

	arena = SDL_CreateRGBSurface(SDL_HWSURFACE, 600, 600, 32, 0, 0, 0, 0);
	arena_pos.x = (WIN_WIDTH / 2) - (600 / 2);
	arena_pos.y = (WIN_HEIGHT / 2) - (600 / 2);
	SDL_FillRect(arena, NULL, SDL_MapRGB(screen->format, 200, 200, 200));
	SDL_BlitSurface(arena, NULL, screen, &arena_pos);
	return (arena);
}

static SDL_Surface	*put_background(SDL_Surface *screen)
{
	SDL_Surface	*bk_img;
	SDL_Rect	bk_img_pos;

	bk_img = IMG_Load(BK_IMG);
	bk_img_pos.x = 0;
	bk_img_pos.y = 100;
	SDL_BlitSurface(bk_img, NULL, screen, &bk_img_pos);
	return (bk_img);
}

void			put_pieces(t_visual *visual)
{
	visual->color_p1.r = 0;
	visual->color_p1.g = 0;
	visual->color_p1.b = 255;
	visual->color_p2.r = 0;
	visual->color_p2.g = 255;
	visual->color_p2.b = 0;
	visual->bk_img = put_background(visual->screen);
	visual->header = put_header(visual->screen);
	visual->arena = put_arena(visual->screen);
}
