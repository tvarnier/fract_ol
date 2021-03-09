/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ftoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:05:08 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 16:05:35 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digits(long long n)
{
	if (n == -9223372036854775807 - 1)
		return (ft_count_digits(-223372036854775808) + 1);
	if (n < 0)
		return (ft_count_digits(n * (-1)));
	else if (n >= 10)
		return (ft_count_digits(n / 10) + 1);
	else
		return (1);
}

static char		*ft_insert_digits(char *str, long long n, int len)
{
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
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

static char		*ft_insert_decimal(long double n, int decimal, int z)
{
	char		*str;
	int			i;

	if (!(str = ft_strnew(decimal + 1)))
		return (NULL);
	n = (n - (long long)n);
	n = (n < 0) ? n * -1.0f : n;
	i = 0;
	while (++i <= decimal)
	{
		n = (n - (long long)n);
		str[i] = (long long)(n * 10) + 48;
		n = n * 10;
	}
	str[0] = '.';
	if (z)
	{
		while ((str[decimal] == '0' || str[decimal] == '.') && decimal >= 0)
			decimal--;
		str = ft_strrep(str, ft_strsub(str, 0, decimal + 1));
	}
	return (str);
}

char			*ft_ftoa(long double n, int decimal, int z)
{
	int		len;
	char	*str;
	char	*tmp;
	int		sign;

	sign = (n < 0) ? 1 : 0;
	len = ft_count_digits((long long)n) + sign;
	str = NULL;
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (sign)
		str[0] = '-';
	str = ft_insert_digits(str, (long long)n, len);
	if (decimal > 0)
	{
		tmp = ft_insert_decimal(n, decimal, z);
		str = ft_strrep(str, ft_strjoin(str, tmp));
		ft_strdel(&tmp);
	}
	return (str);
}
