/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:27:35 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 23:01:54 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void	free_movie(t_movie **head)
{
	t_movie		*tmp;

	while (*head)
	{
		tmp = *head;
		free_tabstr(&tmp->map);
		tmp->prev = NULL;
		(*head) = (*head)->next;
		free(tmp);
	}
}

void	free_node(t_movie *movie)
{
	free_tabstr(&movie->map);
	movie->prev->next = movie->next;
	movie->next->prev = movie->prev;
	free(movie);
}

void	free_display(t_display *display)
{
	free(display->p1);
	free(display->p2);
	free_movie(&(display->movie));
}
