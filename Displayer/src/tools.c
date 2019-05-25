/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 08:05:48 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 09:08:15 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void	free_sdl(t_display *display)
{
	Mix_CloseAudio();
	TTF_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(display->render);
	SDL_DestroyWindow(display->window);
	SDL_Quit();
}

int		load_music(t_display *display)
{
	display->music = Mix_LoadMUS(BK_MUSIC);
	if (!display->music)
	{
		ft_dprintf(2, "Error will Loading the Music: %s\n",
				Mix_GetError());
		return (0);
	}
	Mix_PlayMusic(display->music, display->mute);
	return (1);
}

void	free_movie(t_movie **head)
{
	t_movie		*tmp;

	while (*head)
	{
		tmp = *head;
		free_tabstr(&tmp->map);
		tmp->prev = NULL;
		(*head) = (*head)->next;
		free(tmp);
	}
}

void	free_node(t_movie *movie)
{
	free_tabstr(&movie->map);
	movie->prev->next = movie->next;
	movie->next->prev = movie->prev;
	free(movie);
}

void	free_display(t_display *display)
{
	free(display->p1);
	free(display->p2);
	free_movie(&(display->movie));
}
