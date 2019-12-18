/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unicode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 02:36:41 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 17:06:13 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_unicode(wchar_t c)
{
	if ((unsigned long long)c >= ft_pow(2, 8 * MB_CUR_MAX))
		return (1);
	if (c >= 1048576)
		return (1);
	if (c >= 0xD800 && c <= 0xDB7F)
		return (1);
	else if (c >= 0xDC00 && c <= 0xDFFF)
		return (1);
	return (0);
}

int			len_unicode(wchar_t c)
{
	int		n;

	if (c >= 65536)
		n = 4;
	else if (c >= 2048)
		n = 3;
	else if ((c >= 256) || (c >= 128 && MB_CUR_MAX >= 2))
		n = 2;
	else
		n = 1;
	return (n);
}

char		*get_unicode(wchar_t c)
{
	char	*s;
	int		i;
	int		n;

	if (check_unicode(c))
		return (NULL);
	n = len_unicode(c);
	s = ft_strnew(n);
	if (n == 1)
	{
		s[0] = c;
		return (s);
	}
	i = 0;
	while (i < MB_CUR_MAX && i < n)
	{
		if (i == 0)
			s[0] = (c >> (6 * (n - i - 1)) | (240 << (4 - n)));
		else
			s[i] = ((c >> (6 * (n - i - 1)) & 63) | 128);
		i++;
	}
	return (s);
}
