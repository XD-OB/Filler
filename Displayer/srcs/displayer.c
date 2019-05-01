#include "display.h"

static void	draw_it(t_visual *v, char *str, int level, SDL_Surface **block)
{
	SDL_Rect	pos;
	int		i;

	i = -1;
	while (++i < v->width)
	{
		v->blocks[level * v->width + i] = NULL;
		if (str[i] == 'x' || str[i] == 'o')
		{
			v->blocks[level * v->width + i] =
				SDL_CreateRGBSurface(SDL_HWSURFACE, BLOCK(v->width),
						BLOCK(v->height), 32, 0, 0, 0, 0);
			pos.y = level * (BLOCK(v->height) + 1) + 200;
			pos.x = i * (BLOCK(v->width) + 1) + 400;
			if (str[i] == 'x')
				SDL_FillRect(block[level * v->width + i], NULL,
					SDL_MapRGB(v->screen->format, 0, 255, 0));
			else if (str[i] == 'o')
				SDL_FillRect(block[level * v->width + i], NULL,
					SDL_MapRGB(v->screen->format, 0, 0, 255));
			SDL_BlitSurface(block[level * v->width + i], NULL,
					v->screen, &pos);
			SDL_Flip(v->screen);
		}
	}
}

/*
**	i:	0:i	1:j
*/

void	update_screen(t_visual *v)
{
	SDL_Event	event;
	char		*line;
	int		i[2];

	i[0] = -1;
	v->blocks = (SDL_Surface**)malloc(sizeof(SDL_Surface*)
			* (v->width * v->height));
	while (get_next_line(0, &line) > 0)
	{
		SDL_PollEvent(&event);
		free(line);
		i[0] = -1;
		while (++i[0] < v->height)
		{
			i[1] = 0;
			get_next_line(0, &line);
			while (line[i[1]] != ' ')
				i[1]++;
			draw_it(v, &line[++i[1]], i[0], v->blocks);
			free(line);
		}
		event_trigger(&event);
		if (visual_score(v))
			return ;
	}
}

void	display_players(t_visual *v)
{
	TTF_Font	*font;
	SDL_Rect	pos_p;
	char		*line;
	int		i;

	i = -1;
	font = TTF_OpenFont(FONT_TYPE, FONT_SIZE);
	while (++i < 6)
	{
		get_next_line(0, &line);
		free(line);
	}
	pos_p.y = 0;
	pos_p.x = 80;
	v->player1 = player_name();
	v->text_p1 = TTF_RenderText_Blended(font, v->player1, v->color_p1);
	SDL_BlitSurface(v->text_p1, NULL, v->screen, &pos_p);
	get_next_line(0, &line);
	free(line);
	v->player2 = player_name();
	pos_p.y = 0;
	pos_p.x = 1380 - ((int)ft_strlen(v->player2) * 40);
	v->text_p2 = TTF_RenderText_Blended(font, v->player2, v->color_p2);
	SDL_BlitSurface(v->text_p2, NULL, v->screen, &pos_p);
	TTF_CloseFont(font);
}
