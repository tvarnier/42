/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_change_tray.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 23:00:21 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 07:02:22 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

#include <stdio.h>

static void		ft_insert_diagonale(t_tray *p, char ***tab)
{
	int		x;
	int		y;
	int		verif;

	x = -1;
	while ((*tab)[++x] && (y = -1))
		while ((*tab)[x][++y])
		{
			verif = ((*tab)[x][y] != '.') ? 1 : 0;
			if (verif == 0 && x - 1 >= 0 && y - 1 >= 0
					&& (*tab)[x - 1][y - 1] == p->foe)
				(*tab)[x][y] = ft_tolower(p->foe);
			else if (verif == 0 && x - 1 >= 0 && y + 1 < p->t_l
					&& (*tab)[x - 1][y + 1] == p->foe)
				(*tab)[x][y] = ft_tolower(p->foe);
			else if (verif == 0 && x + 1 < p->t_h && y - 1 >= 0
					&& (*tab)[x + 1][y - 1] == p->foe)
				(*tab)[x][y] = ft_tolower(p->foe);
			else if (verif == 0 && x + 1 < p->t_h && y + 1 < p->t_l
					&& (*tab)[x + 1][y + 1] == p->foe)
				(*tab)[x][y] = ft_tolower(p->foe);
		}
}

void			ft_insert_piece(t_tray *p, int x, int y, char ***tab)
{
	int		a;
	int		b;

	a = -1;
	while ((p->piece)[++a])
	{
		b = -1;
		while ((p->piece)[a][++b])
		{
			if ((p->piece)[a][b] == '*' && (*tab)[x + a][y + b] != p->player)
				(*tab)[x + a][y + b] = ft_tolower(p->player);
		}
	}
	ft_insert_diagonale(p, tab);
}

void			ft_clear_tab(char ***tab)
{
	int		x;
	int		y;

	x = -1;
	while ((*tab)[++x] != 0)
	{
		y = -1;
		while ((*tab)[x][++y])
			if ((*tab)[x][y] == 'x' || (*tab)[x][y] == 'o'
					|| (*tab)[x][y] == '1')
				(*tab)[x][y] = '.';
	}
}
