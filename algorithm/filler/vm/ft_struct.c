/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 23:58:39 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 06:25:06 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

t_tray		*ft_new_tray(void)
{
	t_tray		*tmp;

	tmp = NULL;
	if (!(tmp = (t_tray *)malloc(sizeof(t_tray))))
		return (NULL);
	tmp->x = 0;
	tmp->y = 0;
	tmp->p1 = NULL;
	tmp->p2 = NULL;
	tmp->score_p1 = 0;
	tmp->score_p2 = 0;
	return (tmp);
}

void		ft_clr_tray(t_tray **tray)
{
	if (*tray)
	{
		if ((*tray)->p1)
		{
			ft_strdel(&((*tray)->p1));
			(*tray)->p1 = NULL;
		}
		if ((*tray)->p2)
		{
			ft_strdel(&((*tray)->p2));
			(*tray)->p2 = NULL;
		}
		free(*tray);
		*tray = NULL;
	}
	*tray = NULL;
}
