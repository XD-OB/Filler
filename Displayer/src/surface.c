/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:01:00 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/02 20:06:34 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static SDL_Surface	*put_header(t_visual *v)
{
	SDL_Surface		*header;
	SDL_Rect		pos;

	header = SDL_CreateRGBSurface(0, WIN_WIDTH, 90, 32, 0, 0, 0, 0);
	pos.x = 0;
	pos.y = 0;
	SDL_FillRect(header, NULL, SDL_MapRGB(header->format, 200, 200, 200));
	SDL_BlitSurface(header, NULL, v->screen, &pos);
	SDL_UpdateWindowSurface(v->window);
	return (header);
}

static SDL_Surface	*put_arena(t_visual *v)
{
	SDL_Surface		*arena;
	SDL_Rect		arena_pos;

	arena = SDL_CreateRGBSurface(0, 598, 600, 32, 0, 0, 0, 0);
	arena_pos.x = (WIN_WIDTH / 2) - (600 / 2);
	arena_pos.y = (WIN_HEIGHT / 2) - (600 / 2);
	SDL_FillRect(arena, NULL, SDL_MapRGB(arena->format, 200, 200, 200));
	SDL_BlitSurface(arena, NULL, v->screen, &arena_pos);
	SDL_UpdateWindowSurface(v->window);
	return (arena);
}

static SDL_Surface	*put_background(t_visual *v)
{
	SDL_Surface		*bk_img;
	SDL_Rect		bk_img_pos;

	bk_img = IMG_Load(BK_IMG);
	bk_img_pos.x = 0;
	bk_img_pos.y = 90;
	SDL_BlitSurface(bk_img, NULL, v->screen, &bk_img_pos);
	SDL_UpdateWindowSurface(v->window);
	return (bk_img);
}

static void			color_mode1(SDL_Color *color_p1, SDL_Color *color_p2)
{
	color_p1->r = 213;
	color_p1->g = 174;
	color_p1->b = 65;
	color_p2->r = 97;
	color_p2->g = 85;
	color_p2->b = 80;
}

void				put_pieces(t_visual *visual, int ac, char **av)
{
	if (ac > 1 && !ft_strcmp(av[1], "mode1"))
		color_mode1(&(visual->color_p1), &(visual->color_p2));
	else if (ac > 1 && !ft_strcmp(av[1], "mode2"))
	{
		visual->color_p1.r = 233;
		visual->color_p1.g = 75;
		visual->color_p1.b = 60;
		visual->color_p2.r = 0;
		visual->color_p2.g = 165;
		visual->color_p2.b = 145;
	}
	else
	{
		visual->color_p1.r = 254;
		visual->color_p1.g = 132;
		visual->color_p1.b = 14;
		visual->color_p2.r = 0;
		visual->color_p2.g = 110;
		visual->color_p2.b = 109;
	}
	visual->bk_img = put_background(visual);
	visual->header = put_header(visual);
	visual->arena = put_arena(visual);
}
