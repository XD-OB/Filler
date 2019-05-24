/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:59:53 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 05:21:40 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		size_token(t_filler *filler)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	if (ft_strncmp(line, "Piece ", 6))
	{
		free_filler(filler);
		free(line);
		return (0);
	}
	filler->token_y = ft_atoi(&line[6]);
	i = 7;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	filler->token_x = ft_atoi(&line[i]);
	free(line);
	return (1);
}

static int		take_token(t_filler *filler)
{
	char		*line;
	int			i;

	if (!(filler->token =
		(char**)malloc(sizeof(char*) * (filler->token_y + 1))))
	{
		free_filler(filler);
		return (0);
	}
	filler->token[filler->token_y] = NULL;
	i = 0;
	while (i < filler->token_y)
	{
		get_next_line(0, &line);
		filler->token[i] = ft_strdup(line);
		free(line);
		i++;
	}
	return (1);
}

static void		set_token(t_filler *filler)
{
	char		**new_token;
	int			i;

	if (!(new_token =
		(char**)malloc(sizeof(char*) * (filler->token_y + 1))))
		return ;
	new_token[filler->token_y] = NULL;
	i = 0;
	while (i < filler->token_y)
	{
		new_token[i] = ft_strdup(filler->token[i]);
		i++;
	}
	free_tabstr(&filler->token);
	filler->token = new_token;
}

static void		real_token(t_filler *filler)
{
	int			i;
	int			j;

	i = filler->token_y;
	while (--i >= 0 && (is_allpoint(filler->token[i])))
		filler->token_y--;
	j = filler->token_x;
	while (--j >= 0)
	{
		i = filler->token_y - 1;
		while (i >= 0 && filler->token[i][j] == '.')
			i--;
		if (i == -1)
		{
			i = filler->token_y;
			while (--i >= 0)
				filler->token[i][j] = '\0';
			filler->token_x--;
		}
		else
			break ;
	}
}

int				get_token(t_filler *filler)
{
	int		i;
	int		j;

	if (!size_token(filler))
		return (0);
	if (!(take_token(filler)))
		return (0);
	real_token(filler);
	set_token(filler);
	i = -1;
	filler->begin_y = 0;
	while (++i < filler->token_y && is_allpoint(filler->token[i]))
		filler->begin_y++;
	i = -1;
	filler->begin_x = filler->token_x;
	while (++i < filler->token_y)
	{
		j = 0;
		while (j < filler->token_x && filler->token[i][j] == '.')
			j++;
		filler->begin_x = ft_min(j, filler->begin_x);
	}
	return (1);
}
