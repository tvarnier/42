/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_upper.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 00:51:22 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 03:54:27 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_apply_flag(t_format *tab, char **res, int *l)
{
	if (tab->width < 0)
	{
		tab->flag = ft_strrep(tab->flag, ft_strchar(tab->flag, '-'));
		tab->width *= -1;
	}
	tab->space = 0;
	if (ft_strchr(tab->flag, '-'))
		*res = ft_strrep(*res, ft_flag_minus(tab, *res));
	else if (ft_strchr(tab->flag, '0') && tab->prec <= 0)
		*res = ft_strrep(*res, ft_flag_zero(tab, *res));
	else
		*res = ft_strrep(*res, ft_flag_default(tab, *res));
	*l = ft_strlen(*res);
}

char			*ft_form_upper(va_list arg, t_format *tab, int *l)
{
	char	*res;

	(void)arg;
	*l = 1;
	res = ft_strinit(tab->format, 1);
	ft_apply_flag(tab, &res, l);
	return (res);
}
