/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_tray.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 15:41:58 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 23:26:11 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

static void		ft_get_tray_dim(t_tray *p)
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
	p->t_h = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	p->t_l = ft_atoi(line + i + 1);
	ft_strdel(&line);
}

static char		**ft_get_tray(int h, int l)
{
	char	**tmp;
	int		i;
	char	*line;
	int		ret;

	tmp = NULL;
	if (!(tmp = (char **)malloc(sizeof(char *) * (h + 1))))
		return (NULL);
	tmp[h] = 0;
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

static void		ft_get_piece_dim(t_tray *p)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	ret = ft_get_next_line(0, &line, 1);
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	p->p_h = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	p->p_l = ft_atoi(line + i + 1);
	ft_strdel(&line);
}

static char		**ft_get_piece(int h)
{
	char	**tmp;
	int		i;
	char	*line;
	int		ret;

	tmp = NULL;
	if (!(tmp = (char **)malloc(sizeof(char **) * (h + 1))))
		return (NULL);
	tmp[h] = 0;
	line = NULL;
	i = -1;
	while (++i < h)
	{
		ret = ft_get_next_line(0, &line, 1);
		tmp[i] = ft_strdup(line);
		ft_strdel(&line);
		line = NULL;
	}
	return (tmp);
}

t_tray			*ft_init_tray(int player)
{
	t_tray*p;

	if (!(p = ft_new_tray()))
		return (NULL);
	p->player = player;
	p->foe = (player == 'O') ? 'X' : 'O';
	ft_get_tray_dim(p);
	p->tray = ft_get_tray(p->t_h, p->t_l);
	ft_get_piece_dim(p);
	p->piece = ft_get_piece(p->p_h);
	return (p);
}
