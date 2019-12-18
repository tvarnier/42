/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   connect_one.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 22:38:24 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 22:40:08 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		one(t_fdf *fdf, t_line l)
{
	int		e;

	e = l.dx;
	l.dx = e * 2;
	l.dy = l.dy * 2;
	while (1)
	{
		fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
		if ((l.x1 = l.x1 + 1) == l.x2)
			break ;
		if ((e = e - l.dy) < 0)
		{
			l.y1 = l.y1 + 1;
			e = e + l.dx;
		}
	}
}

void		one_two(t_fdf *fdf, t_line l)
{
	int		e;

	e = l.dx;
	l.dx = e * 2;
	l.dy = l.dy * 2;
	while (1)
	{
		fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
		if ((l.x1 = l.x1 + 1) == l.x2)
			break ;
		if ((e = e + l.dy) < 0)
		{
			l.y1 = l.y1 - 1;
			e = e + l.dx;
		}
	}
}

void		one_three(t_fdf *fdf, t_line l)
{
	int		e;

	e = l.dx;
	l.dx = e * 2;
	l.dy = l.dy * 2;
	while (1)
	{
		fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
		if ((l.x1 = l.x1 - 1) == l.x2)
			break ;
		if ((e = e + l.dy) >= 0)
		{
			l.y1 = l.y1 + 1;
			e = e + l.dx;
		}
	}
}

void		one_four(t_fdf *fdf, t_line l)
{
	int		e;

	e = l.dx;
	l.dx = e * 2;
	l.dy = l.dy * 2;
	while (1)
	{
		fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
		if ((l.x1 = l.x1 - 1) == l.x2)
			break ;
		if ((e = e - l.dy) >= 0)
		{
			l.y1 = l.y1 - 1;
			e = e + l.dx;
		}
	}
}
