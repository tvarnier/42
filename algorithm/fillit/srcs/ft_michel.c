/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_michel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 18:59:10 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 19:16:35 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_insert_piece(t_tetris *list, int x, int y, char ***tab)
{
	int		a;
	int		b;

	a = -1;
	while ((list->piece)[++a])
	{
		b = -1;
		while ((list->piece)[a][++b])
		{
			if ((list->piece)[a][b] == '#')
				(*tab)[x + a][y + b] = list->letter;
		}
	}
}

int		ft_place_piece(t_tetris *list, int x, int y, char ***tab)
{
	int		a;
	int		b;

	a = -1;
	while ((list->piece)[++a])
	{
		if (!((*tab)[x + a]))
			return (0);
		b = -1;
		while ((list->piece)[a][++b])
		{
			if (!((*tab)[x + a][y + b]))
				return (0);
			if ((list->piece)[a][b] == '#' && !((*tab)[x + a][y + b] == '.'))
				return (0);
		}
	}
	ft_insert_piece(list, x, y, tab);
	return (1);
}

void	ft_rm_piece(char ***tab, char letter)
{
	int		x;
	int		y;

	x = -1;
	while ((*tab)[++x])
	{
		y = -1;
		while ((*tab)[x][++y])
		{
			if ((*tab)[x][y] == letter)
				(*tab)[x][y] = '.';
		}
	}
}

int		ft_get_square(t_tetris *list, char ***tab, int i)
{
	int		y;
	int		x;

	if (!(*tab))
	{
		if (!(ft_alloc_tab(tab, i)))
			return (-1);
	}
	if (list && (x = -1) == -1)
	{
		while (++x < i && (y = -1) == -1)
		{
			while (++y < i)
			{
				if (ft_place_piece(list, x, y, tab))
				{
					if (ft_get_square(list->next, tab, i))
						return (1);
					ft_rm_piece(tab, list->letter);
				}
			}
		}
		return (0);
	}
	return (1);
}

int		ft_resolve(t_tetris *list)
{
	int		lst_len;
	int		i;
	char	**tab;
	int		res;

	if (!list)
		return (0);
	lst_len = ft_nbr_piece(list);
	i = 0;
	while (lst_len * 4 > ft_pow(i, 2))
		i++;
	tab = NULL;
	while ((res = ft_get_square(list, &tab, i)) == 0)
	{
		ft_free_tab(tab, i);
		tab = NULL;
		i++;
	}
	if (res == -1)
		return (0);
	ft_print_tab(tab);
	ft_free_tab(tab, i);
	return (1);
}
