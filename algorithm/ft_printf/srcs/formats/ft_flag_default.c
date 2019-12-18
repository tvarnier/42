/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag_default.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 00:56:22 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 02:40:56 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_default(t_format *tab, char *res)
{
	char	*tmp;
	int		len;
	int		i;

	if (tab->width <= (int)ft_strlen(res) && tab->space &&
			res[0] != '+' && res[0] != '-')
		return (ft_strjoin(" ", res));
	else if (tab->width <= (int)ft_strlen(res))
		return (ft_strdup(res));
	len = tab->width;
	tmp = ft_strinit(' ', len);
	i = ft_strlen(res);
	while (--i >= 0)
		tmp[--len] = res[i];
	return (tmp);
}

char	*ft_flag_default_char(t_format *tab, char *res, int *l)
{
	int		len;
	char	*tmp;
	int		i;

	if (tab->width <= *l)
		return (ft_strdup(res));
	len = tab->width;
	tmp = ft_strinit(' ', len);
	i = *l;
	*l = len;
	while (--i >= 0)
		tmp[--len] = res[i];
	return (tmp);
}
