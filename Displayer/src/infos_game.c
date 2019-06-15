/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:20:58 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 09:59:01 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static int		skip_header(void)
{
	char		*line;
	int			ret;
	int			i;

	i = 0;
	while (i < 6)
	{
		if ((ret = get_next_line(0, &line)) <= 0)
		{
			if (ret == 0)
				free(line);
			ft_dprintf(2, "Displayer: Bad file\n");
			return (0);
		}
		free(line);
		i++;
	}
	return (1);
}

static char		*get_filler_name(char *line)
{
	int			i;

	i = 0;
	while (line[i] && line[i] != ']')
		i++;
	if (ft_strstr(line, ".filler"))
	{
		while (i > 0 && line[i] != '.')
			i--;
		line[i] = '\0';
		i--;
	}
	while (i > 0 && line[i] != '/')
		i--;
	return (ft_strdup(&line[i + 1]));
}

static int		bad_player(char **line)
{
	free(*line);
	ft_dprintf(2, "Displayer: Bad player\n");
	return (0);
}

int				get_players(t_display *display)
{
	char		*line;

	if (!skip_header())
		return (0);
	get_next_line(0, &line);
	if (!ft_strncmp(line, "$$$ exec p1 : [", 15))
		display->p1 = get_filler_name(&line[14]);
	else
		return (bad_player(&line));
	free(line);
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	if (!ft_strncmp(line, "$$$ exec p2 : [", 15))
		display->p2 = get_filler_name(&line[14]);
	else
		return (bad_player(&line));
	free(line);
	return (1);
}
