/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_winner.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 06:29:59 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 06:33:42 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

static void		ft_print_leplusbo(t_tray *p)
{
	if (p->score_p1 > p->score_p2 && ft_strcmp(p->p1, "tvarnier") == 0)
	{
		ft_print_space(LEFT_SPACE + 1 + p->y - 11);
		ft_putstr("(il é vrémen trê for)\n");
	}
	else if (p->score_p2 > p->score_p1 && ft_strcmp(p->p2, "tvarnier") == 0)
	{
		ft_print_space(LEFT_SPACE + 1 + p->y - 11);
		ft_putstr("(il é vrémen trê for)\n");
	}
}

void			ft_print_winner(t_tray *p)
{
	if (p->score_p1 > p->score_p2)
		ft_putstr(O_COLOR);
	else if (p->score_p2 > p->score_p1)
		ft_putstr(X_COLOR);
	else
		ft_putstr(BORDER_COLOR);
	ft_putstr("\n");
	ft_print_space(LEFT_SPACE + 1 + p->y - 21);
	ft_putstr(" __      __.__                            \n");
	ft_print_space(LEFT_SPACE + 1 + p->y - 21);
	ft_putstr("/  \\    /  \\__| ____   ____   ___________ \n");
	ft_print_space(LEFT_SPACE + 1 + p->y - 21);
	ft_putstr("\\   \\/\\/   /  |/    \\ /    \\_/ __ \\_  __ \\\n");
	ft_print_space(LEFT_SPACE + 1 + p->y - 21);
	ft_putstr(" \\        /|  |   |  \\   |  \\  ___/|  | \\/\n");
	ft_print_space(LEFT_SPACE + 1 + p->y - 21);
	ft_putstr("  \\__/\\  / |__|___|  /___|  /\\___  >__|   \n");
	ft_print_space(LEFT_SPACE + 1 + p->y - 21);
	ft_putstr("       \\/          \\/     \\/     \\/       \n");
	ft_print_leplusbo(p);
	ft_putstr("\n");
	ft_putstr(END_COLOR);
}
