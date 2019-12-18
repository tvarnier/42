/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag_hashtag.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 03:46:52 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 17:48:23 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_hashtag_hex(t_format *tab, char *res)
{
	char	*tmp;
	int		len;

	tab->width = ft_abs(tab->width);
	if (ft_strchr(tab->flag, '0') && tab->prec < 0
			&& tab->width > (int)ft_strlen(res) + 2)
	{
		len = tab->width;
		tmp = ft_flag_zero(tab, res);
		tmp[1] = (tab->format == 'x') ? 'x' : 'X';
		return (tmp);
	}
	else
	{
		if (tab->format == 'x')
			tmp = ft_strjoin("0x", res);
		else
			tmp = ft_strjoin("0X", res);
		if (ft_strchr(tab->flag, '-'))
			return (tmp = ft_strrep(tmp, ft_flag_minus(tab, tmp)));
		else
			return (tmp = ft_strrep(tmp, ft_flag_default(tab, tmp)));
	}
}

char	*ft_flag_hashtag_oct(t_format *tab, char *res)
{
	(void)tab;
	if (res[0] == '0')
		return (ft_strdup(res));
	else
		return (ft_strjoin("0", res));
}
