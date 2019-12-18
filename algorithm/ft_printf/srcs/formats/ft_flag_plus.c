/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag_plus.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 01:00:32 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 03:09:28 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_plus(t_format *tab, char *res)
{
	(void)tab;
	if (res[0] != '-')
		return (ft_strjoin("+", res));
	return (ft_strdup(res));
}
