/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:20:44 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 18:32:28 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t y;

	if (needle[0] == '\0')
		return ((char *)&(haystack[0]));
	i = 0;
	while (haystack[i] && i < len)
	{
		y = 0;
		if (haystack[i] == needle[y])
		{
			while (haystack[i + y] == needle[y] && needle[y] && (i + y) < len)
				y++;
			if (needle[y] == '\0')
				return ((char *)&(haystack[i]));
		}
		i++;
	}
	return (NULL);
}
