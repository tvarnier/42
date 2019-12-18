/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compute.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 17:57:35 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 21:00:53 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		pts_angle(t_pts *pts, int angle_z, float high)
{
	(*pts).a_x = ((*pts).o_x) * cos(M_PI * angle_z / 180.0f) - ((*pts).o_y)
		* sin(M_PI * angle_z / 180.0f);
	(*pts).a_y = ((*pts).o_x) * sin(M_PI * angle_z / 180.0f) + ((*pts).o_y)
		* cos(M_PI * angle_z / 180.0f);
	(*pts).a_z = ((*pts).o_z * high);
}

static void		compute_pts(t_fdf *fdf)
{
	int		x;
	int		y;

	x = -1;
	while (++x < fdf->h && (y = -1) == -1)
		while (++y < fdf->l)
		{
			pts_angle(&(fdf->pts[x][y]), fdf->angle_z, fdf->high);
			if (fdf->proj == 1)
			{
				fdf->pts[x][y].a_x = iso_x(fdf->pts[x][y].a_x,
						fdf->pts[x][y].a_y, fdf->pts[x][y].a_z);
				fdf->pts[x][y].a_y = iso_y(fdf->pts[x][y].a_x,
						fdf->pts[x][y].a_y, fdf->pts[x][y].a_z);
			}
			else if (fdf->proj == 2)
			{
				fdf->pts[x][y].a_x = oblic_x(fdf->pts[x][y].a_x,
						fdf->pts[x][y].a_y, fdf->pts[x][y].a_z);
				fdf->pts[x][y].a_y = oblic_y(fdf->pts[x][y].a_x,
						fdf->pts[x][y].a_y, fdf->pts[x][y].a_z);
			}
		}
}

static void		compute_corners(t_fdf *fdf)
{
	int		x;

	x = -1;
	while (++x < 4)
	{
		pts_angle(&(fdf->corner[x]), fdf->angle_z, fdf->high);
		if (fdf->proj == 1)
		{
			fdf->corner[x].a_x = iso_x(fdf->corner[x].a_x,
					fdf->corner[x].a_y, fdf->corner[x].a_z);
			fdf->corner[x].a_y = iso_y(fdf->corner[x].a_x,
					fdf->corner[x].a_y, fdf->corner[x].a_z);
		}
		else if (fdf->proj == 2)
		{
			fdf->corner[x].a_x = oblic_x(fdf->corner[x].a_x,
					fdf->corner[x].a_y, fdf->corner[x].a_z);
			fdf->corner[x].a_y = oblic_y(fdf->corner[x].a_x,
					fdf->corner[x].a_y, fdf->corner[x].a_z);
		}
	}
}

void			compute_pos(t_fdf *fdf)
{
	compute_pts(fdf);
	compute_corners(fdf);
}
