/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:20:51 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/11 23:46:36 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void		free_all(t_visual **visual)
{
	int		i;

	i = -1;
	while (++i < (*visual)->height * (*visual)->width)
	{
		if ((*visual)->blocks[i])
			SDL_FreeSurface((*visual)->blocks[i]);
	}
	SDL_FreeSurface((*visual)->arena);
	SDL_FreeSurface((*visual)->bk_img);
	SDL_FreeSurface((*visual)->header);
	SDL_FreeSurface((*visual)->win);
	free((*visual)->player1);
	free((*visual)->player2);
	Mix_FreeMusic((*visual)->music);
	free(*visual);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
}

char		*player_name(void)
{
	char	*line;
	char	*str;
	int		i;

	i = 3;
	get_next_line(0, &line);
	while (line[i] != ']')
		i++;
	while (line[i] != '.')
		i--;
	line[i] = '\0';
	while (line[i] != '/')
		i--;
	str = ft_strdup(&line[i + 1]);
	free(line);
	return (str);
}
