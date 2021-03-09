/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:59:36 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 03:32:48 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_first(const char *s, int i)
{
	if (s[i + 1] == 0)
		return (i + 1);
	else if (s[i + 2] == 0)
		return (i + 2);
	else if (s[i + 3] == 0)
		return (i + 3);
	else if (s[i + 4] == 0)
		return (i + 4);
	else if (s[i + 5] == 0)
		return (i + 5);
	else if (s[i + 6] == 0)
		return (i + 6);
	else if (s[i + 7] == 0)
		return (i + 7);
	else if (s[i + 8] == 0)
		return (i + 8);
	else if (s[i + 9] == 0)
		return (i + 9);
	else if (s[i + 10] == 0)
		return (i + 10);
	return (0);
}

size_t			ft_strlen(const char *s)
{
	int		i;
	int		count;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if ((count = ft_strlen_first(s, i)))
			return (count);
		if ((count = ft_strlen_first(s, i + 10)))
			return (count);
		if ((count = ft_strlen_first(s, i + 20)))
			return (count);
		if ((count = ft_strlen_first(s, i + 30)))
			return (count);
		if ((count = ft_strlen_first(s, i + 40)))
			return (count);
		if ((count = ft_strlen_first(s, i + 50)))
			return (count);
		if ((count = ft_strlen_first(s, i + 60)))
			return (count);
		i += 70;
	}
	return (i);
}
