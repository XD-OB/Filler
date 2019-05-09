/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 01:12:47 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/03 03:59:41 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_tab(char ***tab, int size_y)
{
	int	i;

	i = -1;
	while (++i < size_y)
		free((*tab)[i]);
	free(*tab);
}

void	free_filler(t_filler *filler)
{
	int	i;

	i = 0;
	while (i < filler->rows)
	{
		free(filler->map[i]);
		i++;
	}
	i = 0;
	if (filler->map)
		free(filler->map);
	free_tab(&(filler->token), filler->token_y);
}

int		is_allpoint(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
