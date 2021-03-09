/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compute.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 13:17:53 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 04:00:14 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int color[5], double percent)
{
	if (percent <= 0.25)
		return (color[0] + ((color[0] - color[1]) * percent * 4));
	else if (percent <= 0.5)
		return (color[0] + ((color[1] - color[2]) * (percent - 0.25) * 4));
	else if (percent <= 0.75)
		return (color[0] + ((color[2] - color[3]) * (percent - 0.5) * 4));
	else
		return (color[0] + ((color[3] - color[4]) * (percent - 0.75) * 4));
}

void	fill_pixel(char **s, int x, int y, int color)
{
	int		pos;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pos = 4 * x + WIDTH * 4 * y;
	(*s)[pos + 2] = (color >> (8 * 2)) & 255;
	(*s)[pos + 1] = (color >> (8 * 1)) & 255;
	(*s)[pos] = (color >> (8 * 0)) & 255;
}

void	(*get_fct(t_fractal fractal))(t_data*, t_thr_data*)
{
	if (fractal == julia)
		return (&f_julia);
	else if (fractal == mandelbrot)
		return (&f_mandelbrot);
	else if (fractal == burningship)
		return (&f_burningship);
	return (NULL);
}

void	*compute_thread(void *param)
{
	int			x_max;
	void		(*fct)(t_data*, t_thr_data*);
	t_data		*d;
	t_thr_data	*t;

	t = (t_thr_data*)param;
	d = t->d;
	fct = get_fct(d->fractal);
	if (fct == NULL)
		leave_failure(d->mlx, d->win);
	t->x = (t->id_thr == 0) ? -1 : (int)(WIDTH * (t->id_thr / 8.0) - 1.0);
	x_max = (int)(WIDTH * ((t->id_thr + 1.0) / 8.0));
	while (++(t->x) < x_max)
	{
		t->p_r = 1 * ((long double)t->x - WIDTH / 2.0)
			/ (0.5 * d->zoom * WIDTH) + (long double)d->left;
		t->y = -1;
		while (++(t->y) < HEIGHT)
		{
			t->p_i = ((long double)t->y - (long double)HEIGHT / 2.0)
				/ (0.5 * d->zoom * (long double)HEIGHT) + (long double)d->up;
			fct(d, t);
		}
	}
	pthread_exit(NULL);
}

void	compute(t_data *d)
{
	int			i;
	pthread_t	*thr;
	t_thr_data	*t;

	if (d->fractal == pythagoras)
		f_pythagoras(d);
	else if (d->fractal == barnsley)
		f_barnsley(d);
	else
	{
		thr = malloc(sizeof(pthread_t) * 8);
		t = d->t;
		i = -1;
		while (++i < 8)
			pthread_create(&(thr[i]), NULL, compute_thread, &(t[i]));
		i = -1;
		while (++i < 8)
			pthread_join(thr[i], NULL);
		ft_memdel((void**)&thr);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}
