/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_me.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:23:45 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 22:36:01 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void	print_list(t_movie *movie)
{
	int	i;

	while (movie)
	{
		i = 0;
		ft_putstr("----------------------\n");
		while (movie->map[i])
		{
			ft_putendl(movie->map[i]);
			i++;
		}
		ft_putstr("----------------------\n");
		movie = movie->next;
	}
}
