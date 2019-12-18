/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_s.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 02:01:03 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 11:31:04 by tvarnier    ###    #+. /#+    ###.fr     */
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

static char		*ft_form_scaps_extend(char **tmp, wchar_t *ws, t_format *tab)
{
	int		i;
	char	*res;

	res = ft_strnew(0);
	i = -1;
	while (ws[++i])
	{
		if (!(*tmp = ft_strrep(*tmp, get_unicode(ws[i])))
				&& ((int)ft_strlen(res) + len_unicode(ws[i]) < tab->prec
					|| tab->prec == -1 || tab->format == 'S'))
			return (res = ft_strrep(res, NULL));
		if (*tmp)
			res = ft_strrep(res, ft_strjoin(res, *tmp));
		ft_strdel(tmp);
	}
	if ((int)ft_strlen(res) == 0 && i > 0 && tab->prec > 0
			&& tab->format != 'S')
		return (NULL);
	return (res);
}

char			*ft_form_scaps(va_list arg, t_format *tab, int *l)
{
	char		*res;
	wchar_t		*ws;
	char		*tmp;

	ws = (wchar_t *)va_arg(arg, wchar_t *);
	tmp = NULL;
	if (!ws)
		res = ft_strdup("(null)");
	else
	{
		if (!(res = ft_form_scaps_extend(&tmp, ws, tab)))
			return (NULL);
	}
	ft_apply_flag(tab, &res, l);
	return (res);
}

char			*ft_form_s(va_list arg, t_format *tab, int *l)
{
	char		*res;
	char		*s;

	if (ft_strcmp(tab->size, "l") == 0)
		return (ft_form_scaps(arg, tab, l));
	s = (char *)va_arg(arg, char *);
	if (!s)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(s);
	ft_apply_flag(tab, &res, l);
	return (res);
}
