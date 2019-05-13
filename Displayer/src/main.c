/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:32:39 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/13 01:13:23 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void			map_size(int *height, int *width)
{
	char		*line;
	int			i;

	i = -1;
	get_next_line(0, &line);
	while (line[i] != ' ')
		i++;
	i++;
	*height = ft_atoi(&line[i]);
	while (isdigit(line[i]))
		i++;
	*width = ft_atoi(&line[i]);
	free(line);
}

int				main(int ac, char **av)
{
	t_visual	*visual;

	if (!(visual = (t_visual*)malloc(sizeof(t_visual))))
		return (EXIT_FAILURE);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
		return (EXIT_FAILURE);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	visual->music = Mix_LoadMUS(BK_MUSIC);
	visual->window = SDL_CreateWindow(ICON_TITLE, 200, 200,
			WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_RESIZABLE);
	visual->screen = SDL_GetWindowSurface(visual->window);
	Mix_PlayMusic(visual->music, -1);
	put_pieces(visual, ac, av);
	SDL_UpdateWindowSurface(visual->window);
	display_players(visual);
	map_size(&(visual->height), &(visual->width));
	if (update_screen(visual))
		return (EXIT_SUCCESS);
	SDL_UpdateWindowSurface(visual->window);
	wait_close();
	free_all(&visual);
	return (EXIT_SUCCESS);
}
