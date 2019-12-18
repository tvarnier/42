/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_other.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 06:19:05 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 06:37:19 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void			ft_print_color(char *color, char *s)
{
	ft_putstr(color);
	ft_putstr(s);
	ft_putstr(END_COLOR);
	ft_putstr(END_BCOLOR);
}

void			ft_print_space(int i)
{
	while (i--)
		ft_putstr(" ");
}

void			ft_print_border(int y, int line)
{
	ft_print_space(LEFT_SPACE);
	ft_putstr(BORDER_COLOR);
	if (line == 0)
		ft_putstr("╔");
	else
		ft_putstr("╚");
	while (--y >= 0)
		ft_putstr("══");
	if (line == 0)
		ft_putstr("╗");
	else
		ft_putstr("╝");
	ft_putstr(END_COLOR);
	ft_putstr("\n");
}
