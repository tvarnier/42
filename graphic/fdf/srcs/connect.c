/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   connect.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 16:07:40 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 22:41:57 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		connect_right(t_fdf *fdf, t_line l)
{
	if ((l.dy = l.y2 - l.y1) != 0)
	{
		if (l.dy > 0)
		{
			if (l.dx >= l.dy)
				one(fdf, l);
			else
				two(fdf, l);
		}
		else
		{
			if (l.dx >= -(l.dy))
				one_two(fdf, l);
			else
				two_two(fdf, l);
		}
	}
	else
		while (1)
		{
			fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
			if ((l.x1 = l.x1 + 1) == l.x2)
				break ;
		}
}

void		connect_left(t_fdf *fdf, t_line l)
{
	if ((l.dy = l.y2 - l.y1) != 0)
	{
		if (l.dy > 0)
		{
			if (-(l.dx) >= l.dy)
				one_three(fdf, l);
			else
				two_three(fdf, l);
		}
		else
		{
			if (l.dx <= l.dy)
				one_four(fdf, l);
			else
				two_four(fdf, l);
		}
	}
	else
		while (1)
		{
			fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
			if ((l.x1 = l.x1 - 1) == l.x2)
				break ;
		}
}

void		connect_vertical(t_fdf *fdf, t_line l)
{
	if ((l.dy = l.y2 - l.y1) != 0)
	{
		if (l.dy > 0)
			while (1)
			{
				fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
				if ((l.y1 = l.y1 + 1) == l.y2)
					break ;
			}
		else
			while (1)
			{
				fill_pixel(&(fdf->img_str), l.x1, l.y1, l.color);
				if ((l.y1 = l.y1 - 1) == l.y2)
					break ;
			}
	}
}

void		connect(t_fdf *fdf, t_line l)
{
	if ((l.dx = l.x2 - l.x1) != 0)
	{
		if (l.dx > 0)
			connect_right(fdf, l);
		else if (l.dx < 0)
			connect_left(fdf, l);
	}
	else
		connect_vertical(fdf, l);
}
