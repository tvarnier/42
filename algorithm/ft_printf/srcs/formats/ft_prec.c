/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prec.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 00:40:20 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 02:52:04 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prec_int(t_format *tab, char *res, long long nbr)
{
	int		len;
	char	*tmp;
	int		i;

	if (nbr == 0 && tab->prec == 0)
		return (ft_strnew(0));
	len = (res[0] == '-') ? tab->prec + 1 : tab->prec;
	if (len <= (int)ft_strlen(res))
		return (ft_strdup(res));
	if (!(tmp = ft_strinit('0', len)))
		return (NULL);
	tmp[0] = (res[0] == '-') ? '-' : tmp[0];
	i = ft_strlen(res);
	while (--i >= 0)
		if (res[i] != '-')
			tmp[--len] = res[i];
	return (tmp);
}

char	*ft_prec_uint(t_format *tab, char *res, unsigned long long nbr)
{
	int		len;
	char	*tmp;
	int		i;

	if (nbr == 0 && tab->prec == 0)
		return (ft_strnew(0));
	len = tab->prec;
	if (len <= (int)ft_strlen(res))
		return (ft_strdup(res));
	if (!(tmp = ft_strinit('0', len)))
		return (NULL);
	i = ft_strlen(res);
	while (--i >= 0)
		if (res[i] != '-')
			tmp[--len] = res[i];
	return (tmp);
}

char	*ft_prec_str(t_format *tab, char *res)
{
	int		len;
	char	*s;
	int		i;
	int		l;

	len = (tab->prec <= (int)ft_strlen(res)) ? tab->prec : ft_strlen(res);
	i = 0;
	l = 0;
	while (res[i] && i < len)
	{
		if (!res[i + 1] || res[i + 1] > 0 || res[i + 1] >= -64)
			l = i + 1;
		i++;
	}
	len = (l < len) ? l : len;
	if (!(s = ft_strsub(res, 0, len)))
		return (NULL);
	return (s);
}
