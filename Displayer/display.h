#ifndef	VISUAL_H
# define VISUAL_H

#include "../filler.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

# define WIN_WIDTH 1400
# define WIN_HEIGHT 1000

# define ICON_IMG "./Displayer/img/icon.png"
# define ICON_TITLE "Bring Your Filler And Let's Fight!"
# define ICON_ATTR "Filler Fights"

# define BK_IMG "./Displayer/img/war.jpg"

# define FONT_TYPE "./Displayer/Fonts/nadiasofia.ttf"
# define FONT_SIZE 80

typedef struct		s_visual
{
	SDL_Surface	*screen;
	SDL_Surface	*header;
	SDL_Surface	*bk_img;
	SDL_Surface	*arena;
	int		width;
	int		height;
	SDL_Surface	*text_p1;
	SDL_Surface	*text_p2;
	char		*player1;
	char		*player2;
	SDL_Color	color_p1;
	SDL_Color	color_p2;
}			t_visual;

void			put_pieces(t_visual *visual);
void			free_all(t_visual **visual);
void			error(char *error);
char			*player_name(void);

#endif
