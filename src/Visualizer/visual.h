#ifndef	VISUAL_H
# define VISUAL_H

#include "../../filler.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

SDL_Surface	*put_background(SDL_Surface *screen);
SDL_Surface	*put_header(SDL_Surface *screen);
SDL_Surface	*put_arena(SDL_Surface *screen);

#endif
