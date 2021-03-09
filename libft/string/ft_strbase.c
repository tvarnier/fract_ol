/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strbase.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 20:50:16 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 00:14:58 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbase(int n)
{
	char	*s;
	int		i;

	s = NULL;
	if (n < 2 || n > 36)
		return (NULL);
	if (!(s = ft_strnew(n)))
		return (NULL);
	i = 0;
	while (i < n && i < 10)
	{
		s[i] = 48 + i;
		i++;
	}
	while (i < n)
	{
		s[i] = 97 + i - 10;
		i++;
	}
	return (s);
}
