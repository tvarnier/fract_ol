/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 16:39:56 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 03:59:20 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	f_julia(t_data *d, t_thr_data *t)
{
	long double		z_r;
	long double		z_i;
	long double		tmp;
	int				i;

	z_r = t->p_r;
	z_i = t->p_i;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4.0 && i < d->iter)
	{
		tmp = 2.0 * z_r * z_i + d->c_i;
		z_r = z_r * z_r - z_i * z_i + d->c_r;
		z_i = tmp;
		++i;
	}
	fill_pixel(&(d->img_str), t->x, t->y,
			get_color(d->color, (double)i / (double)d->iter));
}
