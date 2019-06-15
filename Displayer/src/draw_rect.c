/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 05:06:31 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 09:19:55 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static int		draw_x_rect(t_display *display, t_movie *curr,
						int *tab, SDL_Rect rect)
{
	int			i;
	int			j;

	i = tab[0];
	j = tab[1];
	if (curr->map[i][j] == 'X')
	{
		SDL_SetRenderDrawColor(display->render,
				display->color_p2[display->clr].r,
				display->color_p2[display->clr].g,
				display->color_p2[display->clr].b, 255);
		SDL_RenderFillRect(display->render, &rect);
		return (1);
	}
	if (curr->map[i][j] == 'x')
	{
		SDL_SetRenderDrawColor(display->render,
				display->color_p22[display->clr].r,
				display->color_p22[display->clr].g,
				display->color_p22[display->clr].b, 255);
		SDL_RenderFillRect(display->render, &rect);
		return (1);
	}
	return (0);
}

static int		draw_o_rect(t_display *display, t_movie *curr,
						int *tab, SDL_Rect rect)
{
	int			i;
	int			j;

	i = tab[0];
	j = tab[1];
	if (curr->map[i][j] == 'O')
	{
		SDL_SetRenderDrawColor(display->render,
				display->color_p1[display->clr].r,
				display->color_p1[display->clr].g,
				display->color_p1[display->clr].b, 255);
		SDL_RenderFillRect(display->render, &rect);
		return (1);
	}
	if (curr->map[i][j] == 'o')
	{
		SDL_SetRenderDrawColor(display->render,
				display->color_p11[display->clr].r,
				display->color_p11[display->clr].g,
				display->color_p11[display->clr].b, 255);
		SDL_RenderFillRect(display->render, &rect);
		return (1);
	}
	return (0);
}

void			draw_rect(t_display *display, t_movie *curr,
						int i, int j)
{
	SDL_Rect	rect;
	int			tab[2];

	tab[0] = i;
	tab[1] = j;
	rect = ft_rect(BLOCK(display->map_h),
			BLOCK(display->map_w),
			i * (rect.h + 1) + ((HEIGHT - 600) / 2),
			j * (rect.w + 1) + ((WIDTH - 600) / 2));
	if (draw_x_rect(display, curr, tab, rect))
		return ;
	else if (draw_o_rect(display, curr, tab, rect))
		return ;
	else
	{
		SDL_SetRenderDrawColor(display->render, 240, 240, 240, 255);
		SDL_RenderFillRect(display->render, &rect);
	}
}
