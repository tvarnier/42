/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_fct.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 21:30:00 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 18:00:31 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_init_tab(t_format **tab, const char *format, int i,
		va_list arg)
{
	(*tab)->flag = ft_get_flag(format, i);
	(*tab)->space = ft_get_space(format, i);
	(*tab)->width = ft_get_width(format, i, arg);
	(*tab)->prec = ft_get_prec(format, i, arg, tab);
	(*tab)->size = ft_get_size(format, i);
	(*tab)->format = format[i - 1];
}

static char		*ft_redirect(char *(*f)(va_list, t_format*, int*), va_list arg,
		t_format *tab, int *l)
{
	return (f(arg, tab, l));
}

static char		*ft_init_fct(const char *format, int i, va_list arg, int *l)
{
	void		**fct_tab;
	char		*res;
	t_format	*tab;
	int			y;
	char		*s;

	s = "sSpdDioOuUxXcCfFbeEgGrkt%";
	fct_tab = ft_get_form_tab();
	tab = ft_new_format();
	ft_init_tab(&tab, format, i, arg);
	res = NULL;
	y = -1;
	while (s[++y])
		if (s[y] == format[i - 1])
			break ;
	res = ft_redirect(fct_tab[y], arg, tab, l);
	ft_clr_format(&tab);
	free(fct_tab);
	return (res);
}

char			*ft_get_fct(va_list arg, const char *format, int *i, int *l)
{
	char		*s;
	int			y;

	s = "sSpdDioOuUxXcCfFbeEgGrkt%";
	while (format[++(*i)])
	{
		y = -1;
		while (s[++y])
			if (s[y] == format[*i] && (*i)++)
			{
				return (ft_init_fct(format, *i, arg, l));
			}
		if (ft_isupper(format[*i]) && format[*i + 1] != 'F'
				&& format[*i + 1] != 'f' && (*i)++)
		{
			return (ft_init_fct(format, *i, arg, l));
		}
		else if (format[*i] == '}')
			break ;
	}
	return (ft_strnew(0));
}
