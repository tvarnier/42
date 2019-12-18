/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 20:56:03 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 10:33:48 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_fdf			*ft_newfdf(void)
{
	t_fdf	*tmp;

	tmp = NULL;
	if (!(tmp = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
		return (NULL);
	tmp->pts = NULL;
	tmp->h = 0;
	tmp->l = 0;
	tmp->mlx = NULL;
	tmp->win = NULL;
	tmp->zoom = 0;
	return (tmp);
}

void			ft_delfdf(t_fdf *fdf)
{
	if (fdf)
	{
		if (fdf->pts)
			ft_delpts(&(fdf->pts), fdf->h);
		if (fdf->corner)
			ft_memdel((void**)&(fdf->corner));
		ft_memdel((void**)&fdf);
	}
}

void			ft_delpts(t_pts ***pts, int h)
{
	int		i;

	if (*pts)
	{
		i = -1;
		while (++i < h)
			ft_memdel((void**)&((*pts)[i]));
		ft_memdel((void**)&(*pts));
	}
}

static t_pts	*ft_init_corner(int h, int l)
{
	t_pts	*tmp;

	if (!(tmp = (t_pts*)ft_memalloc(sizeof(t_pts) * (4))))
		return (NULL);
	tmp[0].o_x = 0;
	tmp[0].o_y = 0;
	tmp[0].o_z = 0;
	tmp[1].o_x = l - 1;
	tmp[1].o_y = 0;
	tmp[1].o_z = 0;
	tmp[2].o_x = 0;
	tmp[2].o_y = h - 1;
	tmp[2].o_z = 0;
	tmp[3].o_x = l - 1;
	tmp[3].o_y = h - 1;
	tmp[3].o_z = 0;
	return (tmp);
}

void			ft_init_fdf(t_fdf *fdf)
{
	fdf->corner = ft_init_corner(fdf->h, fdf->l);
	fdf->proj = 1;
	fdf->faces = 0;
	fdf->zoom = ft_get_zoom(fdf->h, fdf->l);
	fdf->left = ft_get_left(fdf);
	fdf->up = ft_get_up(fdf);
	fdf->angle_z = 0;
	fdf->high = 1;
	fdf->mouse_hold = 0;
	fdf->mouse_x = 0;
	fdf->mouse_y = 0;
}
