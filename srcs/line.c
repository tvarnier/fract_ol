/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/08 18:55:02 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 19:07:19 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double	ft_fabs(double v)
{
	return (v = (v < 0) ? v * -1 : v);
}

t_line	init_line(t_pts start, t_pts end)
{
	t_line	l;

	l.i = -1;
	l.q = 1;
	l.step_x = end.x - start.x;
	l.step_y = end.y - start.y;
	l.t = ft_fabs(l.step_x);
	l.u = ft_fabs(l.step_y);
	return (l);
}

void	line(t_pts start, t_pts end, t_data *d, int color)
{
	t_line		l;

	l = init_line(start, end);
	if (l.t > l.u && (l.n = ft_fabs(l.step_x)))
	{
		l.step_y /= ft_fabs(l.step_x);
		l.step_x /= ft_fabs(l.step_x);
	}
	else
	{
		l.n = ft_fabs(l.step_y);
		l.step_x /= ft_fabs(l.step_y);
		l.step_y /= ft_fabs(l.step_y);
	}
	while (++l.i < l.n)
	{
		l.pos_x = start.x + l.i * l.step_x;
		l.pos_y = start.y + l.i * l.step_y;
		if ((l.pos_x >= 0 && l.pos_x <= WIDTH)
				&& (l.pos_y >= 0 && l.pos_y <= HEIGHT))
			fill_pixel(&(d->img_str), l.pos_x, l.pos_y, color);
		if (200 - l.q > 0)
			l.q++;
	}
}
