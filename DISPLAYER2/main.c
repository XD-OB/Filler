/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 05:29:31 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 09:00:36 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

char	*get_filler_name(char *line)
{
	int		i;

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

int	skip_header(void)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 6)
	{
		if (get_next_line(0, &line) <= 0)
		{
			ft_dprintf(2, "Displayer: Bad file\n");
			return (0);
		}
		free(line);
		i++;
	}
	return (1);
}

int	bad_player(char **line)
{
	free(*line);
	ft_dprintf(2, "Displayer: Bad player\n");
	return (0);
}

int			get_players(t_display *display)
{
	char	*line;
	int		i;

	if (!skip_header())
		return (0);
	get_next_line(0, &line);
	if (!ft_strncmp(line, "$$$ exec p1 : [", 15))
	{
		display->p1 = get_filler_name(&line[14]);
		free(line);
	}
	else
		return (bad_player(&line));
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	if (!ft_strncmp(line, "$$$ exec p2 : [", 15))
	{
		display->p2 = get_filler_name(&line[14]);
		free(line);
	}
	else
		return (bad_player(&line));
	ft_putendl(display->p1);
	ft_putendl(display->p2);
	return (1);
}

void	free_display(t_display *display)
{
	free(display->p1);
	free(display->p2);
}

t_movie	*add_part(t_movie *prev)
{
	t_movie		*node;

	node = (t_movie*)malloc(sizeof(t_movie));
	node->next = NULL;
	node->prev = prev;
}

int		main(int ac, char **av)
{
	t_display	display;
	t_movie		*begin;

	if (!get_players(&display))
		return (EXIT_FAILURE);
	begin = add_part(NULL);
	while (get_next_line(0, &line) > 0 && !ft_strncmp(line, "Plateau"))
	{
		charge_movie(begin);
		begin = begin->next;
	}
	/*if (!init_sdl())
		return (EXIT_FAILURE);
	if (!create_window_render(&display))
		return (EXIT_FAILURE);
	SDL_Delay(3000);
	free_sdl(&display);*/
	//free(&display);
	return (EXIT_SUCCESS);
}
