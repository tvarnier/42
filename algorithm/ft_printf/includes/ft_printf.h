/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 18:32:54 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 11:09:40 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"
# include <locale.h>
# include <wchar.h>

typedef struct		s_format
{
	char	*flag;
	int		space;
	int		width;
	int		prec;
	int		prec_zero;
	char	*size;
	char	format;
}					t_format;

int					ft_printf(const char *format, ...);

char				*ft_get_fct(va_list arg, const char *format, int *i,
		int *l);
char				*ft_get_flag(const char *format, int i);
int					ft_get_width(const char *format, int i, va_list arg);
int					ft_get_prec(const char *format, int i, va_list arg,
		t_format **tab);
char				*ft_get_size(const char *format, int i);
int					ft_get_space(const char *format, int i);

void				**ft_get_form_tab(void);
char				*ft_form_p(va_list arg, t_format *tab, int *l);
char				*ft_form_d(va_list arg, t_format *tab, int *l);
char				*ft_form_o(va_list arg, t_format *tab, int *l);
char				*ft_form_u(va_list arg, t_format *tab, int *l);
char				*ft_form_x(va_list arg, t_format *tab, int *l);
char				*ft_form_c(va_list arg, t_format *tab, int *l);
char				*ft_form_s(va_list arg, t_format *tab, int *l);
char				*ft_form_scaps(va_list arg, t_format *tab, int *l);
char				*ft_form_percent(va_list arg, t_format *tab, int *l);
char				*ft_form_upper(va_list arg, t_format *tab, int *l);
char				*ft_form_f(va_list arg, t_format *tab, int *l);
char				*ft_form_b(va_list arg, t_format *tab, int *l);
char				*ft_form_e(va_list arg, t_format *tab, int *l);
char				*ft_form_g(va_list arg, t_format *tab, int *l);
char				*ft_form_r(va_list arg, t_format *tab, int *l);
char				*ft_form_k(va_list arg, t_format *tab, int *l);
char				*ft_form_t(va_list arg, t_format *tab, int *l);

long long			ft_size_int(va_list arg, char *size);
unsigned long long	ft_size_uint(va_list arg, char *size);
wint_t				ft_size_char(va_list arg, char *size);

char				*ft_prec_int(t_format *tab, char *res, long long nbr);
char				*ft_prec_uint(t_format *tab, char *res,
		unsigned long long nbr);
char				*ft_prec_str(t_format *tab, char *res);

char				*ft_flag_default(t_format *tab, char *res);
char				*ft_flag_default_char(t_format *tab, char *res, int *l);
char				*ft_flag_zero(t_format *tab, char *res);
char				*ft_flag_zero_char(t_format *tab, char *res, int *l);
char				*ft_flag_plus(t_format *tab, char *res);
char				*ft_flag_minus(t_format *tab, char *res);
char				*ft_flag_minus_char(t_format *tab, char *res, int *l);
char				*ft_flag_hashtag_hex(t_format *tab, char *res);
char				*ft_flag_hashtag_oct(t_format *tab, char *res);

char				*get_unicode(wchar_t c);
int					len_unicode(wchar_t c);

t_format			*ft_new_format(void);
void				ft_clr_format(t_format **tab);

#endif
