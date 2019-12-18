/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 21:16:14 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 17:46:04 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		nbr_words;
	int		verif;

	verif = 1;
	nbr_words = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && verif == 1)
		{
			nbr_words++;
			verif = 0;
		}
		else if (s[i] == c && verif == 0)
			verif = 1;
	}
	return (nbr_words);
}

static t_pts	*ft_line_pts(t_fdf *fdf, char *s, int l, int x)
{
	t_pts	*tmp;
	int		a;
	int		verif;

	if (!(tmp = (t_pts*)ft_memalloc(sizeof(t_pts) * (l))))
		return (NULL);
	verif = 1;
	a = -1;
	while (*s)
	{
		if (*s == ' ')
			verif = 1;
		else if (verif == 1 && *s != ' ' && (verif = 0) == 0)
		{
			(tmp[++a]).o_y = x;
			(tmp[a]).o_x = a;
			(tmp[a]).o_z = ft_getnbr(s);
			fdf->min_high = ((tmp[a]).o_z < fdf->min_high) ?
				(tmp[a]).o_z : fdf->min_high;
			fdf->max_high = ((tmp[a]).o_z > fdf->max_high) ?
				(tmp[a]).o_z : fdf->max_high;
		}
		s++;
	}
	return (tmp);
}

static int		ft_create_pts(t_fdf *fdf, t_lstr *lst)
{
	t_pts	**tmp;
	int		i;

	if (!(tmp = (t_pts**)ft_memalloc(sizeof(t_pts*) * (fdf->h))))
		return (0);
	fdf->l = ft_count_words(lst->str, ' ');
	i = 0;
	while (lst)
	{
		if (!(tmp[i] = ft_line_pts(fdf, lst->str, fdf->l, i)))
			return (0);
		lst = lst->next;
		i++;
	}
	fdf->pts = tmp;
	return (1);
}

static int		ft_loop(int *len, char **line, t_lstr **lst, int *ret)
{
	if (*len == -1)
		*len = ft_count_words(*line, ' ');
	if (ft_count_words(*line, ' ') != *len)
	{
		*ret = -1;
		return (0);
	}
	ft_lstraddback(lst, *line, ft_strlen(*line));
	ft_strdel(line);
	return (1);
}

int				ft_read(int fd, t_fdf *fdf)
{
	int		ret;
	char	*line;
	t_lstr	*lst;
	int		len;

	lst = NULL;
	line = NULL;
	len = -1;
	fdf->min_high = 0;
	fdf->max_high = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!ft_loop(&len, &line, &lst, &ret))
			break ;
		(fdf->h)++;
	}
	if (ret >= 0 && fdf->h > 0 && !ft_create_pts(fdf, lst))
		ret = -1;
	if (line)
		ft_strdel(&line);
	ft_lstrclr(lst);
	ft_init_fdf(fdf);
	if (ret == -1)
		return (0);
	return (1);
}
