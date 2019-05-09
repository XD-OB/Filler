/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:59:55 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/02 20:00:55 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static SDL_Color	color_win(int s_p1, int s_p2, t_visual *v)
{
	SDL_Color		color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	if (s_p1 > s_p2)
	{
		ft_printf("\n%{GREEN}P1 ** WIN **%{eoc}\n");
		ft_printf("%{RED}P2    LOSE  %{eoc}\n");
		return (v->color_p1);
	}
	else if (s_p1 < s_p2)
	{
		ft_printf("\n%{RED}P1    LOSE  %{eoc}\n");
		ft_printf("%{GREEN}P2 ** WIN **%{eoc}\n");
		return (v->color_p2);
	}
	else
	{
		ft_printf("\n%{CYAN}P1 -EQUAL- P2%{eoc}\n");
		return (color);
	}
}

static void			score_board(t_visual *v, int s_p1, int s_p2)
{
	ft_printf("P1 :%{CYAN}%-11s ", v->player1);
	ft_printf("%{YELLOW}%d%{eoc}\n", s_p1);
	ft_printf("P2 :%{CYAN}%-11s ", v->player2);
	ft_printf("%{YELLOW}%d%{eoc}\n", s_p2);
}

/*
**	s_p:	score player	0: p1	1: p2
*/

static void			score_result(t_visual *v, char **line)
{
	SDL_Rect		pos_w;
	TTF_Font		*font;
	SDL_Color		color;
	int				s_p[2];

	font = TTF_OpenFont(FONT_WTYPE, FONT_WSIZE);
	s_p[0] = ft_atoi(&(*line)[10]);
	free(*line);
	get_next_line(0, line);
	s_p[1] = ft_atoi(&(*line)[10]);
	free(*line);
	score_board(v, s_p[0], s_p[1]);
	color = color_win(s_p[0], s_p[1], v);
	v->win = TTF_RenderText_Blended(font, "WIN!", color);
	pos_w.y = 20;
	pos_w.x = 650;
	SDL_BlitSurface(v->win, NULL, v->screen, &pos_w);
	SDL_UpdateWindowSurface(v->window);
	TTF_CloseFont(font);
}

int					visual_score(t_visual *v)
{
	char			*line;

	get_next_line(0, &line);
	while (ft_strncmp(line, "Plateau", 4) && ft_strncmp(line, "==", 2))
	{
		free(line);
		if (ft_strncmp(line, "==", 2))
			get_next_line(0, &line);
	}
	if (!ft_strncmp(line, "==", 2))
	{
		score_result(v, &line);
		return (1);
	}
	else
		free(line);
	SDL_UpdateWindowSurface(v->window);
	return (0);
}
