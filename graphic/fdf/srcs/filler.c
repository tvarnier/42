/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 18:12:30 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 22:35:33 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		int_swap(float *x1, float *y1, float *x2, float *y2)
{
	float	tmp;

	tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
	tmp = *y1;
	*y1 = *y2;
	*y2 = tmp;
}

static void		order_coord(t_face *f)
{
	if (f->y1 > f->y2)
		int_swap(&(f->x1), &(f->y1), &(f->x2), &(f->y2));
	if (f->y1 > f->y3)
		int_swap(&(f->x1), &(f->y1), &(f->x3), &(f->y3));
	if (f->y2 > f->y3)
		int_swap(&(f->x2), &(f->y2), &(f->x3), &(f->y3));
}

static void		ft_loop(t_fdf *fdf, float y, float dx1, float dx2)
{
	t_line		l;

	l.color = fdf->f.color;
	while ((fdf->f.sy) <= y)
	{
		l.x1 = (int)(fdf->f.sx);
		l.y1 = (int)(fdf->f.sy);
		l.x2 = (int)(fdf->f.ex);
		l.y2 = (int)(fdf->f.ey);
		connect(fdf, l);
		fdf->f.sy = (fdf->f.sy) + 1;
		fdf->f.ey = (fdf->f.ey) + 1;
		fdf->f.sx = (fdf->f.sx) + dx1;
		fdf->f.ex = (fdf->f.ex) + dx2;
	}
}

void			fill(t_fdf *fdf, t_face *f)
{
	order_coord(f);
	f->dx1 = ((f->y2 - f->y1) > 0) ? (f->x2 - f->x1) / (f->y2 - f->y1) : 0;
	f->dx2 = ((f->y3 - f->y1) > 0) ? (f->x3 - f->x1) / (f->y3 - f->y1) : 0;
	f->dx3 = ((f->y3 - f->y2) > 0) ? (f->x3 - f->x2) / (f->y3 - f->y2) : 0;
	f->sx = f->x1;
	f->sy = f->y1;
	f->ex = f->x1;
	f->ey = f->y1;
	if (f->dx1 > f->dx2)
	{
		ft_loop(fdf, f->y2, f->dx2, f->dx1);
		f->ex = f->x2;
		f->ey = f->y2;
		ft_loop(fdf, f->y3, f->dx2, f->dx3);
	}
	else
	{
		ft_loop(fdf, f->y2, f->dx1, f->dx2);
		f->sx = f->x2;
		f->sy = f->y2;
		ft_loop(fdf, f->y3, f->dx3, f->dx2);
	}
}

void			print_face_triangle(t_fdf *fdf, int x, int y, int add)
{
	int		max;

	max = (fdf->pts[x + add][y + add].o_z > fdf->pts[x][y + 1].o_z) ?
		fdf->pts[x + add][y + add].o_z : fdf->pts[x][y + 1].o_z;
	max = (fdf->pts[x + 1][y].o_z > max) ? fdf->pts[x + 1][y].o_z : max;
	max = (fdf->pts[x + 1][y + 1].o_z > max) ?
		fdf->pts[x + 1][y + 1].o_z : max;
	fdf->f.color = get_color(fdf, max);
	fdf->f.x1 = pos_x(fdf, x + add, y + add);
	fdf->f.y1 = pos_y(fdf, x + add, y + add);
	fdf->f.x2 = pos_x(fdf, x, y + 1);
	fdf->f.y2 = pos_y(fdf, x, y + 1);
	fdf->f.x3 = pos_x(fdf, x + 1, y);
	fdf->f.y3 = pos_y(fdf, x + 1, y);
	if (in_screen(fdf->f.x1, fdf->f.y1) || in_screen(fdf->f.x2, fdf->f.y2)
			|| in_screen(fdf->f.x3, fdf->f.y3))
		fill(fdf, &(fdf->f));
}
