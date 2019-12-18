/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/21 02:15:38 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/21 04:00:50 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchar(char *s, char c)
{
	int		i;
	int		len;
	char	*tmp;

	len = ft_strlen(s);
	tmp = NULL;
	if (!(tmp = ft_strnew(len + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
	{
		tmp[i] = s[i];
	}
	tmp[i] = c;
	return (tmp);
}
