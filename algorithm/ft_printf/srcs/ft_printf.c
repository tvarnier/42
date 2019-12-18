/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 12:16:32 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:26:26 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlstr(t_lstr **lst)
{
	int			count;
	t_lstr		*tmp;
	int			i;

	tmp = *lst;
	count = 0;
	while (*lst)
	{
		i = -1;
		while (++i < (*lst)->l)
			write(1, &((*lst)->str[i]), 1);
		count += (*lst)->l;
		*lst = (*lst)->next;
	}
	ft_lstrclr(tmp);
	*lst = NULL;
	return (count);
}

static int	ft_printf_next(const char *format, va_list arg, int *i,
		t_lstr **lst)
{
	char		*s;
	int			l;
	int			count;

	count = 0;
	s = NULL;
	if (*format == '%')
	{
		l = 0;
		if (!(s = ft_strrep(s, ft_get_fct(arg, format, i, &l))))
			return (-1);
		ft_lstraddback(lst, s, l);
	}
	else
	{
		while (format[*i] && format[*i] != '%')
			(*i)++;
		s = ft_strrep(s, ft_strsub(format, 0, *i));
		ft_lstraddback(lst, s, *i);
	}
	if (*format == '%' || !format[*i])
		count += ft_putlstr(lst);
	ft_strdel(&s);
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list		arg;
	t_lstr		*lst;
	int			tmp;
	int			i;
	int			count;

	va_start(arg, format);
	lst = NULL;
	count = 0;
	while (*format && ft_strlen(format) && !(i = 0))
	{
		tmp = ft_printf_next(format, arg, &i, &lst);
		count += (tmp == -1) ? 0 : tmp;
		if (tmp == -1)
			return (-1);
		format = format + i;
	}
	va_end(arg);
	return (count);
}
