/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_res_fct.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 06:53:56 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 17:08:57 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_newline(size_t size)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	if (!(tmp = (char*)(malloc(sizeof(*tmp) * (size + 1)))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp[i] = '.';
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

size_t		ft_nbr_piece(t_tetris *begin_list)
{
	size_t	i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

void		ft_print_tab(char **tab)
{
	int		x;

	x = -1;
	while (tab[++x] != 0)
	{
		ft_putstr(tab[x]);
		ft_putchar('\n');
	}
}

void		ft_free_tab(char **tab, int i)
{
	int		x;

	if (tab)
	{
		x = -1;
		while (++x < i)
		{
			ft_strdel(&(tab[x]));
		}
		free(tab);
		tab = NULL;
	}
}

int			ft_alloc_tab(char ***tab, int i)
{
	int		x;

	if (*tab)
		ft_free_tab(*tab, i);
	*tab = NULL;
	if (!(*tab = (char **)malloc(sizeof(*tab) * (i + 1))))
		return (0);
	(*tab)[i] = 0;
	x = -1;
	while (++x < i)
	{
		if (!((*tab)[x] = ft_newline(i)))
			return (0);
	}
	return (1);
}
