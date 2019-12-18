/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag_minus.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 01:04:31 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 23:50:27 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_minus(t_format *tab, char *res)
{
	int		len;
	char	*tmp;
	int		i;

	if (tab->width <= (int)ft_strlen(res) && tab->space
			&& res[0] != '-' && res[0] != '+')
		return (ft_strjoin(" ", res));
	else if (tab->width <= (int)ft_strlen(res))
		return (ft_strdup(res));
	len = tab->width;
	tmp = ft_strinit(' ', len);
	tab->space = (res[0] == '-' || res[0] == '+') ? 0 : tab->space;
	i = -1;
	while (res[++i])
		tmp[i + tab->space] = res[i];
	return (tmp);
}

char	*ft_flag_minus_char(t_format *tab, char *res, int *l)
{
	int		len;
	char	*tmp;
	int		i;

	if (tab->width <= *l)
		return (ft_strdup(res));
	len = tab->width;
	tmp = ft_strinit(' ', len);
	i = -1;
	while (++i < *l)
		tmp[i] = res[i];
	*l = len;
	return (tmp);
}
