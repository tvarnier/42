/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   change.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 22:37:08 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 22:55:34 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_fdf *fdf)
{
	fdf->angle_z = 0;
	fdf->zoom = ft_get_zoom(fdf->h, fdf->l);
	fdf->left = ft_get_left(fdf);
	fdf->up = ft_get_up(fdf);
	compute_pos(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_pos(fdf);
}

void	change_proj(t_fdf *fdf)
{
	fdf->angle_z = 0;
	fdf->proj = (fdf->proj == 2) ? 1 : 2;
	fdf->zoom = ft_get_zoom(fdf->h, fdf->l);
	fdf->left = ft_get_left(fdf);
	fdf->up = ft_get_up(fdf);
	compute_pos(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_pos(fdf);
}

void	change_face(t_fdf *fdf)
{
	fdf->faces = (fdf->faces == 1) ? 0 : 1;
	compute_pos(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	print_pos(fdf);
}
