/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 00:45:37 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 00:03:10 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digits(long long n)
{
	if (n == -9223372036854775807 - 1)
		return (ft_count_digits(-223372036854775808) + 1);
	if (n < 0)
		return (ft_count_digits(n * (-1)) + 1);
	else if (n >= 10)
		return (ft_count_digits(n / 10) + 1);
	else
		return (1);
}

static char		*ft_insert_digits(char *str, long long n, int len)
{
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -9223372036854775807 - 1)
		{
			str[1] = '9';
			n = -223372036854775808;
		}
		n *= (-1);
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

char			*ft_itoa(long long n)
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
