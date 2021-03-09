/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   leave.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/10 05:11:19 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/10 05:12:55 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	leave_success(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	exit(EXIT_SUCCESS);
}

void	leave_failure(void *mlx, void *win)
{
	ft_putendl("ERROR");
	mlx_destroy_window(mlx, win);
	exit(EXIT_FAILURE);
}

int		leave_hook(void *param)
{
	t_data	*d;

	d = (void*)param;
	leave_success(d->mlx, d->win);
	return (0);
}
