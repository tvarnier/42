/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag_zero.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 02:13:47 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 03:21:47 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_zero(t_format *tab, char *res)
{
	int		len;
	char	*tmp;
	int		i;

	if (tab->width <= (int)ft_strlen(res) && tab->space
			&& res[0] != '-' && res[0] != '+')
		return (ft_strjoin(" ", res));
	if (tab->width <= (int)ft_strlen(res))
		return (ft_strdup(res));
	len = tab->width;
	tmp = ft_strinit('0', len);
	tmp[0] = (tab->space) ? ' ' : tmp[0];
	tmp[0] = (res[0] == '+' || res[0] == '-') ? res[0] : tmp[0];
	i = ft_strlen(res);
	while (--i >= 0)
		if (res[i] != '-' && res[i] != '+')
			tmp[--len] = res[i];
	return (tmp);
}

char	*ft_flag_zero_char(t_format *tab, char *res, int *l)
{
	char	*tmp;
	int		i;
	int		len;

	if (tab->width <= *l && tab->space)
	{
		*l += 1;
		return (ft_strjoin(" ", res));
	}
	if (tab->width <= *l)
		return (ft_strdup(res));
	len = tab->width;
	tmp = ft_strinit('0', len);
	tmp[0] = (tab->space) ? ' ' : tmp[0];
	i = *l;
	*l = len;
	while (--i >= 0)
		tmp[--len] = res[i];
	return (tmp);
}
