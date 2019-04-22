#include "visual.h"

char	*player_name(void)
{
	char	*line;
	char	*str;
	int	i;

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

void	draw_it(SDL_Surface *screen, int height, int width, char *str, int level)
{
	int		h_block;
	int		w_block;
	SDL_Surface	*block;
	SDL_Rect	pos;
	int		i;

	i = -1;
	h_block = 600 / (height - 1) - 4;
	w_block = 600 / (width - 1) - 4;
	while (++i < width)
	{
		if (str[i] != '.')
		{
			block = SDL_CreateRGBSurface(SDL_HWSURFACE, w_block, h_block, 32, 0, 0, 0, 0);
			pos.y = level * (h_block + 2) + 200;
			pos.x = i * (w_block + 2) + 401;
			if (str[i] == 'X')
				SDL_FillRect(block, NULL, SDL_MapRGB(screen->format, 0, 255, 0));
			else if (str[i] == 'O')
				SDL_FillRect(block, NULL, SDL_MapRGB(screen->format, 0, 0, 255));
			else
				SDL_FillRect(block, NULL, SDL_MapRGB(screen->format, 255, 0, 0));
			SDL_BlitSurface(block, NULL, screen, &pos);
			SDL_Flip(screen);
		}
	}
}

SDL_Surface	*put_win_p1(SDL_Surface *screen, char *p1, char *p2)
{
	SDL_Surface	*win;
	SDL_Rect	pos;

	win = SDL_CreateRGBSurface(SDL_HWSURFACE, 1400, 100, 32, 0, 0, 0, 0);
	pos.x = 0;
	pos.y = 1300;
	SDL_BlitSurface(win, NULL, screen, &pos);
	SDL_Flip(screen);
}

void	update_screen(SDL_Surface *screen)
{
	SDL_Event	event;
	SDL_Surface	*win;
	char	*line;
	char	*p2;
	char	*p1;
	int	width;
	int	height;
	int	i;
	int	j;

	i = -1;
	while (++i < 6)
	{
		get_next_line(0, &line);
		free(line);
	}
	p1 = player_name();
	get_next_line(0, &line);
	free(line);
	p2 = player_name();
	get_next_line(0, &line);
	i = -1;
	while (line[i] != ' ')
		i++;
	height = ft_atoi(&line[++i]);
	while (isdigit(line[i]))
		i++;
	width = ft_atoi(&line[i]);
	free(line);
	while (get_next_line(0, &line) > 0)
	{
		SDL_PollEvent(&event);
		free(line);
		i = -1;
		while (++i < height)
		{
			j = 0;
			get_next_line(0, &line);
			while (line[j] != ' ')
				j++;
			j++;
			draw_it(screen, height, width, &line[j], i);
			free(line);
		}
		if (event.type == SDL_QUIT)
			exit(1) ;
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				exit(1);
		}
		get_next_line(0, &line);
		while (ft_strncmp(line, "Plateau", 4) && ft_strncmp(line, "==", 2))
		{
			free(line);
			get_next_line(0, &line);
		}
		if (!ft_strncmp(line, "==", 2))
		{
			//win = put_win_p1(screen, p2, p1);
			//win = put_win_p2(screen, p2, p1);
			return ;
		}
		free(line);
	}
}

void	error(char *error)
{
	ft_dprintf(2, "Initializing Error!:\n%s\n", error);
	exit(EXIT_FAILURE);
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

void	free_quit(SDL_Surface *a, SDL_Surface *b, SDL_Surface *c)
{
	SDL_FreeSurface(a);
	SDL_FreeSurface(b);
	SDL_FreeSurface(c);
	SDL_Quit();
}

int	main(void)
{
	SDL_Surface	*screen;
	SDL_Surface	*header;
	SDL_Surface	*bk_img;
	SDL_Surface	*arena;
	//SDL_Event	event;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
		error((char*)SDL_GetError);
	//if (TTF_init() == -1)
	//	error(TTF_GetError());
	if (!(screen = SDL_SetVideoMode(1400, 1000, 32, SDL_SWSURFACE)))
		error((char*)SDL_GetError);
	SDL_WM_SetIcon(IMG_Load("./Visualizer/img/icon.png"), NULL);
	SDL_WM_SetCaption("Bring Your Filler And Let's Fight!", "Filler Fights");
	bk_img = put_background(screen);
	header = put_header(screen);
	arena = put_arena(screen);
	SDL_Flip(screen);
	update_screen(screen);
	wait_close();

	free_quit(bk_img, header, arena);
	return (EXIT_SUCCESS);
}
