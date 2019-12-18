/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 15:59:32 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 10:57:21 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		print_borders(t_fdf *fdf, int x, int y)
{
	float	max;
	t_line	l;

	l.x1 = pos_x(fdf, x, y);
	l.y1 = pos_y(fdf, x, y);
	if (x >= 0 && x < fdf->h - 1)
	{
		max = (fdf->pts[x][y].o_z > fdf->pts[x + 1][y].o_z) ?
			fdf->pts[x][y].o_z : fdf->pts[x + 1][y].o_z;
		l.color = get_color(fdf, max);
		l.x2 = pos_x(fdf, x + 1, y);
		l.y2 = pos_y(fdf, x + 1, y);
		if (in_screen(l.x1, l.y1) || in_screen(l.x2, l.y2))
			connect(fdf, l);
	}
	if (y >= 0 && y < fdf->l - 1)
	{
		max = (fdf->pts[x][y].o_z > fdf->pts[x][y + 1].o_z) ?
			fdf->pts[x][y].o_z : fdf->pts[x][y + 1].o_z;
		l.color = get_color(fdf, max);
		l.x2 = pos_x(fdf, x, y + 1);
		l.y2 = pos_y(fdf, x, y + 1);
		if (in_screen(l.x1, l.y1) || in_screen(l.x2, l.y2))
			connect(fdf, l);
	}
}

static void		print_faces(t_fdf *fdf, int x, int y)
{
	if (x >= 0 && x < fdf->h - 1 && y >= 0 && y < fdf->l - 1)
	{
		print_face_triangle(fdf, x, y, 0);
		print_face_triangle(fdf, x, y, 1);
	}
}

static void		ft_print_loop(t_fdf *fdf, int x_add, int y_add, int order)
{
	int		x;
	int		y;
	int		h;
	int		l;

	h = (order == 0) ? fdf->h : fdf->l;
	l = (order == 0) ? fdf->l : fdf->h;
	x = (x_add == -1) ? h - 1 : 0;
	while (x >= 0 && x < h)
	{
		y = (y_add == -1) ? l - 1 : 0;
		while (y >= 0 && y < l)
		{
			if (order == 0 && fdf->faces == 1)
				print_faces(fdf, x, y);
			else if (order == 0 && fdf->faces == 0)
				print_borders(fdf, x, y);
			else if (fdf->faces == 1)
				print_faces(fdf, y, x);
			else
				print_borders(fdf, y, x);
			y += y_add;
		}
		x += x_add;
	}
}

static void		print_order(t_fdf *fdf)
{
	if (fdf->corner[3].a_y >= fdf->corner[2].a_y
			&& fdf->corner[3].a_y >= fdf->corner[1].a_y
			&& fdf->corner[3].a_y >= fdf->corner[0].a_y)
		ft_print_loop(fdf, -1, -1, 0);
	else if (fdf->corner[1].a_y >= fdf->corner[2].a_y
			&& fdf->corner[1].a_y >= fdf->corner[0].a_y
			&& fdf->corner[1].a_y >= fdf->corner[3].a_y)
		ft_print_loop(fdf, -1, -1, 1);
	else if (fdf->corner[0].a_y >= fdf->corner[2].a_y
			&& fdf->corner[0].a_y >= fdf->corner[1].a_y
			&& fdf->corner[0].a_y >= fdf->corner[3].a_y)
		ft_print_loop(fdf, 1, 1, 0);
	else
		ft_print_loop(fdf, 1, 1, 1);
}

void			print_pos(t_fdf *fdf)
{
	ft_bzero((void*)fdf->img_str, WIDTH * HEIGHT * 4);
	print_order(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
