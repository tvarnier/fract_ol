/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 14:20:14 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 01:29:30 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdlib.h>

# define WIDTH 700
# define HEIGHT 700
# define MIN_ITER 1
# define MAX_ITER 150

# define ESC 53
# define LEFT_ARROW 123
# define UP_ARROW 126
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define A 0
# define W 13
# define D 2
# define S 1
# define R 15
# define C 8
# define PLUS 69
# define MINUS 78
# define ONE 83
# define TWO 84
# define THREE 85
# define FOUR 86
# define FIVE 87
# define LEFT_CLICK 1
# define SCROLL_DOWN 4
# define SCROLL_UP 5

typedef enum		e_fractal
{
	julia = 1,
	mandelbrot = 2,
	burningship = 3,
	pythagoras = 4,
	barnsley = 5,
}					t_fractal;

typedef struct s_thr_data	t_thr_data;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_str;
	t_thr_data		*t;
	t_fractal		fractal;
	int				color[5];
	int				iter;
	long double		up;
	long double		left;
	long double		zoom;
	int				click;
	int				mouse_x;
	int				mouse_y;
	long double		c_r;
	long double		c_i;
	double			pyth_angle;
}					t_data;

struct				s_thr_data
{
	t_data			*d;
	int				id_thr;
	long double		p_r;
	long double		p_i;
	int				x;
	int				y;
};

typedef struct		s_line
{
	double			step_x;
	double			step_y;
	double			pos_x;
	double			pos_y;
	double			n;
	double			t;
	double			u;
	int				i;
	int				q;
}					t_line;

typedef struct		s_pts
{
	int				x;
	int				y;
}					t_pts;

typedef struct		s_pyth
{
	t_pts			a;
	t_pts			b;
	t_pts			c;
	t_pts			d;
	t_pts			e;
}					t_pyth;

void				launch(t_data *d);
void				init_data(t_data *d);

int					key_hook(int key, void *param);
int					leave_hook(void *param);
void				leave_success(void *mlx, void *win);
void				leave_failure(void *mlx, void *win);
int					mouse_hook(int button, int x, int y, void *param);
int					motion_hook(int x, int y, void *param);

void				compute(t_data *d);
void				compute_recursive(t_data *d);
void				line(t_pts start, t_pts end, t_data *d, int color);
void				fill_pixel(char **s, int x, int y, int color);
int					get_color(int color[5], double percent);

void				f_julia(t_data *d, t_thr_data *t);
void				f_mandelbrot(t_data *d, t_thr_data *t);
void				f_burningship(t_data *d, t_thr_data *t);
void				f_pythagoras(t_data *d);
void				f_barnsley(t_data *d);

#endif
