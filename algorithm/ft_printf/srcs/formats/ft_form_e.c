/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_f.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 17:11:04 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 13:51:34 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_apply_flag(t_format *tab, char **res, int *l,
		long double nbr)
{
	if (tab->width < 0)
	{
		tab->flag = ft_strrep(tab->flag, ft_strchar(tab->flag, '-'));
		tab->width *= -1;
	}
	if (ft_strchr(tab->flag, '+') && nbr >= 0)
		*res = ft_strrep(*res, ft_flag_plus(tab, *res));
	if (ft_strchr(tab->flag, '-'))
		*res = ft_strrep(*res, ft_flag_minus(tab, *res));
	else if (ft_strchr(tab->flag, '0'))
		*res = ft_strrep(*res, ft_flag_zero(tab, *res));
	else
		*res = ft_strrep(*res, ft_flag_default(tab, *res));
	*l = ft_strlen(*res);
}

static int			ft_get_exp(long double *nbr)
{
	int			i;
	int			sign;

	sign = (*nbr >= 0) ? 0 : 1;
	i = 0;
	if (*nbr == 0.0f)
		return (i);
	while ((*nbr >= 10.0f && sign == 0) || (*nbr <= -10.0f && sign == 1))
	{
		*nbr = (*nbr) * 0.1;
		i++;
	}
	while ((*nbr < 1.0f && sign == 0) || (*nbr > -1.0f && sign == 1))
	{
		*nbr = (*nbr) * 10.0;
		i--;
	}
	return (i);
}

static char			*ft_get_rest(int i, t_format *tab)
{
	char	*tmp;

	if (!(tmp = ft_strnew(4)))
		return (NULL);
	tmp[0] = (tab->format == 'E') ? 'E' : 'e';
	tmp[1] = (i >= 0) ? '+' : '-';
	i = ft_abs(i);
	tmp[2] = (i / 10) + 48;
	tmp[3] = (i % 10) + 48;
	return (tmp);
}

char				*ft_form_e(va_list arg, t_format *tab, int *l)
{
	char			*res;
	long double		nbr;
	int				exp;

	if (tab->prec < 0)
		tab->prec = 6;
	if (ft_strcmp(tab->size, "L") == 0)
		nbr = (long double)va_arg(arg, long double);
	else
		nbr = (double)va_arg(arg, double);
	if (nbr != 0.0f)
		nbr = ft_round(nbr, tab->prec);
	exp = ft_get_exp(&nbr);
	if (!(res = ft_ftoa(nbr, tab->prec, 0)))
		return (NULL);
	if (ft_strchr(tab->flag, '#') && !ft_strchr(res, '.'))
		res = ft_strrep(res, ft_strjoin(res, "."));
	res = ft_strrep(res, ft_strjoin(res, ft_get_rest(exp, tab)));
	ft_apply_flag(tab, &res, l, nbr);
	return (res);
}
