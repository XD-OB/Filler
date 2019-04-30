#include "display.h"

void	draw_it(t_visual *v, char *str, int level, SDL_Surface **block)
{
	SDL_Rect	pos;
	int		i;

	i = -1;
	while (++i < v->width)
	{
		if (str[i] == 'x' || str[i] == 'o')
		{
			v->blocks[level * v->width + i] = SDL_CreateRGBSurface(SDL_HWSURFACE, BLOCK(v->width), BLOCK(v->height), 32, 0, 0, 0, 0);
			pos.y = level * (BLOCK(v->height) + 2) + 200;
			pos.x = i * (BLOCK(v->width) + 2) + 401;
			if (str[i] == 'x')
				SDL_FillRect(block[level * v->width + i],  NULL, SDL_MapRGB(v->screen->format, 0, 255, 0));
			else if (str[i] == 'o')
				SDL_FillRect(block[level * v->width + i], NULL, SDL_MapRGB(v->screen->format, 0, 0, 255));
			SDL_BlitSurface(block[level * v->width + i], NULL, v->screen, &pos);
			SDL_Flip(v->screen);
		}
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

static void	score_result(t_visual *v, char **line)
{	
	SDL_Rect	pos_w;
	TTF_Font	*font;
	int		score_p1;
	int		score_p2;

	if (!(font = TTF_OpenFont(FONT_TYPE, FONT_SIZE)))
		error((char*)TTF_GetError());
	score_p1 = ft_atoi(&(*line)[10]);
	free(*line);
	get_next_line(0, line);
	score_p2 = ft_atoi(&(*line)[10]);
	free(*line);
	ft_printf("P1 :%-12s:%d\nP2 :%-12s:%d\n", v->player1, score_p1,
			v->player2, score_p2);
	v->win = TTF_RenderText_Blended(font, "WIN!", v->color_p1);
	pos_w.y = 0;
	pos_w.y = 600;
	SDL_BlitSurface(v->win, NULL, v->screen, &pos_w);
	SDL_Flip(v->screen);
	TTF_CloseFont(font);
}

int		visual_score(t_visual *v)
{
	char	*line;

	get_next_line(0, &line);
	while (ft_strncmp(line, "Plateau", 4) && ft_strncmp(line, "==", 2))
	{
		free(line);
		if (ft_strncmp(line, "==", 2))
			get_next_line(0, &line);
	}
	if (!ft_strncmp(line, "==", 2))
	{
		score_result(v, &line);
		return (1);
	}
	else
		free(line);
	SDL_Flip(v->screen);
	return (0);
}

void	event_trigger(SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		exit(1) ;
	if (event->type == SDL_KEYDOWN)
	{
		if (event->key.keysym.sym == SDLK_ESCAPE)
			exit(1);
		if (event->key.keysym.sym == SDLK_p)
			space_pause(event);
		if (event->key.keysym.sym == SDLK_SPACE)
			pas_pause();
	}
}

void	update_screen(t_visual *v)
{
	SDL_Event	event;
	char		*line;
	int		i;
	int		j;

	i = -1;
	v->blocks = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * (v->width * v->height));
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
			draw_it(v, &line[++j], i, v->blocks);
			free(line);
		}
		event_trigger(&event);
		if (visual_score(v))
			return ;
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
	SDL_Flip(visual->screen);
	wait_close();
	//free_all(&visual);
	return (EXIT_SUCCESS);
}
