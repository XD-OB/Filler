#include "display.h"

void	error(char *error)
{
	ft_dprintf(2, "Initializing Error!:\n%s\n", error);
	exit(EXIT_FAILURE);
}

void	free_all(t_visual **visual)
{
	int	i;

	i = -1;
	while (++i < (*visual)->height * (*visual)->width)
	{
		if ((*visual)->blocks[i])
			SDL_FreeSurface((*visual)->blocks[i]);
	}
	SDL_FreeSurface((*visual)->arena);
	SDL_FreeSurface((*visual)->bk_img);
	SDL_FreeSurface((*visual)->header);
	SDL_FreeSurface((*visual)->win);
	free((*visual)->player1);
	free((*visual)->player2);
	free(*visual);
	TTF_Quit();
	SDL_Quit();
}

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
