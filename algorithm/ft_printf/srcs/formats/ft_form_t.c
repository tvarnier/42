/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_k.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 17:27:33 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 17:57:46 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_str_time(t_date *d)
{
	char	*res;

	if (!(res = ft_strinit(':', 8)))
		return (NULL);
	res[0] = ((d->hour / 10) % 10) + 48;
	res[1] = (d->hour % 10) + 48;
	res[3] = ((d->minute / 10) % 10) + 48;
	res[4] = (d->minute % 10) + 48;
	res[6] = ((d->second / 10) % 10) + 48;
	res[7] = (d->second % 10) + 48;
	return (res);
}

char			*ft_form_t(va_list arg, t_format *tab, int *l)
{
	char		*res;
	long		t;
	t_date		*d;

	(void)tab;
	t = (long)va_arg(arg, long);
	d = ft_date(t);
	if (!(res = ft_str_time(d)))
		return (NULL);
	*l = ft_strlen(res);
	free(d);
	return (res);
}
