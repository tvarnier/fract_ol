/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   burningship.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 12:14:17 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 03:59:13 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	f_burningship(t_data *d, t_thr_data *t)
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
		tmp = z_r * z_r - z_i * z_i + t->p_r;
		z_i = fabsl(2.0 * z_r * z_i) + t->p_i;
		z_r = fabsl(tmp);
		++i;
	}
	fill_pixel(&(d->img_str), t->x, t->y,
			get_color(d->color, (double)i / (double)d->iter));
}
