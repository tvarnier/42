/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_size.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 00:38:19 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:05:22 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

long long			ft_size_int(va_list arg, char *size)
{
	if (ft_strstr(size, "j"))
		return ((intmax_t)va_arg(arg, long long));
	else if (ft_strstr(size, "ll"))
		return ((long long)va_arg(arg, long long));
	else if (ft_strstr(size, "l"))
		return ((long)va_arg(arg, long long));
	else if (ft_strstr(size, "z"))
		return ((size_t)va_arg(arg, long long));
	else if (ft_strstr(size, "hh"))
		return ((signed char)va_arg(arg, long long));
	else if (ft_strstr(size, "h"))
		return ((short)va_arg(arg, long long));
	else
		return ((int)va_arg(arg, long long));
}

unsigned long long	ft_size_uint(va_list arg, char *size)
{
	if (ft_strstr(size, "j"))
		return ((uintmax_t)va_arg(arg, unsigned long long));
	else if (ft_strstr(size, "ll"))
		return ((unsigned long long)va_arg(arg, unsigned long long));
	else if (ft_strstr(size, "l"))
		return ((unsigned long)va_arg(arg, unsigned long long));
	else if (ft_strstr(size, "z"))
		return ((size_t)va_arg(arg, unsigned long long));
	else if (ft_strstr(size, "hh"))
		return ((unsigned char)va_arg(arg, unsigned long long));
	else if (ft_strstr(size, "h"))
		return ((unsigned short)va_arg(arg, unsigned long long));
	else
		return ((unsigned int)va_arg(arg, unsigned long long));
}

wint_t				ft_size_char(va_list arg, char *size)
{
	if (ft_strcmp(size, "l") == 0)
		return ((wint_t)va_arg(arg, wint_t));
	else
		return ((char)va_arg(arg, wint_t));
}
