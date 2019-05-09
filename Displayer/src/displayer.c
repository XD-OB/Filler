/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:35:56 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/09 01:06:21 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void		draw_it(t_visual *v, char *str, int level, SDL_Surface **block)
{
	SDL_Rect	pos;
	int			i;

	i = -1;
	while (++i < v->width)
	{
		v->blocks[level * v->width + i] = NULL;
		if (str[i] == 'x' || str[i] == 'o')
		{
			v->blocks[level * v->width + i] = SDL_CreateRGBSurface(0,
					BLOCK(v->width), BLOCK(v->height), 32, 0, 0, 0, 0);
			pos.y = level * (BLOCK(v->height) + 1) + 200;
			pos.x = i * (BLOCK(v->width) + 1) + 400;
			if (str[i] == 'x')
				SDL_FillRect(block[level * v->width + i], NULL,
					SDL_MapRGB(v->header->format, v->color_p2.r,
						v->color_p2.g, v->color_p2.b));
			else if (str[i] == 'o')
				SDL_FillRect(block[level * v->width + i], NULL,
					SDL_MapRGB(v->header->format, v->color_p1.r,
						v->color_p1.g, v->color_p1.b));
			SDL_BlitSurface(block[level * v->width + i], NULL, v->screen, &pos);
			SDL_UpdateWindowSurface(v->window);
		}
	}
}

/*
**	i:	0:i		1:j		2:ret
*/

static int		return_update(t_visual *v, SDL_Event *event)
{
	if (event_trigger(event))
		return (1);
	if (visual_score(v))
		return (0);
	return (2);
}

int				update_screen(t_visual *v)
{
	SDL_Event	event;
	char		*line;
	int			i[3];

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
		if ((i[2] = return_update(v, &event)) != 2)
			return (i[2]);
	}
	return (0);
}

SDL_Rect		rec_point(int y, int x)
{
	SDL_Rect	p;

	p.y = y;
	p.x = x;
	return (p);
}

void			display_players(t_visual *v)
{
	TTF_Font	*font;
	SDL_Rect	pos_p;
	char		*line;
	int			i;

	i = -1;
	font = TTF_OpenFont(FONT_TYPE, FONT_SIZE);
	while (++i < 6)
	{
		get_next_line(0, &line);
		free(line);
	}
	pos_p = rec_point(0, 80);
	v->player1 = player_name();
	v->text_p1 = TTF_RenderText_Blended(font, v->player1, v->color_p1);
	SDL_BlitSurface(v->text_p1, NULL, v->screen, &pos_p);
	get_next_line(0, &line);
	free(line);
	v->player2 = player_name();
	pos_p = rec_point(0, 1380 - ((int)ft_strlen(v->player2) * 40));
	v->text_p2 = TTF_RenderText_Blended(font, v->player2, v->color_p2);
	SDL_BlitSurface(v->text_p2, NULL, v->screen, &pos_p);
	SDL_UpdateWindowSurface(v->window);
	TTF_CloseFont(font);
}
