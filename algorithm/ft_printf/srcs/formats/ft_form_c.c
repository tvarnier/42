/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_c.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 01:46:15 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 03:52:56 by tvarnier    ###    #+. /#+    ###.fr     */
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
	if (ft_strchr(tab->flag, '-'))
		*res = ft_strrep(*res, ft_flag_minus_char(tab, *res, l));
	else if (ft_strchr(tab->flag, '0') && tab->prec <= 0)
		*res = ft_strrep(*res, ft_flag_zero_char(tab, *res, l));
	else
		*res = ft_strrep(*res, ft_flag_default_char(tab, *res, l));
}

char			*ft_form_c(va_list arg, t_format *tab, int *l)
{
	char		*res;
	wint_t		c;

	if (tab->format == 'C')
		c = (wint_t)va_arg(arg, wint_t);
	else
		c = ft_size_char(arg, tab->size);
	res = NULL;
	if (c >= 128)
	{
		if (!(res = get_unicode(c)))
			return (NULL);
		*l = ft_strlen(res);
	}
	else if (c < 0 && tab->format == 'C')
		return (NULL);
	else
	{
		res = ft_strinit(c, 1);
		*l = 1;
	}
	ft_apply_flag(tab, &res, l);
	return (res);
}
