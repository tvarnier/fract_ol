/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uitoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 17:10:50 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 00:32:39 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digits(unsigned long long n)
{
	if (n >= 10)
		return (ft_count_digits(n / 10) + 1);
	else
		return (1);
}

static char		*ft_insert_digits(char *str, unsigned long long n, int len)
{
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

char			*ft_uitoa(unsigned long long n)
{
	int		len;
	char	*str;

	len = ft_count_digits(n);
	str = NULL;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_insert_digits(str, n, len);
	return (str);
}
