/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_form_k.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 17:27:33 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 17:58:49 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_str_date(t_date *d)
{
	char	*res;

	if (!(res = ft_strinit('-', 10)))
		return (NULL);
	res[0] = ((d->year / 1000) % 10) + 48;
	res[1] = ((d->year / 100) % 10) + 48;
	res[2] = ((d->year / 10) % 10) + 48;
	res[3] = (d->year % 10) + 48;
	res[5] = ((d->month / 10) % 10) + 48;
	res[6] = (d->month % 10) + 48;
	res[8] = ((d->day / 10) % 10) + 48;
	res[9] = (d->day % 10) + 48;
	return (res);
}

char			*ft_form_k(va_list arg, t_format *tab, int *l)
{
	char		*res;
	long		t;
	t_date		*d;

	(void)tab;
	t = (long)va_arg(arg, long);
	d = ft_date(t);
	if (!(res = ft_str_date(d)))
		return (NULL);
	*l = ft_strlen(res);
	free(d);
	return (res);
}
