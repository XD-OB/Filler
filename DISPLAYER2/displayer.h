/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 05:31:17 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 02:22:43 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DISPLAYER_H
# define DISPLAYER_H

# include "../libft/libft.h"
# include "stdlib.h"
# include ".brew/include/SDL2/SDL.h"
# include ".brew/include/SDL2/SDL_ttf.h"
# include ".brew/include/SDL2/SDL_mixer.h"
# include ".brew/include/SDL2/SDL_image.h"

# define WIDTH 1400 
# define HEIGHT 1000 

# define TITLE "Bring Your Filler And Let's Fight!"
# define BK_MUSIC "./music/war.ogg"
# define BK_IMG "./img/war.jpg"
# define FONT_TYPE	"./Fonts/nadiasofia.ttf"
# define FONT_SIZE	90

typedef struct			s_movie
{
	char				**map;
	struct s_movie		*prev;
	struct s_movie		*next;
}						t_movie;

typedef struct			s_display
{
	SDL_Window			*window;
	SDL_Renderer		*render;
	Mix_Music			*music;
	t_movie				*movie;
	int					map_h;
	int					map_w;
	int					score_p1;
	int					score_p2;
	char				*p1;
	char				*p2;
	SDL_Color			color_p1;
	SDL_Color			color_p2;
}						t_display;

/*
**			SDL:		-----------GENERAL-----------------------------
*/
int						init_sdl(void);
int						create_window_render(t_display *display);
void					free_sdl(t_display *display);
int						load_music(t_display *display);
SDL_Texture				*load_img(char *path, SDL_Renderer *render);
/*
**			   		    -----------------------------------------------
*/
void					put_scene(t_display *display);
void					display_players(t_display *display);
void					put_pieces(t_display *display, int ac, char **av);
SDL_Rect				ft_rect(int height, int width, int y, int x);
/*
**		parsing:		-----------------------------------------------
*/
int						record_game(t_display *display);
int						get_players(t_display *display);
t_movie					*ft_movie_addnode(t_movie **head);
t_movie					*ft_movie_new(void);
void					free_display(t_display *display);
void					free_node(t_movie *movie);
void					free_movie(t_movie **head);

void					print_tab(char **tab);
void					print_list(t_movie *movie);

#endif
