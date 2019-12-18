/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_x.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 17:51:45 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 03:54:34 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_apply_flag(t_format *tab, char **res, int *l,
		unsigned long long nbr)
{
	if (tab->width < 0)
	{
		tab->flag = ft_strrep(tab->flag, ft_strchar(tab->flag, '-'));
		tab->width *= -1;
	}
	tab->space = 0;
	*res = ft_strrep(*res, ft_prec_uint(tab, *res, nbr));
	if (ft_strchr(tab->flag, '#') && nbr > 0)
		*res = ft_strrep(*res, ft_flag_hashtag_hex(tab, *res));
	else
	{
		if (ft_strchr(tab->flag, '-'))
			*res = ft_strrep(*res, ft_flag_minus(tab, *res));
		else if (ft_strchr(tab->flag, '0') && tab->prec < 0)
			*res = ft_strrep(*res, ft_flag_zero(tab, *res));
		else
			*res = ft_strrep(*res, ft_flag_default(tab, *res));
	}
	*l = ft_strlen(*res);
}

char				*ft_form_x(va_list arg, t_format *tab, int *l)
{
	char				*res;
	unsigned long long	nbr;
	int					i;

	nbr = ft_size_uint(arg, tab->size);
	res = NULL;
	if (!(res = ft_ttob(nbr, 16)))
		return (NULL);
	if (tab->format == 'X')
	{
		i = -1;
		while (res[++i])
			res[i] = ft_toupper(res[i]);
	}
	ft_apply_flag(tab, &res, l, nbr);
	return (res);
}
