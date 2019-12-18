/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 15:41:40 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 22:50:36 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_hook(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (button == 1)
	{
		fdf->mouse_hold = 1;
		fdf->mouse_x = x;
		fdf->mouse_y = y;
	}
	if (button == 5)
		zoom(fdf, 0.9f, x, y);
	else if (button == 4)
		zoom(fdf, 1.1f, x, y);
	return (0);
}

int		realease_hook(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf*)param;
	if (button == 1)
		fdf->mouse_hold = 0;
	return (0);
}

int		motion_hook(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (fdf->mouse_hold == 1)
	{
		rotate(fdf, x, y);
		fdf->mouse_x = x;
		fdf->mouse_y = y;
	}
	return (0);
}
