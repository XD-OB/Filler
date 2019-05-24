/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 05:31:17 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 08:50:27 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DISPLAYER_H
# define DISPLAYER_H

# include "../libft/libft.h"
# include "stdlib.h"
# include ".brew/include/SDL2/SDL.h"
# include ".brew/include/SDL2/SDL_image.h"

# define WIDTH 1200
# define HEIGHT 800

# define TITLE "Bring Your Filler And Let's Fight!"

typedef struct			s_display
{
	SDL_Window			*window;
	SDL_Renderer		*render;
	char				*p1;
	char				*p2;
}						t_display;

typedef struct			s_movie
{
	char				**map;
	char				**token;
	struct s_movie		*prev;
	struct s_movie		*next;
}						t_movie;

int						init_sdl(void);
int						create_window_render(t_display *display);
void					free_sdl(t_display *display);

#endif
