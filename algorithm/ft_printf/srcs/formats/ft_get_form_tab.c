/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_form_tab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:08:59 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 18:11:11 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_get_form_tab_next(void ***tab)
{
	(*tab)[14] = &ft_form_f;
	(*tab)[15] = &ft_form_f;
	(*tab)[16] = &ft_form_b;
	(*tab)[17] = &ft_form_e;
	(*tab)[18] = &ft_form_e;
	(*tab)[19] = &ft_form_g;
	(*tab)[20] = &ft_form_g;
	(*tab)[21] = &ft_form_r;
	(*tab)[22] = &ft_form_k;
	(*tab)[23] = &ft_form_t;
	(*tab)[24] = &ft_form_percent;
	(*tab)[25] = &ft_form_upper;
}

void			**ft_get_form_tab(void)
{
	void	**tab;

	tab = NULL;
	tab = (void**)malloc(sizeof(*tab) * 26);
	tab[0] = &ft_form_s;
	tab[1] = &ft_form_scaps;
	tab[2] = &ft_form_p;
	tab[3] = &ft_form_d;
	tab[4] = &ft_form_d;
	tab[5] = &ft_form_d;
	tab[6] = &ft_form_o;
	tab[7] = &ft_form_o;
	tab[8] = &ft_form_u;
	tab[9] = &ft_form_u;
	tab[10] = &ft_form_x;
	tab[11] = &ft_form_x;
	tab[12] = &ft_form_c;
	tab[13] = &ft_form_c;
	ft_get_form_tab_next(&tab);
	return (tab);
}
