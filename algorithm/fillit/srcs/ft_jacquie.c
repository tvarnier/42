/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_jacquie.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tdautrem <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 20:32:54 by tdautrem     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 21:00:55 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tetrisfree(t_tetris *t)
{
	int			a;
	t_tetris	*tmp;

	while (t)
	{
		a = -1;
		while (t->piece[++a])
			ft_strdel(&(t->piece[a]));
		ft_memdel((void*)&(t->piece));
		tmp = t;
		t = t->next;
		free(tmp);
		tmp = NULL;
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	t_tetris	*tetris;

	tetris = NULL;
	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) > 0)
	{
		if (!(tetris = (t_tetris*)malloc(sizeof(t_tetris))) ||
				ft_read(fd, tetris))
			ft_putstr("error\n");
		else
			ft_resolve(tetris);
		ft_tetrisfree(tetris);
	}
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}
