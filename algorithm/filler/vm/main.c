/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 01:36:18 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 06:49:59 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

static void		ft_free_tab(char ***tab)
{
	int		i;

	i = -1;
	while ((*tab)[++i] != 0)
		ft_strdel(&((*tab)[i]));
	free(*tab);
}

static void		ft_go_top(int x)
{
	int		i;

	i = -1;
	while (++i < x)
		ft_putstr(UP);
}

static void		ft_init(t_tray **p, char ***tab)
{
	ft_putstr("\033[1J\033[H\033[?25l\033[1m");
	*p = ft_new_tray();
	ft_get_players(&((*p)->p1), &((*p)->p2));
	ft_get_tray_dim(&((*p)->x), &((*p)->y));
	ft_print_players(*p);
	ft_print_border((*p)->y, 0);
	*tab = ft_get_tray((*p)->x, (*p)->y);
	ft_print_tab(*tab);
	ft_print_border((*p)->y, 1);
	ft_putstr(UP);
}

static void		ft_while(t_tray *p, char ***tab, int *i, char **line)
{
	if (*i >= 0 && *i < p->x && !ft_strstr(*line, (*tab)[*i]))
	{
		(*tab)[*i] = ft_strrep((*tab)[*i], ft_strsub(*line, 4, p->y));
		ft_print_line((*tab)[*i]);
	}
	else if (ft_strstr(*line, "Plateau"))
	{
		ft_go_top(p->x);
		*i = -2;
	}
	else if (*i >= 0 && *i < p->x)
		ft_putstr(DOWN);
	if (ft_strstr(*line, "== O fin:"))
		p->score_p1 = ft_atoi((*line) + 9);
	if (ft_strstr(*line, "== X fin:"))
		p->score_p2 = ft_atoi((*line) + 9);
	if (*line)
		ft_strdel(line);
	*line = NULL;
	(*i)++;
	usleep(250);
}

int				main(void)
{
	char	*line;
	t_tray	*p;
	int		i;
	char	**tab;

	ft_init(&p, &tab);
	line = NULL;
	i = p->x;
	while (ft_get_next_line(0, &line, 1) == 1)
		ft_while(p, &tab, &i, &line);
	ft_free_tab(&tab);
	ft_putstr(DOWN);
	ft_print_winner(p);
	ft_clr_tray(&p);
	ft_putstr("\033[?25h");
	return (0);
}
