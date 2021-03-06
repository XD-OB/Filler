/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 06:45:05 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/27 06:18:34 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/ft_printf.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct	s_filler
{
	int			me;
	int			rows;
	int			cols;
	int			begin_y;
	int			begin_x;
	int			token_y;
	int			token_x;
	char		**token;
	int			**heatmap;
	int			**map;
	int			flag;
	int			p_y;
	int			p_x;
	int			ym;
	int			xm;
	int			x;
	int			y;
}				t_filler;

void			init_filler(t_filler *filler);
void			free_filler(t_filler *filler);
int				is_allpoint(char *str);
int				skip_line(void);
int				take_infos(t_filler *filler);
int				int_map(t_filler *filler);
int				get_token(t_filler *filler);
void			put_me_in(t_filler *filler);
void			coord_max(t_filler *filler);
int				heatmap_extrem(t_filler *filler);
int				heat_map(t_filler *filler);
void			free_filler(t_filler *filler);
void			output(t_filler *filler);

#endif
