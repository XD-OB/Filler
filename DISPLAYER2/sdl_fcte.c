/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_fcte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 08:05:48 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 02:23:13 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

#define SDL_INIT_FLAGS	(SDL_INIT_VIDEO | SDL_INIT_AUDIO)
#define IMG_INIT_FLAGS	(IMG_INIT_PNG | IMG_INIT_JPG)

static int	error_manager(int type)
{
	if (type == 0)
	{
		ft_dprintf(2, "Error will Initialize the SDL: %s\n",
				SDL_GetError());
		return (0);
	}
	if (type == 1)
		ft_dprintf(2, "Error will Initialize the SDL_Image: %s\n",
				IMG_GetError());
	if (type == 2)
		ft_dprintf(2, "Error will Initialize the SDL_TTF: %s\n",
				TTF_GetError());
	if (type == 3)
		ft_dprintf(2, "Error will Opening Audio: %s\n",
				Mix_GetError());
	SDL_Quit();
	return (0);
}

int		init_sdl(void)
{
	if (SDL_Init(SDL_INIT_FLAGS) != 0)
		return (error_manager(0));
	if ((IMG_Init(IMG_INIT_FLAGS) & IMG_INIT_FLAGS)
			!= IMG_INIT_FLAGS)
		return (error_manager(1));
	if (TTF_Init() == -1)
		return (error_manager(2));
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		return (error_manager(3));
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
	Mix_PlayMusic(display->music, -1);
	return (1);
}

SDL_Texture			*load_img(char *path, SDL_Renderer *renderer)
{
	SDL_Surface		*tmp;
	SDL_Texture		*texture;

	tmp = IMG_Load(BK_IMG);
	if (!tmp)
	{
		ft_dprintf(2, "Error: Can't Load the Image\n%s\n", IMG_GetError());
		return (NULL);
	}
	texture = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_FreeSurface(tmp);
	if (!texture)
	{
		ft_dprintf(2, "Error: Can't Create the Texture\n %s\n", SDL_GetError());
		return (NULL);
	}
	return (texture);
}

SDL_Rect			ft_rect(int height, int width, int y, int x)
{
	SDL_Rect		rect;

	rect.h = height;
	rect.w = width;
	rect.y = y;
	rect.x = x;
	return (rect);
}
