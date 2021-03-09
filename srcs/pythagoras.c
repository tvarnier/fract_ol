/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pythagoras.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 03:56:56 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 03:58:21 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	init_pyth(t_pyth *p, double angle)
{
	p->c.x = p->b.x - (p->a.y - p->b.y);
	p->c.y = p->b.y - (p->b.x - p->a.x);
	p->d.x = p->a.x - (p->a.y - p->b.y);
	p->d.y = p->a.y - (p->b.x - p->a.x);
	p->e.x = ((p->d.x + p->c.x) / 2) + (sqrt(pow(p->d.x - p->c.x, 2)
				+ pow(p->d.y - p->c.y, 2)) / 2.0) * cos((angle) * M_PI / 180.0);
	p->e.y = ((p->d.y + p->c.y) / 2) + (sqrt(pow(p->d.x - p->c.x, 2)
				+ pow(p->d.y - p->c.y, 2)) / 2.0) * sin((angle) * M_PI / 180.0);
}

void	init_coord(t_pyth *p, t_pts i, t_pts y)
{
	p->a.x = i.x;
	p->a.y = i.y;
	p->b.x = y.x;
	p->b.y = y.y;
}

void	compute_pythagoras(t_data *data, t_pyth p, int times, double angle)
{
	int		color;

	init_pyth(&p, angle);
	if (times >= data->iter / 5)
		return ;
	color = get_color(data->color, (double)((100 / 5) - times)
			/ (double)(100 / 5));
	line(p.a, p.b, data, color);
	line(p.c, p.b, data, color);
	line(p.c, p.d, data, color);
	line(p.a, p.d, data, color);
	init_coord(&p, p.d, p.e);
	compute_pythagoras(data, p, times + 1, angle - 90.0
			* (data->pyth_angle));
	init_coord(&p, p.e, p.c);
	compute_pythagoras(data, p, times + 1, angle + 90.0
			* (1 - data->pyth_angle));
}

void	f_pythagoras(t_data *d)
{
	t_pyth	p;

	d->iter = (d->iter > 100) ? 100 : d->iter;
	ft_bzero((void*)d->img_str, WIDTH * HEIGHT * 4);
	p.a.x = WIDTH * 42 / 100 + d->left * WIDTH / 2;
	p.a.y = HEIGHT * 70 / 100 + d->up * HEIGHT / 2;
	p.b.x = WIDTH * 57 / 100 + d->left * WIDTH / 2;
	p.b.y = p.a.y;
	compute_pythagoras(d, p, 0, -180.0 * d->pyth_angle);
}
