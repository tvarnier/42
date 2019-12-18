/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pos.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 16:40:47 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 10:49:00 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_fdf *fdf, int x, int y)
{
	int		tmp_up;
	int		tmp_left;

	(void)x;
	(void)y;
	fdf->angle_z = ((fdf->angle_z - ((fdf->mouse_x - x) / 2)) % 360);
	if (fdf->angle_z < 0)
		fdf->angle_z += 360;
	tmp_up = fdf->pts[fdf->h - 1][fdf->l - 1].a_y * fdf->zoom;
	tmp_left = fdf->pts[fdf->h - 1][fdf->l - 1].a_x * fdf->zoom;
	compute_pos(fdf);
	tmp_up -= fdf->pts[fdf->h - 1][fdf->l - 1].a_y * fdf->zoom;
	tmp_left -= fdf->pts[fdf->h - 1][fdf->l - 1].a_x * fdf->zoom;
	fdf->up = fdf->up + tmp_up / 2;
	fdf->left = fdf->left + tmp_left / 2;
	mlx_clear_window(fdf->mlx, fdf->win);
	print_pos(fdf);
}

void	move(t_fdf *fdf, int left, int up)
{
	fdf->left = fdf->left + (WIDTH * left / 100);
	fdf->up = fdf->up + (HEIGHT * up / 100);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_pos(fdf);
}

void	z_modif(t_fdf *fdf, float add)
{
	fdf->high += add;
	compute_pos(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_pos(fdf);
}
