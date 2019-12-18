/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_tray.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 06:07:10 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 06:24:38 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ft_get_players(char **p1, char **p2)
{
	char	*line;
	int		ret;
	int		pos;

	line = NULL;
	while ((ret = ft_get_next_line(0, &line, 1) == 1
				&& !ft_strstr(line, "exec p1")))
	{
		ft_strdel(&line);
		line = NULL;
	}
	pos = ft_strchar_last(line, '/') + 1;
	*p1 = ft_strsub(line, pos, ft_strchar_last(line, '.') - pos);
	ft_strdel(&line);
	line = NULL;
	while ((ret = ft_get_next_line(0, &line, 1) == 1
				&& !ft_strstr(line, "exec p2")))
	{
		ft_strdel(&line);
		line = NULL;
	}
	pos = ft_strchar_last(line, '/') + 1;
	*p2 = ft_strsub(line, pos, ft_strchar_last(line, '.') - pos);
	ft_strdel(&line);
}

void	ft_get_tray_dim(int *x, int *y)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	while ((ret = ft_get_next_line(0, &line, 1)) == 1
			&& !ft_strstr(line, "Plateau"))
	{
		ft_strdel(&line);
		line = NULL;
	}
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	*x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	*y = ft_atoi(line + i + 1);
	ft_strdel(&line);
}

char	**ft_get_tray(int h, int l)
{
	char	**tmp;
	int		i;
	char	*line;
	int		ret;

	tmp = NULL;
	if (!(tmp = (char **)malloc(sizeof(char *) * (h + 1))))
		return (NULL);
	tmp[h] = NULL;
	line = NULL;
	ret = ft_get_next_line(0, &line, 1);
	ft_strdel(&line);
	line = NULL;
	i = -1;
	while (++i < h)
	{
		ret = ft_get_next_line(0, &line, 1);
		tmp[i] = ft_strsub(line, 4, l);
		ft_strdel(&line);
		line = NULL;
	}
	return (tmp);
}
