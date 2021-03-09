/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_date.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 16:17:43 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 17:21:50 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		*ft_init_month_tab(void)
{
	int		*tmp;

	tmp = (int*)malloc(sizeof(int) * 12);
	tmp[0] = 31;
	tmp[1] = 28;
	tmp[2] = 31;
	tmp[3] = 30;
	tmp[4] = 31;
	tmp[5] = 30;
	tmp[6] = 31;
	tmp[7] = 31;
	tmp[8] = 30;
	tmp[9] = 31;
	tmp[10] = 30;
	tmp[11] = 31;
	return (tmp);
}

static void		ft_hour_change(t_date *d, int *verif)
{
	if (d->month == 10 && d->day == 28 && d->hour == 3 && *verif == 1)
	{
		d->hour += 1;
		*verif = 0;
	}
	else if (d->month == 3 && d->day == 23 && d->hour == 2
			&& *verif == 0)
	{
		d->hour -= 1;
		*verif = 1;
	}
}

static void		ft_change_date(t_date *d, int **tab)
{
	if (d->hour >= 24)
	{
		d->day += 1;
		d->hour = 0;
	}
	if (d->day > (*tab)[d->month - 1])
	{
		d->day = 1;
		d->month += 1;
	}
	if (d->month > 12)
	{
		d->month = 1;
		d->year += 1;
		(*tab)[1] = (d->year % 4 == 0) ? 29 : 28;
	}
}

t_date			*ft_date(long t)
{
	t_date		*d;
	int			verif;
	int			*tab;

	if (!(d = (t_date*)malloc(sizeof(t_date))))
		return (NULL);
	tab = ft_init_month_tab();
	d->second = t % 60;
	d->minute = (t / 60) % 60;
	d->year = 1970;
	d->month = 1;
	d->day = 1;
	d->hour = 0;
	verif = 1;
	while (t > 0)
	{
		ft_hour_change(d, &verif);
		ft_change_date(d, &tab);
		t -= 3600;
		if (t > 0)
			(d->hour) += 1;
	}
	free(tab);
	return (d);
}
