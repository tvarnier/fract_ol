/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 14:18:10 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 01:43:38 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	ft_get_fractal(char *str)
{
	if (!ft_strcmp(str, "1") || !ft_strcmp(str, "julia"))
		return (julia);
	else if (!ft_strcmp(str, "2") || !ft_strcmp(str, "mandelbrot"))
		return (mandelbrot);
	else if (!ft_strcmp(str, "3") || !ft_strcmp(str, "burningship"))
		return (burningship);
	else if (!ft_strcmp(str, "4") || !ft_strcmp(str, "pythagoras"))
		return (pythagoras);
	else if (!ft_strcmp(str, "5") || !ft_strcmp(str, "barnsley"))
		return (barnsley);
	return (0);
}

void		show_usage(void)
{
	ft_putendl("usage: ./fractol name_or_num_fractal");
	ft_putendl("                 1  julia");
	ft_putendl("                 2  mandelbrot");
	ft_putendl("                 3  burningship");
	ft_putendl("                 4  pythagoras");
	ft_putendl("                 5  barnsley");
}

int			main(int ac, char **av)
{
	t_data	d;

	if (ac == 2)
	{
		if ((d.fractal = ft_get_fractal(av[1])))
			launch(&d);
		else
			show_usage();
	}
	else
		show_usage();
}
