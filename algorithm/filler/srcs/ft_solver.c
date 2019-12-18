/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solver.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 22:04:03 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 07:11:46 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

static void		ft_mark_foe_area(t_tray *p, int x, int y, char ***tab)
{
	int		i;

	i = 0;
	while (x + (++i) < p->t_h && ((*tab)[x + i][y] == '.'
				|| (*tab)[x + i][y] == '1'))
		(*tab)[x + i][y] = '1';
	i = 0;
	while (x - (++i) >= 0 && ((*tab)[x - i][y] == '.'
				|| (*tab)[x - i][y] == '1'))
		(*tab)[x - i][y] = '1';
	i = 0;
	while (y + (++i) < p->t_l && ((*tab)[x][y + i] == '.'
				|| (*tab)[x][y + i] == '1'))
		(*tab)[x][y + i] = '1';
	i = 0;
	while (y - (++i) >= 0 && ((*tab)[x][y - i] == '.'
				|| (*tab)[x][y - i] == '1'))
		(*tab)[x][y - i] = '1';
}

static int		ft_count_foe_area(t_tray *p, char **tab)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	x = -1;
	while (++x < p->t_h)
	{
		y = -1;
		while (++y < p->t_l)
			if (tab[x][y] == '1' || tab[x][y] == p->foe
					|| tab[x][y] == ft_tolower(p->foe))
				count++;
	}
	return (count);
}

int				ft_foe_area(t_tray *p, char ***tab)
{
	int		x;
	int		y;

	x = -1;
	while (++x < p->t_h)
	{
		y = -1;
		while (++y < p->t_l)
		{
			if ((*tab)[x][y] == p->foe || (*tab)[x][y] == ft_tolower(p->foe))
				ft_mark_foe_area(p, x, y, tab);
		}
	}
	return (ft_count_foe_area(p, *tab));
}

int				ft_range_foe(t_tray *p, int x, int y, char **tab)
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		count;

	count = 0;
	a = -1;
	while (++a < p->p_h && (b = -1))
		while (++b < p->p_l)
			if (tab[x + a][y + b] == ft_tolower(p->player) && (c = -1))
				while (++c < p->t_h && (d = -1))
					while (++d < p->t_l)
						if ((tab[c][d] == p->foe
									|| tab[c][d] == ft_tolower(p->foe))
								&& (count == 0
									|| (ft_abs(x + a - c)
										+ ft_abs(y + b - d)) < count))
							count = ft_abs(x + a - c) + ft_abs(y + b - d);
	return (count);
}
