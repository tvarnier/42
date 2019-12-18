/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_tab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 06:13:26 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 06:27:53 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

static char		*ft_get_color(char c)
{
	if (c == '.')
		return (DEFAULT_BCOLOR);
	else if (c == 'O')
		return (O_BCOLOR);
	else if (c == 'o')
		return (O_BCOLOR_II);
	else if (c == 'X')
		return (X_BCOLOR);
	else if (c == 'x')
		return (X_BCOLOR_II);
	return (END_BCOLOR);
}

static int		ft_line_len(char *s)
{
	int		len;
	char	c;
	int		i;

	len = LEFT_SPACE + 7 + ft_strlen(END_BCOLOR) + ft_strlen(BORDER_COLOR)
		+ ft_strlen(END_COLOR);
	c = 'A';
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			len += ft_strlen(ft_get_color(s[i]));
			c = s[i];
		}
		len += 2;
	}
	return (len);
}

static char		*ft_get_line(char *s, int len)
{
	char	*line;
	int		i;
	int		a;
	char	c;

	if (!(line = ft_strinit(' ', len)))
		return (NULL);
	i = LEFT_SPACE;
	i = ft_strins(line, BORDER_COLOR, i);
	i = ft_strins(line, "║", i);
	c = 'A';
	a = -1;
	while (s[++a])
	{
		if (s[a] != c)
			i = ft_strins(line, ft_get_color(s[a]), i);
		c = s[a];
		i = ft_strins(line, "  ", i);
	}
	i = ft_strins(line, END_BCOLOR, i);
	i = ft_strins(line, "║", i);
	i = ft_strins(line, END_COLOR, i);
	i = ft_strins(line, "\n", i);
	return (line);
}

void			ft_print_line(char *s)
{
	char	*line;
	int		len;

	len = ft_line_len(s);
	line = ft_get_line(s, len);
	write(1, line, len);
	ft_strdel(&line);
}

void			ft_print_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i] != 0)
		ft_print_line(tab[i]);
}
