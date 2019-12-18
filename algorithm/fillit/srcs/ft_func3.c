/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_func3.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tdautrem <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 08:25:25 by tdautrem     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 20:40:27 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_readpiece(int *i, int *linebool, t_tetris *tetris, char *line)
{
	*linebool = 0;
	if (ft_construct(line, tetris, *i))
		return (1);
	if (*i == 3 && ft_verifpiece(tetris))
		return (1);
	(*i)++;
	return (0);
}

int		ft_readn(int *i, int *a, t_tetris **tetris, char *line)
{
	if (line[0] != '\0')
		return (1);
	if (!((*tetris)->next = (t_tetris*)malloc(sizeof(t_tetris))))
		return (1);
	(*tetris) = (*tetris)->next;
	(*tetris)->next = NULL;
	if (!((*tetris)->piece = ft_meminit((*tetris)->piece, 5)))
		return (1);
	(*tetris)->letter = 'A' + (++(*a));
	*i = 0;
	if (*a == 26)
		return (1);
	return (0);
}

int		ft_readinit(int *i, char *line, t_tetris **tetris, t_data **d)
{
	if (!(*d = (t_data*)malloc(sizeof(t_data))))
		return (1);
	(*d)->error = 0;
	*i = 0;
	(*d)->a = -1;
	if (!((*tetris)->piece = ft_meminit((*tetris)->piece, 5)))
	{
		free(*d);
		return (1);
	}
	(*tetris)->letter = 'A' + (++((*d)->a));
	(*tetris)->next = NULL;
	(*d)->linebool = 1;
	line = NULL;
	return (0);
}

int		ft_readeach(int *i, t_data **d, t_tetris **tetris, char *line)
{
	if (*i < 4)
	{
		if (((*d)->error = ft_readpiece(i, &((*d)->linebool), *tetris, line)))
			return (1);
	}
	else if (*i == 4)
	{
		if (((*d)->error = ft_readn(i, &((*d)->a), tetris, line)))
			return (1);
		(*d)->linebool = 1;
	}
	ft_strdel(&line);
	return (0);
}

int		ft_read(const int fd, t_tetris *tetris)
{
	int		ret;
	char	*line;
	int		i;
	t_data	*d;

	line = NULL;
	if (ft_readinit(&i, line, &tetris, &d))
		return (1);
	while ((ret = get_next_line(fd, &line, 0)) == 1)
		if (ft_readeach(&i, &d, &tetris, line))
			break ;
	ft_strdel(&line);
	get_next_line(fd, &line, 1);
	close(fd);
	if (d->linebool || d->error || i != 4)
	{
		free(d);
		return (1);
	}
	free(d);
	return (0);
}
