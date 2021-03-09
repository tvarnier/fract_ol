/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:06:50 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 18:20:08 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int y;

	if (needle[0] == '\0')
		return ((char *)&(haystack[0]));
	i = -1;
	while (haystack[++i])
	{
		y = 0;
		if (haystack[i] == needle[y])
		{
			while (haystack[i + y] == needle[y] && needle[y])
				y++;
			if (needle[y] == '\0')
				return ((char *)&(haystack[i]));
		}
	}
	return (NULL);
}
