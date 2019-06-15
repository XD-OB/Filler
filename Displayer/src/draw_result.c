/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_result.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:55:01 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 20:44:57 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static void	display_score2(t_display *display)
{
	SDL_Texture	*texture;
	SDL_Surface	*tmp;
	SDL_Rect	p;
	TTF_Font	*font;
	char		*str[2];

	font = TTF_OpenFont("./Fonts/arial.ttf", 60);
	str[0] = ft_itoa(display->score_p2);
	str[1] = str[0];
	str[0] = ft_strjoin("score: ", str[0]);
	free(str[1]);
	tmp = TTF_RenderText_Blended(font, str[0],
			display->color_p2[display->clr]);
	free(str[0]);
	texture = SDL_CreateTextureFromSurface(display->render, tmp);
	SDL_FreeSurface(tmp);
	SDL_QueryTexture(texture, NULL, NULL, &p.w, &p.h);
	p.x = WIDTH - WIDTH / 20 - p.w;
	p.y = HEIGHT / 6;
	SDL_RenderCopy(display->render, texture, NULL, &p);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
}

static void	display_score1(t_display *display)
{
	SDL_Texture	*texture;
	SDL_Surface	*tmp;
	SDL_Rect	p;
	TTF_Font	*font;
	char		*str[2];

	font = TTF_OpenFont("./Fonts/arial.ttf", 60);
	str[0] = ft_itoa(display->score_p1);
	str[1] = str[0];
	str[0] = ft_strjoin("score: ", str[0]);
	free(str[1]);
	tmp = TTF_RenderText_Blended(font, str[0],
			display->color_p1[display->clr]);
	free(str[0]);
	texture = SDL_CreateTextureFromSurface(display->render, tmp);
	SDL_FreeSurface(tmp);
	SDL_QueryTexture(texture, NULL, NULL, &p.w, &p.h);
	p.x = WIDTH / 20;
	p.y = HEIGHT / 6;
	SDL_RenderCopy(display->render, texture, NULL, &p);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
}

static void	display_winner(t_display *display)
{
	SDL_Texture	*texture;
	SDL_Surface	*tmp;
	SDL_Color	color;
	TTF_Font	*font;
	SDL_Rect	p;

	font = TTF_OpenFont(FONT_WTYPE, FONT_WSIZE);
	color = (display->score_p1 > display->score_p2) ?
		display->color_p1[display->clr] :
		display->color_p2[display->clr];
	tmp = TTF_RenderText_Blended(font, "WIN!", color);
	texture = SDL_CreateTextureFromSurface(display->render, tmp);
	SDL_FreeSurface(tmp);
	SDL_QueryTexture(texture, NULL, NULL, &p.w, &p.h);
	p.x = (WIDTH - p.w) / 2;
	p.y = 10;
	SDL_RenderCopy(display->render, texture, NULL, &p);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
}

void		draw_result(t_display *display, t_movie *curr)
{
	draw_current(display, curr);
	display_winner(display);
	display_score1(display);
	display_score2(display);
	display->pause = 1;
	SDL_RenderPresent(display->render);
}
