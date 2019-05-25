/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_result.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:55:01 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 08:59:10 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static void	ft_strprecombin(char *s1, char **s2)
{
	char	*new;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(*s2);
	new = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	new[len_s1 + len_s2] = '\0';
	i = -1;
	while (++i < len_s1)
		new[i] = s1[i];
	j = 0;
	while (j < len_s2)
		new[i++] = (*s2)[j++];
	free(*s2);
	*s2 = new;
}

static void	display_score2(t_display *display)
{
	SDL_Texture	*texture;
	SDL_Surface	*tmp;
	SDL_Rect	p;
	TTF_Font	*font;
	char		*str;

	font = TTF_OpenFont("./Fonts/arial.ttf", 60);
	str = ft_itoa(display->score_p2);
	str = ft_strjoin("score: ", str);
	tmp = TTF_RenderText_Blended(font, str,
			display->color_p2[display->clr]);
	free(str);
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
	char		*str;

	font = TTF_OpenFont("./Fonts/arial.ttf", 60);
	str = ft_itoa(display->score_p1);
	str = ft_strjoin("score: ", str);
	tmp = TTF_RenderText_Blended(font, str,
			display->color_p1[display->clr]);
	free(str);
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
