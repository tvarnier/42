/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 14:02:36 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 23:21:54 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

static char		ft_get_player(void)
{
	char	*line;
	char	player;
	int		ret;

	player = 0;
	line = NULL;
	ret = ft_get_next_line(0, &line, 1);
	if (ft_strstr(line, "p1"))
		player = 'O';
	else if (ft_strstr(line, "p2"))
		player = 'X';
	ft_strdel(&line);
	return (player);
}

static void		ft_write_res(t_res *res)
{
	char	*tmp;

	tmp = ft_itoa(res->x);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	tmp = NULL;
	ft_putstr(" ");
	tmp = ft_itoa(res->y);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	ft_putstr("\n");
}

static void		ft_if_can_place(t_tray *p, t_res *res, int x, int y)
{
	int		foe_area;
	int		range;

	ft_insert_piece(p, x, y, &(p->tray));
	if (ft_block_foe(p, x, y, p->tray))
	{
		foe_area = ft_foe_area(p, &(p->tray));
		if (res->pt <= 0 || foe_area < res->pt)
			ft_insert_res(res, x, y, foe_area);
	}
	else if (res->pt <= 0)
	{
		range = ft_range_foe(p, x, y, p->tray);
		if (res->range == 0 || range < res->range)
		{
			ft_insert_res(res, x, y, -1);
			res->range = range;
		}
	}
	ft_clear_tab(&(p->tray));
}

static void		ft_while(char player, int *verif)
{
	t_tray		*p;
	int			x;
	int			y;
	t_res		*res;

	p = ft_init_tray(player);
	res = ft_new_res();
	x = -1;
	while (++x < p->t_h && (y = -1))
		while (++y < p->t_l)
			if (ft_can_place(p, x, y, &(p->tray)))
			{
				ft_if_can_place(p, res, x, y);
				*verif = 1;
			}
	ft_write_res(res);
	free(res);
	ft_clr_tray(&p);
}

int				main(void)
{
	char			player;
	int				verif;

	player = ft_get_player();
	while (1)
	{
		verif = 0;
		ft_while(player, &verif);
		if (verif == 0)
			break ;
	}
	return (0);
}
