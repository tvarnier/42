/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   connect_two.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 22:40:21 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 22:41:15 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		two(t_fdf *fdf, t_line l)
{
	int		e;

	e = l.dy;
	l.dy = e * 2;
	l.dx = l.dx * 2;
	while (1)
	{
		fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
		if ((l.y1 = l.y1 + 1) == l.y2)
			break ;
		if ((e = e - l.dx) < 0)
		{
			l.x1 = l.x1 + 1;
			e = e + l.dy;
		}
	}
}

void		two_two(t_fdf *fdf, t_line l)
{
	int		e;

	e = l.dy;
	l.dy = e * 2;
	l.dx = l.dx * 2;
	while (1)
	{
		fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
		if ((l.y1 = l.y1 - 1) == l.y2)
			break ;
		if ((e = e + l.dx) > 0)
		{
			l.x1 = l.x1 + 1;
			e = e + l.dy;
		}
	}
}

void		two_three(t_fdf *fdf, t_line l)
{
	int		e;

	e = l.dy;
	l.dy = e * 2;
	l.dx = l.dx * 2;
	while (1)
	{
		fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
		if ((l.y1 = l.y1 + 1) == l.y2)
			break ;
		if ((e = e + l.dx) <= 0)
		{
			l.x1 = l.x1 - 1;
			e = e + l.dy;
		}
	}
}

void		two_four(t_fdf *fdf, t_line l)
{
	int		e;

	e = l.dy;
	l.dy = e * 2;
	l.dx = l.dx * 2;
	while (1)
	{
		fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
		if ((l.y1 = l.y1 - 1) == l.y2)
			break ;
		if ((e = e - l.dx) >= 0)
		{
			l.x1 = l.x1 - 1;
			e = e + l.dy;
		}
	}
}
