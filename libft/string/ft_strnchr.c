/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 00:43:54 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 00:45:28 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int end, int c)
{
	int i;

	i = -1;
	while (s[++i] && i < end)
		if (s[i] == c)
			return ((char *)&(s[i]));
	if (s[i] == c)
		return ((char *)&(s[i]));
	return (NULL);
}
