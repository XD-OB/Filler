#include "display.h"

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

int	main(void)
{
	t_visual	*visual;
	char		*line;

	if (!(visual = (t_visual*)malloc(sizeof(t_visual))))
		exit(-1);
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
	free_all(&visual);
	return (EXIT_SUCCESS);
}
