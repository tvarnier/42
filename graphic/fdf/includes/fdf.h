/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 19:49:24 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 10:56:56 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define WIDTH 2560
# define HEIGHT 1500

# define C_LAND_MIN 0x385D3E
# define C_LAND_MAX 0xE9E813
# define C_SEA_MAX 0xA7C3F5
# define C_SEA_MIN 0x4B59DE

typedef struct		s_pts
{
	int				o_x;
	int				o_y;
	int				o_z;
	float			a_x;
	float			a_y;
	float			a_z;
}					t_pts;

typedef struct		s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				color;
}					t_line;

typedef struct		s_face
{
	float			x1;
	float			y1;
	float			x2;
	float			y2;
	float			x3;
	float			y3;
	float			dx1;
	float			dx2;
	float			dx3;
	float			sx;
	float			sy;
	float			ex;
	float			ey;
	int				color;
}					t_face;

typedef struct		s_fdf
{
	t_pts			**pts;
	t_pts			*corner;
	int				h;
	int				l;
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_str;
	float			zoom;
	int				left;
	int				up;
	int				proj;
	int				faces;
	int				angle_z;
	float			high;
	int				max_high;
	int				min_high;
	int				mouse_hold;
	int				mouse_x;
	int				mouse_y;
	t_face			f;
}					t_fdf;

t_fdf				*ft_newfdf(void);
void				ft_delfdf(t_fdf *fdf);
void				ft_delpts(t_pts ***pts, int h);
void				ft_init_fdf(t_fdf *fdf);

int					ft_read(int fd, t_fdf *fdf);

void				ft_lauch(t_fdf *fdf);
int					key_hook(int key, void *param);
int					mouse_hook(int button, int x, int y, void *param);
int					realease_hook(int button, int x, int y, void *param);
int					motion_hook(int x, int y, void *param);

void				compute_pos(t_fdf *fdf);
int					get_color(t_fdf *fdf, int alt);
int					in_screen(int x, int y);
int					pos_x(t_fdf *fdf, int x, int y);
int					pos_y(t_fdf *fdf, int x, int y);
void				print_pos(t_fdf *fdf);
void				fill_pixel(char **img_str, int x, int y, int color);

void				connect(t_fdf *fdf, t_line l);
void				one(t_fdf *fdf, t_line l);
void				one_two(t_fdf *fdf, t_line l);
void				one_three(t_fdf *fdf, t_line l);
void				one_four(t_fdf *fdf, t_line l);
void				two(t_fdf *fdf, t_line l);
void				two_two(t_fdf *fdf, t_line l);
void				two_three(t_fdf *fdf, t_line l);
void				two_four(t_fdf *fdf, t_line l);

void				print_face_triangle(t_fdf *fdf, int x, int y, int add);
void				fill(t_fdf *fdf, t_face *f);

float				iso_x(float x, float y, float z);
float				iso_y(float x, float y, float z);
float				oblic_x(float x, float y, float z);
float				oblic_y(float x, float y, float z);

float				ft_get_zoom(int x, int y);
void				zoom(t_fdf *fdf, float zoom, int left, int up);
int					ft_get_left(t_fdf *fdf);
int					ft_get_up(t_fdf *fdf);

void				move(t_fdf *fdf, int left, int up);
void				rotate(t_fdf *fdf, int x, int y);
void				z_modif(t_fdf *fdf, float add);
void				reset(t_fdf *fdf);
void				change_proj(t_fdf *fdf);
void				change_face(t_fdf *fdf);

#endif
