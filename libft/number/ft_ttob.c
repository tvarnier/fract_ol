/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ttob.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 23:45:08 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 00:44:00 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ttob(unsigned long long n, int base)
{
	char	*str_base;
	int		i;
	char	*str;
	int		y;

	if (n == 0)
		return (ft_strinit('0', 1));
	if (base < 2 || base > 36)
		return (NULL);
	if (!(str_base = ft_strbase(base)))
		return (NULL);
	i = 0;
	while (n >= ft_pow(base, i) && ft_pow(base, i - 1) < ft_pow(base, i))
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	y = 0;
	while (--i >= 0)
	{
		str[y++] = str_base[(n / ft_pow(base, i))];
		n -= (n / ft_pow(base, i) * ft_pow(base, i));
	}
	ft_strdel(&str_base);
	return (str);
}
