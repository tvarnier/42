/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 20:28:09 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 20:20:53 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		esc_leave(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	exit(EXIT_SUCCESS);
}

int			key_hook(int key, void *fdf)
{
	t_fdf		*tmp;

	tmp = (t_fdf*)fdf;
	if (key == 53)
		esc_leave(tmp->mlx, tmp->win);
	else if (key == 123 || key == 0)
		move(fdf, -2, 0);
	else if (key == 126 || key == 13)
		move(fdf, 0, -2);
	else if (key == 124 || key == 2)
		move(fdf, 2, 0);
	else if (key == 125 || key == 1)
		move(fdf, 0, 2);
	else if (key == 69)
		z_modif(fdf, 0.1f);
	else if (key == 78)
		z_modif(fdf, -0.1f);
	else if (key == 35)
		change_proj(fdf);
	else if (key == 3)
		change_face(fdf);
	else if (key == 15)
		reset(fdf);
	return (0);
}
