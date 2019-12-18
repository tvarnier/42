/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_players.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 06:33:56 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 06:37:46 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

static void		ft_print_players_next(t_tray *p)
{
	ft_print_color(X_COLOR, "|   __/\\_______/\n");
	ft_print_space(LEFT_SPACE + 1 + p->y / 2 - 6);
	ft_print_color(O_COLOR, "|__|  ");
	ft_print_color(O_COLOR, p->p1);
	if (ft_strlen(p->p1) > 6)
		ft_print_space(p->y - 11 - (ft_strlen(p->p1) - 6));
	else
		ft_print_space(p->y - 11 + (6 - ft_strlen(p->p1)));
	ft_print_color(X_COLOR, "|__|  ");
	ft_print_color(X_COLOR, p->p2);
	ft_putstr("\n\n");
}

void			ft_print_players(t_tray *p)
{
	ft_putstr("\n");
	ft_print_space(LEFT_SPACE + 1 + p->y / 2 - 6);
	ft_print_color(O_COLOR, "       ____ ");
	ft_print_space(p->y - 11);
	ft_print_color(X_COLOR, "       ________  \n");
	ft_print_space(LEFT_SPACE + 1 + p->y / 2 - 6);
	ft_print_color(O_COLOR, "______/_   |");
	ft_print_space(p->y - 11);
	ft_print_color(X_COLOR, "______ \\_____  \\\n");
	ft_print_space(LEFT_SPACE + 1 + p->y / 2 - 6);
	ft_print_color(O_COLOR, "\\____ \\|   |");
	ft_print_space(p->y - 11);
	ft_print_color(X_COLOR, "\\____ \\ /  ____/\n");
	ft_print_space(LEFT_SPACE + 1 + p->y / 2 - 6);
	ft_print_color(O_COLOR, "|  |_> >   |");
	ft_print_space(p->y - 11);
	ft_print_color(X_COLOR, "|  |_> >       \\\n");
	ft_print_space(LEFT_SPACE + 1 + p->y / 2 - 6);
	ft_print_color(O_COLOR, "|   __/|___|");
	ft_print_space(p->y - 11);
	ft_print_players_next(p);
}
