/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct_format.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 19:00:02 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 03:05:50 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_new_format(void)
{
	t_format	*tmp;

	tmp = NULL;
	if (!(tmp = (t_format*)malloc(sizeof(*tmp))))
		return (NULL);
	tmp->flag = NULL;
	tmp->space = 0;
	tmp->width = 0;
	tmp->prec = 0;
	tmp->prec_zero = 0;
	tmp->size = NULL;
	tmp->format = 0;
	return (tmp);
}

void		ft_clr_format(t_format **tab)
{
	if (*tab)
	{
		if ((*tab)->flag)
			ft_strdel(&((*tab)->flag));
		(*tab)->flag = NULL;
		if ((*tab)->size)
			ft_strdel(&((*tab)->size));
		(*tab)->size = NULL;
		free(*tab);
		*tab = NULL;
	}
}
