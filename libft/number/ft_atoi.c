/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:15:01 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 18:49:22 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int			i;
	long long	res;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45)
		sign = -1;
	if (nptr[i] == 45 || nptr[i] == 43)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + (nptr[i] - 48);
		if (res < 0 && sign == 1)
			return (-1);
		else if (res < 0 && sign == -1)
			return (0);
		i++;
	}
	return (res * sign);
}
