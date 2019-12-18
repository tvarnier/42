/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tdautrem <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 22:52:16 by tdautrem     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 19:17:14 by tdautrem    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_recursive(int n, int i, char *str)
{
	if (n >= 10)
	{
		ft_recursive(n / 10, i - 1, str);
		str[i] = (n % 10) + '0';
	}
	else
		str[i] = (n % 10) + '0';
}

static int		ft_nbrlength(int n)
{
	int length;

	if (n == -2147483648)
		return (11);
	length = 0;
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n >= 10)
	{
		length++;
		n /= 10;
	}
	return (length + 1);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		nbrlength;

	nbrlength = ft_nbrlength(n);
	str = (char*)malloc(sizeof(*str) * nbrlength + 1);
	if (!str)
		return (NULL);
	str[nbrlength] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = -147483648;
			str[1] = '2';
		}
		str[0] = '-';
		n *= -1;
	}
	ft_recursive(n, nbrlength - 1, str);
	return (str);
}
