#include "display.h"

void	space_pause(void)
{
	SDL_Event	event;
	int		pass;

	pass = 1;
	while (pass)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
			pass = 0;
	}
}

void	draw_it(t_visual *v, char *str, int level)
{
	int		h_block;
	int		w_block;
	SDL_Surface	*block;
	SDL_Rect	pos;
	int		i;

	i = -1;
	h_block = 600 / (v->height - 1) - 4;
	w_block = 600 / (v->width - 1) - 4;
	while (++i < v->width)
	{
		if (str[i] != '.')
		{
			block = SDL_CreateRGBSurface(SDL_HWSURFACE, w_block, h_block, 32, 0, 0, 0, 0);
			pos.y = level * (h_block + 2) + 200;
			pos.x = i * (w_block + 2) + 401;
			if (str[i] == 'X')
				SDL_FillRect(block, NULL, SDL_MapRGB(v->screen->format, 0, 255, 0));
			else if (str[i] == 'O')
				SDL_FillRect(block, NULL, SDL_MapRGB(v->screen->format, 0, 0, 255));
			else
				SDL_FillRect(block, NULL, SDL_MapRGB(v->screen->format, 255, 0, 0));
			SDL_BlitSurface(block, NULL, v->screen, &pos);
			SDL_Flip(v->screen);
		}
	}
}

SDL_Surface	*put_win_p(t_visual *visual, int who)
{
	SDL_Surface	*win;
	SDL_Rect	pos;

	pos.x = 0;
	pos.y = 1300;
	win = SDL_CreateRGBSurface(SDL_HWSURFACE, WIN_WIDTH, 100, 32, 0, 0, 0, 0);
	SDL_BlitSurface(win, NULL, visual->screen, &pos);
	SDL_Flip(visual->screen);
	return (win);
}

void	update_screen(t_visual *v)
{
	SDL_Event	event;
	//SDL_Surface	*win;
	char		*line;
	int		i;
	int		j;

	while (get_next_line(0, &line) > 0)
	{
		SDL_PollEvent(&event);
		free(line);
		i = -1;
		while (++i < v->height)
		{
			j = 0;
			get_next_line(0, &line);
			while (line[j] != ' ')
				j++;
			draw_it(v, &line[++j], i);
			free(line);
		}
		if (event.type == SDL_QUIT)
			exit(1) ;
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				exit(1);
			if (event.key.keysym.sym == SDLK_p)
				space_pause();
		}
		get_next_line(0, &line);
		while (ft_strncmp(line, "Plateau", 4) && ft_strncmp(line, "==", 2))
		{
			free(line);
			get_next_line(0, &line);
		}
		if (!ft_strncmp(line, "==", 2))
		{
			//win = put_win_p(v, 1);
			//win = put_win_p(v, 2);
			return ;
		}
		free(line);
		SDL_Flip(v->screen);
	}
}

void	wait_close(void)
{
	SDL_Event event;
	int	pass;

	pass = 1;
	while (pass)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			pass = 0;
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				pass = 0;
		}
	}
}

void	map_size(int *height, int *width)
{
	char	*line;
	int	i;

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

void	display_players(t_visual *v)
{
	TTF_Font	*font;
	SDL_Rect	pos_p;
	char		*line;
	int		i;

	i = -1;
	if (!(font = TTF_OpenFont(FONT_TYPE, FONT_SIZE)))
		error((char*)TTF_GetError());
	while (++i < 6)
	{
		get_next_line(0, &line);
		free(line);
	}
	pos_p.y = 0;
	pos_p.x = 80;
	v->player1 = player_name();
	v->text_p1 = TTF_RenderText_Blended(font, v->player1, v->color_p1);
	SDL_BlitSurface(v->text_p1, NULL, v->screen, &pos_p);
	get_next_line(0, &line);
	free(line);
	v->player2 = player_name();
	pos_p.y = 0;
	pos_p.x = 1380 - ((int)ft_strlen(v->player2) * 50);
	v->text_p2 = TTF_RenderText_Blended(font, v->player2, v->color_p2);
	SDL_BlitSurface(v->text_p2, NULL, v->screen, &pos_p);
	TTF_CloseFont(font);
}

int	main(void)
{
	t_visual	*visual;
	char		*line;

	if (!(visual = (t_visual*)malloc(sizeof(t_visual))))
		error("Can't Allocate memory space");
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
		error((char*)SDL_GetError);
	if (TTF_Init() == -1)
		error((char*)TTF_GetError());
	if (!(visual->screen = SDL_SetVideoMode(WIN_WIDTH,
				WIN_HEIGHT, 32, SDL_SWSURFACE)))
		error((char*)SDL_GetError);
	SDL_WM_SetIcon(IMG_Load(ICON_IMG), NULL);
	SDL_WM_SetCaption(ICON_TITLE, ICON_ATTR);
	put_pieces(visual);
	display_players(visual);
	SDL_Flip(visual->screen);
	map_size(&(visual->height), &(visual->width));
	update_screen(visual);
	wait_close();
	free_all(&visual);
	return (EXIT_SUCCESS);
}
