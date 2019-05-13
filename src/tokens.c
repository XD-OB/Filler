/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 00:59:05 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/13 02:00:15 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void		init_token_size(t_filler *filler)
{
	int			i;
	char		*line;

	i = 6;
	get_next_line(0, &line);
	filler->token_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	filler->token_x = ft_atoi(&line[i]);
	free(line);
}

static void		real_token(char ***token, t_filler *filler)
{
	int			i;
	int			j;

	i = filler->token_y;
	while (--i >= 0 && (is_allpoint((*token)[i])))
	{
		(filler->token_y)--;
		free((*token)[i]);
	}
	j = filler->token_x;
	while (--j >= 0)
	{
		i = filler->token_y - 1;
		while (i >= 0 && (*token)[i][j] == '.')
			i--;
		if (i == -1)
		{
			i = filler->token_y;
			while (--i >= 0)
				(*token)[i][j] = '\0';
			(filler->token_x)--;
		}
		else
			break ;
	}
}

static void		open_token(char **token, t_filler *filler)
{
	int			i;
	int			j;

	i = -1;
	filler->begin_y = 0;
	while (++i < filler->token_y && is_allpoint(token[i]))
		filler->begin_y++;
	i = -1;
	filler->begin_x = filler->token_x;
	while (++i < filler->token_y)
	{
		j = 0;
		while (j < filler->token_x && token[i][j] == '.')
			j++;
		filler->begin_x = ft_min(j, filler->begin_x);
	}
}

char			**get_token(t_filler *filler)
{
	char		**token;
	char		*line;
	int			i;

	i = -1;
	init_token_size(filler);
	token = (char**)malloc(sizeof(char*) * filler->token_y);
	while (++i < filler->token_y)
	{
		get_next_line(0, &line);
		token[i] = ft_strdup(line);
		free(line);
	}
	real_token(&token, filler);
	open_token(token, filler);
	return (token);
}
