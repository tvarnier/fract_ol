/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 15:27:13 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 03:53:10 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_data *d)
{
	srand(time(NULL));
	d->color[0] = rand() % 0xFFFFFF;
	d->color[1] = rand() % 0xFFFFFF;
	d->color[2] = rand() % 0xFFFFFF;
	d->color[3] = rand() % 0xFFFFFF;
	d->color[4] = rand() % 0xFFFFFF;
}

void	change_fractal(t_data *d, int fractal)
{
	d->fractal = fractal;
	init_data(d);
}

void	key_fractal(int key, t_data *d)
{
	if (key == ONE)
		change_fractal(d, 1);
	else if (key == TWO)
		change_fractal(d, 2);
	else if (key == THREE)
		change_fractal(d, 3);
	else if (key == FOUR)
		change_fractal(d, 4);
	else if (key == FIVE)
		change_fractal(d, 5);
}

int		key_hook(int key, void *param)
{
	t_data		*d;

	d = (t_data*)param;
	if (key == ESC)
		leave_success(d->mlx, d->win);
	else if (key == LEFT_ARROW || key == A)
		d->left -= 0.1 / d->zoom;
	else if (key == UP_ARROW || key == W)
		d->up -= 0.1 / d->zoom;
	else if (key == RIGHT_ARROW || key == D)
		d->left += 0.1 / d->zoom;
	else if (key == DOWN_ARROW || key == S)
		d->up += 0.1 / d->zoom;
	else if (key == PLUS)
		d->iter = (d->iter + 5 < MAX_ITER) ? d->iter + 5 : MAX_ITER;
	else if (key == MINUS)
		d->iter = (d->iter - 5 > MIN_ITER) ? d->iter - 5 : MIN_ITER;
	else if (key == R)
		init_data(d);
	else if (key == C)
		change_color(d);
	key_fractal(key, d);
	compute(d);
	return (0);
}
