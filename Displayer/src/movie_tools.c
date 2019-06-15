/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:32:55 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/25 09:20:16 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

t_movie			*ft_movie_new(void)
{
	t_movie	*node;

	if (!(node = (t_movie*)malloc(sizeof(t_movie))))
		return (NULL);
	node->map = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_movie			*ft_movie_addnode(t_movie **head)
{
	t_movie		*curr;

	if (!*head)
	{
		*head = ft_movie_new();
		return (*head);
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = ft_movie_new();
	curr->next->prev = curr;
	return (curr->next);
}
