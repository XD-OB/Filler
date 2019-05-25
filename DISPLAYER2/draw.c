/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 07:17:59 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 08:59:29 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void		draw_current(t_display *display, t_movie *curr)
{
	int		i;
	int		j;

	put_pieces(display);
	if (curr)
	{
		i = -1;
		while (++i < display->map_h)
		{
			j = -1;
			while (++j < display->map_w)
				draw_rect(display, curr, i, j);
		}
	}
	SDL_RenderPresent(display->render);
}

void		draw_next(t_display *display, t_movie **curr)
{
	if (!(*curr)->next)
		draw_result(display, *curr);
	if ((*curr)->next)
	{
		*curr = (*curr)->next;
		draw_current(display, *curr);
	}
}

void		draw_prev(t_display *display, t_movie **curr)
{
	if ((*curr)->prev)
	{
		*curr = (*curr)->prev;
		draw_current(display, *curr);
	}
}



