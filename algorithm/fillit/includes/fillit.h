/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tdautrem <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 20:39:11 by tdautrem     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 19:26:53 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct	s_data
{
	int				a;
	int				linebool;
	int				error;
}				t_data;

typedef struct	s_tetris
{
	char			letter;
	char			**piece;
	struct s_tetris	*next;
}				t_tetris;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

char			**ft_meminit(char **s, size_t len);
int				ft_construct(char *line, t_tetris *tetris, int a);
char			**ft_tabrep(char **t1, char **t2);
int				ft_freenewpiece(char **na);
int				ft_buildpiece(t_tetris *t, t_coord *min, t_coord *max,
		t_coord *co);

int				ft_freeallcoord(t_coord *co1, t_coord *co2, t_coord *co3);
int				ft_checkvoisin(t_tetris *t, t_coord *co, int psize, int *nbrv);
void			ft_changeminmax(int *psize, t_coord **max, t_coord **min,
		t_coord *co);
int				ft_initminmax(int *psize, t_coord **max, t_coord **min,
		t_coord **co);
int				ft_verifpiece(t_tetris *t);

int				ft_readpiece(int *i, int *linebool, t_tetris *tetris,
		char *line);
int				ft_readn(int *i, int *a, t_tetris **tetris, char *line);
int				ft_readinit(int *i, char *line, t_tetris **tetris, t_data **d);
int				ft_readeach(int *i, t_data **d, t_tetris **tetris, char *line);
int				ft_read(const int fd, t_tetris *tetris);

int				ft_resolve(t_tetris *list);
char			*ft_newline(size_t size);
size_t			ft_nbr_piece(t_tetris *begin_list);
void			ft_print_tab(char **tab);
void			ft_free_tab(char **tab, int i);
int				ft_alloc_tab(char ***tab, int i);

#endif
