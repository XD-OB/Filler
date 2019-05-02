/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:23:04 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/02 21:28:05 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "../filler.h"
# include "./SDL/SDL.h"
# include "./SDL/SDL_image.h"
# include "./SDL/SDL_ttf.h"

# define WIN_WIDTH 1400
# define WIN_HEIGHT 1000

# define BLOCK(x) (600 / x - 1)

# define ICON_IMG "./Displayer/img/icon.png"
# define ICON_TITLE "Bring Your Filler And Let's Fight!"
# define ICON_ATTR "Filler Fights"

# define BK_IMG "./Displayer/img/war.jpg"

# define FONT_TYPE "./Displayer/Fonts/nadiasofia.ttf"
# define FONT_SIZE 70
# define FONT_WTYPE "./Displayer/Fonts/GROBOLD.ttf"
# define FONT_WSIZE 40

typedef struct		s_visual
{
	SDL_Window		*window;
	SDL_Surface		*screen;
	SDL_Renderer	*renderer;
	SDL_Surface		*header;
	SDL_Surface		*bk_img;
	SDL_Surface		*arena;
	SDL_Surface		**blocks;
	int				width;
	int				height;
	SDL_Surface		*text_p1;
	SDL_Surface		*text_p2;
	SDL_Surface		*win;
	char			*player1;
	char			*player2;
	SDL_Color		color_p1;
	SDL_Color		color_p2;
}					t_visual;

void				put_pieces(t_visual *visual, int ac, char **av);
void				free_all(t_visual **visual);
char				*player_name(void);
void				space_pause(SDL_Event *event);
void				pas_pause(void);
int					visual_score(t_visual *v);
void				event_trigger(SDL_Event *event);
void				wait_close(void);
void				display_players(t_visual *v);
void				update_screen(t_visual *v);

#endif
