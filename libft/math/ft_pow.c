/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pow.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 19:33:03 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 06:25:09 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_pow(long long n, int exp)
{
	int					i;
	unsigned long long	res;

	if (exp < 0)
		return (0);
	res = 1;
	i = 0;
	while (i++ < exp)
		res *= n;
	return (res);
}
