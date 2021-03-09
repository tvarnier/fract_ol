/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   launch.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 15:06:58 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/10 05:13:48 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		init_data(t_data *d)
{
	d->iter = 50;
	d->zoom = 1;
	d->up = 0.0;
	d->left = 0.0;
	d->click = 0;
	d->mouse_x = 0;
	d->mouse_y = 0;
	d->c_r = 0.285;
	d->c_i = 0.01;
	d->pyth_angle = 0.5;
	d->color[0] = 0Xfd00ff;
	d->color[1] = 0xfdff00;
	d->color[2] = 0x00ff38;
	d->color[3] = 0x00f9ff;
	d->color[4] = 0x3c00ff;
}

t_thr_data	*init_data_thread(t_data *d)
{
	t_thr_data	*tmp;
	int			i;

	tmp = NULL;
	if (!(tmp = (t_thr_data*)malloc(sizeof(t_thr_data) * 8)))
		return (NULL);
	i = -1;
	while (++i < 8)
	{
		tmp[i].d = d;
		tmp[i].id_thr = i;
		tmp[i].p_r = 0.0;
		tmp[i].p_i = 0.0;
		tmp[i].x = 0;
		tmp[i].y = 0;
	}
	return (tmp);
}

void		launch(t_data *d)
{
	int			bpp;
	int			s_l;
	int			endian;
	t_thr_data	*thr_data;

	init_data(d);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "Fract'ol");
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img_str = mlx_get_data_addr(d->img, &(bpp), &(s_l), &(endian));
	if (!(thr_data = init_data_thread(d)))
		leave_failure(d->mlx, d->win);
	d->t = thr_data;
	compute(d);
	mlx_hook(d->win, 2, (1L << 0), key_hook, (void*)d);
	mlx_hook(d->win, 6, (1L << 6), motion_hook, (void*)d);
	mlx_hook(d->win, 17, 0, leave_hook, (void*)d);
	mlx_mouse_hook(d->win, mouse_hook, (void*)d);
	mlx_loop(d->mlx);
	mlx_destroy_image(d->mlx, d->img);
	ft_memdel((void**)&thr_data);
}
