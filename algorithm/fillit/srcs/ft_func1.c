/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_func1.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tdautrem <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 08:13:30 by tdautrem     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 20:40:05 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_meminit(char **s, size_t len)
{
	int i;

	if (!(s = (char**)malloc(sizeof(char*) * len)))
		return (NULL);
	i = -1;
	while (++i < (int)len)
		s[i] = NULL;
	return (s);
}

int		ft_construct(char *line, t_tetris *tetris, int a)
{
	int i;

	i = -1;
	if (!(tetris->piece[a] = ft_strnew(4)))
		return (1);
	while (line[++i])
	{
		if ((line[i] != '.' && line[i] != '#') || i == 4)
			return (1);
		else
			tetris->piece[a][i] = line[i];
	}
	if (i != 4)
		return (1);
	return (0);
}

char	**ft_tabrep(char **t1, char **t2)
{
	int y;

	y = -1;
	while (t1[++y])
		ft_strdel(&(t1[y]));
	free(t1);
	t1 = NULL;
	return (t2);
}

int		ft_freenewpiece(char **na)
{
	int i;

	i = -1;
	while (na[++i])
		ft_strdel(&(na[i]));
	if (na)
		ft_memdel((void*)&na);
	return (1);
}

int		ft_buildpiece(t_tetris *t, t_coord *min, t_coord *max, t_coord *co)
{
	char **na;

	na = NULL;
	if (!(na = ft_meminit(na, max->y - min->y + 2)))
		return (1);
	co->y = -1;
	while (++(co->y) + min->y <= max->y)
	{
		co->x = -1;
		na[co->y] = NULL;
		if (!(na[co->y] = ft_strnew(max->x - min->x + 1)))
			return (ft_freenewpiece(na));
		while (++(co->x) + min->x <= max->x)
			na[co->y][co->x] = t->piece[co->y + min->y][co->x + min->x];
	}
	t->piece = ft_tabrep(t->piece, na);
	return (0);
}
