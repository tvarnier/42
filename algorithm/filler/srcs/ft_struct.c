/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 23:11:43 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 07:30:51 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

t_tray		*ft_new_tray(void)
{
	t_tray		*tmp;

	tmp = NULL;
	if (!(tmp = (t_tray *)malloc(sizeof(t_tray))))
		return (NULL);
	tmp->player = 0;
	tmp->foe = 0;
	tmp->t_h = 0;
	tmp->t_l = 0;
	tmp->tray = NULL;
	tmp->p_h = 0;
	tmp->p_l = 0;
	tmp->piece = NULL;
	return (tmp);
}

void		ft_clr_tray(t_tray **tray)
{
	int		i;

	if (*tray)
	{
		if ((*tray)->tray)
		{
			i = -1;
			while (((*tray)->tray)[++i])
				ft_strdel(&(((*tray)->tray)[i]));
			free((*tray)->tray);
		}
		if ((*tray)->piece)
		{
			i = -1;
			while (((*tray)->piece)[++i])
				ft_strdel(&(((*tray)->piece)[i]));
			free((*tray)->piece);
		}
		free(*tray);
	}
	*tray = NULL;
}

t_res		*ft_new_res(void)
{
	t_res		*tmp;

	if (!(tmp = (t_res *)malloc(sizeof(t_res))))
		return (NULL);
	tmp->x = 0;
	tmp->y = 0;
	tmp->pt = 0;
	tmp->range = 0;
	return (tmp);
}

void		ft_insert_res(t_res *res, int x, int y, int pt)
{
	res->x = x;
	res->y = y;
	res->pt = pt;
}
