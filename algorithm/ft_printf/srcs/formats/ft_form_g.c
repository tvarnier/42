/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_g.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 11:19:02 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 14:41:10 by tvarnier    ###    #+. /#+    ###.fr     */
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

static int			ft_get_exp(long double nbr)
{
	int			i;
	int			sign;

	sign = (nbr >= 0) ? 0 : 1;
	i = 0;
	if (nbr == 0.0f)
		return (i);
	while ((nbr >= 10.0f && sign == 0) || (nbr <= -10.0f && sign == 1))
	{
		nbr = (nbr) * 0.1f;
		i++;
	}
	while ((nbr < 1.0f && sign == 0) || (nbr > -1.0f && sign == 1))
	{
		nbr = (nbr) * 10.0f;
		i--;
	}
	return (i);
}

static long double	ft_get_nbr(long double nbr, int i)
{
	int		y;

	if (i < 0)
	{
		y = 1;
		while (--y > i)
			nbr = nbr * 10.0;
	}
	else
	{
		y = -1;
		while (++y < i)
			nbr = nbr * 0.1;
	}
	return (nbr);
}

static char			*ft_get_rest(int i, t_format *tab)
{
	char	*tmp;

	if (!(tmp = ft_strnew(4)))
		return (NULL);
	tmp[0] = (tab->format == 'G') ? 'E' : 'e';
	tmp[1] = (i >= 0) ? '+' : '-';
	i = ft_abs(i);
	tmp[2] = (i / 10) + 48;
	tmp[3] = (i % 10) + 48;
	return (tmp);
}

char				*ft_form_g(va_list arg, t_format *tab, int *l)
{
	char			*res;
	long double		nbr;
	int				exp;

	tab->prec = (tab->prec < 0) ? 6 : tab->prec;
	nbr = (ft_strcmp(tab->size, "L") == 0)
		? (long double)va_arg(arg, long double) : (double)va_arg(arg, double);
	exp = ft_get_exp(nbr);
	nbr = (exp < -4 || exp >= tab->prec) ? ft_get_nbr(nbr, exp) : nbr;
	tab->prec = (exp < 0 && ft_abs(exp) > tab->prec) ? ft_abs(exp) : tab->prec;
	if (ft_strchr(tab->flag, '#'))
		tab->prec = (tab->prec - ft_intlen(ft_abs((int)nbr)) >= 0)
			? tab->prec - ft_intlen(ft_abs((int)nbr)) : 0;
	nbr = (nbr != 0.0f) ? ft_round(nbr, tab->prec) : nbr;
	res = (!ft_strchr(tab->flag, '#')) ? ft_ftoa(nbr, tab->prec, 1)
		: ft_ftoa(nbr, tab->prec, 0);
	if (ft_strchr(tab->flag, '#') && !ft_strchr(res, '.'))
		res = ft_strrep(res, ft_strjoin(res, "."));
	tab->prec = (tab->prec == 0) ? 1 : tab->prec;
	if (exp < -4 || exp >= tab->prec)
		res = ft_strrep(res, ft_strjoin(res, ft_get_rest(exp, tab)));
	ft_apply_flag(tab, &res, l, nbr);
	return (res);
}
