/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pixel.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 22:26:07 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 11:02:20 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(t_fdf *fdf, int alt)
{
	float	percent;

	if (alt == 0)
		return (C_LAND_MIN);
	else if (alt > 0)
	{
		percent = (float)alt / (float)fdf->max_high;
		alt = ((C_LAND_MIN >> 16) & 255) + ((((C_LAND_MAX >> 16) & 255)
					- ((C_LAND_MIN >> 16) & 255)) * percent);
		alt = (alt << 8) + ((C_LAND_MIN >> 8) & 255) + ((((C_LAND_MAX >> 8)
						& 255) - ((C_LAND_MIN >> 8) & 255)) * percent);
		alt = (alt << 8) + ((C_LAND_MIN) & 255)
			+ ((((C_LAND_MAX) & 255) - ((C_LAND_MIN) & 255)) * percent);
	}
	else
	{
		percent = (float)alt / (float)fdf->min_high;
		alt = ((C_SEA_MAX >> 16) & 255) + ((((C_SEA_MIN >> 16) & 255)
					- ((C_SEA_MAX >> 16) & 255)) * percent);
		alt = (alt << 8) + ((C_SEA_MAX >> 8) & 255) + ((((C_SEA_MIN >> 8) & 255)
					- ((C_SEA_MAX >> 8) & 255)) * percent);
		alt = (alt << 8) + ((C_SEA_MAX) & 255) + ((((C_SEA_MIN) & 255)
					- ((C_SEA_MAX) & 255)) * percent);
	}
	return (alt);
}

void	fill_pixel(char **s, int x, int y, int color)
{
	int		pos;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pos = 4 * x + WIDTH * 4 * y;
	if ((*s)[pos] == 0 && (*s)[pos + 1] == 0 && (*s)[pos + 2] == 0)
	{
		(*s)[pos + 2] = (color >> (8 * 2)) & 255;
		(*s)[pos + 1] = (color >> (8 * 1)) & 255;
		(*s)[pos] = (color >> (8 * 0)) & 255;
	}
}

int		pos_x(t_fdf *fdf, int x, int y)
{
	return ((int)(fdf->pts[x][y].a_x * fdf->zoom + fdf->left));
}

int		pos_y(t_fdf *fdf, int x, int y)
{
	return ((int)(fdf->pts[x][y].a_y * fdf->zoom + fdf->up));
}

int		in_screen(int x, int y)
{
	return ((x < 0 || x > WIDTH || y < 0 || y > HEIGHT) ? 0 : 1);
}
