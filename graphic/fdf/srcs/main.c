/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 19:22:56 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 22:18:07 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_fdf	*fdf;

	fdf = NULL;
	fd = 0;
	if (ac == 2 && (fd = open(av[1], O_RDONLY)) > 0)
	{
		if (!(fdf = ft_newfdf()) || !ft_read(fd, fdf))
			ft_putendl("Error");
		else
			ft_lauch(fdf);
		ft_delfdf(fdf);
		close(fd);
	}
	else
		ft_putendl("usage: ./fillit map");
	return (0);
}
