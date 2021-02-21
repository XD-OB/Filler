/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 02:18:43 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 10:31:40 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void				display_players(t_display *display)
{
	TTF_Font		*font;
	SDL_Surface		*tmp;
	SDL_Texture		*text;
	SDL_Rect		pos;
	int				i;

	i = 0;
	font = TTF_OpenFont(FONT_TYPE, FONT_SIZE);
	tmp = TTF_RenderText_Blended(font, display->p1,
			display->color_p1[display->clr]);
	text = SDL_CreateTextureFromSurface(display->render, tmp);
	pos = ft_rect(0, 0, 8, 100);
	SDL_QueryTexture(text, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(display->render, text, NULL, &pos);
	SDL_FreeSurface(tmp);
	SDL_DestroyTexture(text);
	tmp = TTF_RenderText_Blended(font, display->p2,
			display->color_p2[display->clr]);
	text = SDL_CreateTextureFromSurface(display->render, tmp);
	SDL_QueryTexture(text, NULL, NULL, &pos.w, &pos.h);
	pos.y = 8;
	pos.x = WIDTH - 100 - pos.w;
	SDL_RenderCopy(display->render, text, NULL, &pos);
	SDL_FreeSurface(tmp);
	SDL_DestroyTexture(text);
}

void				put_scene(t_display *display)
{
	SDL_Texture		*bk_texture;
	SDL_Rect		rect;

	bk_texture = load_img(BK_IMG, display->render);
	SDL_RenderCopy(display->render, bk_texture, NULL, NULL);
	SDL_DestroyTexture(bk_texture);
	rect = ft_rect(HEIGHT / 10, WIDTH - WIDTH / 25, 0, WIDTH / 50);
	SDL_SetRenderDrawColor(display->render, 200, 200, 200, 255);
	SDL_RenderFillRect(display->render, &rect);
	rect = ft_rect(BOX, BOX, (HEIGHT / 2) - BOX/2, (WIDTH / 2) - BOX/2);
	SDL_SetRenderDrawColor(display->render, 200, 200, 200, 255);
	SDL_RenderFillRect(display->render, &rect);
}
