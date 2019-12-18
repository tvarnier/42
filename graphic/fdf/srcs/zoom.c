/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 15:31:39 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 21:09:20 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(t_fdf *fdf, float zoom, int left, int up)
{
	float		up1;
	float		up2;
	float		left1;
	float		left2;

	(void)left;
	(void)up;
	if (zoom > 1.0f && fdf->zoom >= (float)WIDTH)
		return ;
	up1 = (fdf->pts[fdf->h - 1][fdf->l - 1].a_y * fdf->zoom);
	left1 = ((fdf->pts[0][fdf->l - 1].a_x * fdf->zoom)
			- (fdf->pts[fdf->h - 1][0].a_x * fdf->zoom));
	fdf->zoom = (fdf->zoom * zoom);
	up2 = (fdf->pts[fdf->h - 1][fdf->l - 1].a_y * fdf->zoom);
	left2 = ((fdf->pts[0][fdf->l - 1].a_x * fdf->zoom)
			- (fdf->pts[fdf->h - 1][0].a_x * fdf->zoom));
	fdf->up += (int)((up1 - up2) / 2);
	fdf->left += (int)((left1 - left2) / 4);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_pos(fdf);
}

float		ft_get_zoom(int x, int y)
{
	float	height;
	float	percent;
	float	width;
	float	len1;
	float	len2;

	percent = iso_y(x, 0, 0) / iso_y(x, y, 0);
	height = (HEIGHT * percent);
	width = height * iso_x(x, 0, 0) / iso_y(x, 0, 0);
	len1 = ((sqrt(pow(height, 2) + pow(width, 2)) / (float)x));
	percent = iso_x(0, y, 0) / (iso_x(0, y, 0) - iso_x(x, 0, 0));
	width = ((float)WIDTH * percent);
	height = width * iso_y(0, y, 0) / iso_x(0, y, 0);
	len2 = ((sqrt(pow(height, 2) + pow(width, 2)) / (float)y));
	return ((len1 < len2) ? len1 : len2);
}

int			ft_get_left(t_fdf *fdf)
{
	float	y;

	if (fdf->proj == 1)
	{
		y = (iso_y(0, fdf->l, 0.0f) + (iso_y(fdf->h, 0, 0.0f))
				* (float)fdf->zoom);
		return ((WIDTH - (int)(y)) / 2);
	}
	else
		return ((WIDTH - oblic_y(fdf->h, fdf->l, 0.0f) * fdf->zoom) / 2);
}

int			ft_get_up(t_fdf *fdf)
{
	if (fdf->proj == 1)
		return ((HEIGHT - (iso_x(fdf->h, fdf->l, 0.0f) * fdf->zoom)) / 4);
	else
		return ((HEIGHT - (oblic_x(fdf->h, fdf->l, 0.0f) * fdf->zoom)) / 2);
}
