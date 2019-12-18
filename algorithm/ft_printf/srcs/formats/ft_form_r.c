/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_r.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 11:45:26 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 18:13:26 by tvarnier    ###    #+. /#+    ###.fr     */
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
	if (tab->prec >= 0)
		*res = ft_strrep(*res, ft_prec_str(tab, *res));
	if (ft_strchr(tab->flag, '-'))
		*res = ft_strrep(*res, ft_flag_minus(tab, *res));
	else if (ft_strchr(tab->flag, '0') && (tab->prec < 0 || tab->prec_zero))
		*res = ft_strrep(*res, ft_flag_zero(tab, *res));
	else
		*res = ft_strrep(*res, ft_flag_default(tab, *res));
	*l = ft_strlen(*res);
}

static int		ft_get_len_str(char *s)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] < 32)
			count++;
		count++;
	}
	return (count);
}

char			*ft_form_r(va_list arg, t_format *tab, int *l)
{
	char		*res;
	char		*s;
	int			i;

	s = (char *)va_arg(arg, char *);
	if (!s)
		res = ft_strdup("(null)");
	else
	{
		if (!(res = ft_strnew(ft_get_len_str(s))))
			return (NULL);
		i = 0;
		while (*s)
		{
			res[i++] = (*s < 32) ? '^' : *s;
			if (*s < 32)
				res[i++] = *s + 64;
			s++;
		}
	}
	ft_apply_flag(tab, &res, l);
	return (res);
}
