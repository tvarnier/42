/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   launcher.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 13:15:50 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 16:03:51 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lauch(t_fdf *fdf)
{
	int		bpp;
	int		s_l;
	int		endian;

	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img_str = mlx_get_data_addr(fdf->img, &(bpp), &(s_l), &(endian));
	compute_pos(fdf);
	print_pos(fdf);
	mlx_hook(fdf->win, 2, (1L << 0), key_hook, (void*)fdf);
	mlx_hook(fdf->win, 5, (1L << 3), realease_hook, (void*)fdf);
	mlx_hook(fdf->win, 6, (1L << 6), motion_hook, (void*)fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, (void*)fdf);
	mlx_loop(fdf->mlx);
}
