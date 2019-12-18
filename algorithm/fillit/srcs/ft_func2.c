/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_func2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tdautrem <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 08:19:26 by tdautrem     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 19:18:48 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_freeallcoord(t_coord *co1, t_coord *co2, t_coord *co3)
{
	ft_memdel((void*)&co1);
	ft_memdel((void*)&co2);
	ft_memdel((void*)&co3);
	return (1);
}

int		ft_checkvoisin(t_tetris *t, t_coord *co, int psize, int *nbrv)
{
	int		nbrvoisin;

	nbrvoisin = 0;
	nbrvoisin += (co->y != 0 && t->piece[co->y - 1][co->x] == '#');
	nbrvoisin += (co->y != 3 && t->piece[co->y + 1][co->x] == '#');
	nbrvoisin += (co->x != 0 && t->piece[co->y][co->x - 1] == '#');
	nbrvoisin += (co->x != 3 && t->piece[co->y][co->x + 1] == '#');
	if (nbrvoisin == 0 || !(psize < 4))
		return (1);
	(*nbrv) += nbrvoisin;
	return (0);
}

void	ft_changeminmax(int *psize, t_coord **max, t_coord **min, t_coord *co)
{
	(*max)->x = co->x > (*max)->x ? co->x : (*max)->x;
	(*max)->y = co->y > (*max)->y ? co->y : (*max)->y;
	(*min)->x = co->x < (*min)->x ? co->x : (*min)->x;
	(*min)->y = co->y < (*min)->y ? co->y : (*min)->y;
	(*psize)++;
}

int		ft_initminmax(int *psize, t_coord **max, t_coord **min, t_coord **co)
{
	if (!((*co) = (t_coord*)malloc(sizeof(t_coord))) ||
			!((*max) = (t_coord*)malloc(sizeof(t_coord))) ||
			!((*min) = (t_coord*)malloc(sizeof(t_coord))))
		return (1);
	*psize = 0;
	(*co)->y = -1;
	(*max)->x = 0;
	(*max)->y = 0;
	(*min)->x = 3;
	(*min)->y = 3;
	return (0);
}

int		ft_verifpiece(t_tetris *t)
{
	t_coord		*co;
	t_coord		*max;
	t_coord		*min;
	int			psize;
	int			nbrv;

	nbrv = 0;
	if (ft_initminmax(&psize, &max, &min, &co))
		return (ft_freeallcoord(co, min, max));
	while (++(co->y) < 4)
	{
		co->x = -1;
		while (++(co->x) < 4)
			if (t->piece[co->y][co->x] == '#')
			{
				if (ft_checkvoisin(t, co, psize, &nbrv))
					return (ft_freeallcoord(co, min, max));
				ft_changeminmax(&psize, &max, &min, co);
			}
	}
	if (psize != 4 || ft_buildpiece(t, min, max, co) || nbrv < 6)
		return (ft_freeallcoord(co, min, max));
	ft_freeallcoord(co, min, max);
	return (0);
}
