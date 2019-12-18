/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 13:51:13 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 23:22:01 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

typedef struct		s_tray
{
	char	player;
	char	foe;
	int		t_h;
	int		t_l;
	char	**tray;
	int		p_h;
	int		p_l;
	char	**piece;
}					t_tray;

typedef struct		s_res
{
	int		x;
	int		y;
	int		pt;
	int		range;
}					t_res;

t_tray				*ft_new_tray(void);
void				ft_clr_tray(t_tray **tray);

t_res				*ft_new_res(void);
void				ft_insert_res(t_res *res, int x, int y, int pt);

t_tray				*ft_init_tray(int player);

int					ft_can_place(t_tray *p, int x, int y, char ***tab);
int					ft_block_foe(t_tray *p, int x, int y, char **tab);
int					ft_foe_area(t_tray *p, char ***tab);
int					ft_range_foe(t_tray *p, int x, int y, char **tab);

void				ft_insert_piece(t_tray *p, int x, int y, char ***tab);
void				ft_clear_tab(char ***tab);

#endif
