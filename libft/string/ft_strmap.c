/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:54:41 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 17:51:09 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		len;
	int		i;

	if (s)
	{
		len = ft_strlen(s);
		tmp = NULL;
		if (!(tmp = (char*)malloc(sizeof(*tmp) * (len + 1))))
			return (NULL);
		i = -1;
		while (++i < len)
			tmp[i] = f(s[i]);
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
