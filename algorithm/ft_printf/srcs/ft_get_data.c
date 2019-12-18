/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_data.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 14:05:44 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 13:08:14 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_get_flag(const char *format, int i)
{
	char	*tmp;
	char	*c;
	int		y;
	int		x;

	tmp = ft_strnew(0);
	c = "#+-";
	y = -1;
	while (++y < i)
	{
		x = -1;
		while (c[++x])
			if (format[y] == c[x] && !ft_strchr(tmp, c[x]))
				tmp = ft_strrep(tmp, ft_strchar(tmp, c[x]));
		if (format[y] == '0' && !ft_isdigit(format[y - 1])
				&& !ft_strnchr(format + y, i - y, '#') && format[y - 1] != '-')
		{
			if (!ft_strchr(tmp, '0'))
				tmp = ft_strrep(tmp, ft_strchar(tmp, '0'));
		}
	}
	return (tmp);
}

int			ft_get_width(const char *format, int i, va_list arg)
{
	int		n;
	int		nbr;

	n = -1;
	nbr = 0;
	while (format[++n] && n < i && format[n] != '.')
	{
		if (format[n] == '*')
			nbr = (int)va_arg(arg, int);
		else if (format[n] >= '0' && format[n] <= '9'
				&& !ft_isdigit(format[n - 1]))
			nbr = (ft_atoi(format + n));
	}
	return (nbr);
}

int			ft_get_prec(const char *format, int i, va_list arg, t_format **tab)
{
	int		n;

	n = -1;
	while (format[++n] && n < i)
	{
		if (format[n] == '.' && format[n + 1] == '*')
			return ((int)va_arg(arg, int));
		if (format[n] == '.' && format[n + 1])
		{
			if (!ft_isdigit(format[n + 1]))
				(*tab)->prec_zero = 1;
			return (ft_atoi(format + n + 1));
		}
	}
	return (-1);
}

char		*ft_get_size(const char *format, int i)
{
	char	*c;
	char	*mod;
	int		y;
	int		n;

	c = "hljzL";
	mod = NULL;
	if (!(mod = ft_strnew(0)))
		return (NULL);
	n = 0;
	while (format[++n] && n < i)
	{
		y = -1;
		while (c[++y])
			if (c[y] == format[n])
				mod = ft_strrep(mod, ft_strchar(mod, c[y]));
	}
	return (mod);
}

int			ft_get_space(const char *format, int i)
{
	int		y;

	y = -1;
	while (++y < i && format[y] != '.')
		if (format[y] == ' ')
			return (1);
	return (0);
}
