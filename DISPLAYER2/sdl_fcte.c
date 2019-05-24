/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_fcte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 08:05:48 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 08:06:14 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

int		init_sdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		ft_dprintf(2, "Error will Initialize the SDL: %s\n",
				SDL_GetError());
		SDL_Quit();
		return (0);
	}
	return (1);
}

int		create_window_render(t_display *display)
{
	display->window = SDL_CreateWindow(
			TITLE,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WIDTH, HEIGHT, 0);
	if (!display->window)
	{
		ft_dprintf(2, "Error will creating the Window: %s\n",
				SDL_GetError());
		SDL_Quit();
		return (0);
	}
	display->render = SDL_CreateRenderer(
			display->window, -1,
			SDL_RENDERER_ACCELERATED);
	if (!display->render)
	{
		ft_dprintf(2, "Error will creating the Renderer %s\n",
				SDL_GetError());
		SDL_Quit();
		return (0);
	}
	return (1);
}

void	free_sdl(t_display *display)
{
	SDL_DestroyRenderer(display->render);
	SDL_DestroyWindow(display->window);
	SDL_Quit();
}
