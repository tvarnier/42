/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_u.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 17:11:22 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 03:53:08 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_apply_flag(t_format *tab, char **res, int *l,
		unsigned long long nbr)
{
	if (tab->width < 0)
	{
		tab->flag = ft_strrep(tab->flag, ft_strchar(tab->flag, '-'));
		tab->width *= -1;
	}
	*res = ft_strrep(*res, ft_prec_uint(tab, *res, nbr));
	if (ft_strchr(tab->flag, '#'))
		*res = ft_strrep(*res, ft_flag_hashtag_oct(tab, *res));
	if (ft_strchr(tab->flag, '-'))
		*res = ft_strrep(*res, ft_flag_minus(tab, *res));
	else if (ft_strchr(tab->flag, '0') && tab->prec < 0)
		*res = ft_strrep(*res, ft_flag_zero(tab, *res));
	else
		*res = ft_strrep(*res, ft_flag_default(tab, *res));
	*l = ft_strlen(*res);
}

char			*ft_form_o(va_list arg, t_format *tab, int *l)
{
	char				*res;
	unsigned long long	nbr;

	tab->space = 0;
	if (tab->format == 'O')
		nbr = (unsigned long long)va_arg(arg, unsigned long long);
	else
		nbr = ft_size_uint(arg, tab->size);
	if (!(res = ft_ttob(nbr, 8)))
		return (NULL);
	ft_apply_flag(tab, &res, l, nbr);
	return (res);
}
