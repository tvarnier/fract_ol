/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   barnsley.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 01:31:10 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 01:22:05 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	new_coords(double *x, double *y)
{
	int		r;
	double	tmp;

	r = rand() % 100;
	tmp = *x;
	if (r == 0)
	{
		*x = 0;
		*y = 0.16 * (*y);
	}
	else if (r >= 1 && r <= 7)
	{
		*x = -0.15 * (*x) + 0.28 * (*y);
		*y = 0.26 * tmp + 0.24 * (*y) + 0.44;
	}
	else if (r >= 8 && r <= 15)
	{
		*x = 0.2 * (*x) - 0.26 * (*y);
		*y = 0.23 * tmp + 0.22 * (*y) + 1.6;
	}
	else
	{
		*x = 0.85 * (*x) + 0.04 * (*y);
		*y = -0.04 * tmp + 0.85 * (*y) + 1.6;
	}
}

void	compute_barnsley(t_data *d, unsigned long iter)
{
	double	x;
	double	y;

	srand(time(NULL));
	x = 0;
	y = 0;
	while (iter > 0)
	{
		new_coords(&x, &y);
		fill_pixel(&(d->img_str),
				50 * x * d->zoom + WIDTH / 2.0 - d->left * WIDTH,
				50 * y * d->zoom - d->up * WIDTH,
				0x3A5F0B);
		iter--;
	}
}

void	f_barnsley(t_data *d)
{
	ft_bzero((void*)d->img_str, WIDTH * HEIGHT * 4);
	compute_barnsley(d, d->iter * 10000);
}
