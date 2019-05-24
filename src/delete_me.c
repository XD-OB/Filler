/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_me.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 02:19:10 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/24 02:20:08 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		print_matrice(int **tab, int rows, int cols)
{
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (tab[i][j] >= 0 && tab[i][j] < 10)
				ft_putchar_fd(' ', 2);
			ft_dprintf(2, "%d", tab[i][j]);
			j++;
		}
		ft_putchar_fd('\n', 2);
		i++;
	}
}

void		print_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		ft_putstr_fd(tab[i], 2);
		ft_putchar_fd('\n', 2);
	}
	ft_putchar_fd('\n', 2);
}
