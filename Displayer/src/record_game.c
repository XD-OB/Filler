/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:16:12 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 09:04:48 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static char		*ft_read_line(void)
{
	char	*line;
	char	*res;

	get_next_line(0, &line);
	res = ft_strdup(&line[4]);
	free(line);
	return (res);
}

static int		get_score(t_display *display, char **line)
{
	if (!ft_strncmp(*line, "== ", 3))
	{
		display->score_p1 = ft_atoi(&(*line)[10]);
		free(*line);
		if (get_next_line(0, line) <= 0)
		{
			free(*line);
			return (1);
		}
		display->score_p2 = ft_atoi(&(*line)[10]);
		free(*line);
		return (1);
	}
	return (0);
}

static int		parser_game(t_display *display, t_movie **node)
{
	char	*line;
	int		i;

	if (!((*node)->map = (char**)malloc(sizeof(char*) * (display->map_h + 1))))
		return (-1);
	(*node)->map[display->map_h] = NULL;
	i = -1;
	while (++i < display->map_h)
		(*node)->map[i] = ft_read_line();
	get_next_line(0, &line);
	while (ft_strncmp(line, "Plateau ", 8))
	{
		if (get_score(display, &line))
			return (0);
		free(line);
		get_next_line(0, &line);
	}
	free(line);
	get_next_line(0, &line);
	free(line);
	return (1);
}

static int		get_dimension(t_display *display)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	if (ft_strncmp(line, "Plateau ", 8))
	{
		free(line);
		return (0);
	}
	display->map_h = ft_atoi(&line[8]);
	i = 9;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	display->map_w = ft_atoi(&line[i + 1]);
	free(line);
	get_next_line(0, &line);
	free(line);
	return (1);
}

int				record_game(t_display *display)
{
	t_movie	*node;
	int		pass;

	display->movie = NULL;
	if (!get_players(display))
		return (0);
	if (!get_dimension(display))
		return (0);
	pass = 1;
	while (pass)
	{
		node = ft_movie_addnode(&display->movie);
		if (node == NULL)
		{
			free_movie(&display->movie);
			return (0);
		}
		if ((pass = parser_game(display, &node)) == -1)
		{
			free_movie(&display->movie);
			return (0);
		}
	}
	return (1);
}
