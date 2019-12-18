/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 01:35:13 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 06:48:06 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct		s_tray
{
	int				x;
	int				y;
	char			*p1;
	char			*p2;
	int				score_p1;
	int				score_p2;
}					t_tray;

# define O_BCOLOR "\033[48;2;85;255;85m"
# define O_BCOLOR_II "\033[48;2;170;255;170m"
# define X_BCOLOR "\033[48;2;255;255;85m"
# define X_BCOLOR_II "\033[48;2;255;255;170m"
# define DEFAULT_BCOLOR "\033[40m"
# define END_BCOLOR "\033[49m"

# define BORDER_COLOR "\033[30;1m"
# define O_COLOR "\033[38;2;85;255;85m"
# define X_COLOR "\033[38;2;255;255;85m"
# define END_COLOR "\033[39m"

# define UP "\033[1A"
# define DOWN "\033[1B"
# define ERASE "\033[K"

# define LEFT_SPACE 50

t_tray				*ft_new_tray(void);
void				ft_clr_tray(t_tray **tray);

void				ft_get_players(char **p1, char **p2);
void				ft_get_tray_dim(int *x, int *y);
char				**ft_get_tray(int h, int l);

void				ft_print_line(char *s);
void				ft_print_tab(char **tab);
void				ft_print_players(t_tray *p);
void				ft_print_border(int y, int line);
void				ft_print_winner(t_tray *p);
void				ft_print_color(char *color, char *s);
void				ft_print_space(int i);

#endif
