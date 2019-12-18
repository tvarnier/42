/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_d.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 14:44:28 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 05:08:14 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_apply_flag(t_format *tab, char **res, int *l, long long nbr)
{
	if (tab->width < 0)
	{
		tab->flag = ft_strrep(tab->flag, ft_strchar(tab->flag, '-'));
		tab->width *= -1;
	}
	*res = ft_strrep(*res, ft_prec_int(tab, *res, nbr));
	if (ft_strchr(tab->flag, '+') && nbr >= 0)
		*res = ft_strrep(*res, ft_flag_plus(tab, *res));
	if (ft_strchr(tab->flag, '-'))
		*res = ft_strrep(*res, ft_flag_minus(tab, *res));
	else if (ft_strchr(tab->flag, '0') && tab->prec < 0)
		*res = ft_strrep(*res, ft_flag_zero(tab, *res));
	else
		*res = ft_strrep(*res, ft_flag_default(tab, *res));
	*l = ft_strlen(*res);
}

char			*ft_form_d(va_list arg, t_format *tab, int *l)
{
	char		*res;
	long long	nbr;

	if (tab->format == 'D')
		nbr = (long long)va_arg(arg, long long);
	else
		nbr = ft_size_int(arg, tab->size);
	if (!(res = ft_itoa(nbr)))
		return (NULL);
	res = ft_strrep(res, ft_prec_int(tab, res, nbr));
	ft_apply_flag(tab, &res, l, nbr);
	return (res);
}
