/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 05:49:26 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/08 23:18:27 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_minus(char **tab, int *nbr, int *decl)
{
	if (*nbr < 0)
	{
		*tab[0] = '-';
		*nbr = -(*nbr);
		*decl = 1;
	}
	else
		*decl = 0;
}

static	char	*ft_alloc(int n)
{
	int		i;
	char	*tab;

	i = 1;
	tab = NULL;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while ((n = n / 10) >= 1)
		i++;
	i++;
	tab = (char*)malloc(sizeof(char) * i);
	return (tab);
}

char			*ft_itoa(int nb)
{
	int		i;
	int		j;
	int		dec;
	char	*tab;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	tab = ft_alloc(nb);
	if (tab == NULL)
		return (NULL);
	ft_minus(&tab, &nb, &dec);
	j = nb;
	i = 1;
	while ((j = j / 10) >= 1)
		i *= 10;
	while (i >= 1)
	{
		tab[dec] = ((nb / i) + 48);
		nb %= i;
		i /= 10;
		dec++;
	}
	tab[dec] = '\0';
	return (tab);
}
