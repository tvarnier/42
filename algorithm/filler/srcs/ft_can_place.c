/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_can_place.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 07:09:17 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 07:11:44 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int				ft_can_place(t_tray *p, int x, int y, char ***tab)
{
	int		a;
	int		b;
	int		count;

	count = 0;
	a = -1;
	while ((p->piece)[++a])
	{
		if (!((*tab)[x + a]))
			return (0);
		b = -1;
		while ((p->piece)[a][++b])
		{
			if (!((*tab)[x + a][y + b]))
				return (0);
			if ((p->piece)[a][b] == '*' && !((*tab)[x + a][y + b] == '.')
					&& (*tab)[x + a][y + b] != p->player)
				return (0);
			if ((p->piece)[a][b] == '*' && (*tab)[x + a][y + b] == p->player)
				count++;
		}
	}
	if (count == 1)
		return (1);
	return (0);
}

static int		ft_is_foe_area(t_tray *p, int x, int y, char **tab)
{
	int		i;

	i = 0;
	while (x + (++i) < p->t_h && tab[x + i][		y] != p->player
			&& tab[x + i][y] != ft_tolower(p->player))
		if (tab[x + i][y] == p->foe || tab[x + i][y] == ft_tolower(p->foe))
			return (1);
	i = 0;
	while (x - (++i) >= 0 && tab[x - i][y] != p->player
			&& tab[x - i][y] != ft_tolower(p->player))
		if (tab[x - i][y] == p->foe || tab[x - i][y] == ft_tolower(p->foe))
			return (1);
	i = 0;
	while (y + (++i) < p->t_l && tab[x][y + i] != p->player
			&& tab[x][y + i] != ft_tolower(p->player))
		if (tab[x][y + i] == p->foe || tab[x][y + i] == ft_tolower(p->foe))
			return (1);
	i = 0;
	while (y - (++i) >= 0 && tab[x][y - i] != p->player
			&& tab[x][y - i] != ft_tolower(p->player))
		if (tab[x][y - i] == p->foe || tab[x][y - i] == ft_tolower(p->foe))
			return (1);
	return (0);
}

int				ft_block_foe(t_tray *p, int x, int y, char **tab)
{
	int		a;
	int		b;

	a = -1;
	while (++a < p->p_h)
	{
		b = -1;
		while (++b < p->p_l)
			if (tab[x + a][y + b] == ft_tolower(p->player)
					&& ft_is_foe_area(p, x + a, y + b, tab))
				return (1);
	}
	return (0);
}
