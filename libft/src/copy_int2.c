/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_int2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:54:32 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/23 23:08:04 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**copy_int2(int **old_map, int size_y, int size_x)
{
	int		**new_map;
	int		i;
	int		j;

	if (!(new_map = (int**)malloc(sizeof(int*) * (size_y + 1))))
		return (NULL);
	new_map[size_y] = NULL;
	i = 0;
	while (i < size_y)
	{
		j = 0;
		new_map[i] = (int*)malloc(sizeof(int) * size_x);
		while (j < size_x)
		{
			new_map[i][j] = old_map[i][j];
			j++;
		}
		i++;
	}
	return (new_map);
}
