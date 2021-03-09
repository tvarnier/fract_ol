/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 15:51:57 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 01:09:07 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *d, double add, int x, int y)
{
	d->zoom *= add;
	if (add >= 1.0)
	{
		d->left += (((WIDTH / d->zoom) * ((double)x / (double)WIDTH - 0.5))
				/ (double)WIDTH) / 2.0;
		d->up += (((HEIGHT / d->zoom) * ((double)y / (double)HEIGHT - 0.5))
				/ (double)HEIGHT) / 2.0;
	}
	else
	{
		d->left -= (((WIDTH / d->zoom) * ((double)x / (double)WIDTH - 0.5))
				/ (double)WIDTH) / 2.0;
		d->up -= (((HEIGHT / d->zoom) * ((double)y / (double)HEIGHT - 0.5))
				/ (double)HEIGHT) / 2.0;
	}
}

int		mouse_hook(int button, int x, int y, void *param)
{
	t_data		*d;

	d = (t_data*)param;
	if (button == LEFT_CLICK)
		d->click = (d->click == 0) ? 1 : 0;
	else if (d->fractal < pythagoras && button == SCROLL_DOWN)
		zoom(d, 1.2, x, y);
	else if (d->fractal < pythagoras && button == SCROLL_UP)
		zoom(d, 0.8, x, y);
	compute(d);
	return (0);
}

int		motion_hook(int x, int y, void *param)
{
	t_data	*d;

	d = (t_data*)param;
	if ((d->fractal == julia || d->fractal == pythagoras)
			&& d->click == 0 && (d->mouse_x != 0 || d->mouse_y != 0))
	{
		d->c_r += ((long double)(x - d->mouse_x) / (long double)WIDTH) * 2.0;
		d->c_i += ((long double)(y - d->mouse_y) / (long double)HEIGHT) * 2.0;
		d->pyth_angle += ((long double)(x - d->mouse_x) / (long double)WIDTH);
		d->pyth_angle = (d->pyth_angle < 0.25) ? 0.25 : d->pyth_angle;
		d->pyth_angle = (d->pyth_angle > 0.75) ? 0.75 : d->pyth_angle;
		compute(d);
	}
	d->mouse_x = x;
	d->mouse_y = y;
	return (0);
}
